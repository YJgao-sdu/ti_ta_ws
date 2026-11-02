// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from locomotion_msgs:msg/RobotStates.idl
// generated code does not contain a copyright notice

#ifndef LOCOMOTION_MSGS__MSG__DETAIL__ROBOT_STATES__BUILDER_HPP_
#define LOCOMOTION_MSGS__MSG__DETAIL__ROBOT_STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "locomotion_msgs/msg/detail/robot_states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace locomotion_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotStates_joint_torques
{
public:
  explicit Init_RobotStates_joint_torques(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  ::locomotion_msgs::msg::RobotStates joint_torques(::locomotion_msgs::msg::RobotStates::_joint_torques_type arg)
  {
    msg_.joint_torques = std::move(arg);
    return std::move(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_joint_velocities
{
public:
  explicit Init_RobotStates_joint_velocities(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_joint_torques joint_velocities(::locomotion_msgs::msg::RobotStates::_joint_velocities_type arg)
  {
    msg_.joint_velocities = std::move(arg);
    return Init_RobotStates_joint_torques(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_joint_positions
{
public:
  explicit Init_RobotStates_joint_positions(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_joint_velocities joint_positions(::locomotion_msgs::msg::RobotStates::_joint_positions_type arg)
  {
    msg_.joint_positions = std::move(arg);
    return Init_RobotStates_joint_velocities(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_com_velocity_relative
{
public:
  explicit Init_RobotStates_com_velocity_relative(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_joint_positions com_velocity_relative(::locomotion_msgs::msg::RobotStates::_com_velocity_relative_type arg)
  {
    msg_.com_velocity_relative = std::move(arg);
    return Init_RobotStates_joint_positions(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_com_position_relative
{
public:
  explicit Init_RobotStates_com_position_relative(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_com_velocity_relative com_position_relative(::locomotion_msgs::msg::RobotStates::_com_position_relative_type arg)
  {
    msg_.com_position_relative = std::move(arg);
    return Init_RobotStates_com_velocity_relative(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_two_wheel_distance_dot
{
public:
  explicit Init_RobotStates_two_wheel_distance_dot(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_com_position_relative two_wheel_distance_dot(::locomotion_msgs::msg::RobotStates::_two_wheel_distance_dot_type arg)
  {
    msg_.two_wheel_distance_dot = std::move(arg);
    return Init_RobotStates_com_position_relative(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_two_wheel_distance
{
public:
  explicit Init_RobotStates_two_wheel_distance(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_two_wheel_distance_dot two_wheel_distance(::locomotion_msgs::msg::RobotStates::_two_wheel_distance_type arg)
  {
    msg_.two_wheel_distance = std::move(arg);
    return Init_RobotStates_two_wheel_distance_dot(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_pose_rpy_dot
{
public:
  explicit Init_RobotStates_pose_rpy_dot(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_two_wheel_distance pose_rpy_dot(::locomotion_msgs::msg::RobotStates::_pose_rpy_dot_type arg)
  {
    msg_.pose_rpy_dot = std::move(arg);
    return Init_RobotStates_two_wheel_distance(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_pose_rpy
{
public:
  explicit Init_RobotStates_pose_rpy(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_pose_rpy_dot pose_rpy(::locomotion_msgs::msg::RobotStates::_pose_rpy_type arg)
  {
    msg_.pose_rpy = std::move(arg);
    return Init_RobotStates_pose_rpy_dot(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_pose_position_dot
{
public:
  explicit Init_RobotStates_pose_position_dot(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_pose_rpy pose_position_dot(::locomotion_msgs::msg::RobotStates::_pose_position_dot_type arg)
  {
    msg_.pose_position_dot = std::move(arg);
    return Init_RobotStates_pose_rpy(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_pose_position
{
public:
  explicit Init_RobotStates_pose_position(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_pose_position_dot pose_position(::locomotion_msgs::msg::RobotStates::_pose_position_type arg)
  {
    msg_.pose_position = std::move(arg);
    return Init_RobotStates_pose_position_dot(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_twist_angular_int
{
public:
  explicit Init_RobotStates_twist_angular_int(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_pose_position twist_angular_int(::locomotion_msgs::msg::RobotStates::_twist_angular_int_type arg)
  {
    msg_.twist_angular_int = std::move(arg);
    return Init_RobotStates_pose_position(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_twist_angular
{
public:
  explicit Init_RobotStates_twist_angular(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_twist_angular_int twist_angular(::locomotion_msgs::msg::RobotStates::_twist_angular_type arg)
  {
    msg_.twist_angular = std::move(arg);
    return Init_RobotStates_twist_angular_int(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_twist_linear_int
{
public:
  explicit Init_RobotStates_twist_linear_int(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_twist_angular twist_linear_int(::locomotion_msgs::msg::RobotStates::_twist_linear_int_type arg)
  {
    msg_.twist_linear_int = std::move(arg);
    return Init_RobotStates_twist_angular(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_twist_linear
{
public:
  explicit Init_RobotStates_twist_linear(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_twist_linear_int twist_linear(::locomotion_msgs::msg::RobotStates::_twist_linear_type arg)
  {
    msg_.twist_linear = std::move(arg);
    return Init_RobotStates_twist_linear_int(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_fsm_state_name
{
public:
  explicit Init_RobotStates_fsm_state_name(::locomotion_msgs::msg::RobotStates & msg)
  : msg_(msg)
  {}
  Init_RobotStates_twist_linear fsm_state_name(::locomotion_msgs::msg::RobotStates::_fsm_state_name_type arg)
  {
    msg_.fsm_state_name = std::move(arg);
    return Init_RobotStates_twist_linear(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

class Init_RobotStates_header
{
public:
  Init_RobotStates_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStates_fsm_state_name header(::locomotion_msgs::msg::RobotStates::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RobotStates_fsm_state_name(msg_);
  }

private:
  ::locomotion_msgs::msg::RobotStates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::locomotion_msgs::msg::RobotStates>()
{
  return locomotion_msgs::msg::builder::Init_RobotStates_header();
}

}  // namespace locomotion_msgs

#endif  // LOCOMOTION_MSGS__MSG__DETAIL__ROBOT_STATES__BUILDER_HPP_
