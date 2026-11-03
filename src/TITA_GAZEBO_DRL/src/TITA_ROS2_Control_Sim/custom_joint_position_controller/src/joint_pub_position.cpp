#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <control_msgs/msg/multi_dof_command.hpp>
#include <geometry_msgs/msg/transform.hpp>  // 添加 Transform 的导入

using namespace std::chrono_literals;

class JointPositionController : public rclcpp::Node
{
public:
    JointPositionController()
        : Node("joint_pub_position")
    {
        // 初始化发布器和订阅器
        position_publisher_ = this->create_publisher<control_msgs::msg::MultiDOFCommand>("/tita/pid_controller/reference", 10);
        velocity_publisher_ = this->create_publisher<control_msgs::msg::MultiDOFCommand>("/tita/wheel_pid_controller/reference", 10); // 新增
        target_position_subscriber_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(
            "/tita/actions", 10, std::bind(&JointPositionController::targetPositionCallback, this, std::placeholders::_1));
        control_timer_ = this->create_wall_timer(
            2ms, std::bind(&JointPositionController::controlLoop, this));
	    std::cout << "执行1" << std::endl;
    }

private:
    std::vector<double> target_positions_;
    rclcpp::Publisher<control_msgs::msg::MultiDOFCommand>::SharedPtr position_publisher_;
    rclcpp::Publisher<control_msgs::msg::MultiDOFCommand>::SharedPtr velocity_publisher_; // 新增
    rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr target_position_subscriber_;
    rclcpp::TimerBase::SharedPtr control_timer_;
    std::vector<double> last_wheel_positions_{0.0, 0.0}; // 新增
    rclcpp::Time last_time_; // 新增

    void targetPositionCallback(const std_msgs::msg::Float32MultiArray::SharedPtr msg)
    {
        target_positions_.assign(msg->data.begin(), msg->data.end());
    }

    void controlLoop()
    {
       //if (target_positions_.empty()) {
	 //      RCLCPP_INFO(this->get_logger(), "waiting for /tita/actions...");
           //return;
	    //}

       if (target_positions_.size() != 8) {
            RCLCPP_WARN(this->get_logger(), "Expected 8 target positions, got %zu", target_positions_.size());
            return;
        }

        // 创建并初始化 MultiDOFCommand 消息
        auto position_command = control_msgs::msg::MultiDOFCommand();
        auto velocity_command = control_msgs::msg::MultiDOFCommand(); // 新增

        // 指定关节名称
        const std::vector<std::string> position_joint_names = {
            "joint_left_leg_1",
            "joint_left_leg_2",
            "joint_left_leg_3",
            "joint_right_leg_1",
            "joint_right_leg_2",
            "joint_right_leg_3"
        };
        const std::vector<std::string> velocity_joint_names = {
            "joint_left_leg_4",
            "joint_right_leg_4"
        };


        // 设置 degrees of freedom (DoF) 的名称
        position_command.dof_names = position_joint_names;

        // 设置 values 为目标位置
        position_command.values.resize(6);
        for (size_t i = 0; i < 6; ++i) {
            position_command.values[i] = target_positions_[i];
        }

        // 设置 values_dot 为 0
        position_command.values_dot.resize(6, 0.0); // 将速度设为0

        velocity_command.dof_names = velocity_joint_names;
        velocity_command.values.resize(2);
        // 获取当前时间并计算时间间隔
        auto current_time = this->now();
        float dt = 0.02f; // 默认20ms

        if (last_time_.nanoseconds() > 0) {
            dt = (current_time - last_time_).seconds();
            if (dt <= 0.001f) { // 避免时间间隔过小
                dt = 0.02f;
            }
        }
        last_time_ = current_time;

        // 后2个关节：速度控制（索引6-7）
        for (size_t i = 0; i < 2; ++i) {
            double current_wheel_pos = target_positions_[6 + i];
            // 计算速度：位置变化率
            double wheel_velocity = (current_wheel_pos - last_wheel_positions_[i]) / dt;
            velocity_command.values[i] = wheel_velocity;
            last_wheel_positions_[i] = current_wheel_pos;
        }
        velocity_command.values_dot.resize(2, 0.0); // 加速度设为0

        // 发布消息
        position_publisher_->publish(position_command);
        velocity_publisher_->publish(velocity_command);
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


