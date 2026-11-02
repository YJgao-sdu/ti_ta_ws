// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tita_system_interfaces:srv/PowerSelfTestSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__TRAITS_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tita_system_interfaces/srv/detail/power_self_test_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'power_self_test'
#include "diagnostic_msgs/msg/detail/diagnostic_array__traits.hpp"

namespace tita_system_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PowerSelfTestSrv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: power_self_test
  {
    out << "power_self_test: ";
    to_flow_style_yaml(msg.power_self_test, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PowerSelfTestSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: power_self_test
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_self_test:\n";
    to_block_style_yaml(msg.power_self_test, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PowerSelfTestSrv_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tita_system_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tita_system_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tita_system_interfaces::srv::PowerSelfTestSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tita_system_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tita_system_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const tita_system_interfaces::srv::PowerSelfTestSrv_Request & msg)
{
  return tita_system_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tita_system_interfaces::srv::PowerSelfTestSrv_Request>()
{
  return "tita_system_interfaces::srv::PowerSelfTestSrv_Request";
}

template<>
inline const char * name<tita_system_interfaces::srv::PowerSelfTestSrv_Request>()
{
  return "tita_system_interfaces/srv/PowerSelfTestSrv_Request";
}

template<>
struct has_fixed_size<tita_system_interfaces::srv::PowerSelfTestSrv_Request>
  : std::integral_constant<bool, has_fixed_size<diagnostic_msgs::msg::DiagnosticArray>::value> {};

template<>
struct has_bounded_size<tita_system_interfaces::srv::PowerSelfTestSrv_Request>
  : std::integral_constant<bool, has_bounded_size<diagnostic_msgs::msg::DiagnosticArray>::value> {};

template<>
struct is_message<tita_system_interfaces::srv::PowerSelfTestSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tita_system_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PowerSelfTestSrv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PowerSelfTestSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PowerSelfTestSrv_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tita_system_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tita_system_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tita_system_interfaces::srv::PowerSelfTestSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tita_system_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tita_system_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const tita_system_interfaces::srv::PowerSelfTestSrv_Response & msg)
{
  return tita_system_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tita_system_interfaces::srv::PowerSelfTestSrv_Response>()
{
  return "tita_system_interfaces::srv::PowerSelfTestSrv_Response";
}

template<>
inline const char * name<tita_system_interfaces::srv::PowerSelfTestSrv_Response>()
{
  return "tita_system_interfaces/srv/PowerSelfTestSrv_Response";
}

template<>
struct has_fixed_size<tita_system_interfaces::srv::PowerSelfTestSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tita_system_interfaces::srv::PowerSelfTestSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tita_system_interfaces::srv::PowerSelfTestSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tita_system_interfaces::srv::PowerSelfTestSrv>()
{
  return "tita_system_interfaces::srv::PowerSelfTestSrv";
}

template<>
inline const char * name<tita_system_interfaces::srv::PowerSelfTestSrv>()
{
  return "tita_system_interfaces/srv/PowerSelfTestSrv";
}

template<>
struct has_fixed_size<tita_system_interfaces::srv::PowerSelfTestSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<tita_system_interfaces::srv::PowerSelfTestSrv_Request>::value &&
    has_fixed_size<tita_system_interfaces::srv::PowerSelfTestSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<tita_system_interfaces::srv::PowerSelfTestSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<tita_system_interfaces::srv::PowerSelfTestSrv_Request>::value &&
    has_bounded_size<tita_system_interfaces::srv::PowerSelfTestSrv_Response>::value
  >
{
};

template<>
struct is_service<tita_system_interfaces::srv::PowerSelfTestSrv>
  : std::true_type
{
};

template<>
struct is_service_request<tita_system_interfaces::srv::PowerSelfTestSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tita_system_interfaces::srv::PowerSelfTestSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__TRAITS_HPP_
