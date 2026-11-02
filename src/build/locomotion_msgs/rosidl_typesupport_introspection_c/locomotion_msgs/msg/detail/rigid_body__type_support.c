// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from locomotion_msgs:msg/RigidBody.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "locomotion_msgs/msg/detail/rigid_body__rosidl_typesupport_introspection_c.h"
#include "locomotion_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "locomotion_msgs/msg/detail/rigid_body__functions.h"
#include "locomotion_msgs/msg/detail/rigid_body__struct.h"


// Include directives for member types
// Member `inertia`
#include "geometry_msgs/msg/inertia.h"
// Member `inertia`
#include "geometry_msgs/msg/detail/inertia__rosidl_typesupport_introspection_c.h"
// Member `transform`
#include "geometry_msgs/msg/pose.h"
// Member `transform`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  locomotion_msgs__msg__RigidBody__init(message_memory);
}

void locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_fini_function(void * message_memory)
{
  locomotion_msgs__msg__RigidBody__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_message_member_array[2] = {
  {
    "inertia",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__RigidBody, inertia),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "transform",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__RigidBody, transform),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_message_members = {
  "locomotion_msgs__msg",  // message namespace
  "RigidBody",  // message name
  2,  // number of fields
  sizeof(locomotion_msgs__msg__RigidBody),
  locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_message_member_array,  // message members
  locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_init_function,  // function to initialize message memory (memory has to be allocated)
  locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_message_type_support_handle = {
  0,
  &locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_locomotion_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, locomotion_msgs, msg, RigidBody)() {
  locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Inertia)();
  locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_message_type_support_handle.typesupport_identifier) {
    locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &locomotion_msgs__msg__RigidBody__rosidl_typesupport_introspection_c__RigidBody_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
