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
#include <numeric>
#include <sstream>

using std::placeholders::_1;

// FR-194 策略推理节点
// 观测 prop (32维) = [ang_vel(3), gravity(3), commands[:4](4), joint_pos(6), joint_vel(8), last_actions(8)]
// ONNX 输入 (194维) = [current_prop(32), history(5*32=160), mode_onehot(2)]
class TitaWheelFootNode : public rclcpp::Node
{
public:
    TitaWheelFootNode()
        : Node("tita_wheelfoot_node"),
          env_(ORT_LOGGING_LEVEL_WARNING, "TITAWheelfootONNX")
    {
        imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
            "/tita/imu_sensor_broadcaster/imu", 10,
            std::bind(&TitaWheelFootNode::imuCallback, this, _1));

        rclcpp::QoS qos(10);
        qos.best_effort();
        joint_state_sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "/tita/joint_states", qos,
            std::bind(&TitaWheelFootNode::jointStateCallback, this, _1));

        cmd_vel_sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "/tita3037088/command/teleop/command", qos,
            std::bind(&TitaWheelFootNode::joycmdCallback, this, _1));

        using CommandMsg = control_msgs::msg::MultiDOFCommand;
        pos_action_pub_ = this->create_publisher<CommandMsg>(
            "/tita/pid_controller/reference", 10);
        vel_action_pub_ = this->create_publisher<CommandMsg>(
            "/tita/wheel_pid_controller/reference", 10);

        if (!loadParameters()) { RCLCPP_ERROR(this->get_logger(), "Failed to load parameters."); rclcpp::shutdown(); }
        RCLCPP_INFO(this->get_logger(), "Loading ONNX model from: %s", model_path.c_str());
        if (!loadONNXModel(model_path)) { RCLCPP_ERROR(this->get_logger(), "Failed to load ONNX model."); rclcpp::shutdown(); }

        control_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(20), std::bind(&TitaWheelFootNode::controlLoop, this));

        history_dof_pos_.resize(8);
        history_dof_vel_.resize(8);
        default_joint_angles_.resize(8);
        observation_.resize(observations_size_, 0.0f);
        current_obs_.resize(observations_size_, 0.0f);
        last_actions_.resize(actions_size_, 0.0f);
        current_commands_.resize(commands_size_, 0.0f);

        for (size_t i = 0; i < 8; ++i) {
            history_dof_pos_[i] = std::deque<float>(history_length_dof_pos_, default_joint_angles_[i]);
            history_dof_vel_[i] = std::deque<float>(history_length_dof_vel_, 0.0f);
        }

        RCLCPP_INFO(this->get_logger(), "TitaWheelFootNode (FR-194) ready.");
    }

    ~TitaWheelFootNode() { if (policy_session_) { delete policy_session_; policy_session_ = nullptr; } }

private:
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_sub_;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr cmd_vel_sub_;

    rclcpp::Publisher<control_msgs::msg::MultiDOFCommand>::SharedPtr pos_action_pub_;
    rclcpp::Publisher<control_msgs::msg::MultiDOFCommand>::SharedPtr vel_action_pub_;

    rclcpp::TimerBase::SharedPtr control_timer_;
    sensor_msgs::msg::Imu::SharedPtr latest_imu_msg_;
    sensor_msgs::msg::JointState::SharedPtr latest_joint_state_msg_;
    std::mutex imu_mutex_, joint_state_mutex_;

    Ort::Env env_;
    Ort::Session *policy_session_ = nullptr;
    Ort::SessionOptions session_options_;
    std::vector<const char *> input_names_, output_names_;
    std::string input_name_storage_, output_name_storage_;
    std::vector<int64_t> input_shape_, output_shape_;
    std::vector<std::string> input_names_storage_;
    std::vector<std::vector<int64_t>> input_shapes_;
    std::deque<std::vector<float>> history_buffer_;
    int prop_dim_ = 32;
    const std::vector<size_t> pos_joint_indices = {0, 1, 2, 4, 5, 6};

    std::vector<std::string> joint_names_ = {
        "joint_left_leg_1","joint_left_leg_2","joint_left_leg_3","joint_left_leg_4",
        "joint_right_leg_1","joint_right_leg_2","joint_right_leg_3","joint_right_leg_4"};
    std::vector<float> default_joint_angles_;
    float obs_scales_angvel_, obs_scales_dofpos_, obs_scales_dofvel_, obs_scales_gravity_;
    float scaled_commands_x_, scaled_commands_y_, scaled_commands_z_, scaled_commands_h_;
    float stiffness_, damping_, action_scale_pos_, action_scale_vel_, user_torque_limit_, decimation_;
    int actions_size_, observations_size_, commands_size_, history_len_;
    float clip_observations_, clip_actions_;
    std::string model_path;
    int history_length_dof_pos_, history_length_dof_vel_;

    std::vector<float> observation_, last_actions_, current_obs_, current_commands_;
    std::vector<std::deque<float>> history_dof_pos_, history_dof_vel_;
    bool has_received_observation_ = false;

    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg) {
        std::lock_guard<std::mutex> lock(imu_mutex_); latest_imu_msg_ = msg;
        static bool once=false; if(!once){once=true; RCLCPP_INFO(this->get_logger(),"IMU received");}
    }

    void jointStateCallback(const sensor_msgs::msg::JointState::SharedPtr msg) {
        std::lock_guard<std::mutex> lock(joint_state_mutex_);
        std::vector<std::string> desired_order = {
            "joint_left_leg_1","joint_left_leg_2","joint_left_leg_3","joint_left_leg_4",
            "joint_right_leg_1","joint_right_leg_2","joint_right_leg_3","joint_right_leg_4"};
        std::vector<double> sp(desired_order.size()), sv(desired_order.size()), se(desired_order.size());
        for(size_t i=0;i<desired_order.size();++i){
            auto it=std::find(msg->name.begin(),msg->name.end(),desired_order[i]);
            if(it!=msg->name.end()){size_t idx=std::distance(msg->name.begin(),it);sp[i]=msg->position[idx];sv[i]=msg->velocity[idx];se[i]=msg->effort[idx];}
        }
        auto sm=std::make_shared<sensor_msgs::msg::JointState>();
        sm->header=msg->header;sm->name=desired_order;sm->position=sp;sm->velocity=sv;sm->effort=se;
        latest_joint_state_msg_=sm;
        static bool once=false;if(!once){once=true;RCLCPP_INFO(this->get_logger(),"JointState received");}
    }

    void joycmdCallback(const sensor_msgs::msg::Joy::SharedPtr msg) {
        current_commands_[0]=1.2f*(-0.5f)*msg->axes[2]*scaled_commands_x_;
        current_commands_[1]=0.0f;
        current_commands_[2]=msg->axes[3]*scaled_commands_z_;
        current_commands_[3]=0.1f+0.15f*((-msg->axes[5])+1.0f)*scaled_commands_h_;
        if(std::abs(msg->axes[2])<=0.1f)current_commands_[0]=0.0f;
        if(std::abs(msg->axes[3])<=0.01f)current_commands_[2]=0.0f;
    }

    bool loadParameters() {
        RCLCPP_INFO(this->get_logger(),"Loading parameters...");
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_left_leg_1",-0.0);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_left_leg_2",0.8);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_left_leg_3",-1.5);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_left_leg_4",0.0);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_right_leg_1",0.0);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_right_leg_2",0.8);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_right_leg_3",-1.5);
        this->declare_parameter<float>("TITAWheelfootCfg.default_joint_angle.joint_right_leg_4",0.0);
        this->declare_parameter<int>("TITAWheelfootCfg.observation.history_length_dof_pos",0);
        this->declare_parameter<int>("TITAWheelfootCfg.observation.history_length_dof_vel",0);
        this->declare_parameter<float>("TITAWheelfootCfg.control.stiffness",40.0);
        this->declare_parameter<float>("TITAWheelfootCfg.control.damping",1.0);
        this->declare_parameter<float>("TITAWheelfootCfg.control.action_scale_pos",0.25);
        this->declare_parameter<float>("TITAWheelfootCfg.control.action_scale_vel",8.0);
        this->declare_parameter<float>("TITAWheelfootCfg.control.decimation",4.0);
        this->declare_parameter<float>("TITAWheelfootCfg.control.user_torque_limit",45.0);
        this->declare_parameter<float>("TITAWheelfootCfg.normalization.clip_scales.clip_observations",100.0);
        this->declare_parameter<float>("TITAWheelfootCfg.normalization.clip_scales.clip_actions",100.0);
        this->declare_parameter<float>("TITAWheelfootCfg.normalization.obs_scales.ang_vel",0.25);
        this->declare_parameter<float>("TITAWheelfootCfg.normalization.obs_scales.dof_pos",1.0);
        this->declare_parameter<float>("TITAWheelfootCfg.normalization.obs_scales.dof_vel",0.05);
        this->declare_parameter<float>("TITAWheelfootCfg.normalization.obs_scales.projected_gravity",1.0);
        this->declare_parameter<int>("TITAWheelfootCfg.size.actions_size",8);
        this->declare_parameter<int>("TITAWheelfootCfg.size.observations_size",32);
        this->declare_parameter<int>("TITAWheelfootCfg.size.history_len",5);
        this->declare_parameter<int>("TITAWheelfootCfg.size.commands_size",4);
        this->declare_parameter<float>("TITAWheelfootCfg.user_cmd_scales.lin_vel_x",2.0);
        this->declare_parameter<float>("TITAWheelfootCfg.user_cmd_scales.lin_vel_y",2.0);
        this->declare_parameter<float>("TITAWheelfootCfg.user_cmd_scales.ang_vel_yaw",0.25);
        this->declare_parameter<float>("TITAWheelfootCfg.user_cmd_scales.base_height",1.0);
        this->declare_parameter<std::string>("TITAWheelfootCfg.model_path","/mnt/dev/tita_ws/src/TITA_GAZEBO_DRL/src/TITA_DRL/config/policy/policy_fr194.onnx");

        default_joint_angles_.resize(8);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_left_leg_1",default_joint_angles_[0]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_left_leg_2",default_joint_angles_[1]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_left_leg_3",default_joint_angles_[2]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_left_leg_4",default_joint_angles_[3]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_right_leg_1",default_joint_angles_[4]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_right_leg_2",default_joint_angles_[5]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_right_leg_3",default_joint_angles_[6]);
        this->get_parameter("TITAWheelfootCfg.default_joint_angle.joint_right_leg_4",default_joint_angles_[7]);
        this->get_parameter("TITAWheelfootCfg.observation.history_length_dof_pos",history_length_dof_pos_);
        this->get_parameter("TITAWheelfootCfg.observation.history_length_dof_vel",history_length_dof_vel_);
        this->get_parameter("TITAWheelfootCfg.control.stiffness",stiffness_);
        this->get_parameter("TITAWheelfootCfg.control.damping",damping_);
        this->get_parameter("TITAWheelfootCfg.control.action_scale_pos",action_scale_pos_);
        this->get_parameter("TITAWheelfootCfg.control.action_scale_vel",action_scale_vel_);
        this->get_parameter("TITAWheelfootCfg.control.decimation",decimation_);
        this->get_parameter("TITAWheelfootCfg.control.user_torque_limit",user_torque_limit_);
        this->get_parameter("TITAWheelfootCfg.normalization.clip_scales.clip_observations",clip_observations_);
        this->get_parameter("TITAWheelfootCfg.normalization.clip_scales.clip_actions",clip_actions_);
        this->get_parameter("TITAWheelfootCfg.normalization.obs_scales.ang_vel",obs_scales_angvel_);
        this->get_parameter("TITAWheelfootCfg.normalization.obs_scales.dof_pos",obs_scales_dofpos_);
        this->get_parameter("TITAWheelfootCfg.normalization.obs_scales.dof_vel",obs_scales_dofvel_);
        this->get_parameter("TITAWheelfootCfg.normalization.obs_scales.projected_gravity",obs_scales_gravity_);
        this->get_parameter("TITAWheelfootCfg.size.actions_size",actions_size_);
        this->get_parameter("TITAWheelfootCfg.size.observations_size",observations_size_);
        this->get_parameter("TITAWheelfootCfg.size.history_len",history_len_);
        this->get_parameter("TITAWheelfootCfg.size.commands_size",commands_size_);
        this->get_parameter("TITAWheelfootCfg.user_cmd_scales.lin_vel_x",scaled_commands_x_);
        this->get_parameter("TITAWheelfootCfg.user_cmd_scales.lin_vel_y",scaled_commands_y_);
        this->get_parameter("TITAWheelfootCfg.user_cmd_scales.ang_vel_yaw",scaled_commands_z_);
        this->get_parameter("TITAWheelfootCfg.user_cmd_scales.base_height",scaled_commands_h_);
        this->get_parameter("TITAWheelfootCfg.model_path",model_path);
        RCLCPP_INFO(this->get_logger(),"Parameters loaded.");
        return true;
    }

    bool loadONNXModel(const std::string &mp) {
        session_options_.SetIntraOpNumThreads(1);
        try{policy_session_=new Ort::Session(env_,mp.c_str(),session_options_);}
        catch(const std::exception &e){RCLCPP_ERROR(this->get_logger(),"ONNX load failed: %s",e.what());return false;}
        input_names_storage_.clear();input_names_.clear();
        size_t ni=policy_session_->GetInputCount();
        Ort::AllocatorWithDefaultOptions alloc;
        for(size_t i=0;i<ni;i++){auto np=policy_session_->GetInputNameAllocated(i,alloc);input_names_storage_.push_back(std::string(np.get()));if(i==0)input_name_storage_=input_names_storage_.back();}
        auto op=policy_session_->GetOutputNameAllocated(0,alloc);output_name_storage_=std::string(op.get());
        for(const auto& n:input_names_storage_)input_names_.push_back(n.c_str());
        output_names_.push_back(output_name_storage_.c_str());
        input_shapes_.clear();
        for(size_t i=0;i<ni;i++){auto s=policy_session_->GetInputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();input_shapes_.push_back(s);}
        output_shape_=policy_session_->GetOutputTypeInfo(0).GetTensorTypeAndShapeInfo().GetShape();
        RCLCPP_INFO(this->get_logger(),"ONNX loaded: %s",mp.c_str());
        return true;
    }

    void controlLoop() {
        sensor_msgs::msg::Imu::SharedPtr imu_msg;
        sensor_msgs::msg::JointState::SharedPtr joint_msg;
        {std::lock_guard<std::mutex> lk(imu_mutex_);imu_msg=latest_imu_msg_;}
        {std::lock_guard<std::mutex> lk(joint_state_mutex_);joint_msg=latest_joint_state_msg_;}
        if(!imu_msg||!joint_msg){RCLCPP_WARN_THROTTLE(this->get_logger(),*this->get_clock(),1000,"Waiting for sensors...");return;}

        std::vector<float> obs(observations_size_,0.0f);
        std::vector<float> la=last_actions_,cmd=current_commands_;

        Eigen::Quaterniond q(imu_msg->orientation.w,imu_msg->orientation.x,imu_msg->orientation.y,imu_msg->orientation.z);
        Eigen::Vector3d pg=q.toRotationMatrix().transpose()*Eigen::Vector3d(0,0,-1);

        obs[0]=static_cast<float>(imu_msg->angular_velocity.x)*obs_scales_angvel_;
        obs[1]=static_cast<float>(imu_msg->angular_velocity.y)*obs_scales_angvel_;
        obs[2]=static_cast<float>(imu_msg->angular_velocity.z)*obs_scales_angvel_;
        obs[3]=static_cast<float>(pg.x())*obs_scales_gravity_;
        obs[4]=static_cast<float>(pg.y())*obs_scales_gravity_;
        obs[5]=static_cast<float>(pg.z())*obs_scales_gravity_;
        obs[6]=cmd[0];obs[7]=cmd[1];obs[8]=cmd[2];obs[9]=cmd[3];
        for(size_t i=0;i<8;++i){if(i<joint_msg->velocity.size())obs[16+i]=static_cast<float>(joint_msg->velocity[i])*obs_scales_dofvel_;}
        for(size_t j=0;j<pos_joint_indices.size();++j){size_t i=pos_joint_indices[j];if(i<joint_msg->position.size()){obs[10+j]=(static_cast<float>(joint_msg->position[i])-default_joint_angles_[i])*obs_scales_dofpos_;}}
        for(size_t i=0;i<la.size();++i)obs[24+i]=la[i];
        current_obs_=obs;has_received_observation_=true;
        std::transform(current_obs_.begin(),current_obs_.end(),current_obs_.begin(),[this](float x){return std::clamp(x,-clip_observations_,clip_observations_);});

        std::vector<float> actions=runInference(current_obs_);
        std::transform(actions.begin(),actions.end(),actions.begin(),[this](float x){return std::clamp(x,-clip_actions_,clip_actions_);});
        auto dp=convertActionsToDesiredPositions(actions);
        auto dv=convertActionsToDesiredVelocities(actions);
        std::vector<float> dg;dg.reserve(8);dg.insert(dg.end(),dp.begin(),dp.end());dg.insert(dg.end(),dv.begin(),dv.end());
        publishDesiredPositions(dg);
    }

    std::vector<float> runInference(const std::vector<float> &) {
        while(history_buffer_.size()<static_cast<size_t>(history_len_))history_buffer_.insert(history_buffer_.begin(),current_obs_);
        std::vector<float> ind;ind.reserve(observations_size_+history_len_*observations_size_+2);
        ind.insert(ind.end(),current_obs_.begin(),current_obs_.end());
        for(const auto& f:history_buffer_)ind.insert(ind.end(),f.begin(),f.end());
        bool rec=false;
        if(current_obs_.size()>=6)rec=(current_obs_[5]>-0.2f*obs_scales_gravity_);
        ind.push_back(rec?0.0f:1.0f);ind.push_back(rec?1.0f:0.0f);
        size_t exp=observations_size_+history_len_*observations_size_+2;
        if(ind.size()!=exp){RCLCPP_ERROR(this->get_logger(),"Input size mismatch");return std::vector<float>(actions_size_,0.0f);}
        history_buffer_.push_back(current_obs_);
        if(history_buffer_.size()>static_cast<size_t>(history_len_))history_buffer_.pop_front();

        Ort::MemoryInfo mi=Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator,OrtMemTypeCPU);
        std::vector<Ort::Value> its;std::vector<int64_t> ish={1,static_cast<int64_t>(ind.size())};
        its.push_back(Ort::Value::CreateTensor<float>(mi,ind.data(),ind.size(),ish.data(),ish.size()));
        try{
            if(!policy_session_){RCLCPP_ERROR(this->get_logger(),"ONNX session null");return std::vector<float>(actions_size_,0.0f);}
            auto ot=policy_session_->Run(Ort::RunOptions{nullptr},input_names_.data(),its.data(),1,output_names_.data(),1);
            float*d=ot[0].GetTensorMutableData<float>();
            return std::vector<float>(d,d+actions_size_);
        }catch(const std::exception &e){RCLCPP_ERROR(this->get_logger(),"Inference failed: %s",e.what());return std::vector<float>(actions_size_,0.0f);}
    }

    std::vector<float> convertActionsToDesiredPositions(const std::vector<float> &actions) {
        std::vector<float> pos(6,0.0f);
        const size_t poi[6]={10,11,12,13,14,15},pai[6]={0,1,2,4,5,6};
        for(size_t i=0;i<6;i++){
            size_t oi=poi[i],ai=pai[i],vi=16+ai;
            if(oi>=current_obs_.size()||vi>=current_obs_.size())continue;
            float jp=current_obs_[oi]/obs_scales_dofpos_+default_joint_angles_[ai];
            float jv=current_obs_[vi]/obs_scales_dofvel_;
            float amin=jp-default_joint_angles_[ai]+(damping_*jv-user_torque_limit_)/stiffness_;
            float amax=jp-default_joint_angles_[ai]+(damping_*jv+user_torque_limit_)/stiffness_;
            float ca=std::max(amin/action_scale_pos_,std::min(amax/action_scale_pos_,actions[ai]));
            pos[i]=ca*action_scale_pos_+default_joint_angles_[ai];
        }
        last_actions_=actions;
        return pos;
    }

    std::vector<float> convertActionsToDesiredVelocities(const std::vector<float> &actions) {
        std::vector<float> vel(2,0.0f);
        vel[0]=actions[3]*action_scale_vel_;vel[1]=actions[7]*action_scale_vel_;
        return vel;
    }

    void publishDesiredPositions(const std::vector<float> &goals) {
        if(goals.empty())return;
        control_msgs::msg::MultiDOFCommand pc,vc;
        pc.dof_names.reserve(6);pc.values.reserve(6);vc.dof_names.reserve(2);vc.values.reserve(2);
        for(size_t i=0;i<goals.size();++i){
            if(i==6){vc.dof_names.push_back(joint_names_[3]);vc.values.push_back(goals[i]);}
            else if(i==7){vc.dof_names.push_back(joint_names_[7]);vc.values.push_back(goals[i]);}
            else if(i>2){pc.dof_names.push_back(joint_names_[i+1]);pc.values.push_back(goals[i]);}
            else{pc.dof_names.push_back(joint_names_[i]);pc.values.push_back(goals[i]);}
        }
        pos_action_pub_->publish(pc);vel_action_pub_->publish(vc);
    }
};

int main(int argc,char**argv){rclcpp::init(argc,argv);auto node=std::make_shared<TitaWheelFootNode>();rclcpp::spin(node);rclcpp::shutdown();return 0;}
