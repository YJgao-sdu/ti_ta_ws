// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tita_system_interfaces:srv/PowerStateSetSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_STATE_SET_SRV__TRAITS_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_STATE_SET_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tita_system_interfaces/srv/detail/power_state_set_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'power_state_set'
#include "diagnostic_msgs/msg/detail/diagnostic_array__traits.hpp"

namespace tita_system_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PowerStateSetSrv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: power_state_set
  {
    out << "power_state_set: ";
    to_flow_style_yaml(msg.power_state_set, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PowerStateSetSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: power_state_set
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_state_set:\n";
    to_block_style_yaml(msg.power_state_set, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PowerStateSetSrv_Request & msg, bool use_flow_style = false)
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
  const tita_system_interfaces::srv::PowerStateSetSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tita_system_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tita_system_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const tita_system_interfaces::srv::PowerStateSetSrv_Request & msg)
{
  return tita_system_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tita_system_interfaces::srv::PowerStateSetSrv_Request>()
{
  return "tita_system_interfaces::srv::PowerStateSetSrv_Request";
}

template<>
inline const char * name<tita_system_interfaces::srv::PowerStateSetSrv_Request>()
{
  return "tita_system_interfaces/srv/PowerStateSetSrv_Request";
}

template<>
struct has_fixed_size<tita_system_interfaces::srv::PowerStateSetSrv_Request>
  : std::integral_constant<bool, has_fixed_size<diagnostic_msgs::msg::DiagnosticArray>::value> {};

template<>
struct has_bounded_size<tita_system_interfaces::srv::PowerStateSetSrv_Request>
  : std::integral_constant<bool, has_bounded_size<diagnostic_msgs::msg::DiagnosticArray>::value> {};

template<>
struct is_message<tita_system_interfaces::srv::PowerStateSetSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tita_system_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PowerStateSetSrv_Response & msg,
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
  const PowerStateSetSrv_Response & msg,
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

inline std::string to_yaml(const PowerStateSetSrv_Response & msg, bool use_flow_style = false)
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
  const tita_system_interfaces::srv::PowerStateSetSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tita_system_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tita_system_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const tita_system_interfaces::srv::PowerStateSetSrv_Response & msg)
{
  return tita_system_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tita_system_interfaces::srv::PowerStateSetSrv_Response>()
{
  return "tita_system_interfaces::srv::PowerStateSetSrv_Response";
}

template<>
inline const char * name<tita_system_interfaces::srv::PowerStateSetSrv_Response>()
{
  return "tita_system_interfaces/srv/PowerStateSetSrv_Response";
}

template<>
struct has_fixed_size<tita_system_interfaces::srv::PowerStateSetSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tita_system_interfaces::srv::PowerStateSetSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tita_system_interfaces::srv::PowerStateSetSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tita_system_interfaces::srv::PowerStateSetSrv>()
{
  return "tita_system_interfaces::srv::PowerStateSetSrv";
}

template<>
inline const char * name<tita_system_interfaces::srv::PowerStateSetSrv>()
{
  return "tita_system_interfaces/srv/PowerStateSetSrv";
}

template<>
struct has_fixed_size<tita_system_interfaces::srv::PowerStateSetSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<tita_system_interfaces::srv::PowerStateSetSrv_Request>::value &&
    has_fixed_size<tita_system_interfaces::srv::PowerStateSetSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<tita_system_interfaces::srv::PowerStateSetSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<tita_system_interfaces::srv::PowerStateSetSrv_Request>::value &&
    has_bounded_size<tita_system_interfaces::srv::PowerStateSetSrv_Response>::value
  >
{
};

template<>
struct is_service<tita_system_interfaces::srv::PowerStateSetSrv>
  : std::true_type
{
};

template<>
struct is_service_request<tita_system_interfaces::srv::PowerStateSetSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tita_system_interfaces::srv::PowerStateSetSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_STATE_SET_SRV__TRAITS_HPP_
