// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tita_perception_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
#define TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_

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
// Member 'label'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BoundingBox in the package tita_perception_interfaces.
typedef struct tita_perception_interfaces__msg__BoundingBox
{
  std_msgs__msg__Header header;
  double x_min;
  double y_min;
  double x_max;
  double y_max;
  rosidl_runtime_c__String label;
} tita_perception_interfaces__msg__BoundingBox;

// Struct for a sequence of tita_perception_interfaces__msg__BoundingBox.
typedef struct tita_perception_interfaces__msg__BoundingBox__Sequence
{
  tita_perception_interfaces__msg__BoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_perception_interfaces__msg__BoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
