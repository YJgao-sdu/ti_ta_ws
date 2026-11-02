// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_perception_interfaces:msg/BoundingBoxArray.idl
// generated code does not contain a copyright notice

#ifndef TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__BUILDER_HPP_
#define TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_perception_interfaces/msg/detail/bounding_box_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_perception_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoundingBoxArray_boxes
{
public:
  explicit Init_BoundingBoxArray_boxes(::tita_perception_interfaces::msg::BoundingBoxArray & msg)
  : msg_(msg)
  {}
  ::tita_perception_interfaces::msg::BoundingBoxArray boxes(::tita_perception_interfaces::msg::BoundingBoxArray::_boxes_type arg)
  {
    msg_.boxes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_perception_interfaces::msg::BoundingBoxArray msg_;
};

class Init_BoundingBoxArray_header
{
public:
  Init_BoundingBoxArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBoxArray_boxes header(::tita_perception_interfaces::msg::BoundingBoxArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BoundingBoxArray_boxes(msg_);
  }

private:
  ::tita_perception_interfaces::msg::BoundingBoxArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_perception_interfaces::msg::BoundingBoxArray>()
{
  return tita_perception_interfaces::msg::builder::Init_BoundingBoxArray_header();
}

}  // namespace tita_perception_interfaces

#endif  // TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__BUILDER_HPP_
