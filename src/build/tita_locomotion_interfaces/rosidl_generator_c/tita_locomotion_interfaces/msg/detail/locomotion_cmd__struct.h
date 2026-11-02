// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tita_locomotion_interfaces:msg/LocomotionCmd.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__STRUCT_H_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__STRUCT_H_

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
// Member 'fsm_mode'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/LocomotionCmd in the package tita_locomotion_interfaces.
/**
  * Command manager send msg to locomotion unit.
 */
typedef struct tita_locomotion_interfaces__msg__LocomotionCmd
{
  std_msgs__msg__Header header;
  /// "stand" "jump" "die"
  rosidl_runtime_c__String fsm_mode;
  /// Robot body pose
  geometry_msgs__msg__Pose pose;
  /// Speed control of robot chassis
  geometry_msgs__msg__Twist twist;
} tita_locomotion_interfaces__msg__LocomotionCmd;

// Struct for a sequence of tita_locomotion_interfaces__msg__LocomotionCmd.
typedef struct tita_locomotion_interfaces__msg__LocomotionCmd__Sequence
{
  tita_locomotion_interfaces__msg__LocomotionCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_locomotion_interfaces__msg__LocomotionCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__STRUCT_H_
