// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tita_system_interfaces:srv/PowerSelfTestSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__BUILDER_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tita_system_interfaces/srv/detail/power_self_test_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_PowerSelfTestSrv_Request_power_self_test
{
public:
  Init_PowerSelfTestSrv_Request_power_self_test()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_system_interfaces::srv::PowerSelfTestSrv_Request power_self_test(::tita_system_interfaces::srv::PowerSelfTestSrv_Request::_power_self_test_type arg)
  {
    msg_.power_self_test = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::PowerSelfTestSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::PowerSelfTestSrv_Request>()
{
  return tita_system_interfaces::srv::builder::Init_PowerSelfTestSrv_Request_power_self_test();
}

}  // namespace tita_system_interfaces


namespace tita_system_interfaces
{

namespace srv
{

namespace builder
{

class Init_PowerSelfTestSrv_Response_success
{
public:
  Init_PowerSelfTestSrv_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tita_system_interfaces::srv::PowerSelfTestSrv_Response success(::tita_system_interfaces::srv::PowerSelfTestSrv_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tita_system_interfaces::srv::PowerSelfTestSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tita_system_interfaces::srv::PowerSelfTestSrv_Response>()
{
  return tita_system_interfaces::srv::builder::Init_PowerSelfTestSrv_Response_success();
}

}  // namespace tita_system_interfaces

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__BUILDER_HPP_
