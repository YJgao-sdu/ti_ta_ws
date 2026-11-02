// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tita_perception_interfaces:srv/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__STRUCT_H_
#define TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in srv/ObjectDetection in the package tita_perception_interfaces.
typedef struct tita_perception_interfaces__srv__ObjectDetection_Request
{
  sensor_msgs__msg__Image image;
} tita_perception_interfaces__srv__ObjectDetection_Request;

// Struct for a sequence of tita_perception_interfaces__srv__ObjectDetection_Request.
typedef struct tita_perception_interfaces__srv__ObjectDetection_Request__Sequence
{
  tita_perception_interfaces__srv__ObjectDetection_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_perception_interfaces__srv__ObjectDetection_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "tita_perception_interfaces/msg/detail/bounding_box_array__struct.h"

/// Struct defined in srv/ObjectDetection in the package tita_perception_interfaces.
typedef struct tita_perception_interfaces__srv__ObjectDetection_Response
{
  tita_perception_interfaces__msg__BoundingBoxArray result;
} tita_perception_interfaces__srv__ObjectDetection_Response;

// Struct for a sequence of tita_perception_interfaces__srv__ObjectDetection_Response.
typedef struct tita_perception_interfaces__srv__ObjectDetection_Response__Sequence
{
  tita_perception_interfaces__srv__ObjectDetection_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_perception_interfaces__srv__ObjectDetection_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__STRUCT_H_
