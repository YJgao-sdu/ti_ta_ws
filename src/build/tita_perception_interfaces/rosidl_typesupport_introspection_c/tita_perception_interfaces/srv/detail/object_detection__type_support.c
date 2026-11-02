// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tita_perception_interfaces:srv/ObjectDetection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tita_perception_interfaces/srv/detail/object_detection__rosidl_typesupport_introspection_c.h"
#include "tita_perception_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tita_perception_interfaces/srv/detail/object_detection__functions.h"
#include "tita_perception_interfaces/srv/detail/object_detection__struct.h"


// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/image.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tita_perception_interfaces__srv__ObjectDetection_Request__init(message_memory);
}

void tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_fini_function(void * message_memory)
{
  tita_perception_interfaces__srv__ObjectDetection_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_message_member_array[1] = {
  {
    "image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_perception_interfaces__srv__ObjectDetection_Request, image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_message_members = {
  "tita_perception_interfaces__srv",  // message namespace
  "ObjectDetection_Request",  // message name
  1,  // number of fields
  sizeof(tita_perception_interfaces__srv__ObjectDetection_Request),
  tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_message_member_array,  // message members
  tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_message_type_support_handle = {
  0,
  &tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tita_perception_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_perception_interfaces, srv, ObjectDetection_Request)() {
  tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_message_type_support_handle.typesupport_identifier) {
    tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tita_perception_interfaces__srv__ObjectDetection_Request__rosidl_typesupport_introspection_c__ObjectDetection_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tita_perception_interfaces/srv/detail/object_detection__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tita_perception_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tita_perception_interfaces/srv/detail/object_detection__functions.h"
// already included above
// #include "tita_perception_interfaces/srv/detail/object_detection__struct.h"


// Include directives for member types
// Member `result`
#include "tita_perception_interfaces/msg/bounding_box_array.h"
// Member `result`
#include "tita_perception_interfaces/msg/detail/bounding_box_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tita_perception_interfaces__srv__ObjectDetection_Response__init(message_memory);
}

void tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_fini_function(void * message_memory)
{
  tita_perception_interfaces__srv__ObjectDetection_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_perception_interfaces__srv__ObjectDetection_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_message_members = {
  "tita_perception_interfaces__srv",  // message namespace
  "ObjectDetection_Response",  // message name
  1,  // number of fields
  sizeof(tita_perception_interfaces__srv__ObjectDetection_Response),
  tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_message_member_array,  // message members
  tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_message_type_support_handle = {
  0,
  &tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tita_perception_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_perception_interfaces, srv, ObjectDetection_Response)() {
  tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_perception_interfaces, msg, BoundingBoxArray)();
  if (!tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_message_type_support_handle.typesupport_identifier) {
    tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tita_perception_interfaces__srv__ObjectDetection_Response__rosidl_typesupport_introspection_c__ObjectDetection_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tita_perception_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tita_perception_interfaces/srv/detail/object_detection__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tita_perception_interfaces__srv__detail__object_detection__rosidl_typesupport_introspection_c__ObjectDetection_service_members = {
  "tita_perception_interfaces__srv",  // service namespace
  "ObjectDetection",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // tita_perception_interfaces__srv__detail__object_detection__rosidl_typesupport_introspection_c__ObjectDetection_Request_message_type_support_handle,
  NULL  // response message
  // tita_perception_interfaces__srv__detail__object_detection__rosidl_typesupport_introspection_c__ObjectDetection_Response_message_type_support_handle
};

static rosidl_service_type_support_t tita_perception_interfaces__srv__detail__object_detection__rosidl_typesupport_introspection_c__ObjectDetection_service_type_support_handle = {
  0,
  &tita_perception_interfaces__srv__detail__object_detection__rosidl_typesupport_introspection_c__ObjectDetection_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_perception_interfaces, srv, ObjectDetection_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_perception_interfaces, srv, ObjectDetection_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tita_perception_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_perception_interfaces, srv, ObjectDetection)() {
  if (!tita_perception_interfaces__srv__detail__object_detection__rosidl_typesupport_introspection_c__ObjectDetection_service_type_support_handle.typesupport_identifier) {
    tita_perception_interfaces__srv__detail__object_detection__rosidl_typesupport_introspection_c__ObjectDetection_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tita_perception_interfaces__srv__detail__object_detection__rosidl_typesupport_introspection_c__ObjectDetection_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_perception_interfaces, srv, ObjectDetection_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tita_perception_interfaces, srv, ObjectDetection_Response)()->data;
  }

  return &tita_perception_interfaces__srv__detail__object_detection__rosidl_typesupport_introspection_c__ObjectDetection_service_type_support_handle;
}
