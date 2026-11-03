#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <control_msgs/msg/multi_dof_command.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <onnxruntime_cxx_api.h>
#include <Eigen/Dense>
#include <vector>
#include <cmath>
#include <string>
#include <deque>
#include <mutex>

using std::placeholders::_1;

// 定义 TitaPointFootNode 类
class TitaWheelFootNode : public rclcpp::Node
{
public:
    TitaWheelFootNode()
        : Node("tita_wheelfoot_node"),
          env_(ORT_LOGGING_LEVEL_WARNING, "TITAWheelfootONNX")
    {
        // 初始化订阅者
        imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
            "/tita/imu_sensor_broadcaster/imu", 10,
            std::bind(&TitaWheelFootNode::imuCallback, this, _1));  // 3037088
        
        rclcpp::QoS qos(10);
        qos.best_effort(); 
        joint_state_sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "/tita/joint_states", qos,
            std::bind(&TitaWheelFootNode::jointStateCallback, this, _1)); // 3037088

        cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10,
            std::bind(&TitaWheelFootNode::cmdVelCallback, this, _1));
        // cmd_vel_sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
        //     "/tita3037088/command/teleop/command", qos,
        //     std::bind(&TitaWheelFootNode::joycmdCallback, this, _1));

        // 初始化发布者
    	using CommandMsg = control_msgs::msg::MultiDOFCommand;
        pos_action_pub_ = this->create_publisher<CommandMsg>(
            "/tita/pid_controller/reference", 10);
        vel_action_pub_ = this->create_publisher<CommandMsg>(
            "/tita/wheel_pid_controller/reference", 10);

        // 加载参数
        if (!loadParameters())
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to load parameters.");
            rclcpp::shutdown();
        }

        // 加载 ONNX 模型
        RCLCPP_INFO(this->get_logger(), "Loading ONNX model from: %s", model_path.c_str());
        if (!loadONNXModel(model_path))
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to load ONNX model.");
            rclcpp::shutdown();
        }

	// 创建定时器，控制循环以50Hz频率运行
        control_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(20),
            std::bind(&TitaWheelFootNode::controlLoop, this));

        // 初始化历史数据结构
        history_dof_pos_.resize(8);
        history_dof_vel_.resize(8);

        // 初始化默认关节角度
        default_joint_angles_.resize(8);

        // 初始化观测向量
        observation_.resize(observations_size_, 0.0f);
        current_obs_.resize(observations_size_, 0.0f);

        // 初始化上一次动作
        last_actions_.resize(actions_size_, 0.0f);

        // 初始化当前命令
        current_commands_.resize(4, 0.0f);

        // 使用默认值初始化历史队列
        for (size_t i = 0; i < 8; ++i)
        {
            history_dof_pos_[i] = std::deque<float>(history_length_dof_pos_, default_joint_angles_[i]);
            history_dof_vel_[i] = std::deque<float>(history_length_dof_vel_, 0.0f);
        }

        RCLCPP_INFO(this->get_logger(), "TitaWheelFootNode initialized successfully.");
    }

    ~TitaWheelFootNode()
    {
        if (policy_session_)
        {
            delete policy_session_;
            policy_session_ = nullptr;
        }
    }

private:
    // 订阅者和发布者
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_sub_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
    // rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr cmd_vel_sub_;

    rclcpp::Publisher<control_msgs::msg::MultiDOFCommand>::SharedPtr pos_action_pub_;
    rclcpp::Publisher<control_msgs::msg::MultiDOFCommand>::SharedPtr vel_action_pub_;

    // 定时器
    rclcpp::TimerBase::SharedPtr control_timer_;

    // 最新的消息存储
    sensor_msgs::msg::Imu::SharedPtr latest_imu_msg_;
    sensor_msgs::msg::JointState::SharedPtr latest_joint_state_msg_;

    // 互斥锁
    std::mutex imu_mutex_;
    std::mutex joint_state_mutex_;

    // ONNX模型相关
    Ort::Env env_;
    Ort::Session *policy_session_ = nullptr;
    Ort::SessionOptions session_options_;
    std::vector<const char *> input_names_;
    std::vector<const char *> output_names_;
    std::string input_name_storage_;
    std::string output_name_storage_;
    std::vector<int64_t> input_shape_;
    std::vector<int64_t> output_shape_;
    std::vector<std::string> input_names_storage_;  // 存储多个输入名称
    std::vector<std::vector<int64_t>> input_shapes_; // 存储多个输入形状
    std::vector<std::vector<float>> history_buffer_;  // 存储历史数据的缓冲区
    int prop_dim_ = 32;        // n_proprio - 3
    const std::vector<size_t> pos_joint_indices = {0, 1, 2, 4, 5, 6};

    // 参数
    std::vector<std::string> joint_names_ = {
            "joint_left_leg_1",
            "joint_left_leg_2",
            "joint_left_leg_3",
	        "joint_left_leg_4",
            "joint_right_leg_1",
            "joint_right_leg_2",
            "joint_right_leg_3",
            "joint_right_leg_4"};
    std::vector<float> default_joint_angles_;
    float obs_scales_angvel_, obs_scales_dofpos_, obs_scales_dofvel_;
    float scaled_commands_x_, scaled_commands_y_, scaled_commands_z_, scaled_commands_h_;
    float stiffness_, damping_, action_scale_pos_, action_scale_vel_, user_torque_limit_, decimation_;
    int actions_size_, observations_size_, commands_size_, history_len_;
    float clip_observations_, clip_actions_;
    std::string model_path;

    int history_length_dof_pos_;
    int history_length_dof_vel_;

    // 数据
    std::vector<float> observation_;
    std::vector<float> hisory_buffer_;
    std::vector<float> last_actions_;
    std::vector<std::deque<float>> history_dof_pos_;
    std::vector<std::deque<float>> history_dof_vel_;
    std::vector<float> current_obs_;

    // 当前速度命令
    std::vector<float> current_commands_;

    // 标志位，指示是否已接收到初始观测
    bool has_received_observation_ = false;

    // 观测数据的键
    std::vector<std::string> observation_keys_ = {
        "ang_vel_x",
        "ang_vel_y",
        "ang_vel_z",
        "gravity_proj_x",
        "gravity_proj_y",
        "gravity_proj_z",
        "current_command_1",
        "current_command_2",
        "current_command_3",
    	"current_command_4",
        "joint_left_leg_1_pos",
        "joint_left_leg_2_pos",
        "joint_left_leg_3_pos",
        "joint_right_leg_1_pos",
        "joint_right_leg_2_pos",
        "joint_right_leg_3_pos",
        "joint_left_leg_1_vel",
        "joint_left_leg_2_vel",
        "joint_left_leg_3_vel",
    	"joint_left_leg_4_vel",
        "joint_right_leg_1_vel",
        "joint_right_leg_2_vel",
        "joint_right_leg_3_vel",
    	"joint_right_leg_4_vel",
        "last_action_1",
        "last_action_2",
        "last_action_3",
        "last_action_4",
        "last_action_5",
        "last_action_6",
    	"last_action_7",
    	"last_action_8"};
    // 打印obs
    void printObservations(const std::vector<float> &observations)
    {
        if (observations.size() != observation_keys_.size())
        {
            RCLCPP_WARN(this->get_logger(), "Observations size (%lu) does not match keys size (%lu).", observations.size(), observation_keys_.size());
            return;
        }

        std::stringstream ss;
        ss << "{\n";
        for (size_t i = 0; i < observations.size(); ++i)
        {
            ss << "  " << observation_keys_[i] << ": " << observations[i] << "\n";
        }
        ss << "}";

        RCLCPP_INFO(this->get_logger(), "Observations:\n%s", ss.str().c_str());
    }
    // 成员函数

    // IMU消息回调
    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
    	std::lock_guard<std::mutex> lock(imu_mutex_);
        latest_imu_msg_ = msg;
        static bool once = false;
        if (!once) { once = true; RCLCPP_INFO(this->get_logger(), "第一个 IMU received"); }
    }

    // JointState 消息回调
    void jointStateCallback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
	    std::lock_guard<std::mutex> lock(joint_state_mutex_);

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

        // 创建用于排序后的 position、velocity 和 effort 数据的向量
        std::vector<double> sorted_position(desired_order.size());
        std::vector<double> sorted_velocity(desired_order.size());
        std::vector<double> sorted_effort(desired_order.size());

        // 遍历所需顺序中的每个关节名，找到在传入消息（msg）中的对应索引
        for (size_t i = 0; i < desired_order.size(); ++i)
        {
            auto it = std::find(msg->name.begin(), msg->name.end(), desired_order[i]);
            if (it != msg->name.end())
            {
                size_t index = std::distance(msg->name.begin(), it);
                sorted_position[i] = msg->position[index];
                sorted_velocity[i] = msg->velocity[index];
                sorted_effort[i] = msg->effort[index];
            }
        }
        // std::cout << "左轮关节速度：" << sorted_velocity[3] << std::endl; 

        // 创建一个新的 JointState 消息，使用排序后的数据
        auto sorted_msg = std::make_shared<sensor_msgs::msg::JointState>();
        sorted_msg->header = msg->header;
        sorted_msg->name = desired_order;
        sorted_msg->position = sorted_position;
        sorted_msg->velocity = sorted_velocity;
        sorted_msg->effort = sorted_effort;

        // 将排序后的消息赋值给 latest_joint_state_msg_
        latest_joint_state_msg_ = sorted_msg;
        static bool once = false;
        if (!once) { once = true; RCLCPP_INFO(this->get_logger(), "第一个 JointState received"); }
    }

    // cmd_vel消息回调
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        // Use the user_cmd_scales to scale the velocity commands
        current_commands_[0] = static_cast<float>(msg->linear.x) * scaled_commands_x_;
        current_commands_[1] = static_cast<float>(msg->linear.y) * scaled_commands_y_;
        current_commands_[2] = static_cast<float>(msg->angular.z) * scaled_commands_z_;
 	    current_commands_[3] = static_cast<float>(msg->linear.z) * scaled_commands_h_;

        float norm1 = std::sqrt(current_commands_[0] * current_commands_[0]);
        float norm2 = std::sqrt(current_commands_[2] * current_commands_[2]);

        // 阈值判断
        if (norm1 <= 0.01f) {
            current_commands_[0] = 0.0f;
        }
        if (norm2 <= 0.01f) {
            current_commands_[2] = 0.0f;
        }

        std::cout << "指令值: ";
        for (size_t i = 0; i < current_commands_.size(); ++i) {
            std::cout << current_commands_[i];
            if (i < current_commands_.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    // void joycmdCallback(const sensor_msgs::msg::Joy::SharedPtr msg)
    // {
    //     // Use the user_cmd_scales to scale the velocity commands
    //     current_commands_[0] = 1.2 * msg->axes[2] * scaled_commands_x_;  // 前进
    //     current_commands_[1] = 0 * msg->axes[3] * scaled_commands_y_;  // 横向
    //     current_commands_[2] = msg->axes[0] * scaled_commands_z_;  // 自转
    //     current_commands_[3] = 0.1 + 0.3 * msg->axes[1] * scaled_commands_h_;  // 高度/俯仰
        
    //     float norm1 = std::sqrt(msg->axes[2] * msg->axes[2]);
    //     if (norm1 <= 0.1f) {
    //         current_commands_[0] = 0.0f;
    //     }
    //     float norm2 = std::sqrt(msg->axes[0] * msg->axes[0]);
    //     if (norm2 <= 0.1f) {
    //         current_commands_[2] = 0.0f;
    //     }
    //     std::cout << "指令值: ";
    //     for (size_t i = 0; i < current_commands_.size(); ++i) {
    //         std::cout << current_commands_[i];
    //         if (i < current_commands_.size() - 1) std::cout << ", ";
    //     }
    //     std::cout << std::endl;
    // }

    // 加载参数
    bool loadParameters()
    {
        RCLCPP_INFO(this->get_logger(), "Loading parameters directly...");
        // 参数声明
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_left_leg_1", -0.0);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_left_leg_2", 0.8);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_left_leg_3", -1.5);
	this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_left_leg_4", 0.0);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_right_leg_1", 0.0);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_right_leg_2", 0.8);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_right_leg_3", -1.5);
	this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_right_leg_4", 0.0);

        this->declare_parameter<int>("TITAWheelfootCfg.observation.history_length_dof_pos", 0);
        this->declare_parameter<int>("TITAWheelfootCfg.observation.history_length_dof_vel", 0);

        this->declare_parameter<float>("TITAWheelfootCfg.control.stiffness", 30.0);
        this->declare_parameter<float>("TITAWheelfootCfg.control.damping", 0.5);
        this->declare_parameter<float>("TITAWheelfootCfg.control.action_scale_pos", 0.25);
    	this->declare_parameter<float>("TITAWheelfootCfg.control.action_scale_vel", 8.0);
        this->declare_parameter<float>("TITAWheelfootCfg.control.decimation", 4.0);
        this->declare_parameter<float>("TITAWheelfootCfg.control.user_torque_limit", 45.0);

        this->declare_parameter<float>("TITAWheelfootCfg.normalization.clip_scales.clip_observations", 100.0);
        this->declare_parameter<float>("TITAWheelfootCfg.normalization.clip_scales.clip_actions", 100.0);
        this->declare_parameter<float>("TITAWheelfootCfg.normalization.obs_scales.ang_vel", 0.25);
        this->declare_parameter<float>("TITAWheelfootCfg.normalization.obs_scales.dof_pos", 1.0);
        this->declare_parameter<float>("TITAWheelfootCfg.normalization.obs_scales.dof_vel", 0.05);

        this->declare_parameter<int>("TITAWheelfootCfg.size.actions_size", 8);
        this->declare_parameter<int>("TITAWheelfootCfg.size.observations_size", 32);
        this->declare_parameter<int>("TITAWheelfootCfg.size.observation_history_len", 10);
        this->declare_parameter<int>("TITAWheelfootCfg.size.commands_size", 4);

        this->declare_parameter<float>("TITAWheelfootCfg.user_cmd_scales.lin_vel_x", 2.0);
        this->declare_parameter<float>("TITAWheelfootCfg.user_cmd_scales.lin_vel_y", 2.0);
        this->declare_parameter<float>("TITAWheelfootCfg.user_cmd_scales.ang_vel_yaw", 0.25);
	    this->declare_parameter<float>("TITAWheelfootCfg.user_cmd_scales.base_height", 1.0);

        this->declare_parameter<std::string>("TITAWheelfootCfg.model_path", "/mnt/dev/tita_ws/src/TITA_GAZEBO_DRL/src/TITA_DRL/config/policy/policy_57.onnx");


        // 获取参数
        default_joint_angles_.resize(8);
        // 默认角度
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_left_leg_1", default_joint_angles_[0]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_left_leg_2", default_joint_angles_[1]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_left_leg_3", default_joint_angles_[2]);
    	this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_left_leg_4", default_joint_angles_[3]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_right_leg_1", default_joint_angles_[4]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_right_leg_2", default_joint_angles_[5]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_right_leg_3", default_joint_angles_[6]);
	    this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_right_leg_4", default_joint_angles_[7]);
        // 历史数据长度
        this->get_parameter("TITAWheelfootCfg.observation.history_length_dof_pos", history_length_dof_pos_);
        this->get_parameter("TITAWheelfootCfg.observation.history_length_dof_vel", history_length_dof_vel_);
        // control参数
        this->get_parameter("TITAWheelfootCfg.control.stiffness", stiffness_);
        this->get_parameter("TITAWheelfootCfg.control.damping", damping_);
        this->get_parameter("TITAWheelfootCfg.control.action_scale_pos", action_scale_pos_);
	    this->get_parameter("TITAWheelfootCfg.control.action_scale_vel", action_scale_vel_);
        this->get_parameter("TITAWheelfootCfg.control.decimation", decimation_);
        this->get_parameter("TITAWheelfootCfg.control.user_torque_limit", user_torque_limit_);
        // 剪切和归一化参数
        this->get_parameter("TITAWheelfootCfg.normalization.clip_scales.clip_observations", clip_observations_);
        this->get_parameter("TITAWheelfootCfg.normalization.clip_scales.clip_actions", clip_actions_);
        this->get_parameter("TITAWheelfootCfg.normalization.obs_scales.ang_vel", obs_scales_angvel_);
        this->get_parameter("TITAWheelfootCfg.normalization.obs_scales.dof_pos", obs_scales_dofpos_);
        this->get_parameter("TITAWheelfootCfg.normalization.obs_scales.dof_vel", obs_scales_dofvel_);
        // 网络结构参数
        this->get_parameter("TITAWheelfootCfg.size.actions_size", actions_size_);
        this->get_parameter("TITAWheelfootCfg.size.observations_size", observations_size_);
        this->get_parameter("TITAWheelfootCfg.size.observation_history_len", history_len_);
        this->get_parameter("TITAWheelfootCfg.size.commands_size", commands_size_);
        // 命令缩放参数
        this->get_parameter("TITAWheelfootCfg.user_cmd_scales.lin_vel_x", scaled_commands_x_);
        this->get_parameter("TITAWheelfootCfg.user_cmd_scales.lin_vel_y", scaled_commands_y_);
        this->get_parameter("TITAWheelfootCfg.user_cmd_scales.ang_vel_yaw", scaled_commands_z_);
	    this->get_parameter("TITAWheelfootCfg.user_cmd_scales.base_height", scaled_commands_h_);
        // onnx文件路径
        this->get_parameter("TITAWheelfootCfg.model_path", model_path);

        RCLCPP_INFO(this->get_logger(), "Parameters loaded successfully.");
        return true;
    }

    // 加载 ONNX 模型
    bool loadONNXModel(const std::string &model_path)
    {
        session_options_.SetIntraOpNumThreads(1);

        try
        {
            policy_session_ = new Ort::Session(env_, model_path.c_str(), session_options_);
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to load ONNX model: %s", e.what());
            return false;
        }

        // 清空之前的存储
        input_names_storage_.clear();
        input_names_.clear();

        // 获取输入数量（应该是2个）
        size_t num_inputs = policy_session_->GetInputCount();
        RCLCPP_INFO(this->get_logger(), "Model has %zu inputs", num_inputs);

        Ort::AllocatorWithDefaultOptions allocator;

        // 遍历所有输入
        for (size_t i = 0; i < num_inputs; i++)
        {
            // 获取输入名称
            auto input_name_ptr = policy_session_->GetInputNameAllocated(i, allocator);
            input_names_storage_.push_back(std::string(input_name_ptr.get()));
        
            // 如果是第一个输入，保存到原来的变量中以保持兼容
            if (i == 0) {
                input_name_storage_ = input_names_storage_.back();
            }
        }

        // 获取输出名称
        auto output_name_ptr = policy_session_->GetOutputNameAllocated(0, allocator);
        output_name_storage_ = std::string(output_name_ptr.get());
    
        // 构建输入名称指针向量
        input_names_.clear();
        for (const auto& name : input_names_storage_) {
            input_names_.push_back(name.c_str());
        }
        
        output_names_.clear();
        output_names_.push_back(output_name_storage_.c_str());
    	// 打印所有输入名称
        for (size_t i = 0; i < input_names_.size(); i++) {
            RCLCPP_INFO(this->get_logger(),
                "ONNX model input[%zu] name = '%s'", i, input_names_[i]);
        }
        RCLCPP_INFO(this->get_logger(),
            "ONNX model output[0] name = '%s'", output_names_[0]);
            
    	// 获取所有输入的形状
        input_shapes_.clear();
        for (size_t i = 0; i < num_inputs; i++) {
            auto shape = policy_session_->GetInputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
            input_shapes_.push_back(shape);
        }
        output_shape_ = policy_session_->GetOutputTypeInfo(0).GetTensorTypeAndShapeInfo().GetShape();


        // 调试信息
    	// std::cout << "执行4" << std::endl;
        // 打印所有输入的形状
        std::stringstream ss;
        for (size_t i = 0; i < input_shapes_.size(); i++) {
            ss.str("");
            ss << "Model input[" << i << "] shape:";
            for (auto dim : input_shapes_[i]) {
                ss << " " << dim;
            }
            RCLCPP_INFO(this->get_logger(), ss.str().c_str());
        }

        ss.str("");
        ss << "Model output shape:";
        for (auto dim : output_shape_)
        {
            ss << " " << dim;
        }
        RCLCPP_INFO(this->get_logger(), ss.str().c_str());

        RCLCPP_INFO(this->get_logger(), "ONNX model loaded successfully: %s", model_path.c_str());
        return true;
    }

    // 控制循环
    void controlLoop()
    {
        // 获取最新的 IMU 和 JointState 消息
        sensor_msgs::msg::Imu::SharedPtr imu_msg;
        sensor_msgs::msg::JointState::SharedPtr joint_msg;

        {
            std::lock_guard<std::mutex> imu_lock(imu_mutex_);
            imu_msg = latest_imu_msg_;
        }

        {
            std::lock_guard<std::mutex> joint_lock(joint_state_mutex_);
            joint_msg = latest_joint_state_msg_;
        }

        // 检查是否接收到所有必要的消息
        if (!imu_msg || !joint_msg)
        {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "Waiting for both IMU and JointState messages.");
            return;
        }

        // 准备临时变量
        std::vector<float> temp_observation(observations_size_, 0.0f);
        std::vector<float> temp_last_actions = last_actions_;
        std::vector<float> temp_current_commands = current_commands_;
        std::vector<std::deque<float>> temp_history_dof_pos = history_dof_pos_;
        std::vector<std::deque<float>> temp_history_dof_vel = history_dof_vel_;

        // 将四元数转换为 ZYX 欧拉角并计算重力投影
        Eigen::Quaterniond q(imu_msg->orientation.w, imu_msg->orientation.x, imu_msg->orientation.y, imu_msg->orientation.z);
        Eigen::Matrix3d rot_matrix = q.toRotationMatrix();
        Eigen::Vector3d gravity_vector(0, 0, -1);
        Eigen::Vector3d projected_gravity = rot_matrix.transpose() * gravity_vector;

        // 更新观测 - 角速度 (索引 0-2)
        temp_observation[0] = static_cast<float>(imu_msg->angular_velocity.x) * obs_scales_angvel_;
        temp_observation[1] = static_cast<float>(imu_msg->angular_velocity.y) * obs_scales_angvel_;
        temp_observation[2] = static_cast<float>(imu_msg->angular_velocity.z) * obs_scales_angvel_;

        // 更新观测 - 重力投影向量 (索引 3-5)
        temp_observation[3] = static_cast<float>(projected_gravity.x());
        temp_observation[4] = static_cast<float>(projected_gravity.y());
        temp_observation[5] = static_cast<float>(projected_gravity.z());

        // 更新观测中的速度命令 (索引 6-9)
        if (observations_size_ >= 9)
        {
            temp_observation[6] = temp_current_commands[0];
            temp_observation[7] = temp_current_commands[1];
            temp_observation[8] = temp_current_commands[2];
    	    temp_observation[9] = temp_current_commands[3];
        }
        // 更新关节状态
        for (size_t i = 0; i < 8; ++i)
        {
            if (i >= joint_msg->position.size() || i >= joint_msg->velocity.size())
            {
                RCLCPP_WARN(this->get_logger(), "JointState message does not have enough data.");
                continue;
            }

            float pos_offset = static_cast<float>(joint_msg->position[i]);
            float vel_scaled = static_cast<float>(joint_msg->velocity[i]);

            // 更新关节位置历史 (未缩放，用于历史数据)
            temp_history_dof_pos[i].push_front(pos_offset);
            if (temp_history_dof_pos[i].size() > static_cast<size_t>(history_length_dof_pos_))
                temp_history_dof_pos[i].pop_back();

            // 更新关节速度历史 (未缩放，用于历史数据)
            temp_history_dof_vel[i].push_front(vel_scaled);
            if (temp_history_dof_vel[i].size() > static_cast<size_t>(history_length_dof_vel_))
                temp_history_dof_vel[i].pop_back();

            // 缩放当前关节速度并更新观测 (索引 16-23)
            temp_observation[16 + i] = vel_scaled * obs_scales_dofvel_;
        }
        // 缩放当前关节位置偏移并更新观测 (索引 10-15)
    	for (size_t j = 0; j < pos_joint_indices.size(); ++j)
        {
            size_t i = pos_joint_indices[j];  // 原始关节索引

            if (i < joint_msg->position.size())
            {
                float pos_offset = static_cast<float>(joint_msg->position[i]);
                // 位置偏移写入观测 (索引 10-15，共6个位置)
                temp_observation[10 + j] = (pos_offset - default_joint_angles_[i]) * obs_scales_dofpos_;
            }
        }

        // 更新观测中的上一次动作 (索引 24-31)
        for (size_t i = 0; i < temp_last_actions.size(); ++i)
        {
            if (20 + static_cast<int>(i) >= observations_size_)
                break;
            temp_observation[24 + i] = temp_last_actions[i];
        }

        // 缩放并添加关节位置历史 (索引 32-49)
        int idx = 32;
        for (size_t i = 0; i < 6; ++i) // 遍历每个关节
        {
            for (int j = 0; j < history_length_dof_pos_; ++j) // 从最近到最旧的历史
            {
                if (idx >= observations_size_)
                    break;
                float pos_offset = (temp_history_dof_pos[i][j] - default_joint_angles_[i]) * obs_scales_dofpos_;
                temp_observation[idx++] = pos_offset;
            }
        }

        // 缩放并添加关节速度历史 (索引 50-65)
        for (size_t i = 0; i < 8; ++i) // 遍历每个关节
        {
            for (int j = 0; j < history_length_dof_vel_; ++j) // 从最近到最旧的历史
            {
                if (idx >= observations_size_)
                    break;
                float vel_scaled = temp_history_dof_vel[i][j] * obs_scales_dofvel_;
                temp_observation[idx++] = vel_scaled;
            }
        }

        // 更新当前观测向量
        current_obs_ = temp_observation;

        // 更新历史数据
        history_dof_pos_ = temp_history_dof_pos;
        history_dof_vel_ = temp_history_dof_vel;

        // 设置标志位，指示已接收到初始观测
        has_received_observation_ = true;

        // 剪裁观测值
        std::transform(current_obs_.begin(), current_obs_.end(), current_obs_.begin(),
                       [this](float x) -> float
                       { return std::clamp(x, -clip_observations_, clip_observations_); });
        //printObservations(current_obs_);
        // 运行推理
        std::vector<float> actions = runInference(current_obs_);
        std::transform(actions.begin(), actions.end(), actions.begin(),
                       [this](float x) -> float
                       { return std::clamp(x, -clip_actions_, clip_actions_); });

        // 将动作转换为期望的位置
        std::vector<float> desired_positions = convertActionsToDesiredPositions(actions);
    	std::vector<float> desired_velocities = convertActionsToDesiredVelocities(actions);
        std::vector<float> desired_goals;
        desired_goals.reserve(desired_positions.size() + desired_velocities.size());
        desired_goals.insert(desired_goals.end(), desired_positions.begin(), desired_positions.end());
        desired_goals.insert(desired_goals.end(), desired_velocities.begin(), desired_velocities.end());

        // 发布期望的位置
        publishDesiredPositions(desired_goals);
    }

    // 运行推理
    std::vector<float> runInference(const std::vector<float> &input_obs)
    {
        history_buffer_.push_back(current_obs_);
        if (history_buffer_.size() > static_cast<size_t>(history_len_)) {
            history_buffer_.erase(history_buffer_.begin());  // 移除最老的
        }

        // 2. 如果历史缓冲区不够长，用当前观测填充
        while (history_buffer_.size() < static_cast<size_t>(history_len_)) {
            history_buffer_.insert(history_buffer_.begin(), current_obs_);
        }

        // 3. 展平历史数据
        std::vector<float> hist_obs;
        hist_obs.reserve(history_len_ * prop_dim_);
        for (const auto& frame : history_buffer_) {
            hist_obs.insert(hist_obs.end(), frame.begin(), frame.end());
        }

        // 4. 检查输入大小
        if (hist_obs.size() != static_cast<size_t>(history_len_ * prop_dim_)) {
            RCLCPP_ERROR(this->get_logger(), "History size mismatch");
            return std::vector<float>(actions_size_, 0.0f);
        }

        Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);

        std::vector<Ort::Value> input_tensors;

        // 第一个输入：历史观测
        std::vector<int64_t> hist_shape = {1, static_cast<int64_t>(hist_obs.size())};
        input_tensors.push_back(
            Ort::Value::CreateTensor<float>(memory_info, 
                                            hist_obs.data(),
                                            hist_obs.size(), 
                                            hist_shape.data(), 
                                            hist_shape.size()));
        
        // 第二个输入：当前观测
        std::vector<int64_t> current_shape = {1, static_cast<int64_t>(current_obs_.size())};
        input_tensors.push_back(
            Ort::Value::CreateTensor<float>(memory_info, 
                                            const_cast<float*>(current_obs_.data()),
                                            current_obs_.size(), 
                                            current_shape.data(), 
                                            current_shape.size()));

        

        // 运行推理
        try
        {
	    // 1. 会话空指针
            if (!policy_session_) { RCLCPP_ERROR(this->get_logger(), "ONNX session null"); return {}; }

            // 打印输入名称以便确认
            RCLCPP_INFO(this->get_logger(), "Input names: %s, %s", 
            input_names_[0], input_names_[1]);

            auto output_tensors = policy_session_->Run(Ort::RunOptions{nullptr}, input_names_.data(),
                                                       input_tensors.data(), 2,
                                                       output_names_.data(), 1);

            // 获取输出结果
            float *output_data = output_tensors[0].GetTensorMutableData<float>();
            std::vector<float> output_values(output_data, output_data + actions_size_);
            return output_values;
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to run inference: %s", e.what());
            return std::vector<float>(actions_size_, 0.0f);
        }
    }

    // 将动作转换为期望的位置
    std::vector<float> convertActionsToDesiredPositions(const std::vector<float> &actions)
    {
        std::vector<float> desired_positions;
        desired_positions.resize(6, 0.0f);

        // 使用最新的观测数据
        std::vector<float> temp_observation = current_obs_;
        
        const size_t pos_obs_idx[6] = {6, 7, 8, 9, 10, 11};
        const size_t pos_act_idx[6] = {0, 1, 2, 4, 5, 6};
        for (size_t i = 0; i < 6; i++)
        {   
            size_t obs_i = pos_obs_idx[i];   // 在 obs 里的位置
            size_t act_i = pos_act_idx[i];   // 在 actions 里的位置

            if (obs_i >= temp_observation.size() || 12 + act_i >= temp_observation.size())
                continue;

            float joint_position = temp_observation[obs_i] / obs_scales_dofpos_ + default_joint_angles_[act_i];
            float joint_velocity = temp_observation[12 + act_i] / obs_scales_dofvel_;

            float actionMin = joint_position - default_joint_angles_[act_i] + (damping_ * joint_velocity - user_torque_limit_) / stiffness_;
            float actionMax = joint_position - default_joint_angles_[act_i] + (damping_ * joint_velocity + user_torque_limit_) / stiffness_;

            float scaled_action = std::max(actionMin / action_scale_pos_, std::min(actionMax / action_scale_pos_, actions[act_i]));
            desired_positions[i] = scaled_action * action_scale_pos_ + default_joint_angles_[act_i];
        }

        // 更新上一次动作
        last_actions_ = actions;
        return desired_positions;
    }
    std::vector<float> convertActionsToDesiredVelocities(const std::vector<float> &actions)
    {
        std::vector<float> desired_velocities;
        desired_velocities.resize(2, 0.0f);

        // 使用最新的观测数据
        std::vector<float> temp_observation = current_obs_;

        const size_t vel_obs_idx[2] = {15, 19};  // 在 obs 里的位置
        for (size_t i = 0; i < 2; i++)
        {
            size_t obs_i = vel_obs_idx[i];   // 在 obs 里的位置
            size_t act_i = (i == 0) ? 3 : 7;
            if (obs_i >= temp_observation.size())           // 越界保护
            {
                desired_velocities[i] = 0.0f;
                continue;
            }
            desired_velocities[i] = actions[act_i] * action_scale_vel_;
        }
        return desired_velocities;
    }

    // 发布期望的位置
    void publishDesiredPositions(const std::vector<float> &desired_goals)
    {
	    if (desired_goals.empty()) {
            RCLCPP_WARN(this->get_logger(), "desired_goals 是空的!");
            return;
        }
    	static bool once = false;
        if (!once && !desired_goals.empty()) {
            once = true;
            RCLCPP_INFO(this->get_logger(), "RL 第一次8维动作 published, 均值=%.3f",
                std::accumulate(desired_goals.begin(), desired_goals.end(), 0.0) / 8.0);
        }
    	control_msgs::msg::MultiDOFCommand pos_cmd;   // 位置控制  
        control_msgs::msg::MultiDOFCommand vel_cmd;   // 速度控制
        pos_cmd.dof_names.reserve(6); 
        pos_cmd.values.reserve(6);   
        vel_cmd.dof_names.reserve(2);
        vel_cmd.values.reserve(2);
        for (size_t i = 0; i < desired_goals.size(); ++i)
        {
            if (i == 6)          // 速度控制关节
            {
                vel_cmd.dof_names.push_back(joint_names_[3]);
                // 这里把“位置量”当成“速度量”用，实际请换成 computeDesiredVelocity(i)
                vel_cmd.values.push_back(desired_goals[i]);
            }
            else if (i == 7)     // 速度控制关节
            {
                vel_cmd.dof_names.push_back(joint_names_[i]);
                vel_cmd.values.push_back(desired_goals[i]);
            }
            else if (i > 2)                      // 位置控制关节
            {
                pos_cmd.dof_names.push_back(joint_names_[i+1]);
                pos_cmd.values.push_back(desired_goals[i]);
            }
	    else                                 // 位置控制关节
            {
                pos_cmd.dof_names.push_back(joint_names_[i]);
                pos_cmd.values.push_back(desired_goals[i]);
            }
        }
        pos_action_pub_->publish(pos_cmd);               // 发出去
        vel_action_pub_->publish(vel_cmd);
    	static bool first_pos = false;
        static bool first_vel = false;
        if (!first_pos && !pos_cmd.values.empty()) {
            first_pos = true;
            RCLCPP_INFO(this->get_logger(), "第一次 pos reference forwarded, values.size=%zu", pos_cmd.values.size());
        }
        if (!first_vel && !pos_cmd.values.empty()) {
            first_vel = true;
            RCLCPP_INFO(this->get_logger(), "第一次 vel reference forwarded, values.size=%zu", vel_cmd.values.size());
        }
    }
};

// 主函数
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<TitaWheelFootNode>();
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}




