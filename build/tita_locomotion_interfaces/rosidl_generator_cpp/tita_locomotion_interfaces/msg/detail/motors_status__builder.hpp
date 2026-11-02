// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_locomotion_interfaces:msg/MotorsStatus.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__BUILDER_HPP_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_locomotion_interfaces/msg/detail/motors_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_locomotion_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorsStatus_value
{
public:
  explicit Init_MotorsStatus_value(::tita_locomotion_interfaces::msg::MotorsStatus & msg)
  : msg_(msg)
  {}
  ::tita_locomotion_interfaces::msg::MotorsStatus value(::tita_locomotion_interfaces::msg::MotorsStatus::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_locomotion_interfaces::msg::MotorsStatus msg_;
};

class Init_MotorsStatus_key
{
public:
  explicit Init_MotorsStatus_key(::tita_locomotion_interfaces::msg::MotorsStatus & msg)
  : msg_(msg)
  {}
  Init_MotorsStatus_value key(::tita_locomotion_interfaces::msg::MotorsStatus::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_MotorsStatus_value(msg_);
  }

private:
  ::tita_locomotion_interfaces::msg::MotorsStatus msg_;
};

class Init_MotorsStatus_header
{
public:
  Init_MotorsStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorsStatus_key header(::tita_locomotion_interfaces::msg::MotorsStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorsStatus_key(msg_);
  }

private:
  ::tita_locomotion_interfaces::msg::MotorsStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_locomotion_interfaces::msg::MotorsStatus>()
{
  return tita_locomotion_interfaces::msg::builder::Init_MotorsStatus_header();
}

}  // namespace tita_locomotion_interfaces

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__BUILDER_HPP_
