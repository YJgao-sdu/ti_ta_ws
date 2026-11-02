// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tita_locomotion_interfaces:msg/MotorsStatus.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__STRUCT_H_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__STRUCT_H_

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
// Member 'value'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/MotorsStatus in the package tita_locomotion_interfaces.
typedef struct tita_locomotion_interfaces__msg__MotorsStatus
{
  std_msgs__msg__Header header;
  uint16_t key;
  rosidl_runtime_c__boolean__Sequence value;
} tita_locomotion_interfaces__msg__MotorsStatus;

// Struct for a sequence of tita_locomotion_interfaces__msg__MotorsStatus.
typedef struct tita_locomotion_interfaces__msg__MotorsStatus__Sequence
{
  tita_locomotion_interfaces__msg__MotorsStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_locomotion_interfaces__msg__MotorsStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__STRUCT_H_
