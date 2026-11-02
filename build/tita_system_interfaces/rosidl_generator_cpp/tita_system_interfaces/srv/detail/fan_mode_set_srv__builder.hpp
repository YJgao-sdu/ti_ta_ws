// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_system_interfaces:srv/FanModeSetSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__FAN_MODE_SET_SRV__BUILDER_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__FAN_MODE_SET_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_system_interfaces/srv/detail/fan_mode_set_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_FanModeSetSrv_Request_fan_mode
{
public:
  Init_FanModeSetSrv_Request_fan_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_system_interfaces::srv::FanModeSetSrv_Request fan_mode(::tita_system_interfaces::srv::FanModeSetSrv_Request::_fan_mode_type arg)
  {
    msg_.fan_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::FanModeSetSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::FanModeSetSrv_Request>()
{
  return tita_system_interfaces::srv::builder::Init_FanModeSetSrv_Request_fan_mode();
}

}  // namespace tita_system_interfaces


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_FanModeSetSrv_Response_success
{
public:
  Init_FanModeSetSrv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_system_interfaces::srv::FanModeSetSrv_Response success(::tita_system_interfaces::srv::FanModeSetSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::FanModeSetSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::FanModeSetSrv_Response>()
{
  return tita_system_interfaces::srv::builder::Init_FanModeSetSrv_Response_success();
}

}  // namespace tita_system_interfaces

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__FAN_MODE_SET_SRV__BUILDER_HPP_
