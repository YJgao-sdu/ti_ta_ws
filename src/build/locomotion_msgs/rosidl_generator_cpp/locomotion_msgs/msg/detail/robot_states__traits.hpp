// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from locomotion_msgs:msg/RobotStates.idl
// generated code does not contain a copyright notice

#ifndef LOCOMOTION_MSGS__MSG__DETAIL__ROBOT_STATES__TRAITS_HPP_
#define LOCOMOTION_MSGS__MSG__DETAIL__ROBOT_STATES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "locomotion_msgs/msg/detail/robot_states__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'twist_linear'
// Member 'twist_linear_int'
// Member 'twist_angular'
// Member 'twist_angular_int'
// Member 'pose_position'
// Member 'pose_position_dot'
// Member 'pose_rpy'
// Member 'pose_rpy_dot'
// Member 'com_position_relative'
// Member 'com_velocity_relative'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace locomotion_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStates & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: fsm_state_name
  {
    out << "fsm_state_name: ";
    rosidl_generator_traits::value_to_yaml(msg.fsm_state_name, out);
    out << ", ";
  }

  // member: twist_linear
  {
    out << "twist_linear: ";
    to_flow_style_yaml(msg.twist_linear, out);
    out << ", ";
  }

  // member: twist_linear_int
  {
    out << "twist_linear_int: ";
    to_flow_style_yaml(msg.twist_linear_int, out);
    out << ", ";
  }

  // member: twist_angular
  {
    out << "twist_angular: ";
    to_flow_style_yaml(msg.twist_angular, out);
    out << ", ";
  }

  // member: twist_angular_int
  {
    out << "twist_angular_int: ";
    to_flow_style_yaml(msg.twist_angular_int, out);
    out << ", ";
  }

  // member: pose_position
  {
    out << "pose_position: ";
    to_flow_style_yaml(msg.pose_position, out);
    out << ", ";
  }

  // member: pose_position_dot
  {
    out << "pose_position_dot: ";
    to_flow_style_yaml(msg.pose_position_dot, out);
    out << ", ";
  }

  // member: pose_rpy
  {
    out << "pose_rpy: ";
    to_flow_style_yaml(msg.pose_rpy, out);
    out << ", ";
  }

  // member: pose_rpy_dot
  {
    out << "pose_rpy_dot: ";
    to_flow_style_yaml(msg.pose_rpy_dot, out);
    out << ", ";
  }

  // member: two_wheel_distance
  {
    out << "two_wheel_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.two_wheel_distance, out);
    out << ", ";
  }

  // member: two_wheel_distance_dot
  {
    out << "two_wheel_distance_dot: ";
    rosidl_generator_traits::value_to_yaml(msg.two_wheel_distance_dot, out);
    out << ", ";
  }

  // member: com_position_relative
  {
    out << "com_position_relative: ";
    to_flow_style_yaml(msg.com_position_relative, out);
    out << ", ";
  }

  // member: com_velocity_relative
  {
    out << "com_velocity_relative: ";
    to_flow_style_yaml(msg.com_velocity_relative, out);
    out << ", ";
  }

  // member: joint_positions
  {
    if (msg.joint_positions.size() == 0) {
      out << "joint_positions: []";
    } else {
      out << "joint_positions: [";
      size_t pending_items = msg.joint_positions.size();
      for (auto item : msg.joint_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: joint_velocities
  {
    if (msg.joint_velocities.size() == 0) {
      out << "joint_velocities: []";
    } else {
      out << "joint_velocities: [";
      size_t pending_items = msg.joint_velocities.size();
      for (auto item : msg.joint_velocities) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: joint_torques
  {
    if (msg.joint_torques.size() == 0) {
      out << "joint_torques: []";
    } else {
      out << "joint_torques: [";
      size_t pending_items = msg.joint_torques.size();
      for (auto item : msg.joint_torques) {
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
  const RobotStates & msg,
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

  // member: fsm_state_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fsm_state_name: ";
    rosidl_generator_traits::value_to_yaml(msg.fsm_state_name, out);
    out << "\n";
  }

  // member: twist_linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist_linear:\n";
    to_block_style_yaml(msg.twist_linear, out, indentation + 2);
  }

  // member: twist_linear_int
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist_linear_int:\n";
    to_block_style_yaml(msg.twist_linear_int, out, indentation + 2);
  }

  // member: twist_angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist_angular:\n";
    to_block_style_yaml(msg.twist_angular, out, indentation + 2);
  }

  // member: twist_angular_int
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist_angular_int:\n";
    to_block_style_yaml(msg.twist_angular_int, out, indentation + 2);
  }

  // member: pose_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_position:\n";
    to_block_style_yaml(msg.pose_position, out, indentation + 2);
  }

  // member: pose_position_dot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_position_dot:\n";
    to_block_style_yaml(msg.pose_position_dot, out, indentation + 2);
  }

  // member: pose_rpy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_rpy:\n";
    to_block_style_yaml(msg.pose_rpy, out, indentation + 2);
  }

  // member: pose_rpy_dot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_rpy_dot:\n";
    to_block_style_yaml(msg.pose_rpy_dot, out, indentation + 2);
  }

  // member: two_wheel_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "two_wheel_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.two_wheel_distance, out);
    out << "\n";
  }

  // member: two_wheel_distance_dot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "two_wheel_distance_dot: ";
    rosidl_generator_traits::value_to_yaml(msg.two_wheel_distance_dot, out);
    out << "\n";
  }

  // member: com_position_relative
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "com_position_relative:\n";
    to_block_style_yaml(msg.com_position_relative, out, indentation + 2);
  }

  // member: com_velocity_relative
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "com_velocity_relative:\n";
    to_block_style_yaml(msg.com_velocity_relative, out, indentation + 2);
  }

  // member: joint_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_positions.size() == 0) {
      out << "joint_positions: []\n";
    } else {
      out << "joint_positions:\n";
      for (auto item : msg.joint_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: joint_velocities
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_velocities.size() == 0) {
      out << "joint_velocities: []\n";
    } else {
      out << "joint_velocities:\n";
      for (auto item : msg.joint_velocities) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: joint_torques
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_torques.size() == 0) {
      out << "joint_torques: []\n";
    } else {
      out << "joint_torques:\n";
      for (auto item : msg.joint_torques) {
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

inline std::string to_yaml(const RobotStates & msg, bool use_flow_style = false)
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
  const locomotion_msgs::msg::RobotStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  locomotion_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use locomotion_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const locomotion_msgs::msg::RobotStates & msg)
{
  return locomotion_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<locomotion_msgs::msg::RobotStates>()
{
  return "locomotion_msgs::msg::RobotStates";
}

template<>
inline const char * name<locomotion_msgs::msg::RobotStates>()
{
  return "locomotion_msgs/msg/RobotStates";
}

template<>
struct has_fixed_size<locomotion_msgs::msg::RobotStates>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<locomotion_msgs::msg::RobotStates>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<locomotion_msgs::msg::RobotStates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LOCOMOTION_MSGS__MSG__DETAIL__ROBOT_STATES__TRAITS_HPP_
