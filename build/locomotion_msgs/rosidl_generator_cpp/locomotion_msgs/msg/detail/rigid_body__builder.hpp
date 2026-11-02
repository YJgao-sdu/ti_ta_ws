// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from locomotion_msgs:msg/RigidBody.idl
// generated code does not contain a copyright notice

#ifndef LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__BUILDER_HPP_
#define LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "locomotion_msgs/msg/detail/rigid_body__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace locomotion_msgs
{

namespace msg
{

namespace builder
{

class Init_RigidBody_transform
{
public:
  explicit Init_RigidBody_transform(::locomotion_msgs::msg::RigidBody & msg)
  : msg_(msg)
  {}
  ::locomotion_msgs::msg::RigidBody transform(::locomotion_msgs::msg::RigidBody::_transform_type arg)
  {
    msg_.transform = std::move(arg);
    return std::move(msg_);
  }

private:
  ::locomotion_msgs::msg::RigidBody msg_;
};

class Init_RigidBody_inertia
{
public:
  Init_RigidBody_inertia()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RigidBody_transform inertia(::locomotion_msgs::msg::RigidBody::_inertia_type arg)
  {
    msg_.inertia = std::move(arg);
    return Init_RigidBody_transform(msg_);
  }

private:
  ::locomotion_msgs::msg::RigidBody msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::locomotion_msgs::msg::RigidBody>()
{
  return locomotion_msgs::msg::builder::Init_RigidBody_inertia();
}

}  // namespace locomotion_msgs

#endif  // LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__BUILDER_HPP_
