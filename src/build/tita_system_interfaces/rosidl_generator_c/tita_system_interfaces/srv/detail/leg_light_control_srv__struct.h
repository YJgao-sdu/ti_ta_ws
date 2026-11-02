// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tita_system_interfaces:srv/LegLightControlSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__LEG_LIGHT_CONTROL_SRV__STRUCT_H_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__LEG_LIGHT_CONTROL_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/LegLightControlSrv in the package tita_system_interfaces.
typedef struct tita_system_interfaces__srv__LegLightControlSrv_Request
{
  /// A total of 10 lights can be controlled,
  /// and the light efficiency of each light is represented
  /// by the data structure uint32_t, so you need to use a
  /// uint32_t array containing 10 elements
  /// The leg light command needs to specify whether it controls
  /// the left leg or the right leg, which would use a uint8_t value
  /// indicating whether the command is sent to the left or right
  /// leg, as shown in the following example:
  /// If you want to send the command to the left leg:
  /// uint8_t target_leg_light = 0x01;
  /// or If you want to send the command to the right leg:
  /// uint8_t target_leg_light = 0x02;
  /// If you want to control the headlights, set the bool
  /// is_control to true, when you give up control, you need
  /// to set the bool to false, after which the light effect
  /// will be automatically taken over by the software's
  /// internal state machine
  /// rgbl values refer to red, green and blue
  /// for example: light_rgbl_value = 0x12345678
  /// This means that default is: (0x12U) (This value is meaningless.
  /// It is only used to fill the uint32_t data of type), red is: (0x34U),
  /// green is: (0x56U), blue is: (0x78U)
  /// Each time you write data, you must complete the 48
  /// light effects, because the underlying software will
  /// directly update the light effects of 48 light beads
  /// at one time
  /// It should be noted that please limit the command control
  /// frequency of the leg to less than 30hz, too high control
  /// frequency will crowd out the signal bandwidth of the motion control
  bool is_control;
  uint8_t target_leg_light;
  uint32_t light_rgbl_value[10];
} tita_system_interfaces__srv__LegLightControlSrv_Request;

// Struct for a sequence of tita_system_interfaces__srv__LegLightControlSrv_Request.
typedef struct tita_system_interfaces__srv__LegLightControlSrv_Request__Sequence
{
  tita_system_interfaces__srv__LegLightControlSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_system_interfaces__srv__LegLightControlSrv_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/LegLightControlSrv in the package tita_system_interfaces.
typedef struct tita_system_interfaces__srv__LegLightControlSrv_Response
{
  bool success;
} tita_system_interfaces__srv__LegLightControlSrv_Response;

// Struct for a sequence of tita_system_interfaces__srv__LegLightControlSrv_Response.
typedef struct tita_system_interfaces__srv__LegLightControlSrv_Response__Sequence
{
  tita_system_interfaces__srv__LegLightControlSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tita_system_interfaces__srv__LegLightControlSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__LEG_LIGHT_CONTROL_SRV__STRUCT_H_
