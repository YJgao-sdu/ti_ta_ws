#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
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
        this->declare_parameter("kp_vel", 0.0);
        this->declare_parameter("ki_vel", 0.0);
        this->declare_parameter("kd_vel", 0.5);
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
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr effort_publisher_;
    rclcpp::Subscription<control_msgs::msg::MultiDOFCommand>::SharedPtr target_position_subscriber_;
    rclcpp::Subscription<control_msgs::msg::MultiDOFCommand>::SharedPtr target_velocity_subscriber_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_subscriber_;
    rclcpp::TimerBase::SharedPtr control_timer_;

    void targetPositionCallback(const control_msgs::msg::MultiDOFCommand::SharedPtr msg)
    {
        if (msg->values.empty()) { 
            RCLCPP_INFO(this->get_logger(), "Received empty data vector");
            return;
	}
	    target_positions_.assign(msg->values.begin(), msg->values.end());
        if (pos_integral_error_.size() != target_positions_.size())
        {
            pos_integral_error_.resize(target_positions_.size(), 0.0);
        }
    }
    
    void targetVelocityCallback(const control_msgs::msg::MultiDOFCommand::SharedPtr msg)
    {
        target_velocities_.assign(msg->values.begin(), msg->values.end());
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
        if (target_positions_.empty()) {
            static bool logged = false;
            if (!logged) {
		        RCLCPP_INFO(this->get_logger(), "waiting for /tita/pid_controller/reference...");
                logged = true;
            }
            return;
	    }
        if (current_positions_.empty()) {
		    RCLCPP_INFO(this->get_logger(), "waiting for /tita/joint_state...");
            return;
	}

        std_msgs::msg::Float64MultiArray effort_msg;
        effort_msg.data.resize(target_positions_.size() + target_velocities_.size(), 0.0);

        for (size_t i = 0; i < target_positions_.size(); ++i)
        {
            if (i > 2)
            {
                double position_error = target_positions_[i] - current_positions_[i+1];
                pos_integral_error_[i] = 0; // 计算积分误差（假设循环频率为 10 ms）
                 pos_integral_error_[i] += position_error * 0.01;       // 计算积分误差（假设循环频率为 10 ms）
                double derivative_error = -current_velocities_[i+1]; // 导数误差基于关节速度

                double effort = kp_pos_ * position_error + ki_pos_ * pos_integral_error_[i] + kd_pos_ * derivative_error;
                effort_msg.data[i+1] = effort;
            }
            else
            {
                double position_error = target_positions_[i] - current_positions_[i];
                pos_integral_error_[i] = 0; // 计算积分误差（假设循环频率为 10 ms)
                 pos_integral_error_[i] += position_error * 0.01;       // 计算积分误差（假设循环频率为 10 ms）
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
                double effort = kd_vel_ * velocity_error;
                if(effort > 20){
                    effort = 20;
                }
                else if(effort < -20){
                    effort = -20;
                }
                effort_msg.data[3] = effort; 
            }
            else if (i == 1)
            {
                double velocity_error = target_velocities_[i] - current_velocities_[7];
                double effort = kd_vel_ * velocity_error;
                if(effort > 20){
                    effort = 20;
                }
                else if(effort < -20){
                    effort = -20;
                }
                effort_msg.data[7] = effort; 
            }
        }
        // 发布力矩到控制器
        effort_publisher_->publish(effort_msg);
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