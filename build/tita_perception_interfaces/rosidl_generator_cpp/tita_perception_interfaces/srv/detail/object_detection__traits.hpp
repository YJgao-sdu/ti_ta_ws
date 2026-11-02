// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tita_perception_interfaces:srv/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__TRAITS_HPP_
#define TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tita_perception_interfaces/srv/detail/object_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace tita_perception_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ObjectDetection_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: image
  {
    out << "image: ";
    to_flow_style_yaml(msg.image, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectDetection_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image:\n";
    to_block_style_yaml(msg.image, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectDetection_Request & msg, bool use_flow_style = false)
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

}  // namespace tita_perception_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tita_perception_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tita_perception_interfaces::srv::ObjectDetection_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tita_perception_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tita_perception_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const tita_perception_interfaces::srv::ObjectDetection_Request & msg)
{
  return tita_perception_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tita_perception_interfaces::srv::ObjectDetection_Request>()
{
  return "tita_perception_interfaces::srv::ObjectDetection_Request";
}

template<>
inline const char * name<tita_perception_interfaces::srv::ObjectDetection_Request>()
{
  return "tita_perception_interfaces/srv/ObjectDetection_Request";
}

template<>
struct has_fixed_size<tita_perception_interfaces::srv::ObjectDetection_Request>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<tita_perception_interfaces::srv::ObjectDetection_Request>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<tita_perception_interfaces::srv::ObjectDetection_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
#include "tita_perception_interfaces/msg/detail/bounding_box_array__traits.hpp"

namespace tita_perception_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ObjectDetection_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectDetection_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectDetection_Response & msg, bool use_flow_style = false)
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

}  // namespace tita_perception_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tita_perception_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tita_perception_interfaces::srv::ObjectDetection_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tita_perception_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tita_perception_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const tita_perception_interfaces::srv::ObjectDetection_Response & msg)
{
  return tita_perception_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tita_perception_interfaces::srv::ObjectDetection_Response>()
{
  return "tita_perception_interfaces::srv::ObjectDetection_Response";
}

template<>
inline const char * name<tita_perception_interfaces::srv::ObjectDetection_Response>()
{
  return "tita_perception_interfaces/srv/ObjectDetection_Response";
}

template<>
struct has_fixed_size<tita_perception_interfaces::srv::ObjectDetection_Response>
  : std::integral_constant<bool, has_fixed_size<tita_perception_interfaces::msg::BoundingBoxArray>::value> {};

template<>
struct has_bounded_size<tita_perception_interfaces::srv::ObjectDetection_Response>
  : std::integral_constant<bool, has_bounded_size<tita_perception_interfaces::msg::BoundingBoxArray>::value> {};

template<>
struct is_message<tita_perception_interfaces::srv::ObjectDetection_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tita_perception_interfaces::srv::ObjectDetection>()
{
  return "tita_perception_interfaces::srv::ObjectDetection";
}

template<>
inline const char * name<tita_perception_interfaces::srv::ObjectDetection>()
{
  return "tita_perception_interfaces/srv/ObjectDetection";
}

template<>
struct has_fixed_size<tita_perception_interfaces::srv::ObjectDetection>
  : std::integral_constant<
    bool,
    has_fixed_size<tita_perception_interfaces::srv::ObjectDetection_Request>::value &&
    has_fixed_size<tita_perception_interfaces::srv::ObjectDetection_Response>::value
  >
{
};

template<>
struct has_bounded_size<tita_perception_interfaces::srv::ObjectDetection>
  : std::integral_constant<
    bool,
    has_bounded_size<tita_perception_interfaces::srv::ObjectDetection_Request>::value &&
    has_bounded_size<tita_perception_interfaces::srv::ObjectDetection_Response>::value
  >
{
};

template<>
struct is_service<tita_perception_interfaces::srv::ObjectDetection>
  : std::true_type
{
};

template<>
struct is_service_request<tita_perception_interfaces::srv::ObjectDetection_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tita_perception_interfaces::srv::ObjectDetection_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__TRAITS_HPP_
