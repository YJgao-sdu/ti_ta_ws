// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tita_system_interfaces:srv/PowerSelfTestSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__STRUCT_H_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'power_self_test'
#include "diagnostic_msgs/msg/detail/diagnostic_array__struct.h"

/// Struct defined in srv/PowerSelfTestSrv in the package tita_system_interfaces.
typedef struct tita_system_interfaces__srv__PowerSelfTestSrv_Request
{
  diagnostic_msgs__msg__DiagnosticArray power_self_test;
} tita_system_interfaces__srv__PowerSelfTestSrv_Request;

// Struct for a sequence of tita_system_interfaces__srv__PowerSelfTestSrv_Request.
typedef struct tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence
{
  tita_system_interfaces__srv__PowerSelfTestSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/PowerSelfTestSrv in the package tita_system_interfaces.
typedef struct tita_system_interfaces__srv__PowerSelfTestSrv_Response
{
  bool success;
} tita_system_interfaces__srv__PowerSelfTestSrv_Response;

// Struct for a sequence of tita_system_interfaces__srv__PowerSelfTestSrv_Response.
typedef struct tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence
{
  tita_system_interfaces__srv__PowerSelfTestSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__STRUCT_H_
