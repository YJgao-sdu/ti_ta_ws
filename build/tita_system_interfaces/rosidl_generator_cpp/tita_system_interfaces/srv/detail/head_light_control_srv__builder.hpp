// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_system_interfaces:srv/HeadLightControlSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__HEAD_LIGHT_CONTROL_SRV__BUILDER_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__HEAD_LIGHT_CONTROL_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_system_interfaces/srv/detail/head_light_control_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_HeadLightControlSrv_Request_light_rgbl_value
{
public:
  explicit Init_HeadLightControlSrv_Request_light_rgbl_value(::tita_system_interfaces::srv::HeadLightControlSrv_Request & msg)
  : msg_(msg)
  {}
  ::tita_system_interfaces::srv::HeadLightControlSrv_Request light_rgbl_value(::tita_system_interfaces::srv::HeadLightControlSrv_Request::_light_rgbl_value_type arg)
  {
    msg_.light_rgbl_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::HeadLightControlSrv_Request msg_;
};

class Init_HeadLightControlSrv_Request_is_control
{
public:
  Init_HeadLightControlSrv_Request_is_control()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HeadLightControlSrv_Request_light_rgbl_value is_control(::tita_system_interfaces::srv::HeadLightControlSrv_Request::_is_control_type arg)
  {
    msg_.is_control = std::move(arg);
    return Init_HeadLightControlSrv_Request_light_rgbl_value(msg_);
  }

private:
  ::tita_system_interfaces::srv::HeadLightControlSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::HeadLightControlSrv_Request>()
{
  return tita_system_interfaces::srv::builder::Init_HeadLightControlSrv_Request_is_control();
}

}  // namespace tita_system_interfaces


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_HeadLightControlSrv_Response_success
{
public:
  Init_HeadLightControlSrv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_system_interfaces::srv::HeadLightControlSrv_Response success(::tita_system_interfaces::srv::HeadLightControlSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::HeadLightControlSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::HeadLightControlSrv_Response>()
{
  return tita_system_interfaces::srv::builder::Init_HeadLightControlSrv_Response_success();
}

}  // namespace tita_system_interfaces

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__HEAD_LIGHT_CONTROL_SRV__BUILDER_HPP_
