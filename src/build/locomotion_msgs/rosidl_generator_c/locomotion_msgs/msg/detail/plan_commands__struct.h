// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from locomotion_msgs:msg/PlanCommands.idl
// generated code does not contain a copyright notice

#ifndef LOCOMOTION_MSGS__MSG__DETAIL__PLAN_COMMANDS__STRUCT_H_
#define LOCOMOTION_MSGS__MSG__DETAIL__PLAN_COMMANDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'fsm_state_name'
#include "rosidl_runtime_c/string.h"
// Member 'twist_linear'
// Member 'twist_linear_int'
// Member 'twist_angular'
// Member 'twist_angular_int'
// Member 'pose_position'
// Member 'pose_position_dot'
// Member 'pose_rpy'
// Member 'pose_rpy_dot'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'joint_positions'
// Member 'joint_velocities'
// Member 'joint_torques'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PlanCommands in the package locomotion_msgs.
typedef struct locomotion_msgs__msg__PlanCommands
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String fsm_state_name;
  geometry_msgs__msg__Vector3 twist_linear;
  geometry_msgs__msg__Vector3 twist_linear_int;
  geometry_msgs__msg__Vector3 twist_angular;
  geometry_msgs__msg__Vector3 twist_angular_int;
  geometry_msgs__msg__Vector3 pose_position;
  geometry_msgs__msg__Vector3 pose_position_dot;
  geometry_msgs__msg__Vector3 pose_rpy;
  geometry_msgs__msg__Vector3 pose_rpy_dot;
  double two_wheel_distance;
  double two_wheel_distance_dot;
  rosidl_runtime_c__double__Sequence joint_positions;
  rosidl_runtime_c__double__Sequence joint_velocities;
  rosidl_runtime_c__double__Sequence joint_torques;
} locomotion_msgs__msg__PlanCommands;

// Struct for a sequence of locomotion_msgs__msg__PlanCommands.
typedef struct locomotion_msgs__msg__PlanCommands__Sequence
{
  locomotion_msgs__msg__PlanCommands * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} locomotion_msgs__msg__PlanCommands__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LOCOMOTION_MSGS__MSG__DETAIL__PLAN_COMMANDS__STRUCT_H_
