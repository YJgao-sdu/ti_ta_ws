// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tita_perception_interfaces:msg/BoundingBoxArray.idl
// generated code does not contain a copyright notice

#ifndef TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__STRUCT_H_
#define TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__STRUCT_H_

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
// Member 'boxes'
#include "tita_perception_interfaces/msg/detail/bounding_box__struct.h"

/// Struct defined in msg/BoundingBoxArray in the package tita_perception_interfaces.
typedef struct tita_perception_interfaces__msg__BoundingBoxArray
{
  std_msgs__msg__Header header;
  tita_perception_interfaces__msg__BoundingBox__Sequence boxes;
} tita_perception_interfaces__msg__BoundingBoxArray;

// Struct for a sequence of tita_perception_interfaces__msg__BoundingBoxArray.
typedef struct tita_perception_interfaces__msg__BoundingBoxArray__Sequence
{
  tita_perception_interfaces__msg__BoundingBoxArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_perception_interfaces__msg__BoundingBoxArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__STRUCT_H_
