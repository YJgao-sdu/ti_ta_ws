#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <std_msgs/msg/bool.hpp>  // [新增-阻尼模式] 手动切换阻尼模式
#include <std_msgs/msg/string.hpp>  // [新增-阻尼模式] 发布控制状态
#include <array>  // [新增-阻尼模式] 保存8个关节的力矩和保持位置
#include <cmath>  // [新增-阻尼模式] 检查数值有效性
#include <control_msgs/msg/multi_dof_command.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <mutex>

using namespace std::chrono_literals;

class JointPositionController : public rclcpp::Node
{
public:
    JointPositionController()
        : Node("joint_position_controller")
    {
        // 声明并获取 PID 参数
        this->declare_parameter("kp_pos", 40.0);
        this->declare_parameter("ki_pos", 0.0);
        this->declare_parameter("kd_pos", 1.0);
        this->declare_parameter("kp_vel", 0.8);
        this->declare_parameter("ki_vel", 0.0);
        this->declare_parameter("kd_vel", 0.0035);
        kp_pos_ = this->get_parameter("kp_pos").as_double();
        ki_pos_ = this->get_parameter("ki_pos").as_double();
        kd_pos_ = this->get_parameter("kd_pos").as_double();
        kp_vel_ = this->get_parameter("kp_vel").as_double();
        ki_vel_ = this->get_parameter("ki_vel").as_double();
        kd_vel_ = this->get_parameter("kd_vel").as_double();

        // 初始化发布器和订阅器
        rclcpp::QoS qos(10);
        qos.best_effort(); 
        effort_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/tita/effort_controller/commands", qos); // 3037088
        target_position_subscriber_ = this->create_subscription<control_msgs::msg::MultiDOFCommand>(
            "/tita/pid_controller/reference", 10, std::bind(&JointPositionController::targetPositionCallback, this, std::placeholders::_1));
        target_velocity_subscriber_ = this->create_subscription<control_msgs::msg::MultiDOFCommand>(
            "/tita/wheel_pid_controller/reference", 10, std::bind(&JointPositionController::targetVelocityCallback, this, std::placeholders::_1));
        joint_state_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "/tita/joint_states", qos, std::bind(&JointPositionController::jointStateCallback, this, std::placeholders::_1));
            // 3037088
        
        // [新增-阻尼模式] 声明阻尼控制参数，以下数值仅作为Gazebo初始测试值
        this->declare_parameter("soft_hold_kp", 8.0);
        this->declare_parameter("soft_hold_kd", 1.0);
        this->declare_parameter("wheel_damping_kd", 0.5);
        this->declare_parameter("leg_damping_torque_limit", 8.0);
        this->declare_parameter("wheel_damping_torque_limit", 3.0);
        this->declare_parameter("command_timeout_sec", 0.15);
        this->declare_parameter("transition_time_sec", 0.30);
        soft_hold_kp_ = this->get_parameter("soft_hold_kp").as_double();
        soft_hold_kd_ = this->get_parameter("soft_hold_kd").as_double();
        wheel_damping_kd_ = this->get_parameter("wheel_damping_kd").as_double();
        leg_damping_torque_limit_ = this->get_parameter("leg_damping_torque_limit").as_double();
        wheel_damping_torque_limit_ = this->get_parameter("wheel_damping_torque_limit").as_double();
        command_timeout_sec_ = this->get_parameter("command_timeout_sec").as_double();
        transition_time_sec_ = this->get_parameter("transition_time_sec").as_double();

        // [新增-阻尼模式] 手动阻尼开关：true进入阻尼，false请求恢复RL（需指令恢复新鲜）
        damping_request_subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
            "/tita/safety_damping/enable", 10,
            std::bind(&JointPositionController::dampingRequestCallback, this, std::placeholders::_1));
        damping_status_publisher_ = this->create_publisher<std_msgs::msg::String>(
            "/tita/safety_damping/status", 10);
        last_position_command_time_ = std::chrono::steady_clock::now();
        last_velocity_command_time_ = std::chrono::steady_clock::now();
        last_control_time_ = std::chrono::steady_clock::now();
        last_torque_.fill(0.0);

        control_timer_ = this->create_wall_timer(
            5ms, std::bind(&JointPositionController::controlLoop, this));
    }

private:
    double kp_pos_, kd_pos_, ki_pos_;
    double kp_vel_, kd_vel_, ki_vel_;
    std::vector<double> pos_integral_error_;
    std::vector<double> vel_integral_error_;
    std::vector<double> target_positions_;
    std::vector<double> target_velocities_;
    std::vector<double> current_positions_;
    std::vector<double> current_velocities_;
    std::vector<double> last_velocities_ = std::vector<double>(8, 0.0);
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr effort_publisher_;
    rclcpp::Subscription<control_msgs::msg::MultiDOFCommand>::SharedPtr target_position_subscriber_;
    rclcpp::Subscription<control_msgs::msg::MultiDOFCommand>::SharedPtr target_velocity_subscriber_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_subscriber_;
    rclcpp::TimerBase::SharedPtr control_timer_;

    // [新增-阻尼模式] 阻尼控制参数与模式状态
    double soft_hold_kp_{8.0};
    double soft_hold_kd_{1.0};
    double wheel_damping_kd_{0.5};
    double leg_damping_torque_limit_{8.0};
    double wheel_damping_torque_limit_{3.0};
    double command_timeout_sec_{0.15};
    double transition_time_sec_{0.30};
    bool manual_damping_request_{false};
    bool damping_latched_{false};
    bool release_authorized_{false};
    double damping_blend_{0.0};
    std::array<double, 8> hold_positions_{};
    std::array<double, 8> last_torque_{};
    std::chrono::steady_clock::time_point last_position_command_time_;
    std::chrono::steady_clock::time_point last_velocity_command_time_;
    std::chrono::steady_clock::time_point last_control_time_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr damping_request_subscriber_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr damping_status_publisher_;

    // [新增-阻尼模式] 发布当前控制状态，便于Gazebo和实机监视
    void publishDampingStatus(const std::string &status)
    {
        std_msgs::msg::String msg;
        msg.data = status;
        damping_status_publisher_->publish(msg);
    }

    // [新增-阻尼模式] 接收手动切换命令；退出保护必须由操作者明确确认
    void dampingRequestCallback(const std_msgs::msg::Bool::SharedPtr msg)
    {
        manual_damping_request_ = msg->data;
        if (msg->data) {
            release_authorized_ = false;
            RCLCPP_ERROR(this->get_logger(), "Manual safety damping requested");
        } else if (damping_latched_) {
            release_authorized_ = true;
            RCLCPP_WARN(this->get_logger(), "RL recovery requested; waiting for fresh commands");
        }
    }

    // [新增-阻尼模式] 判断两路RL目标指令是否均在超时时间内更新
    bool rlCommandsFresh() const
    {
        const auto now = std::chrono::steady_clock::now();
        const double pos_age = std::chrono::duration<double>(now - last_position_command_time_).count();
        const double vel_age = std::chrono::duration<double>(now - last_velocity_command_time_).count();
        return !target_positions_.empty() && target_velocities_.size() == 2 &&
               pos_age <= command_timeout_sec_ && vel_age <= command_timeout_sec_;
    }

    // [新增-阻尼模式] 进入保护时锁存当前8个关节的位置
    void enterDampingMode()
    {
        if (damping_latched_ || current_positions_.size() != 8) return;
        std::copy(current_positions_.begin(), current_positions_.end(), hold_positions_.begin());
        damping_latched_ = true;
        release_authorized_ = false;
        RCLCPP_ERROR(this->get_logger(), "SAFETY DAMPING LATCHED");
        publishDampingStatus("DAMPING_LATCHED");
    }

    // [新增-阻尼模式] 计算腿部柔性保持、轮子速度阻尼的8关节力矩
    std::array<double, 8> calculateDampingTorque() const
    {
        std::array<double, 8> tau{};
        for (size_t i = 0; i < 8; ++i) {
            if (i == 3 || i == 7) {
                tau[i] = -wheel_damping_kd_ * current_velocities_[i];
                tau[i] = std::max(-wheel_damping_torque_limit_, std::min(tau[i], wheel_damping_torque_limit_));
            } else {
                tau[i] = soft_hold_kp_ * (hold_positions_[i] - current_positions_[i])
                         - soft_hold_kd_ * current_velocities_[i];
                tau[i] = std::max(-leg_damping_torque_limit_, std::min(tau[i], leg_damping_torque_limit_));
            }
        }
        return tau;
    }

    void targetPositionCallback(const control_msgs::msg::MultiDOFCommand::SharedPtr msg)
    {
        if (msg->values.empty()) { 
            RCLCPP_INFO(this->get_logger(), "Received empty data vector");
            return;
	}
	    target_positions_.assign(msg->values.begin(), msg->values.end());
        // [新增-阻尼模式] 记录最近一次RL腿部位置指令到达时间
        last_position_command_time_ = std::chrono::steady_clock::now();
        if (pos_integral_error_.size() != target_positions_.size())
        {
            pos_integral_error_.resize(target_positions_.size(), 0.0);
        }
    }
    
    void targetVelocityCallback(const control_msgs::msg::MultiDOFCommand::SharedPtr msg)
    {
        target_velocities_.assign(msg->values.begin(), msg->values.end());
        // [新增-阻尼模式] 记录最近一次RL轮速指令到达时间
        last_velocity_command_time_ = std::chrono::steady_clock::now();
        if (vel_integral_error_.size() != target_velocities_.size())
        {
            vel_integral_error_.resize(target_velocities_.size(), 0.0);
        }
    }

    void jointStateCallback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        // 定义所需的关节排序顺序
        std::vector<std::string> desired_order = {
            "joint_left_leg_1",
            "joint_left_leg_2",
            "joint_left_leg_3",
            "joint_left_leg_4",
            "joint_right_leg_1",
            "joint_right_leg_2",
            "joint_right_leg_3",
            "joint_right_leg_4"};

        // 创建用于排序后的 position 和 velocity 数据的向量
        std::vector<double> sorted_position(desired_order.size());
        std::vector<double> sorted_velocity(desired_order.size());

        // 遍历所需顺序中的每个关节名，找到在传入消息（msg）中的对应索引
        for (size_t i = 0; i < desired_order.size(); ++i)
        {
            auto it = std::find(msg->name.begin(), msg->name.end(), desired_order[i]);
            if (it != msg->name.end())
            {
                size_t index = std::distance(msg->name.begin(), it);
                sorted_position[i] = msg->position[index];
                sorted_velocity[i] = msg->velocity[index];
            }
        }
        // 将排序后的关节数据保存到类成员中
        current_positions_ = sorted_position;
        current_velocities_ = sorted_velocity;
    }

    void controlLoop()
    {
        // [新增-阻尼模式] 必须先检查关节状态；阻尼模式不能依赖RL目标位置是否已到达
        if (current_positions_.size() != 8 || current_velocities_.size() != 8) {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                                 "waiting for complete /tita/joint_states...");
            return;
        }

        // [新增-阻尼模式] RL两路指令超时后自动锁存阻尼；不会自动恢复RL
        const bool commands_fresh = rlCommandsFresh();
        const bool command_timeout =
            !target_positions_.empty() && !target_velocities_.empty() && !commands_fresh;

        if (manual_damping_request_ || command_timeout) {
            enterDampingMode();
        } else if (damping_latched_ && release_authorized_ && commands_fresh) {
            damping_latched_ = false;
            release_authorized_ = false;
            RCLCPP_WARN(this->get_logger(), "RL recovery accepted");
            publishDampingStatus("RL_RECOVERING");
        }

        // [新增-阻尼模式] 先准备8维RL力矩缓存，正常RL计算公式及循环保持原样
        std_msgs::msg::Float64MultiArray effort_msg;
        effort_msg.data.resize(8, 0.0);

        if (commands_fresh && target_positions_.size() == 6 && target_velocities_.size() == 2)
        {
            // 原版RL腿部位置控制计算：保持原有代码和注释不变
            for (size_t i = 0; i < target_positions_.size(); ++i)
            {
                if (i > 2)
                {
                    double position_error = target_positions_[i] - current_positions_[i+1];
                    pos_integral_error_[i] = 0; // 计算积分误差（假设循环频率为 5 ms）
                    pos_integral_error_[i] += position_error * 0.005;       // 计算积分误差（假设循环频率为 10 ms）
                    double derivative_error = -current_velocities_[i+1]; // 导数误差基于关节速度

                    double effort = kp_pos_ * position_error + ki_pos_ * pos_integral_error_[i] + kd_pos_ * derivative_error;
                    effort_msg.data[i+1] = effort;
                }
                else
                {
                    double position_error = target_positions_[i] - current_positions_[i];
                    pos_integral_error_[i] = 0; // 计算积分误差（假设循环频率为 5 ms)
                    pos_integral_error_[i] += position_error * 0.005;       // 计算积分误差（假设循环频率为 10 ms）
                    double derivative_error = -current_velocities_[i]; // 导数误差基于关节速度

                    double effort = kp_pos_ * position_error + ki_pos_ * pos_integral_error_[i] + kd_pos_ * derivative_error;
                    effort_msg.data[i] = effort;  
                }
            }
            for (size_t i = 0; i < target_velocities_.size(); ++i)
            {
            
                if (i == 0)
                {
                    double velocity_error = target_velocities_[i] - current_velocities_[3];
                    double effort = kp_vel_ * velocity_error - kd_vel_ * (current_velocities_[3] - last_velocities_[3]) / 0.005; // 假设循环频率为 5 ms
                    last_velocities_[3] = current_velocities_[3];
                    if(effort > 15){
                        effort = 15;
                    }
                    else if(effort < -15){
                        effort = -15;
                    }
                    effort_msg.data[3] = effort; 
                }
                else if (i == 1)
                {
                    double velocity_error = target_velocities_[i] - current_velocities_[7];
                    double effort = kp_vel_ * velocity_error - kd_vel_ * (current_velocities_[7] - last_velocities_[7]) / 0.005; // 假设循环频率为 5 ms
                    last_velocities_[7] = current_velocities_[7];
                    if(effort > 15){
                        effort = 15;
                    }
                    else if(effort < -15){
                        effort = -15;
                    }
                    effort_msg.data[7] = effort; 
                }
            }
        }
        else if (!damping_latched_) {
            // [新增-阻尼模式] RL首次启动或指令数据不完整时不继续输出旧策略力矩
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                                 "waiting for valid RL position and wheel references...");
            return;
        } else {
            // [新增-阻尼模式] 指令超时后渐变期间沿用上周期输出，避免突然清零
            for (size_t i = 0; i < 8; ++i) {
                effort_msg.data[i] = last_torque_[i];
            }
        }

        // [新增-阻尼模式] 计算阻尼力矩，并通过渐变系数切换RL/阻尼控制权
        const auto damping_torque = calculateDampingTorque();
        const auto now = std::chrono::steady_clock::now();
        double dt = std::chrono::duration<double>(now - last_control_time_).count();
        last_control_time_ = now;
        dt = std::max(0.0, std::min(dt, 0.02));
        const double blend_step = transition_time_sec_ > 1e-6 ? dt / transition_time_sec_ : 1.0;
        const double target_blend = damping_latched_ ? 1.0 : 0.0;

        if (damping_blend_ < target_blend) {
            damping_blend_ = std::min(target_blend, damping_blend_ + blend_step);
        } else if (damping_blend_ > target_blend) {
            damping_blend_ = std::max(target_blend, damping_blend_ - blend_step);
        }

        for (size_t i = 0; i < 8; ++i) {
            const double rl_torque = effort_msg.data[i];
            double output_torque =
                (1.0 - damping_blend_) * rl_torque +
                damping_blend_ * damping_torque[i];

            // [新增-阻尼模式] 非有限数值不允许直接传入底层力矩控制器
            if (!std::isfinite(output_torque)) {
                RCLCPP_ERROR(this->get_logger(), "Non-finite torque detected; output set to zero");
                output_torque = 0.0;
            }
            effort_msg.data[i] = output_torque;
            last_torque_[i] = output_torque;
        }
        // 发布力矩到控制器
        effort_publisher_->publish(effort_msg);

        // [新增-阻尼模式] 发布当前模式状态，便于监视和实验记录
        static int status_counter = 0;
        if (++status_counter >= 40) {
            status_counter = 0;
            if (damping_latched_) {
                publishDampingStatus(command_timeout ? "DAMPING_LATCHED_COMMAND_TIMEOUT"
                                                     : "DAMPING_LATCHED_MANUAL");
            } else if (damping_blend_ > 0.0) {
                publishDampingStatus("RL_RECOVERING");
            } else {
                publishDampingStatus("RL_ACTIVE");
            }
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<JointPositionController>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}