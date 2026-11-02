// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tita_locomotion_interfaces:msg/MotorsStatus.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__TRAITS_HPP_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tita_locomotion_interfaces/msg/detail/motors_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace tita_locomotion_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorsStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: key
  {
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << ", ";
  }

  // member: value
  {
    if (msg.value.size() == 0) {
      out << "value: []";
    } else {
      out << "value: [";
      size_t pending_items = msg.value.size();
      for (auto item : msg.value) {
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
  const MotorsStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: key
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "key: ";
    rosidl_generator_traits::value_to_yaml(msg.key, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.value.size() == 0) {
      out << "value: []\n";
    } else {
      out << "value:\n";
      for (auto item : msg.value) {
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

inline std::string to_yaml(const MotorsStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tita_locomotion_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tita_locomotion_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tita_locomotion_interfaces::msg::MotorsStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  tita_locomotion_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tita_locomotion_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tita_locomotion_interfaces::msg::MotorsStatus & msg)
{
  return tita_locomotion_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tita_locomotion_interfaces::msg::MotorsStatus>()
{
  return "tita_locomotion_interfaces::msg::MotorsStatus";
}

template<>
inline const char * name<tita_locomotion_interfaces::msg::MotorsStatus>()
{
  return "tita_locomotion_interfaces/msg/MotorsStatus";
}

template<>
struct has_fixed_size<tita_locomotion_interfaces::msg::MotorsStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tita_locomotion_interfaces::msg::MotorsStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tita_locomotion_interfaces::msg::MotorsStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__TRAITS_HPP_
