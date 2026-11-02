// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_perception_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
#define TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_perception_interfaces/msg/detail/bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoundingBox_label
{
public:
  explicit Init_BoundingBox_label(::tita_perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  ::tita_perception_interfaces::msg::BoundingBox label(::tita_perception_interfaces::msg::BoundingBox::_label_type arg)
  {
    msg_.label = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_y_max
{
public:
  explicit Init_BoundingBox_y_max(::tita_perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_label y_max(::tita_perception_interfaces::msg::BoundingBox::_y_max_type arg)
  {
    msg_.y_max = std::move(arg);
    return Init_BoundingBox_label(msg_);
  }

private:
  ::tita_perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_x_max
{
public:
  explicit Init_BoundingBox_x_max(::tita_perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_y_max x_max(::tita_perception_interfaces::msg::BoundingBox::_x_max_type arg)
  {
    msg_.x_max = std::move(arg);
    return Init_BoundingBox_y_max(msg_);
  }

private:
  ::tita_perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_y_min
{
public:
  explicit Init_BoundingBox_y_min(::tita_perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_x_max y_min(::tita_perception_interfaces::msg::BoundingBox::_y_min_type arg)
  {
    msg_.y_min = std::move(arg);
    return Init_BoundingBox_x_max(msg_);
  }

private:
  ::tita_perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_x_min
{
public:
  explicit Init_BoundingBox_x_min(::tita_perception_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_y_min x_min(::tita_perception_interfaces::msg::BoundingBox::_x_min_type arg)
  {
    msg_.x_min = std::move(arg);
    return Init_BoundingBox_y_min(msg_);
  }

private:
  ::tita_perception_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_header
{
public:
  Init_BoundingBox_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox_x_min header(::tita_perception_interfaces::msg::BoundingBox::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BoundingBox_x_min(msg_);
  }

private:
  ::tita_perception_interfaces::msg::BoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_perception_interfaces::msg::BoundingBox>()
{
  return tita_perception_interfaces::msg::builder::Init_BoundingBox_header();
}

}  // namespace tita_perception_interfaces

#endif  // TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
