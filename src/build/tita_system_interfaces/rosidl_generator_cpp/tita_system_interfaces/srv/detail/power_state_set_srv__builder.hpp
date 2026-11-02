// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_system_interfaces:srv/PowerStateSetSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_STATE_SET_SRV__BUILDER_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_STATE_SET_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_system_interfaces/srv/detail/power_state_set_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_PowerStateSetSrv_Request_power_state_set
{
public:
  Init_PowerStateSetSrv_Request_power_state_set()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_system_interfaces::srv::PowerStateSetSrv_Request power_state_set(::tita_system_interfaces::srv::PowerStateSetSrv_Request::_power_state_set_type arg)
  {
    msg_.power_state_set = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::PowerStateSetSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::PowerStateSetSrv_Request>()
{
  return tita_system_interfaces::srv::builder::Init_PowerStateSetSrv_Request_power_state_set();
}

}  // namespace tita_system_interfaces


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_PowerStateSetSrv_Response_success
{
public:
  Init_PowerStateSetSrv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_system_interfaces::srv::PowerStateSetSrv_Response success(::tita_system_interfaces::srv::PowerStateSetSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::PowerStateSetSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::PowerStateSetSrv_Response>()
{
  return tita_system_interfaces::srv::builder::Init_PowerStateSetSrv_Response_success();
}

}  // namespace tita_system_interfaces

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_STATE_SET_SRV__BUILDER_HPP_
