// auto-generated DO NOT EDIT

#pragma once

#include <algorithm>
#include <array>
#include <functional>
#include <limits>
#include <mutex>
#include <rclcpp/node.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <rclcpp/logger.hpp>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include <parameter_traits/parameter_traits.hpp>

#include <rsl/static_string.hpp>
#include <rsl/static_vector.hpp>
#include <rsl/parameter_validators.hpp>



namespace tita_controller {

// Use validators from RSL
using rsl::unique;
using rsl::subset_of;
using rsl::fixed_size;
using rsl::size_gt;
using rsl::size_lt;
using rsl::not_empty;
using rsl::element_bounds;
using rsl::lower_element_bounds;
using rsl::upper_element_bounds;
using rsl::bounds;
using rsl::lt;
using rsl::gt;
using rsl::lt_eq;
using rsl::gt_eq;
using rsl::one_of;
using rsl::to_parameter_result_msg;

// temporarily needed for backwards compatibility for custom validators
using namespace parameter_traits;

template <typename T>
[[nodiscard]] auto to_parameter_value(T value) {
    return rclcpp::ParameterValue(value);
}

template <size_t capacity>
[[nodiscard]] auto to_parameter_value(rsl::StaticString<capacity> const& value) {
    return rclcpp::ParameterValue(rsl::to_string(value));
}

template <typename T, size_t capacity>
[[nodiscard]] auto to_parameter_value(rsl::StaticVector<T, capacity> const& value) {
    return rclcpp::ParameterValue(rsl::to_vector(value));
}
    struct Params {
        int64_t update_rate = 500;
        std::vector<std::string> joints = {};
        std::string robot_description_path = "/usr/share/robot_description/tita/urdf/robot.urdf";
        int64_t lqr_update_rate = 50;
        double wheel_radius = 0.0925;
        std::vector<std::string> wheel_joint_name = {"joint_left_leg_4", "joint_right_leg_4"};
        std::string base_name = "base_link";
        double static_friction_coefficient = 0.0;
        double sliding_friction_coefficient = 0.3;
        std::vector<double> torque_limit = {80.0, 20.0, 40.0, 5.0, 80.0, 20.0, 40.0, 5.0};
        struct Task {
            struct TwistLinearX {
                double max_velocity = 1.0;
                double max_acceleration = 1.0;
                double min_velocity = -1.0;
                double min_acceleration = -1.0;
                double q0 = 500.0;
                double q1 = 2500.0;
                double q2 = 6800.0;
                double q3 = 1500.0;
                double r0 = 1.0;
                double weight = 1.0;
            } twist_linear_x;
            struct TwistAngularZ {
                double max_velocity = 1.0;
                double max_acceleration = 3.0;
                double kp = 150.0;
                double kd = 25.0;
                double weight = 1.0;
            } twist_angular_z;
            struct PosePositionY {
                double max_position = 0.1;
                double max_velocity = 0.06;
                double max_acceleration = 40.0;
                double kp = 400.0;
                double kd = 40.0;
                double weight = 1.0;
            } pose_position_y;
            struct PosePositionZ {
                double max_position = 0.4;
                double max_velocity = 0.1;
                double max_acceleration = 50.0;
                double min_position = 0.2;
                double kp = 300.0;
                double kd = 10.0;
                double weight = 1.0;
            } pose_position_z;
            struct PoseOrientationYaw {
                double max_position = 0.1;
                double max_velocity = 0.1;
                double max_acceleration = 20.0;
                double kp = 1500.0;
                double kd = 40.0;
                double weight = 1.0;
            } pose_orientation_yaw;
            struct PoseOrientationPitch {
                double max_position = 0.2;
                double max_velocity = 0.8;
                double max_acceleration = 30.0;
                double kp = 700.0;
                double kd = 120.0;
                double weight = 1.0;
            } pose_orientation_pitch;
            struct PoseOrientationRoll {
                double max_position = 0.2;
                double max_velocity = 0.8;
                double max_acceleration = 30.0;
                double kp = 600.0;
                double kd = 50.0;
                double weight = 1.0;
            } pose_orientation_roll;
            struct TwoWheelDistance {
                double default_value = 0.285;
                double max_position = 0.05;
                double max_velocity = 0.05;
                double max_acceleration = 10.0;
                double min_position = -0.05;
                double min_velocity = -0.05;
                double min_acceleration = -10.0;
                double kp = 1500.0;
                double kd = 200.0;
                double weight = 1.0;
            } two_wheel_distance;
        } task;
        struct JointPd {
            std::vector<double> p = {600.0, 80.0, 80.0, 5.0, 600.0, 80.0, 80.0, 5.0};
            std::vector<double> d = {8.0, 8.0, 8.0, 0.2, 8.0, 8.0, 8.0, 0.2};
        } joint_pd;
        struct WbcJointPd {
            std::vector<double> p = {100.0, 0.0, 100.0, 0.0, 100.0, 0.0, 100.0, 0.0};
            std::vector<double> d = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        } wbc_joint_pd;
        struct SingleJointPd1 {
            double p = 0.0;
            double d = 0.0;
        } single_joint_pd1;
        struct SingleJointPd2 {
            double p = 0.0;
            double d = 0.0;
        } single_joint_pd2;
        struct SingleJointPd3 {
            double p = 0.0;
            double d = 0.0;
        } single_joint_pd3;
        struct SingleJointPd4 {
            double p = 0.0;
            double d = 0.0;
        } single_joint_pd4;
        struct Estimator {
            double imu_process_noise_position = 0.02;
            double imu_process_noise_velocity = 0.02;
            double foot_process_noise_position = 0.05;
            double imu_sensor_noise_position = 0.005;
            double imu_sensor_noise_velocity = 0.1;
            double foot_sensor_noise_position = 0.01;
        } estimator;
        // for detecting if the parameter struct has been updated
        rclcpp::Time __stamp;
    };
    struct StackParams {
        int64_t update_rate = 500;
        int64_t lqr_update_rate = 50;
        double wheel_radius = 0.0925;
        double static_friction_coefficient = 0.0;
        double sliding_friction_coefficient = 0.3;
        struct Task {
            struct TwistLinearX {
                double max_velocity = 1.0;
                double max_acceleration = 1.0;
                double min_velocity = -1.0;
                double min_acceleration = -1.0;
                double q0 = 500.0;
                double q1 = 2500.0;
                double q2 = 6800.0;
                double q3 = 1500.0;
                double r0 = 1.0;
                double weight = 1.0;
            } twist_linear_x;
            struct TwistAngularZ {
                double max_velocity = 1.0;
                double max_acceleration = 3.0;
                double kp = 150.0;
                double kd = 25.0;
                double weight = 1.0;
            } twist_angular_z;
            struct PosePositionY {
                double max_position = 0.1;
                double max_velocity = 0.06;
                double max_acceleration = 40.0;
                double kp = 400.0;
                double kd = 40.0;
                double weight = 1.0;
            } pose_position_y;
            struct PosePositionZ {
                double max_position = 0.4;
                double max_velocity = 0.1;
                double max_acceleration = 50.0;
                double min_position = 0.2;
                double kp = 300.0;
                double kd = 10.0;
                double weight = 1.0;
            } pose_position_z;
            struct PoseOrientationYaw {
                double max_position = 0.1;
                double max_velocity = 0.1;
                double max_acceleration = 20.0;
                double kp = 1500.0;
                double kd = 40.0;
                double weight = 1.0;
            } pose_orientation_yaw;
            struct PoseOrientationPitch {
                double max_position = 0.2;
                double max_velocity = 0.8;
                double max_acceleration = 30.0;
                double kp = 700.0;
                double kd = 120.0;
                double weight = 1.0;
            } pose_orientation_pitch;
            struct PoseOrientationRoll {
                double max_position = 0.2;
                double max_velocity = 0.8;
                double max_acceleration = 30.0;
                double kp = 600.0;
                double kd = 50.0;
                double weight = 1.0;
            } pose_orientation_roll;
            struct TwoWheelDistance {
                double default_value = 0.285;
                double max_position = 0.05;
                double max_velocity = 0.05;
                double max_acceleration = 10.0;
                double min_position = -0.05;
                double min_velocity = -0.05;
                double min_acceleration = -10.0;
                double kp = 1500.0;
                double kd = 200.0;
                double weight = 1.0;
            } two_wheel_distance;
        } task;
        struct SingleJointPd1 {
            double p = 0.0;
            double d = 0.0;
        } single_joint_pd1;
        struct SingleJointPd2 {
            double p = 0.0;
            double d = 0.0;
        } single_joint_pd2;
        struct SingleJointPd3 {
            double p = 0.0;
            double d = 0.0;
        } single_joint_pd3;
        struct SingleJointPd4 {
            double p = 0.0;
            double d = 0.0;
        } single_joint_pd4;
        struct Estimator {
            double imu_process_noise_position = 0.02;
            double imu_process_noise_velocity = 0.02;
            double foot_process_noise_position = 0.05;
            double imu_sensor_noise_position = 0.005;
            double imu_sensor_noise_velocity = 0.1;
            double foot_sensor_noise_position = 0.01;
        } estimator;
    };

  class ParamListener{
  public:
    // throws rclcpp::exceptions::InvalidParameterValueException on initialization if invalid parameter are loaded
    ParamListener(rclcpp::Node::SharedPtr node, std::string const& prefix = "")
    : ParamListener(node->get_node_parameters_interface(), node->get_logger(), prefix) {}

    ParamListener(rclcpp_lifecycle::LifecycleNode::SharedPtr node, std::string const& prefix = "")
    : ParamListener(node->get_node_parameters_interface(), node->get_logger(), prefix) {}

    ParamListener(const std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface>& parameters_interface,
                  std::string const& prefix = "")
    : ParamListener(parameters_interface, rclcpp::get_logger("tita_controller"), prefix) {
      RCLCPP_DEBUG(logger_, "ParameterListener: Not using node logger, recommend using other constructors to use a node logger");
    }

    ParamListener(const std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface>& parameters_interface,
                  rclcpp::Logger logger, std::string const& prefix = "") {
      logger_ = logger;
      prefix_ = prefix;
      if (!prefix_.empty() && prefix_.back() != '.') {
        prefix_ += ".";
      }

      parameters_interface_ = parameters_interface;
      declare_params();
      auto update_param_cb = [this](const std::vector<rclcpp::Parameter> &parameters){return this->update(parameters);};
      handle_ = parameters_interface_->add_on_set_parameters_callback(update_param_cb);
      clock_ = rclcpp::Clock();
    }

    Params get_params() const{
      std::lock_guard<std::mutex> lock(mutex_);
      return params_;
    }

    bool try_get_params(Params & params_in) const {
      if (mutex_.try_lock()) {
        if (const bool is_old = params_in.__stamp != params_.__stamp; is_old) {
          params_in = params_;
        }
        mutex_.unlock();
        return true;
      }
      return false;
    }

    bool is_old(Params const& other) const {
      std::lock_guard<std::mutex> lock(mutex_);
      return params_.__stamp != other.__stamp;
    }

    StackParams get_stack_params() {
      Params params = get_params();
      StackParams output;
      output.update_rate = params.update_rate;
      output.lqr_update_rate = params.lqr_update_rate;
      output.wheel_radius = params.wheel_radius;
      output.static_friction_coefficient = params.static_friction_coefficient;
      output.sliding_friction_coefficient = params.sliding_friction_coefficient;
      output.task.twist_linear_x.max_velocity = params.task.twist_linear_x.max_velocity;
      output.task.twist_linear_x.max_acceleration = params.task.twist_linear_x.max_acceleration;
      output.task.twist_linear_x.min_velocity = params.task.twist_linear_x.min_velocity;
      output.task.twist_linear_x.min_acceleration = params.task.twist_linear_x.min_acceleration;
      output.task.twist_linear_x.q0 = params.task.twist_linear_x.q0;
      output.task.twist_linear_x.q1 = params.task.twist_linear_x.q1;
      output.task.twist_linear_x.q2 = params.task.twist_linear_x.q2;
      output.task.twist_linear_x.q3 = params.task.twist_linear_x.q3;
      output.task.twist_linear_x.r0 = params.task.twist_linear_x.r0;
      output.task.twist_linear_x.weight = params.task.twist_linear_x.weight;
      output.task.twist_angular_z.max_velocity = params.task.twist_angular_z.max_velocity;
      output.task.twist_angular_z.max_acceleration = params.task.twist_angular_z.max_acceleration;
      output.task.twist_angular_z.kp = params.task.twist_angular_z.kp;
      output.task.twist_angular_z.kd = params.task.twist_angular_z.kd;
      output.task.twist_angular_z.weight = params.task.twist_angular_z.weight;
      output.task.pose_position_y.max_position = params.task.pose_position_y.max_position;
      output.task.pose_position_y.max_velocity = params.task.pose_position_y.max_velocity;
      output.task.pose_position_y.max_acceleration = params.task.pose_position_y.max_acceleration;
      output.task.pose_position_y.kp = params.task.pose_position_y.kp;
      output.task.pose_position_y.kd = params.task.pose_position_y.kd;
      output.task.pose_position_y.weight = params.task.pose_position_y.weight;
      output.task.pose_position_z.max_position = params.task.pose_position_z.max_position;
      output.task.pose_position_z.max_velocity = params.task.pose_position_z.max_velocity;
      output.task.pose_position_z.max_acceleration = params.task.pose_position_z.max_acceleration;
      output.task.pose_position_z.min_position = params.task.pose_position_z.min_position;
      output.task.pose_position_z.kp = params.task.pose_position_z.kp;
      output.task.pose_position_z.kd = params.task.pose_position_z.kd;
      output.task.pose_position_z.weight = params.task.pose_position_z.weight;
      output.task.pose_orientation_yaw.max_position = params.task.pose_orientation_yaw.max_position;
      output.task.pose_orientation_yaw.max_velocity = params.task.pose_orientation_yaw.max_velocity;
      output.task.pose_orientation_yaw.max_acceleration = params.task.pose_orientation_yaw.max_acceleration;
      output.task.pose_orientation_yaw.kp = params.task.pose_orientation_yaw.kp;
      output.task.pose_orientation_yaw.kd = params.task.pose_orientation_yaw.kd;
      output.task.pose_orientation_yaw.weight = params.task.pose_orientation_yaw.weight;
      output.task.pose_orientation_pitch.max_position = params.task.pose_orientation_pitch.max_position;
      output.task.pose_orientation_pitch.max_velocity = params.task.pose_orientation_pitch.max_velocity;
      output.task.pose_orientation_pitch.max_acceleration = params.task.pose_orientation_pitch.max_acceleration;
      output.task.pose_orientation_pitch.kp = params.task.pose_orientation_pitch.kp;
      output.task.pose_orientation_pitch.kd = params.task.pose_orientation_pitch.kd;
      output.task.pose_orientation_pitch.weight = params.task.pose_orientation_pitch.weight;
      output.task.pose_orientation_roll.max_position = params.task.pose_orientation_roll.max_position;
      output.task.pose_orientation_roll.max_velocity = params.task.pose_orientation_roll.max_velocity;
      output.task.pose_orientation_roll.max_acceleration = params.task.pose_orientation_roll.max_acceleration;
      output.task.pose_orientation_roll.kp = params.task.pose_orientation_roll.kp;
      output.task.pose_orientation_roll.kd = params.task.pose_orientation_roll.kd;
      output.task.pose_orientation_roll.weight = params.task.pose_orientation_roll.weight;
      output.task.two_wheel_distance.default_value = params.task.two_wheel_distance.default_value;
      output.task.two_wheel_distance.max_position = params.task.two_wheel_distance.max_position;
      output.task.two_wheel_distance.max_velocity = params.task.two_wheel_distance.max_velocity;
      output.task.two_wheel_distance.max_acceleration = params.task.two_wheel_distance.max_acceleration;
      output.task.two_wheel_distance.min_position = params.task.two_wheel_distance.min_position;
      output.task.two_wheel_distance.min_velocity = params.task.two_wheel_distance.min_velocity;
      output.task.two_wheel_distance.min_acceleration = params.task.two_wheel_distance.min_acceleration;
      output.task.two_wheel_distance.kp = params.task.two_wheel_distance.kp;
      output.task.two_wheel_distance.kd = params.task.two_wheel_distance.kd;
      output.task.two_wheel_distance.weight = params.task.two_wheel_distance.weight;
      output.single_joint_pd1.p = params.single_joint_pd1.p;
      output.single_joint_pd1.d = params.single_joint_pd1.d;
      output.single_joint_pd2.p = params.single_joint_pd2.p;
      output.single_joint_pd2.d = params.single_joint_pd2.d;
      output.single_joint_pd3.p = params.single_joint_pd3.p;
      output.single_joint_pd3.d = params.single_joint_pd3.d;
      output.single_joint_pd4.p = params.single_joint_pd4.p;
      output.single_joint_pd4.d = params.single_joint_pd4.d;
      output.estimator.imu_process_noise_position = params.estimator.imu_process_noise_position;
      output.estimator.imu_process_noise_velocity = params.estimator.imu_process_noise_velocity;
      output.estimator.foot_process_noise_position = params.estimator.foot_process_noise_position;
      output.estimator.imu_sensor_noise_position = params.estimator.imu_sensor_noise_position;
      output.estimator.imu_sensor_noise_velocity = params.estimator.imu_sensor_noise_velocity;
      output.estimator.foot_sensor_noise_position = params.estimator.foot_sensor_noise_position;

      return output;
    }

    void refresh_dynamic_parameters() {
      auto updated_params = get_params();
      // TODO remove any destroyed dynamic parameters

      // declare any new dynamic parameters
      rclcpp::Parameter param;

    }

    rcl_interfaces::msg::SetParametersResult update(const std::vector<rclcpp::Parameter> &parameters) {
      auto updated_params = get_params();

      for (const auto &param: parameters) {
        if (param.get_name() == (prefix_ + "update_rate")) {
            updated_params.update_rate = param.as_int();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "joints")) {
            if(auto validation_result = unique<std::string>(param);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.joints = param.as_string_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "robot_description_path")) {
            updated_params.robot_description_path = param.as_string();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "lqr_update_rate")) {
            updated_params.lqr_update_rate = param.as_int();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "wheel_radius")) {
            updated_params.wheel_radius = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "wheel_joint_name")) {
            if(auto validation_result = unique<std::string>(param);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.wheel_joint_name = param.as_string_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "base_name")) {
            updated_params.base_name = param.as_string();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "static_friction_coefficient")) {
            updated_params.static_friction_coefficient = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "sliding_friction_coefficient")) {
            updated_params.sliding_friction_coefficient = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_linear_x.max_velocity")) {
            if(auto validation_result = bounds<double>(param, 0.0, 10.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_linear_x.max_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_linear_x.max_acceleration")) {
            if(auto validation_result = bounds<double>(param, 0.0, 10.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_linear_x.max_acceleration = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_linear_x.min_velocity")) {
            if(auto validation_result = bounds<double>(param, -10.0, 0.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_linear_x.min_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_linear_x.min_acceleration")) {
            if(auto validation_result = bounds<double>(param, -10.0, 0.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_linear_x.min_acceleration = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_linear_x.q0")) {
            if(auto validation_result = bounds<double>(param, 0.001, 1000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_linear_x.q0 = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_linear_x.q1")) {
            if(auto validation_result = bounds<double>(param, 0.001, 10000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_linear_x.q1 = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_linear_x.q2")) {
            if(auto validation_result = bounds<double>(param, 0.001, 10000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_linear_x.q2 = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_linear_x.q3")) {
            if(auto validation_result = bounds<double>(param, 0.001, 10000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_linear_x.q3 = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_linear_x.r0")) {
            if(auto validation_result = bounds<double>(param, 0.001, 10);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_linear_x.r0 = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_linear_x.weight")) {
            if(auto validation_result = bounds<double>(param, 0.01, 100);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_linear_x.weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_angular_z.max_velocity")) {
            if(auto validation_result = bounds<double>(param, 0.0, 20.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_angular_z.max_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_angular_z.max_acceleration")) {
            if(auto validation_result = bounds<double>(param, 0.0, 20.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_angular_z.max_acceleration = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_angular_z.kp")) {
            if(auto validation_result = bounds<double>(param, 0.0, 10000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_angular_z.kp = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_angular_z.kd")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_angular_z.kd = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.twist_angular_z.weight")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.twist_angular_z.weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_y.max_position")) {
            if(auto validation_result = bounds<double>(param, 0.0, 0.12);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_y.max_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_y.max_velocity")) {
            if(auto validation_result = bounds<double>(param, 0.0, 0.1);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_y.max_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_y.max_acceleration")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_y.max_acceleration = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_y.kp")) {
            if(auto validation_result = bounds<double>(param, 0.0, 10000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_y.kp = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_y.kd")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_y.kd = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_y.weight")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_y.weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_z.max_position")) {
            if(auto validation_result = bounds<double>(param, 0.3, 0.5);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_z.max_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_z.max_velocity")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_z.max_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_z.max_acceleration")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_z.max_acceleration = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_z.min_position")) {
            if(auto validation_result = bounds<double>(param, 0.1, 0.3);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_z.min_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_z.kp")) {
            if(auto validation_result = bounds<double>(param, 0.0, 10000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_z.kp = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_z.kd")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_z.kd = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_position_z.weight")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_position_z.weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_yaw.max_position")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_yaw.max_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_yaw.max_velocity")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_yaw.max_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_yaw.max_acceleration")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_yaw.max_acceleration = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_yaw.kp")) {
            if(auto validation_result = bounds<double>(param, 0.0, 10000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_yaw.kp = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_yaw.kd")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_yaw.kd = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_yaw.weight")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_yaw.weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_pitch.max_position")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_pitch.max_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_pitch.max_velocity")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_pitch.max_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_pitch.max_acceleration")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_pitch.max_acceleration = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_pitch.kp")) {
            if(auto validation_result = bounds<double>(param, 0.0, 10000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_pitch.kp = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_pitch.kd")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_pitch.kd = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_pitch.weight")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_pitch.weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_roll.max_position")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1.5);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_roll.max_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_roll.max_velocity")) {
            if(auto validation_result = bounds<double>(param, 0.0, 3.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_roll.max_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_roll.max_acceleration")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_roll.max_acceleration = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_roll.kp")) {
            if(auto validation_result = bounds<double>(param, 0.0, 10000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_roll.kp = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_roll.kd")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_roll.kd = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.pose_orientation_roll.weight")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.pose_orientation_roll.weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.two_wheel_distance.default_value")) {
            updated_params.task.two_wheel_distance.default_value = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.two_wheel_distance.max_position")) {
            if(auto validation_result = bounds<double>(param, 0.0, 0.1);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.two_wheel_distance.max_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.two_wheel_distance.max_velocity")) {
            if(auto validation_result = bounds<double>(param, 0.0, 1.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.two_wheel_distance.max_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.two_wheel_distance.max_acceleration")) {
            if(auto validation_result = bounds<double>(param, 0.0, 50.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.two_wheel_distance.max_acceleration = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.two_wheel_distance.min_position")) {
            if(auto validation_result = bounds<double>(param, -0.1, 0.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.two_wheel_distance.min_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.two_wheel_distance.min_velocity")) {
            if(auto validation_result = bounds<double>(param, -1.0, 0.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.two_wheel_distance.min_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.two_wheel_distance.min_acceleration")) {
            if(auto validation_result = bounds<double>(param, -50.0, 0.0);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.two_wheel_distance.min_acceleration = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.two_wheel_distance.kp")) {
            if(auto validation_result = bounds<double>(param, 0, 10000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.two_wheel_distance.kp = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.two_wheel_distance.kd")) {
            if(auto validation_result = bounds<double>(param, 0, 1000);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.two_wheel_distance.kd = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "task.two_wheel_distance.weight")) {
            if(auto validation_result = bounds<double>(param, 0.0, 100);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.task.two_wheel_distance.weight = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "torque_limit")) {
            if(auto validation_result = fixed_size<double>(param, 8);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.torque_limit = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "joint_pd.p")) {
            if(auto validation_result = fixed_size<double>(param, 8);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.joint_pd.p = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "joint_pd.d")) {
            if(auto validation_result = fixed_size<double>(param, 8);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.joint_pd.d = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "wbc_joint_pd.p")) {
            if(auto validation_result = fixed_size<double>(param, 8);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.wbc_joint_pd.p = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "wbc_joint_pd.d")) {
            if(auto validation_result = fixed_size<double>(param, 8);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.wbc_joint_pd.d = param.as_double_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "single_joint_pd1.p")) {
            updated_params.single_joint_pd1.p = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "single_joint_pd1.d")) {
            updated_params.single_joint_pd1.d = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "single_joint_pd2.p")) {
            updated_params.single_joint_pd2.p = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "single_joint_pd2.d")) {
            updated_params.single_joint_pd2.d = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "single_joint_pd3.p")) {
            updated_params.single_joint_pd3.p = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "single_joint_pd3.d")) {
            updated_params.single_joint_pd3.d = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "single_joint_pd4.p")) {
            updated_params.single_joint_pd4.p = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "single_joint_pd4.d")) {
            updated_params.single_joint_pd4.d = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "estimator.imu_process_noise_position")) {
            updated_params.estimator.imu_process_noise_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "estimator.imu_process_noise_velocity")) {
            updated_params.estimator.imu_process_noise_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "estimator.foot_process_noise_position")) {
            updated_params.estimator.foot_process_noise_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "estimator.imu_sensor_noise_position")) {
            updated_params.estimator.imu_sensor_noise_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "estimator.imu_sensor_noise_velocity")) {
            updated_params.estimator.imu_sensor_noise_velocity = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "estimator.foot_sensor_noise_position")) {
            updated_params.estimator.foot_sensor_noise_position = param.as_double();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
      }

      updated_params.__stamp = clock_.now();
      update_internal_params(updated_params);
      return rsl::to_parameter_result_msg({});
    }

    void declare_params(){
      auto updated_params = get_params();
      // declare all parameters and give default values to non-required ones
      if (!parameters_interface_->has_parameter(prefix_ + "update_rate")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Main control loop update rate in Hz";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.update_rate);
          parameters_interface_->declare_parameter(prefix_ + "update_rate", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "joints")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Joint names to control and listen to";
          descriptor.read_only = true;
          auto parameter = to_parameter_value(updated_params.joints);
          parameters_interface_->declare_parameter(prefix_ + "joints", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "robot_description_path")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.robot_description_path);
          parameters_interface_->declare_parameter(prefix_ + "robot_description_path", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "lqr_update_rate")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Lqr Thread update rate in Hz";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.lqr_update_rate);
          parameters_interface_->declare_parameter(prefix_ + "lqr_update_rate", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "wheel_radius")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Radius of a wheel, used for transformation of linear velocity into wheel rotations. If this parameter is wrong the robot will move faster or slower then expected.";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.wheel_radius);
          parameters_interface_->declare_parameter(prefix_ + "wheel_radius", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "wheel_joint_name")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Joint names to control and listen to";
          descriptor.read_only = true;
          auto parameter = to_parameter_value(updated_params.wheel_joint_name);
          parameters_interface_->declare_parameter(prefix_ + "wheel_joint_name", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "base_name")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Name of the base frame";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.base_name);
          parameters_interface_->declare_parameter(prefix_ + "base_name", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "static_friction_coefficient")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Radius of a wheel, used for transformation of linear velocity into wheel rotations. If this parameter is wrong the robot will move faster or slower then expected.";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.static_friction_coefficient);
          parameters_interface_->declare_parameter(prefix_ + "static_friction_coefficient", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "sliding_friction_coefficient")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Radius of a wheel, used for transformation of linear velocity into wheel rotations. If this parameter is wrong the robot will move faster or slower then expected.";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.sliding_friction_coefficient);
          parameters_interface_->declare_parameter(prefix_ + "sliding_friction_coefficient", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_linear_x.max_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max velocity of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 10.0;
          auto parameter = to_parameter_value(updated_params.task.twist_linear_x.max_velocity);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_linear_x.max_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_linear_x.max_acceleration")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max acceleration of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 10.0;
          auto parameter = to_parameter_value(updated_params.task.twist_linear_x.max_acceleration);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_linear_x.max_acceleration", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_linear_x.min_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Min velocity of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = -10.0;
          descriptor.floating_point_range.at(0).to_value = 0.0;
          auto parameter = to_parameter_value(updated_params.task.twist_linear_x.min_velocity);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_linear_x.min_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_linear_x.min_acceleration")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Min acceleration of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = -10.0;
          descriptor.floating_point_range.at(0).to_value = 0.0;
          auto parameter = to_parameter_value(updated_params.task.twist_linear_x.min_acceleration);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_linear_x.min_acceleration", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_linear_x.q0")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Lqr gain";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.001;
          descriptor.floating_point_range.at(0).to_value = 1000;
          auto parameter = to_parameter_value(updated_params.task.twist_linear_x.q0);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_linear_x.q0", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_linear_x.q1")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Lqr gain";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.001;
          descriptor.floating_point_range.at(0).to_value = 10000;
          auto parameter = to_parameter_value(updated_params.task.twist_linear_x.q1);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_linear_x.q1", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_linear_x.q2")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Lqr gain";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.001;
          descriptor.floating_point_range.at(0).to_value = 10000;
          auto parameter = to_parameter_value(updated_params.task.twist_linear_x.q2);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_linear_x.q2", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_linear_x.q3")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Lqr gain";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.001;
          descriptor.floating_point_range.at(0).to_value = 10000;
          auto parameter = to_parameter_value(updated_params.task.twist_linear_x.q3);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_linear_x.q3", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_linear_x.r0")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Integral gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.001;
          descriptor.floating_point_range.at(0).to_value = 10;
          auto parameter = to_parameter_value(updated_params.task.twist_linear_x.r0);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_linear_x.r0", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_linear_x.weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Derivative gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.01;
          descriptor.floating_point_range.at(0).to_value = 100;
          auto parameter = to_parameter_value(updated_params.task.twist_linear_x.weight);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_linear_x.weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_angular_z.max_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max velocity of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 20.0;
          auto parameter = to_parameter_value(updated_params.task.twist_angular_z.max_velocity);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_angular_z.max_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_angular_z.max_acceleration")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max acceleration of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 20.0;
          auto parameter = to_parameter_value(updated_params.task.twist_angular_z.max_acceleration);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_angular_z.max_acceleration", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_angular_z.kp")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Proportional gain :math:k_p for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 10000;
          auto parameter = to_parameter_value(updated_params.task.twist_angular_z.kp);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_angular_z.kp", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_angular_z.kd")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Integral gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1000;
          auto parameter = to_parameter_value(updated_params.task.twist_angular_z.kd);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_angular_z.kd", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.twist_angular_z.weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Derivative gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100;
          auto parameter = to_parameter_value(updated_params.task.twist_angular_z.weight);
          parameters_interface_->declare_parameter(prefix_ + "task.twist_angular_z.weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_y.max_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max position of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 0.12;
          auto parameter = to_parameter_value(updated_params.task.pose_position_y.max_position);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_y.max_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_y.max_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max velocity of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 0.1;
          auto parameter = to_parameter_value(updated_params.task.pose_position_y.max_velocity);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_y.max_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_y.max_acceleration")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max acceleration of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100.0;
          auto parameter = to_parameter_value(updated_params.task.pose_position_y.max_acceleration);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_y.max_acceleration", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_y.kp")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Proportional gain :math:k_p for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 10000;
          auto parameter = to_parameter_value(updated_params.task.pose_position_y.kp);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_y.kp", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_y.kd")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Integral gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1000;
          auto parameter = to_parameter_value(updated_params.task.pose_position_y.kd);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_y.kd", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_y.weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Derivative gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100;
          auto parameter = to_parameter_value(updated_params.task.pose_position_y.weight);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_y.weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_z.max_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max position of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.3;
          descriptor.floating_point_range.at(0).to_value = 0.5;
          auto parameter = to_parameter_value(updated_params.task.pose_position_z.max_position);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_z.max_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_z.max_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max velocity of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1.0;
          auto parameter = to_parameter_value(updated_params.task.pose_position_z.max_velocity);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_z.max_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_z.max_acceleration")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max acceleration of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100.0;
          auto parameter = to_parameter_value(updated_params.task.pose_position_z.max_acceleration);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_z.max_acceleration", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_z.min_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Min position of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.1;
          descriptor.floating_point_range.at(0).to_value = 0.3;
          auto parameter = to_parameter_value(updated_params.task.pose_position_z.min_position);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_z.min_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_z.kp")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Proportional gain :math:k_p for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 10000;
          auto parameter = to_parameter_value(updated_params.task.pose_position_z.kp);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_z.kp", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_z.kd")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Integral gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1000;
          auto parameter = to_parameter_value(updated_params.task.pose_position_z.kd);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_z.kd", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_position_z.weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Derivative gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100;
          auto parameter = to_parameter_value(updated_params.task.pose_position_z.weight);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_position_z.weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_yaw.max_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max position of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1.0;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_yaw.max_position);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_yaw.max_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_yaw.max_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max velocity of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1.0;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_yaw.max_velocity);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_yaw.max_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_yaw.max_acceleration")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max acceleration of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100.0;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_yaw.max_acceleration);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_yaw.max_acceleration", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_yaw.kp")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Proportional gain :math:k_p for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 10000;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_yaw.kp);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_yaw.kp", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_yaw.kd")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Integral gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1000;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_yaw.kd);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_yaw.kd", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_yaw.weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Derivative gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_yaw.weight);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_yaw.weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_pitch.max_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max position of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1.0;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_pitch.max_position);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_pitch.max_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_pitch.max_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max velocity of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1.0;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_pitch.max_velocity);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_pitch.max_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_pitch.max_acceleration")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max acceleration of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100.0;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_pitch.max_acceleration);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_pitch.max_acceleration", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_pitch.kp")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Proportional gain :math:k_p for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 10000;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_pitch.kp);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_pitch.kp", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_pitch.kd")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Integral gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1000;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_pitch.kd);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_pitch.kd", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_pitch.weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Derivative gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_pitch.weight);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_pitch.weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_roll.max_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max position of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1.5;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_roll.max_position);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_roll.max_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_roll.max_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max velocity of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 3.0;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_roll.max_velocity);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_roll.max_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_roll.max_acceleration")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max acceleration of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100.0;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_roll.max_acceleration);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_roll.max_acceleration", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_roll.kp")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Proportional gain :math:k_p for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 10000;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_roll.kp);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_roll.kp", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_roll.kd")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Integral gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1000;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_roll.kd);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_roll.kd", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.pose_orientation_roll.weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Derivative gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100;
          auto parameter = to_parameter_value(updated_params.task.pose_orientation_roll.weight);
          parameters_interface_->declare_parameter(prefix_ + "task.pose_orientation_roll.weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.two_wheel_distance.default_value")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Distance between the two wheels";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.task.two_wheel_distance.default_value);
          parameters_interface_->declare_parameter(prefix_ + "task.two_wheel_distance.default_value", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.two_wheel_distance.max_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max position of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 0.1;
          auto parameter = to_parameter_value(updated_params.task.two_wheel_distance.max_position);
          parameters_interface_->declare_parameter(prefix_ + "task.two_wheel_distance.max_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.two_wheel_distance.max_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max velocity of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 1.0;
          auto parameter = to_parameter_value(updated_params.task.two_wheel_distance.max_velocity);
          parameters_interface_->declare_parameter(prefix_ + "task.two_wheel_distance.max_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.two_wheel_distance.max_acceleration")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max acceleration of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 50.0;
          auto parameter = to_parameter_value(updated_params.task.two_wheel_distance.max_acceleration);
          parameters_interface_->declare_parameter(prefix_ + "task.two_wheel_distance.max_acceleration", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.two_wheel_distance.min_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Min position of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = -0.1;
          descriptor.floating_point_range.at(0).to_value = 0.0;
          auto parameter = to_parameter_value(updated_params.task.two_wheel_distance.min_position);
          parameters_interface_->declare_parameter(prefix_ + "task.two_wheel_distance.min_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.two_wheel_distance.min_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Min velocity of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = -1.0;
          descriptor.floating_point_range.at(0).to_value = 0.0;
          auto parameter = to_parameter_value(updated_params.task.two_wheel_distance.min_velocity);
          parameters_interface_->declare_parameter(prefix_ + "task.two_wheel_distance.min_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.two_wheel_distance.min_acceleration")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Min acceleration of command input";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = -50.0;
          descriptor.floating_point_range.at(0).to_value = 0.0;
          auto parameter = to_parameter_value(updated_params.task.two_wheel_distance.min_acceleration);
          parameters_interface_->declare_parameter(prefix_ + "task.two_wheel_distance.min_acceleration", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.two_wheel_distance.kp")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Proportional gain :math:k_p for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0;
          descriptor.floating_point_range.at(0).to_value = 10000;
          auto parameter = to_parameter_value(updated_params.task.two_wheel_distance.kp);
          parameters_interface_->declare_parameter(prefix_ + "task.two_wheel_distance.kp", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.two_wheel_distance.kd")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Integral gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0;
          descriptor.floating_point_range.at(0).to_value = 1000;
          auto parameter = to_parameter_value(updated_params.task.two_wheel_distance.kd);
          parameters_interface_->declare_parameter(prefix_ + "task.two_wheel_distance.kd", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "task.two_wheel_distance.weight")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Derivative gain :math:k_d for PID";
          descriptor.read_only = false;
          descriptor.floating_point_range.resize(1);
          descriptor.floating_point_range.at(0).from_value = 0.0;
          descriptor.floating_point_range.at(0).to_value = 100;
          auto parameter = to_parameter_value(updated_params.task.two_wheel_distance.weight);
          parameters_interface_->declare_parameter(prefix_ + "task.two_wheel_distance.weight", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "torque_limit")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max torque of every joint motor.";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.torque_limit);
          parameters_interface_->declare_parameter(prefix_ + "torque_limit", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "joint_pd.p")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max torque of every joint motor.";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.joint_pd.p);
          parameters_interface_->declare_parameter(prefix_ + "joint_pd.p", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "joint_pd.d")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max torque of every joint motor.";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.joint_pd.d);
          parameters_interface_->declare_parameter(prefix_ + "joint_pd.d", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "wbc_joint_pd.p")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max torque of every joint motor.";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.wbc_joint_pd.p);
          parameters_interface_->declare_parameter(prefix_ + "wbc_joint_pd.p", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "wbc_joint_pd.d")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Max torque of every joint motor.";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.wbc_joint_pd.d);
          parameters_interface_->declare_parameter(prefix_ + "wbc_joint_pd.d", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "single_joint_pd1.p")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.single_joint_pd1.p);
          parameters_interface_->declare_parameter(prefix_ + "single_joint_pd1.p", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "single_joint_pd1.d")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.single_joint_pd1.d);
          parameters_interface_->declare_parameter(prefix_ + "single_joint_pd1.d", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "single_joint_pd2.p")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.single_joint_pd2.p);
          parameters_interface_->declare_parameter(prefix_ + "single_joint_pd2.p", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "single_joint_pd2.d")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.single_joint_pd2.d);
          parameters_interface_->declare_parameter(prefix_ + "single_joint_pd2.d", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "single_joint_pd3.p")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.single_joint_pd3.p);
          parameters_interface_->declare_parameter(prefix_ + "single_joint_pd3.p", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "single_joint_pd3.d")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.single_joint_pd3.d);
          parameters_interface_->declare_parameter(prefix_ + "single_joint_pd3.d", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "single_joint_pd4.p")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.single_joint_pd4.p);
          parameters_interface_->declare_parameter(prefix_ + "single_joint_pd4.p", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "single_joint_pd4.d")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.single_joint_pd4.d);
          parameters_interface_->declare_parameter(prefix_ + "single_joint_pd4.d", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "estimator.imu_process_noise_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.estimator.imu_process_noise_position);
          parameters_interface_->declare_parameter(prefix_ + "estimator.imu_process_noise_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "estimator.imu_process_noise_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.estimator.imu_process_noise_velocity);
          parameters_interface_->declare_parameter(prefix_ + "estimator.imu_process_noise_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "estimator.foot_process_noise_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.estimator.foot_process_noise_position);
          parameters_interface_->declare_parameter(prefix_ + "estimator.foot_process_noise_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "estimator.imu_sensor_noise_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.estimator.imu_sensor_noise_position);
          parameters_interface_->declare_parameter(prefix_ + "estimator.imu_sensor_noise_position", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "estimator.imu_sensor_noise_velocity")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.estimator.imu_sensor_noise_velocity);
          parameters_interface_->declare_parameter(prefix_ + "estimator.imu_sensor_noise_velocity", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "estimator.foot_sensor_noise_position")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.estimator.foot_sensor_noise_position);
          parameters_interface_->declare_parameter(prefix_ + "estimator.foot_sensor_noise_position", parameter, descriptor);
      }
      // get parameters and fill struct fields
      rclcpp::Parameter param;
      param = parameters_interface_->get_parameter(prefix_ + "update_rate");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.update_rate = param.as_int();
      param = parameters_interface_->get_parameter(prefix_ + "joints");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = unique<std::string>(param);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'joints': {}", validation_result.error()));
      }
      updated_params.joints = param.as_string_array();
      param = parameters_interface_->get_parameter(prefix_ + "robot_description_path");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.robot_description_path = param.as_string();
      param = parameters_interface_->get_parameter(prefix_ + "lqr_update_rate");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.lqr_update_rate = param.as_int();
      param = parameters_interface_->get_parameter(prefix_ + "wheel_radius");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.wheel_radius = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "wheel_joint_name");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = unique<std::string>(param);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'wheel_joint_name': {}", validation_result.error()));
      }
      updated_params.wheel_joint_name = param.as_string_array();
      param = parameters_interface_->get_parameter(prefix_ + "base_name");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.base_name = param.as_string();
      param = parameters_interface_->get_parameter(prefix_ + "static_friction_coefficient");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.static_friction_coefficient = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "sliding_friction_coefficient");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.sliding_friction_coefficient = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_linear_x.max_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 10.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_linear_x.max_velocity': {}", validation_result.error()));
      }
      updated_params.task.twist_linear_x.max_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_linear_x.max_acceleration");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 10.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_linear_x.max_acceleration': {}", validation_result.error()));
      }
      updated_params.task.twist_linear_x.max_acceleration = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_linear_x.min_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, -10.0, 0.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_linear_x.min_velocity': {}", validation_result.error()));
      }
      updated_params.task.twist_linear_x.min_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_linear_x.min_acceleration");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, -10.0, 0.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_linear_x.min_acceleration': {}", validation_result.error()));
      }
      updated_params.task.twist_linear_x.min_acceleration = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_linear_x.q0");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.001, 1000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_linear_x.q0': {}", validation_result.error()));
      }
      updated_params.task.twist_linear_x.q0 = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_linear_x.q1");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.001, 10000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_linear_x.q1': {}", validation_result.error()));
      }
      updated_params.task.twist_linear_x.q1 = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_linear_x.q2");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.001, 10000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_linear_x.q2': {}", validation_result.error()));
      }
      updated_params.task.twist_linear_x.q2 = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_linear_x.q3");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.001, 10000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_linear_x.q3': {}", validation_result.error()));
      }
      updated_params.task.twist_linear_x.q3 = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_linear_x.r0");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.001, 10);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_linear_x.r0': {}", validation_result.error()));
      }
      updated_params.task.twist_linear_x.r0 = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_linear_x.weight");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.01, 100);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_linear_x.weight': {}", validation_result.error()));
      }
      updated_params.task.twist_linear_x.weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_angular_z.max_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 20.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_angular_z.max_velocity': {}", validation_result.error()));
      }
      updated_params.task.twist_angular_z.max_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_angular_z.max_acceleration");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 20.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_angular_z.max_acceleration': {}", validation_result.error()));
      }
      updated_params.task.twist_angular_z.max_acceleration = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_angular_z.kp");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 10000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_angular_z.kp': {}", validation_result.error()));
      }
      updated_params.task.twist_angular_z.kp = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_angular_z.kd");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_angular_z.kd': {}", validation_result.error()));
      }
      updated_params.task.twist_angular_z.kd = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.twist_angular_z.weight");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.twist_angular_z.weight': {}", validation_result.error()));
      }
      updated_params.task.twist_angular_z.weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_y.max_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 0.12);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_y.max_position': {}", validation_result.error()));
      }
      updated_params.task.pose_position_y.max_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_y.max_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 0.1);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_y.max_velocity': {}", validation_result.error()));
      }
      updated_params.task.pose_position_y.max_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_y.max_acceleration");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_y.max_acceleration': {}", validation_result.error()));
      }
      updated_params.task.pose_position_y.max_acceleration = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_y.kp");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 10000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_y.kp': {}", validation_result.error()));
      }
      updated_params.task.pose_position_y.kp = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_y.kd");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_y.kd': {}", validation_result.error()));
      }
      updated_params.task.pose_position_y.kd = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_y.weight");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_y.weight': {}", validation_result.error()));
      }
      updated_params.task.pose_position_y.weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_z.max_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.3, 0.5);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_z.max_position': {}", validation_result.error()));
      }
      updated_params.task.pose_position_z.max_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_z.max_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_z.max_velocity': {}", validation_result.error()));
      }
      updated_params.task.pose_position_z.max_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_z.max_acceleration");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_z.max_acceleration': {}", validation_result.error()));
      }
      updated_params.task.pose_position_z.max_acceleration = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_z.min_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.1, 0.3);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_z.min_position': {}", validation_result.error()));
      }
      updated_params.task.pose_position_z.min_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_z.kp");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 10000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_z.kp': {}", validation_result.error()));
      }
      updated_params.task.pose_position_z.kp = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_z.kd");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_z.kd': {}", validation_result.error()));
      }
      updated_params.task.pose_position_z.kd = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_position_z.weight");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_position_z.weight': {}", validation_result.error()));
      }
      updated_params.task.pose_position_z.weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_yaw.max_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_yaw.max_position': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_yaw.max_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_yaw.max_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_yaw.max_velocity': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_yaw.max_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_yaw.max_acceleration");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_yaw.max_acceleration': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_yaw.max_acceleration = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_yaw.kp");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 10000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_yaw.kp': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_yaw.kp = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_yaw.kd");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_yaw.kd': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_yaw.kd = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_yaw.weight");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_yaw.weight': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_yaw.weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_pitch.max_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_pitch.max_position': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_pitch.max_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_pitch.max_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_pitch.max_velocity': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_pitch.max_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_pitch.max_acceleration");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_pitch.max_acceleration': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_pitch.max_acceleration = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_pitch.kp");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 10000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_pitch.kp': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_pitch.kp = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_pitch.kd");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_pitch.kd': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_pitch.kd = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_pitch.weight");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_pitch.weight': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_pitch.weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_roll.max_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1.5);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_roll.max_position': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_roll.max_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_roll.max_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 3.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_roll.max_velocity': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_roll.max_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_roll.max_acceleration");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_roll.max_acceleration': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_roll.max_acceleration = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_roll.kp");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 10000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_roll.kp': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_roll.kp = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_roll.kd");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_roll.kd': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_roll.kd = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.pose_orientation_roll.weight");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.pose_orientation_roll.weight': {}", validation_result.error()));
      }
      updated_params.task.pose_orientation_roll.weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.two_wheel_distance.default_value");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.task.two_wheel_distance.default_value = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.two_wheel_distance.max_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 0.1);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.two_wheel_distance.max_position': {}", validation_result.error()));
      }
      updated_params.task.two_wheel_distance.max_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.two_wheel_distance.max_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 1.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.two_wheel_distance.max_velocity': {}", validation_result.error()));
      }
      updated_params.task.two_wheel_distance.max_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.two_wheel_distance.max_acceleration");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 50.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.two_wheel_distance.max_acceleration': {}", validation_result.error()));
      }
      updated_params.task.two_wheel_distance.max_acceleration = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.two_wheel_distance.min_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, -0.1, 0.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.two_wheel_distance.min_position': {}", validation_result.error()));
      }
      updated_params.task.two_wheel_distance.min_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.two_wheel_distance.min_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, -1.0, 0.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.two_wheel_distance.min_velocity': {}", validation_result.error()));
      }
      updated_params.task.two_wheel_distance.min_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.two_wheel_distance.min_acceleration");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, -50.0, 0.0);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.two_wheel_distance.min_acceleration': {}", validation_result.error()));
      }
      updated_params.task.two_wheel_distance.min_acceleration = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.two_wheel_distance.kp");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0, 10000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.two_wheel_distance.kp': {}", validation_result.error()));
      }
      updated_params.task.two_wheel_distance.kp = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.two_wheel_distance.kd");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0, 1000);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.two_wheel_distance.kd': {}", validation_result.error()));
      }
      updated_params.task.two_wheel_distance.kd = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "task.two_wheel_distance.weight");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = bounds<double>(param, 0.0, 100);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'task.two_wheel_distance.weight': {}", validation_result.error()));
      }
      updated_params.task.two_wheel_distance.weight = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "torque_limit");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = fixed_size<double>(param, 8);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'torque_limit': {}", validation_result.error()));
      }
      updated_params.torque_limit = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "joint_pd.p");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = fixed_size<double>(param, 8);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'joint_pd.p': {}", validation_result.error()));
      }
      updated_params.joint_pd.p = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "joint_pd.d");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = fixed_size<double>(param, 8);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'joint_pd.d': {}", validation_result.error()));
      }
      updated_params.joint_pd.d = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "wbc_joint_pd.p");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = fixed_size<double>(param, 8);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'wbc_joint_pd.p': {}", validation_result.error()));
      }
      updated_params.wbc_joint_pd.p = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "wbc_joint_pd.d");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = fixed_size<double>(param, 8);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'wbc_joint_pd.d': {}", validation_result.error()));
      }
      updated_params.wbc_joint_pd.d = param.as_double_array();
      param = parameters_interface_->get_parameter(prefix_ + "single_joint_pd1.p");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.single_joint_pd1.p = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "single_joint_pd1.d");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.single_joint_pd1.d = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "single_joint_pd2.p");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.single_joint_pd2.p = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "single_joint_pd2.d");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.single_joint_pd2.d = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "single_joint_pd3.p");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.single_joint_pd3.p = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "single_joint_pd3.d");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.single_joint_pd3.d = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "single_joint_pd4.p");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.single_joint_pd4.p = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "single_joint_pd4.d");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.single_joint_pd4.d = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "estimator.imu_process_noise_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.estimator.imu_process_noise_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "estimator.imu_process_noise_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.estimator.imu_process_noise_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "estimator.foot_process_noise_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.estimator.foot_process_noise_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "estimator.imu_sensor_noise_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.estimator.imu_sensor_noise_position = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "estimator.imu_sensor_noise_velocity");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.estimator.imu_sensor_noise_velocity = param.as_double();
      param = parameters_interface_->get_parameter(prefix_ + "estimator.foot_sensor_noise_position");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.estimator.foot_sensor_noise_position = param.as_double();


      updated_params.__stamp = clock_.now();
      update_internal_params(updated_params);
    }

    private:
      void update_internal_params(Params updated_params) {
        std::lock_guard<std::mutex> lock(mutex_);
        params_ = updated_params;
      }

      std::string prefix_;
      Params params_;
      rclcpp::Clock clock_;
      std::shared_ptr<rclcpp::node_interfaces::OnSetParametersCallbackHandle> handle_;
      std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface> parameters_interface_;

      // rclcpp::Logger cannot be default-constructed
      // so we must provide a initialization here even though
      // every one of our constructors initializes logger_
      rclcpp::Logger logger_ = rclcpp::get_logger("tita_controller");
      std::mutex mutable mutex_;
  };

} // namespace tita_controller
