// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tita_system_interfaces:srv/HeadLightControlSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__HEAD_LIGHT_CONTROL_SRV__STRUCT_H_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__HEAD_LIGHT_CONTROL_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/HeadLightControlSrv in the package tita_system_interfaces.
typedef struct tita_system_interfaces__srv__HeadLightControlSrv_Request
{
  /// A total of 48 lights can be controlled,
  /// and the light efficiency of each light is represented
  /// by the data structure uint32_t, so you need to use a
  /// uint32_t array containing 48 elements
  /// If you want to control the headlights, set the bool
  /// is_control to true, when you give up control, you need
  /// to set the bool to false, after which the light effect
  /// will be automatically taken over by the software's
  /// internal state machine
  /// rgbl values refer to red, green,
  /// blue and brightness
  /// for example: light_rgbl_value = 0x12345678
  /// This means that red is: (0x12U), green is: (0x34U),
  /// blue is: (0x56U), brightness is: (0x78U)
  /// Each time you write data, you must complete the 48
  /// light effects, because the underlying software will
  /// directly update the light effects of 48 light beads
  /// at one time
  bool is_control;
  uint32_t light_rgbl_value[48];
} tita_system_interfaces__srv__HeadLightControlSrv_Request;

// Struct for a sequence of tita_system_interfaces__srv__HeadLightControlSrv_Request.
typedef struct tita_system_interfaces__srv__HeadLightControlSrv_Request__Sequence
{
  tita_system_interfaces__srv__HeadLightControlSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_system_interfaces__srv__HeadLightControlSrv_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/HeadLightControlSrv in the package tita_system_interfaces.
typedef struct tita_system_interfaces__srv__HeadLightControlSrv_Response
{
  bool success;
} tita_system_interfaces__srv__HeadLightControlSrv_Response;

// Struct for a sequence of tita_system_interfaces__srv__HeadLightControlSrv_Response.
typedef struct tita_system_interfaces__srv__HeadLightControlSrv_Response__Sequence
{
  tita_system_interfaces__srv__HeadLightControlSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_system_interfaces__srv__HeadLightControlSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__HEAD_LIGHT_CONTROL_SRV__STRUCT_H_
