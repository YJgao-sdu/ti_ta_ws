// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from locomotion_msgs:msg/RigidBody.idl
// generated code does not contain a copyright notice

#ifndef LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__STRUCT_H_
#define LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'inertia'
#include "geometry_msgs/msg/detail/inertia__struct.h"
// Member 'transform'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/RigidBody in the package locomotion_msgs.
typedef struct locomotion_msgs__msg__RigidBody
{
  geometry_msgs__msg__Inertia inertia;
  geometry_msgs__msg__Pose transform;
} locomotion_msgs__msg__RigidBody;

// Struct for a sequence of locomotion_msgs__msg__RigidBody.
typedef struct locomotion_msgs__msg__RigidBody__Sequence
{
  locomotion_msgs__msg__RigidBody * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} locomotion_msgs__msg__RigidBody__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__STRUCT_H_
