// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_system_interfaces:srv/PowerHeartBeatSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_HEART_BEAT_SRV__BUILDER_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_HEART_BEAT_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_system_interfaces/srv/detail/power_heart_beat_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_PowerHeartBeatSrv_Request_power_heart_beat
{
public:
  Init_PowerHeartBeatSrv_Request_power_heart_beat()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_system_interfaces::srv::PowerHeartBeatSrv_Request power_heart_beat(::tita_system_interfaces::srv::PowerHeartBeatSrv_Request::_power_heart_beat_type arg)
  {
    msg_.power_heart_beat = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::PowerHeartBeatSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::PowerHeartBeatSrv_Request>()
{
  return tita_system_interfaces::srv::builder::Init_PowerHeartBeatSrv_Request_power_heart_beat();
}

}  // namespace tita_system_interfaces


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_PowerHeartBeatSrv_Response_success
{
public:
  Init_PowerHeartBeatSrv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_system_interfaces::srv::PowerHeartBeatSrv_Response success(::tita_system_interfaces::srv::PowerHeartBeatSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::PowerHeartBeatSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::PowerHeartBeatSrv_Response>()
{
  return tita_system_interfaces::srv::builder::Init_PowerHeartBeatSrv_Response_success();
}

}  // namespace tita_system_interfaces

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_HEART_BEAT_SRV__BUILDER_HPP_
