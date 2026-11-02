// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_system_interfaces:srv/TailLightControlSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__TAIL_LIGHT_CONTROL_SRV__BUILDER_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__TAIL_LIGHT_CONTROL_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_system_interfaces/srv/detail/tail_light_control_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_TailLightControlSrv_Request_light_rgbl_value
{
public:
  explicit Init_TailLightControlSrv_Request_light_rgbl_value(::tita_system_interfaces::srv::TailLightControlSrv_Request & msg)
  : msg_(msg)
  {}
  ::tita_system_interfaces::srv::TailLightControlSrv_Request light_rgbl_value(::tita_system_interfaces::srv::TailLightControlSrv_Request::_light_rgbl_value_type arg)
  {
    msg_.light_rgbl_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::TailLightControlSrv_Request msg_;
};

class Init_TailLightControlSrv_Request_is_control
{
public:
  Init_TailLightControlSrv_Request_is_control()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TailLightControlSrv_Request_light_rgbl_value is_control(::tita_system_interfaces::srv::TailLightControlSrv_Request::_is_control_type arg)
  {
    msg_.is_control = std::move(arg);
    return Init_TailLightControlSrv_Request_light_rgbl_value(msg_);
  }

private:
  ::tita_system_interfaces::srv::TailLightControlSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::TailLightControlSrv_Request>()
{
  return tita_system_interfaces::srv::builder::Init_TailLightControlSrv_Request_is_control();
}

}  // namespace tita_system_interfaces


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_TailLightControlSrv_Response_success
{
public:
  Init_TailLightControlSrv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_system_interfaces::srv::TailLightControlSrv_Response success(::tita_system_interfaces::srv::TailLightControlSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::TailLightControlSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::TailLightControlSrv_Response>()
{
  return tita_system_interfaces::srv::builder::Init_TailLightControlSrv_Response_success();
}

}  // namespace tita_system_interfaces

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__TAIL_LIGHT_CONTROL_SRV__BUILDER_HPP_
