// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tita_system_interfaces:srv/HeadLightControlSrv.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tita_system_interfaces/srv/detail/head_light_control_srv__rosidl_typesupport_introspection_c.h"
#include "tita_system_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tita_system_interfaces/srv/detail/head_light_control_srv__functions.h"
#include "tita_system_interfaces/srv/detail/head_light_control_srv__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tita_system_interfaces__srv__HeadLightControlSrv_Request__init(message_memory);
}

void tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_fini_function(void * message_memory)
{
  tita_system_interfaces__srv__HeadLightControlSrv_Request__fini(message_memory);
}

size_t tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__size_function__HeadLightControlSrv_Request__light_rgbl_value(
  const void * untyped_member)
{
  (void)untyped_member;
  return 48;
}

const void * tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__get_const_function__HeadLightControlSrv_Request__light_rgbl_value(
  const void * untyped_member, size_t index)
{
  const uint32_t * member =
    (const uint32_t *)(untyped_member);
  return &member[index];
}

void * tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__get_function__HeadLightControlSrv_Request__light_rgbl_value(
  void * untyped_member, size_t index)
{
  uint32_t * member =
    (uint32_t *)(untyped_member);
  return &member[index];
}

void tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__fetch_function__HeadLightControlSrv_Request__light_rgbl_value(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__get_const_function__HeadLightControlSrv_Request__light_rgbl_value(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__assign_function__HeadLightControlSrv_Request__light_rgbl_value(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__get_function__HeadLightControlSrv_Request__light_rgbl_value(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_message_member_array[2] = {
  {
    "is_control",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_system_interfaces__srv__HeadLightControlSrv_Request, is_control),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "light_rgbl_value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    48,  // array size
    false,  // is upper bound
    offsetof(tita_system_interfaces__srv__HeadLightControlSrv_Request, light_rgbl_value),  // bytes offset in struct
    NULL,  // default value
    tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__size_function__HeadLightControlSrv_Request__light_rgbl_value,  // size() function pointer
    tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__get_const_function__HeadLightControlSrv_Request__light_rgbl_value,  // get_const(index) function pointer
    tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__get_function__HeadLightControlSrv_Request__light_rgbl_value,  // get(index) function pointer
    tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__fetch_function__HeadLightControlSrv_Request__light_rgbl_value,  // fetch(index, &value) function pointer
    tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__assign_function__HeadLightControlSrv_Request__light_rgbl_value,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_message_members = {
  "tita_system_interfaces__srv",  // message namespace
  "HeadLightControlSrv_Request",  // message name
  2,  // number of fields
  sizeof(tita_system_interfaces__srv__HeadLightControlSrv_Request),
  tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_message_member_array,  // message members
  tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_message_type_support_handle = {
  0,
  &tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tita_system_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_system_interfaces, srv, HeadLightControlSrv_Request)() {
  if (!tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_message_type_support_handle.typesupport_identifier) {
    tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tita_system_interfaces__srv__HeadLightControlSrv_Request__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tita_system_interfaces/srv/detail/head_light_control_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tita_system_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tita_system_interfaces/srv/detail/head_light_control_srv__functions.h"
// already included above
// #include "tita_system_interfaces/srv/detail/head_light_control_srv__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tita_system_interfaces__srv__HeadLightControlSrv_Response__init(message_memory);
}

void tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_fini_function(void * message_memory)
{
  tita_system_interfaces__srv__HeadLightControlSrv_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_system_interfaces__srv__HeadLightControlSrv_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_message_members = {
  "tita_system_interfaces__srv",  // message namespace
  "HeadLightControlSrv_Response",  // message name
  1,  // number of fields
  sizeof(tita_system_interfaces__srv__HeadLightControlSrv_Response),
  tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_message_member_array,  // message members
  tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_message_type_support_handle = {
  0,
  &tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tita_system_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_system_interfaces, srv, HeadLightControlSrv_Response)() {
  if (!tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_message_type_support_handle.typesupport_identifier) {
    tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tita_system_interfaces__srv__HeadLightControlSrv_Response__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tita_system_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tita_system_interfaces/srv/detail/head_light_control_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tita_system_interfaces__srv__detail__head_light_control_srv__rosidl_typesupport_introspection_c__HeadLightControlSrv_service_members = {
  "tita_system_interfaces__srv",  // service namespace
  "HeadLightControlSrv",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // tita_system_interfaces__srv__detail__head_light_control_srv__rosidl_typesupport_introspection_c__HeadLightControlSrv_Request_message_type_support_handle,
  NULL  // response message
  // tita_system_interfaces__srv__detail__head_light_control_srv__rosidl_typesupport_introspection_c__HeadLightControlSrv_Response_message_type_support_handle
};

static rosidl_service_type_support_t tita_system_interfaces__srv__detail__head_light_control_srv__rosidl_typesupport_introspection_c__HeadLightControlSrv_service_type_support_handle = {
  0,
  &tita_system_interfaces__srv__detail__head_light_control_srv__rosidl_typesupport_introspection_c__HeadLightControlSrv_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_system_interfaces, srv, HeadLightControlSrv_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_system_interfaces, srv, HeadLightControlSrv_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tita_system_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_system_interfaces, srv, HeadLightControlSrv)() {
  if (!tita_system_interfaces__srv__detail__head_light_control_srv__rosidl_typesupport_introspection_c__HeadLightControlSrv_service_type_support_handle.typesupport_identifier) {
    tita_system_interfaces__srv__detail__head_light_control_srv__rosidl_typesupport_introspection_c__HeadLightControlSrv_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tita_system_interfaces__srv__detail__head_light_control_srv__rosidl_typesupport_introspection_c__HeadLightControlSrv_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_system_interfaces, srv, HeadLightControlSrv_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_system_interfaces, srv, HeadLightControlSrv_Response)()->data;
  }

  return &tita_system_interfaces__srv__detail__head_light_control_srv__rosidl_typesupport_introspection_c__HeadLightControlSrv_service_type_support_handle;
}
