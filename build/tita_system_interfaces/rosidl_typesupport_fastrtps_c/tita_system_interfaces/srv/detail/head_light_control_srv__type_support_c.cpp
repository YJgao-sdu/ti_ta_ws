// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tita_system_interfaces:srv/HeadLightControlSrv.idl
// generated code does not contain a copyright notice
#include "tita_system_interfaces/srv/detail/head_light_control_srv__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tita_system_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tita_system_interfaces/srv/detail/head_light_control_srv__struct.h"
#include "tita_system_interfaces/srv/detail/head_light_control_srv__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _HeadLightControlSrv_Request__ros_msg_type = tita_system_interfaces__srv__HeadLightControlSrv_Request;

static bool _HeadLightControlSrv_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HeadLightControlSrv_Request__ros_msg_type * ros_message = static_cast<const _HeadLightControlSrv_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: is_control
  {
    cdr << (ros_message->is_control ? true : false);
  }

  // Field name: light_rgbl_value
  {
    size_t size = 48;
    auto array_ptr = ros_message->light_rgbl_value;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _HeadLightControlSrv_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HeadLightControlSrv_Request__ros_msg_type * ros_message = static_cast<_HeadLightControlSrv_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: is_control
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_control = tmp ? true : false;
  }

  // Field name: light_rgbl_value
  {
    size_t size = 48;
    auto array_ptr = ros_message->light_rgbl_value;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tita_system_interfaces
size_t get_serialized_size_tita_system_interfaces__srv__HeadLightControlSrv_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HeadLightControlSrv_Request__ros_msg_type * ros_message = static_cast<const _HeadLightControlSrv_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name is_control
  {
    size_t item_size = sizeof(ros_message->is_control);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name light_rgbl_value
  {
    size_t array_size = 48;
    auto array_ptr = ros_message->light_rgbl_value;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HeadLightControlSrv_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tita_system_interfaces__srv__HeadLightControlSrv_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tita_system_interfaces
size_t max_serialized_size_tita_system_interfaces__srv__HeadLightControlSrv_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: is_control
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: light_rgbl_value
  {
    size_t array_size = 48;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tita_system_interfaces__srv__HeadLightControlSrv_Request;
    is_plain =
      (
      offsetof(DataType, light_rgbl_value) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _HeadLightControlSrv_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tita_system_interfaces__srv__HeadLightControlSrv_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_HeadLightControlSrv_Request = {
  "tita_system_interfaces::srv",
  "HeadLightControlSrv_Request",
  _HeadLightControlSrv_Request__cdr_serialize,
  _HeadLightControlSrv_Request__cdr_deserialize,
  _HeadLightControlSrv_Request__get_serialized_size,
  _HeadLightControlSrv_Request__max_serialized_size
};

static rosidl_message_type_support_t _HeadLightControlSrv_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HeadLightControlSrv_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tita_system_interfaces, srv, HeadLightControlSrv_Request)() {
  return &_HeadLightControlSrv_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "tita_system_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "tita_system_interfaces/srv/detail/head_light_control_srv__struct.h"
// already included above
// #include "tita_system_interfaces/srv/detail/head_light_control_srv__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _HeadLightControlSrv_Response__ros_msg_type = tita_system_interfaces__srv__HeadLightControlSrv_Response;

static bool _HeadLightControlSrv_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HeadLightControlSrv_Response__ros_msg_type * ros_message = static_cast<const _HeadLightControlSrv_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  return true;
}

static bool _HeadLightControlSrv_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HeadLightControlSrv_Response__ros_msg_type * ros_message = static_cast<_HeadLightControlSrv_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tita_system_interfaces
size_t get_serialized_size_tita_system_interfaces__srv__HeadLightControlSrv_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HeadLightControlSrv_Response__ros_msg_type * ros_message = static_cast<const _HeadLightControlSrv_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HeadLightControlSrv_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tita_system_interfaces__srv__HeadLightControlSrv_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tita_system_interfaces
size_t max_serialized_size_tita_system_interfaces__srv__HeadLightControlSrv_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: success
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tita_system_interfaces__srv__HeadLightControlSrv_Response;
    is_plain =
      (
      offsetof(DataType, success) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _HeadLightControlSrv_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tita_system_interfaces__srv__HeadLightControlSrv_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_HeadLightControlSrv_Response = {
  "tita_system_interfaces::srv",
  "HeadLightControlSrv_Response",
  _HeadLightControlSrv_Response__cdr_serialize,
  _HeadLightControlSrv_Response__cdr_deserialize,
  _HeadLightControlSrv_Response__get_serialized_size,
  _HeadLightControlSrv_Response__max_serialized_size
};

static rosidl_message_type_support_t _HeadLightControlSrv_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HeadLightControlSrv_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tita_system_interfaces, srv, HeadLightControlSrv_Response)() {
  return &_HeadLightControlSrv_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "tita_system_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tita_system_interfaces/srv/head_light_control_srv.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t HeadLightControlSrv__callbacks = {
  "tita_system_interfaces::srv",
  "HeadLightControlSrv",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tita_system_interfaces, srv, HeadLightControlSrv_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tita_system_interfaces, srv, HeadLightControlSrv_Response)(),
};

static rosidl_service_type_support_t HeadLightControlSrv__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &HeadLightControlSrv__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tita_system_interfaces, srv, HeadLightControlSrv)() {
  return &HeadLightControlSrv__handle;
}

#if defined(__cplusplus)
}
#endif
