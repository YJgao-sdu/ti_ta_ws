// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tita_system_interfaces:srv/LegLightControlSrv.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tita_system_interfaces/srv/detail/leg_light_control_srv__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tita_system_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void LegLightControlSrv_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tita_system_interfaces::srv::LegLightControlSrv_Request(_init);
}

void LegLightControlSrv_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tita_system_interfaces::srv::LegLightControlSrv_Request *>(message_memory);
  typed_message->~LegLightControlSrv_Request();
}

size_t size_function__LegLightControlSrv_Request__light_rgbl_value(const void * untyped_member)
{
  (void)untyped_member;
  return 10;
}

const void * get_const_function__LegLightControlSrv_Request__light_rgbl_value(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint32_t, 10> *>(untyped_member);
  return &member[index];
}

void * get_function__LegLightControlSrv_Request__light_rgbl_value(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint32_t, 10> *>(untyped_member);
  return &member[index];
}

void fetch_function__LegLightControlSrv_Request__light_rgbl_value(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint32_t *>(
    get_const_function__LegLightControlSrv_Request__light_rgbl_value(untyped_member, index));
  auto & value = *reinterpret_cast<uint32_t *>(untyped_value);
  value = item;
}

void assign_function__LegLightControlSrv_Request__light_rgbl_value(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint32_t *>(
    get_function__LegLightControlSrv_Request__light_rgbl_value(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint32_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LegLightControlSrv_Request_message_member_array[3] = {
  {
    "is_control",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_system_interfaces::srv::LegLightControlSrv_Request, is_control),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "target_leg_light",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_system_interfaces::srv::LegLightControlSrv_Request, target_leg_light),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "light_rgbl_value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    10,  // array size
    false,  // is upper bound
    offsetof(tita_system_interfaces::srv::LegLightControlSrv_Request, light_rgbl_value),  // bytes offset in struct
    nullptr,  // default value
    size_function__LegLightControlSrv_Request__light_rgbl_value,  // size() function pointer
    get_const_function__LegLightControlSrv_Request__light_rgbl_value,  // get_const(index) function pointer
    get_function__LegLightControlSrv_Request__light_rgbl_value,  // get(index) function pointer
    fetch_function__LegLightControlSrv_Request__light_rgbl_value,  // fetch(index, &value) function pointer
    assign_function__LegLightControlSrv_Request__light_rgbl_value,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LegLightControlSrv_Request_message_members = {
  "tita_system_interfaces::srv",  // message namespace
  "LegLightControlSrv_Request",  // message name
  3,  // number of fields
  sizeof(tita_system_interfaces::srv::LegLightControlSrv_Request),
  LegLightControlSrv_Request_message_member_array,  // message members
  LegLightControlSrv_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  LegLightControlSrv_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LegLightControlSrv_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LegLightControlSrv_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace tita_system_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tita_system_interfaces::srv::LegLightControlSrv_Request>()
{
  return &::tita_system_interfaces::srv::rosidl_typesupport_introspection_cpp::LegLightControlSrv_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tita_system_interfaces, srv, LegLightControlSrv_Request)() {
  return &::tita_system_interfaces::srv::rosidl_typesupport_introspection_cpp::LegLightControlSrv_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "tita_system_interfaces/srv/detail/leg_light_control_srv__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tita_system_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void LegLightControlSrv_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tita_system_interfaces::srv::LegLightControlSrv_Response(_init);
}

void LegLightControlSrv_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tita_system_interfaces::srv::LegLightControlSrv_Response *>(message_memory);
  typed_message->~LegLightControlSrv_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LegLightControlSrv_Response_message_member_array[1] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tita_system_interfaces::srv::LegLightControlSrv_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LegLightControlSrv_Response_message_members = {
  "tita_system_interfaces::srv",  // message namespace
  "LegLightControlSrv_Response",  // message name
  1,  // number of fields
  sizeof(tita_system_interfaces::srv::LegLightControlSrv_Response),
  LegLightControlSrv_Response_message_member_array,  // message members
  LegLightControlSrv_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  LegLightControlSrv_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LegLightControlSrv_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LegLightControlSrv_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace tita_system_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tita_system_interfaces::srv::LegLightControlSrv_Response>()
{
  return &::tita_system_interfaces::srv::rosidl_typesupport_introspection_cpp::LegLightControlSrv_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tita_system_interfaces, srv, LegLightControlSrv_Response)() {
  return &::tita_system_interfaces::srv::rosidl_typesupport_introspection_cpp::LegLightControlSrv_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "tita_system_interfaces/srv/detail/leg_light_control_srv__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace tita_system_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers LegLightControlSrv_service_members = {
  "tita_system_interfaces::srv",  // service namespace
  "LegLightControlSrv",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<tita_system_interfaces::srv::LegLightControlSrv>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t LegLightControlSrv_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LegLightControlSrv_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace tita_system_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<tita_system_interfaces::srv::LegLightControlSrv>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::tita_system_interfaces::srv::rosidl_typesupport_introspection_cpp::LegLightControlSrv_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::tita_system_interfaces::srv::LegLightControlSrv_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::tita_system_interfaces::srv::LegLightControlSrv_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tita_system_interfaces, srv, LegLightControlSrv)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<tita_system_interfaces::srv::LegLightControlSrv>();
}

#ifdef __cplusplus
}
#endif
