// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tita_locomotion_interfaces:msg/LocomotionCmd.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__TRAITS_HPP_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tita_locomotion_interfaces/msg/detail/locomotion_cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace tita_locomotion_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LocomotionCmd & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: fsm_mode
  {
    out << "fsm_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.fsm_mode, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: twist
  {
    out << "twist: ";
    to_flow_style_yaml(msg.twist, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LocomotionCmd & msg,
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

  // member: fsm_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fsm_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.fsm_mode, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: twist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist:\n";
    to_block_style_yaml(msg.twist, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LocomotionCmd & msg, bool use_flow_style = false)
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
  const tita_locomotion_interfaces::msg::LocomotionCmd & msg,
  std::ostream & out, size_t indentation = 0)
{
  tita_locomotion_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tita_locomotion_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tita_locomotion_interfaces::msg::LocomotionCmd & msg)
{
  return tita_locomotion_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tita_locomotion_interfaces::msg::LocomotionCmd>()
{
  return "tita_locomotion_interfaces::msg::LocomotionCmd";
}

template<>
inline const char * name<tita_locomotion_interfaces::msg::LocomotionCmd>()
{
  return "tita_locomotion_interfaces/msg/LocomotionCmd";
}

template<>
struct has_fixed_size<tita_locomotion_interfaces::msg::LocomotionCmd>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tita_locomotion_interfaces::msg::LocomotionCmd>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tita_locomotion_interfaces::msg::LocomotionCmd>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__TRAITS_HPP_
