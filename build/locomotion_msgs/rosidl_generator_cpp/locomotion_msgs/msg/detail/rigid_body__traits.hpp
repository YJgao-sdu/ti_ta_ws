// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from locomotion_msgs:msg/RigidBody.idl
// generated code does not contain a copyright notice

#ifndef LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__TRAITS_HPP_
#define LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "locomotion_msgs/msg/detail/rigid_body__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'inertia'
#include "geometry_msgs/msg/detail/inertia__traits.hpp"
// Member 'transform'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace locomotion_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RigidBody & msg,
  std::ostream & out)
{
  out << "{";
  // member: inertia
  {
    out << "inertia: ";
    to_flow_style_yaml(msg.inertia, out);
    out << ", ";
  }

  // member: transform
  {
    out << "transform: ";
    to_flow_style_yaml(msg.transform, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RigidBody & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: inertia
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inertia:\n";
    to_block_style_yaml(msg.inertia, out, indentation + 2);
  }

  // member: transform
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "transform:\n";
    to_block_style_yaml(msg.transform, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RigidBody & msg, bool use_flow_style = false)
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

}  // namespace locomotion_msgs

namespace rosidl_generator_traits
{

[[deprecated("use locomotion_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const locomotion_msgs::msg::RigidBody & msg,
  std::ostream & out, size_t indentation = 0)
{
  locomotion_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use locomotion_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const locomotion_msgs::msg::RigidBody & msg)
{
  return locomotion_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<locomotion_msgs::msg::RigidBody>()
{
  return "locomotion_msgs::msg::RigidBody";
}

template<>
inline const char * name<locomotion_msgs::msg::RigidBody>()
{
  return "locomotion_msgs/msg/RigidBody";
}

template<>
struct has_fixed_size<locomotion_msgs::msg::RigidBody>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Inertia>::value && has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<locomotion_msgs::msg::RigidBody>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Inertia>::value && has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<locomotion_msgs::msg::RigidBody>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__TRAITS_HPP_
