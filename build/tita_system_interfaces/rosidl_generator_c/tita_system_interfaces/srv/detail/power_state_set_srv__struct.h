// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tita_system_interfaces:srv/PowerStateSetSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_STATE_SET_SRV__STRUCT_H_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_STATE_SET_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'power_state_set'
#include "diagnostic_msgs/msg/detail/diagnostic_array__struct.h"

/// Struct defined in srv/PowerStateSetSrv in the package tita_system_interfaces.
typedef struct tita_system_interfaces__srv__PowerStateSetSrv_Request
{
  diagnostic_msgs__msg__DiagnosticArray power_state_set;
} tita_system_interfaces__srv__PowerStateSetSrv_Request;

// Struct for a sequence of tita_system_interfaces__srv__PowerStateSetSrv_Request.
typedef struct tita_system_interfaces__srv__PowerStateSetSrv_Request__Sequence
{
  tita_system_interfaces__srv__PowerStateSetSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_system_interfaces__srv__PowerStateSetSrv_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/PowerStateSetSrv in the package tita_system_interfaces.
typedef struct tita_system_interfaces__srv__PowerStateSetSrv_Response
{
  bool success;
} tita_system_interfaces__srv__PowerStateSetSrv_Response;

// Struct for a sequence of tita_system_interfaces__srv__PowerStateSetSrv_Response.
typedef struct tita_system_interfaces__srv__PowerStateSetSrv_Response__Sequence
{
  tita_system_interfaces__srv__PowerStateSetSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_system_interfaces__srv__PowerStateSetSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_STATE_SET_SRV__STRUCT_H_
