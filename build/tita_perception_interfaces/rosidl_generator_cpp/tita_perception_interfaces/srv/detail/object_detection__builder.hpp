// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_perception_interfaces:srv/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__BUILDER_HPP_
#define TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_perception_interfaces/srv/detail/object_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_perception_interfaces
{

namespace srv
{

namespace builder
{

class Init_ObjectDetection_Request_image
{
public:
  Init_ObjectDetection_Request_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_perception_interfaces::srv::ObjectDetection_Request image(::tita_perception_interfaces::srv::ObjectDetection_Request::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_perception_interfaces::srv::ObjectDetection_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_perception_interfaces::srv::ObjectDetection_Request>()
{
  return tita_perception_interfaces::srv::builder::Init_ObjectDetection_Request_image();
}

}  // namespace tita_perception_interfaces


namespace tita_perception_interfaces
{

namespace srv
{

namespace builder
{

class Init_ObjectDetection_Response_result
{
public:
  Init_ObjectDetection_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_perception_interfaces::srv::ObjectDetection_Response result(::tita_perception_interfaces::srv::ObjectDetection_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_perception_interfaces::srv::ObjectDetection_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_perception_interfaces::srv::ObjectDetection_Response>()
{
  return tita_perception_interfaces::srv::builder::Init_ObjectDetection_Response_result();
}

}  // namespace tita_perception_interfaces

#endif  // TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__BUILDER_HPP_
