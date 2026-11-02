// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tita_locomotion_interfaces:msg/MotorsStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tita_locomotion_interfaces/msg/detail/motors_status__rosidl_typesupport_introspection_c.h"
#include "tita_locomotion_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tita_locomotion_interfaces/msg/detail/motors_status__functions.h"
#include "tita_locomotion_interfaces/msg/detail/motors_status__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `value`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tita_locomotion_interfaces__msg__MotorsStatus__init(message_memory);
}

void tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_fini_function(void * message_memory)
{
  tita_locomotion_interfaces__msg__MotorsStatus__fini(message_memory);
}

size_t tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__size_function__MotorsStatus__value(
  const void * untyped_member)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return member->size;
}

const void * tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__get_const_function__MotorsStatus__value(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__boolean__Sequence * member =
    (const rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__get_function__MotorsStatus__value(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  return &member->data[index];
}

void tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__fetch_function__MotorsStatus__value(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const bool * item =
    ((const bool *)
    tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__get_const_function__MotorsStatus__value(untyped_member, index));
  bool * value =
    (bool *)(untyped_value);
  *value = *item;
}

void tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__assign_function__MotorsStatus__value(
  void * untyped_member, size_t index, const void * untyped_value)
{
  bool * item =
    ((bool *)
    tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__get_function__MotorsStatus__value(untyped_member, index));
  const bool * value =
    (const bool *)(untyped_value);
  *item = *value;
}

bool tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__resize_function__MotorsStatus__value(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__boolean__Sequence * member =
    (rosidl_runtime_c__boolean__Sequence *)(untyped_member);
  rosidl_runtime_c__boolean__Sequence__fini(member);
  return rosidl_runtime_c__boolean__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_locomotion_interfaces__msg__MotorsStatus, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "key",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_locomotion_interfaces__msg__MotorsStatus, key),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_locomotion_interfaces__msg__MotorsStatus, value),  // bytes offset in struct
    NULL,  // default value
    tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__size_function__MotorsStatus__value,  // size() function pointer
    tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__get_const_function__MotorsStatus__value,  // get_const(index) function pointer
    tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__get_function__MotorsStatus__value,  // get(index) function pointer
    tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__fetch_function__MotorsStatus__value,  // fetch(index, &value) function pointer
    tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__assign_function__MotorsStatus__value,  // assign(index, value) function pointer
    tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__resize_function__MotorsStatus__value  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_message_members = {
  "tita_locomotion_interfaces__msg",  // message namespace
  "MotorsStatus",  // message name
  3,  // number of fields
  sizeof(tita_locomotion_interfaces__msg__MotorsStatus),
  tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_message_member_array,  // message members
  tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_message_type_support_handle = {
  0,
  &tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tita_locomotion_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_locomotion_interfaces, msg, MotorsStatus)() {
  tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_message_type_support_handle.typesupport_identifier) {
    tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tita_locomotion_interfaces__msg__MotorsStatus__rosidl_typesupport_introspection_c__MotorsStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
