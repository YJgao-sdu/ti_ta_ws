// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tita_perception_interfaces:msg/BoundingBoxArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tita_perception_interfaces/msg/detail/bounding_box_array__rosidl_typesupport_introspection_c.h"
#include "tita_perception_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tita_perception_interfaces/msg/detail/bounding_box_array__functions.h"
#include "tita_perception_interfaces/msg/detail/bounding_box_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `boxes`
#include "tita_perception_interfaces/msg/bounding_box.h"
// Member `boxes`
#include "tita_perception_interfaces/msg/detail/bounding_box__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tita_perception_interfaces__msg__BoundingBoxArray__init(message_memory);
}

void tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_fini_function(void * message_memory)
{
  tita_perception_interfaces__msg__BoundingBoxArray__fini(message_memory);
}

size_t tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__size_function__BoundingBoxArray__boxes(
  const void * untyped_member)
{
  const tita_perception_interfaces__msg__BoundingBox__Sequence * member =
    (const tita_perception_interfaces__msg__BoundingBox__Sequence *)(untyped_member);
  return member->size;
}

const void * tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__get_const_function__BoundingBoxArray__boxes(
  const void * untyped_member, size_t index)
{
  const tita_perception_interfaces__msg__BoundingBox__Sequence * member =
    (const tita_perception_interfaces__msg__BoundingBox__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__get_function__BoundingBoxArray__boxes(
  void * untyped_member, size_t index)
{
  tita_perception_interfaces__msg__BoundingBox__Sequence * member =
    (tita_perception_interfaces__msg__BoundingBox__Sequence *)(untyped_member);
  return &member->data[index];
}

void tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__fetch_function__BoundingBoxArray__boxes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tita_perception_interfaces__msg__BoundingBox * item =
    ((const tita_perception_interfaces__msg__BoundingBox *)
    tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__get_const_function__BoundingBoxArray__boxes(untyped_member, index));
  tita_perception_interfaces__msg__BoundingBox * value =
    (tita_perception_interfaces__msg__BoundingBox *)(untyped_value);
  *value = *item;
}

void tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__assign_function__BoundingBoxArray__boxes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tita_perception_interfaces__msg__BoundingBox * item =
    ((tita_perception_interfaces__msg__BoundingBox *)
    tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__get_function__BoundingBoxArray__boxes(untyped_member, index));
  const tita_perception_interfaces__msg__BoundingBox * value =
    (const tita_perception_interfaces__msg__BoundingBox *)(untyped_value);
  *item = *value;
}

bool tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__resize_function__BoundingBoxArray__boxes(
  void * untyped_member, size_t size)
{
  tita_perception_interfaces__msg__BoundingBox__Sequence * member =
    (tita_perception_interfaces__msg__BoundingBox__Sequence *)(untyped_member);
  tita_perception_interfaces__msg__BoundingBox__Sequence__fini(member);
  return tita_perception_interfaces__msg__BoundingBox__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_perception_interfaces__msg__BoundingBoxArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "boxes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_perception_interfaces__msg__BoundingBoxArray, boxes),  // bytes offset in struct
    NULL,  // default value
    tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__size_function__BoundingBoxArray__boxes,  // size() function pointer
    tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__get_const_function__BoundingBoxArray__boxes,  // get_const(index) function pointer
    tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__get_function__BoundingBoxArray__boxes,  // get(index) function pointer
    tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__fetch_function__BoundingBoxArray__boxes,  // fetch(index, &value) function pointer
    tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__assign_function__BoundingBoxArray__boxes,  // assign(index, value) function pointer
    tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__resize_function__BoundingBoxArray__boxes  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_message_members = {
  "tita_perception_interfaces__msg",  // message namespace
  "BoundingBoxArray",  // message name
  2,  // number of fields
  sizeof(tita_perception_interfaces__msg__BoundingBoxArray),
  tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_message_member_array,  // message members
  tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_init_function,  // function to initialize message memory (memory has to be allocated)
  tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_message_type_support_handle = {
  0,
  &tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tita_perception_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_perception_interfaces, msg, BoundingBoxArray)() {
  tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_perception_interfaces, msg, BoundingBox)();
  if (!tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_message_type_support_handle.typesupport_identifier) {
    tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tita_perception_interfaces__msg__BoundingBoxArray__rosidl_typesupport_introspection_c__BoundingBoxArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
