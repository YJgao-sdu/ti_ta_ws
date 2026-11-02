// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from locomotion_msgs:msg/PlanCommands.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "locomotion_msgs/msg/detail/plan_commands__rosidl_typesupport_introspection_c.h"
#include "locomotion_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "locomotion_msgs/msg/detail/plan_commands__functions.h"
#include "locomotion_msgs/msg/detail/plan_commands__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `fsm_state_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `twist_linear`
// Member `twist_linear_int`
// Member `twist_angular`
// Member `twist_angular_int`
// Member `pose_position`
// Member `pose_position_dot`
// Member `pose_rpy`
// Member `pose_rpy_dot`
#include "geometry_msgs/msg/vector3.h"
// Member `twist_linear`
// Member `twist_linear_int`
// Member `twist_angular`
// Member `twist_angular_int`
// Member `pose_position`
// Member `pose_position_dot`
// Member `pose_rpy`
// Member `pose_rpy_dot`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `joint_positions`
// Member `joint_velocities`
// Member `joint_torques`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  locomotion_msgs__msg__PlanCommands__init(message_memory);
}

void locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_fini_function(void * message_memory)
{
  locomotion_msgs__msg__PlanCommands__fini(message_memory);
}

size_t locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__size_function__PlanCommands__joint_positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_const_function__PlanCommands__joint_positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_function__PlanCommands__joint_positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__fetch_function__PlanCommands__joint_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_const_function__PlanCommands__joint_positions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__assign_function__PlanCommands__joint_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_function__PlanCommands__joint_positions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__resize_function__PlanCommands__joint_positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__size_function__PlanCommands__joint_velocities(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_const_function__PlanCommands__joint_velocities(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_function__PlanCommands__joint_velocities(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__fetch_function__PlanCommands__joint_velocities(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_const_function__PlanCommands__joint_velocities(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__assign_function__PlanCommands__joint_velocities(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_function__PlanCommands__joint_velocities(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__resize_function__PlanCommands__joint_velocities(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__size_function__PlanCommands__joint_torques(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_const_function__PlanCommands__joint_torques(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_function__PlanCommands__joint_torques(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__fetch_function__PlanCommands__joint_torques(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_const_function__PlanCommands__joint_torques(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__assign_function__PlanCommands__joint_torques(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_function__PlanCommands__joint_torques(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__resize_function__PlanCommands__joint_torques(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array[15] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fsm_state_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, fsm_state_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "twist_linear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, twist_linear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "twist_linear_int",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, twist_linear_int),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "twist_angular",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, twist_angular),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "twist_angular_int",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, twist_angular_int),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, pose_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose_position_dot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, pose_position_dot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose_rpy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, pose_rpy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose_rpy_dot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, pose_rpy_dot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "two_wheel_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, two_wheel_distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "two_wheel_distance_dot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, two_wheel_distance_dot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, joint_positions),  // bytes offset in struct
    NULL,  // default value
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__size_function__PlanCommands__joint_positions,  // size() function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_const_function__PlanCommands__joint_positions,  // get_const(index) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_function__PlanCommands__joint_positions,  // get(index) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__fetch_function__PlanCommands__joint_positions,  // fetch(index, &value) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__assign_function__PlanCommands__joint_positions,  // assign(index, value) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__resize_function__PlanCommands__joint_positions  // resize(index) function pointer
  },
  {
    "joint_velocities",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, joint_velocities),  // bytes offset in struct
    NULL,  // default value
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__size_function__PlanCommands__joint_velocities,  // size() function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_const_function__PlanCommands__joint_velocities,  // get_const(index) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_function__PlanCommands__joint_velocities,  // get(index) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__fetch_function__PlanCommands__joint_velocities,  // fetch(index, &value) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__assign_function__PlanCommands__joint_velocities,  // assign(index, value) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__resize_function__PlanCommands__joint_velocities  // resize(index) function pointer
  },
  {
    "joint_torques",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs__msg__PlanCommands, joint_torques),  // bytes offset in struct
    NULL,  // default value
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__size_function__PlanCommands__joint_torques,  // size() function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_const_function__PlanCommands__joint_torques,  // get_const(index) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__get_function__PlanCommands__joint_torques,  // get(index) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__fetch_function__PlanCommands__joint_torques,  // fetch(index, &value) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__assign_function__PlanCommands__joint_torques,  // assign(index, value) function pointer
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__resize_function__PlanCommands__joint_torques  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_members = {
  "locomotion_msgs__msg",  // message namespace
  "PlanCommands",  // message name
  15,  // number of fields
  sizeof(locomotion_msgs__msg__PlanCommands),
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array,  // message members
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_init_function,  // function to initialize message memory (memory has to be allocated)
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_type_support_handle = {
  0,
  &locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_locomotion_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, locomotion_msgs, msg, PlanCommands)() {
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_member_array[9].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_type_support_handle.typesupport_identifier) {
    locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &locomotion_msgs__msg__PlanCommands__rosidl_typesupport_introspection_c__PlanCommands_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
