// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tita_system_interfaces:srv/HeadLightControlSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__HEAD_LIGHT_CONTROL_SRV__TRAITS_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__HEAD_LIGHT_CONTROL_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tita_system_interfaces/srv/detail/head_light_control_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tita_system_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const HeadLightControlSrv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_control
  {
    out << "is_control: ";
    rosidl_generator_traits::value_to_yaml(msg.is_control, out);
    out << ", ";
  }

  // member: light_rgbl_value
  {
    if (msg.light_rgbl_value.size() == 0) {
      out << "light_rgbl_value: []";
    } else {
      out << "light_rgbl_value: [";
      size_t pending_items = msg.light_rgbl_value.size();
      for (auto item : msg.light_rgbl_value) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HeadLightControlSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_control
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_control: ";
    rosidl_generator_traits::value_to_yaml(msg.is_control, out);
    out << "\n";
  }

  // member: light_rgbl_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.light_rgbl_value.size() == 0) {
      out << "light_rgbl_value: []\n";
    } else {
      out << "light_rgbl_value:\n";
      for (auto item : msg.light_rgbl_value) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HeadLightControlSrv_Request & msg, bool use_flow_style = false)
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
  const tita_system_interfaces::srv::HeadLightControlSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tita_system_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tita_system_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const tita_system_interfaces::srv::HeadLightControlSrv_Request & msg)
{
  return tita_system_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tita_system_interfaces::srv::HeadLightControlSrv_Request>()
{
  return "tita_system_interfaces::srv::HeadLightControlSrv_Request";
}

template<>
inline const char * name<tita_system_interfaces::srv::HeadLightControlSrv_Request>()
{
  return "tita_system_interfaces/srv/HeadLightControlSrv_Request";
}

template<>
struct has_fixed_size<tita_system_interfaces::srv::HeadLightControlSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tita_system_interfaces::srv::HeadLightControlSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tita_system_interfaces::srv::HeadLightControlSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tita_system_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const HeadLightControlSrv_Response & msg,
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
  const HeadLightControlSrv_Response & msg,
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

inline std::string to_yaml(const HeadLightControlSrv_Response & msg, bool use_flow_style = false)
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
  const tita_system_interfaces::srv::HeadLightControlSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tita_system_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tita_system_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const tita_system_interfaces::srv::HeadLightControlSrv_Response & msg)
{
  return tita_system_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tita_system_interfaces::srv::HeadLightControlSrv_Response>()
{
  return "tita_system_interfaces::srv::HeadLightControlSrv_Response";
}

template<>
inline const char * name<tita_system_interfaces::srv::HeadLightControlSrv_Response>()
{
  return "tita_system_interfaces/srv/HeadLightControlSrv_Response";
}

template<>
struct has_fixed_size<tita_system_interfaces::srv::HeadLightControlSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tita_system_interfaces::srv::HeadLightControlSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tita_system_interfaces::srv::HeadLightControlSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tita_system_interfaces::srv::HeadLightControlSrv>()
{
  return "tita_system_interfaces::srv::HeadLightControlSrv";
}

template<>
inline const char * name<tita_system_interfaces::srv::HeadLightControlSrv>()
{
  return "tita_system_interfaces/srv/HeadLightControlSrv";
}

template<>
struct has_fixed_size<tita_system_interfaces::srv::HeadLightControlSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<tita_system_interfaces::srv::HeadLightControlSrv_Request>::value &&
    has_fixed_size<tita_system_interfaces::srv::HeadLightControlSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<tita_system_interfaces::srv::HeadLightControlSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<tita_system_interfaces::srv::HeadLightControlSrv_Request>::value &&
    has_bounded_size<tita_system_interfaces::srv::HeadLightControlSrv_Response>::value
  >
{
};

template<>
struct is_service<tita_system_interfaces::srv::HeadLightControlSrv>
  : std::true_type
{
};

template<>
struct is_service_request<tita_system_interfaces::srv::HeadLightControlSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tita_system_interfaces::srv::HeadLightControlSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__HEAD_LIGHT_CONTROL_SRV__TRAITS_HPP_
