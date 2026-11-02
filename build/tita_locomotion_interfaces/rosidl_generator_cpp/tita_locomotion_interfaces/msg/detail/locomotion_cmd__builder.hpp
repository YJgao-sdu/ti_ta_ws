// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_locomotion_interfaces:msg/LocomotionCmd.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__BUILDER_HPP_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_locomotion_interfaces/msg/detail/locomotion_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_locomotion_interfaces
{

namespace msg
{

namespace builder
{

class Init_LocomotionCmd_twist
{
public:
  explicit Init_LocomotionCmd_twist(::tita_locomotion_interfaces::msg::LocomotionCmd & msg)
  : msg_(msg)
  {}
  ::tita_locomotion_interfaces::msg::LocomotionCmd twist(::tita_locomotion_interfaces::msg::LocomotionCmd::_twist_type arg)
  {
    msg_.twist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_locomotion_interfaces::msg::LocomotionCmd msg_;
};

class Init_LocomotionCmd_pose
{
public:
  explicit Init_LocomotionCmd_pose(::tita_locomotion_interfaces::msg::LocomotionCmd & msg)
  : msg_(msg)
  {}
  Init_LocomotionCmd_twist pose(::tita_locomotion_interfaces::msg::LocomotionCmd::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_LocomotionCmd_twist(msg_);
  }

private:
  ::tita_locomotion_interfaces::msg::LocomotionCmd msg_;
};

class Init_LocomotionCmd_fsm_mode
{
public:
  explicit Init_LocomotionCmd_fsm_mode(::tita_locomotion_interfaces::msg::LocomotionCmd & msg)
  : msg_(msg)
  {}
  Init_LocomotionCmd_pose fsm_mode(::tita_locomotion_interfaces::msg::LocomotionCmd::_fsm_mode_type arg)
  {
    msg_.fsm_mode = std::move(arg);
    return Init_LocomotionCmd_pose(msg_);
  }

private:
  ::tita_locomotion_interfaces::msg::LocomotionCmd msg_;
};

class Init_LocomotionCmd_header
{
public:
  Init_LocomotionCmd_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LocomotionCmd_fsm_mode header(::tita_locomotion_interfaces::msg::LocomotionCmd::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LocomotionCmd_fsm_mode(msg_);
  }

private:
  ::tita_locomotion_interfaces::msg::LocomotionCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_locomotion_interfaces::msg::LocomotionCmd>()
{
  return tita_locomotion_interfaces::msg::builder::Init_LocomotionCmd_header();
}

}  // namespace tita_locomotion_interfaces

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__BUILDER_HPP_
