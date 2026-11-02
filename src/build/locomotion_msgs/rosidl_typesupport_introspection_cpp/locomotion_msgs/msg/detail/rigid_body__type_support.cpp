// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from locomotion_msgs:msg/RigidBody.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "locomotion_msgs/msg/detail/rigid_body__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace locomotion_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RigidBody_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) locomotion_msgs::msg::RigidBody(_init);
}

void RigidBody_fini_function(void * message_memory)
{
  auto typed_message = static_cast<locomotion_msgs::msg::RigidBody *>(message_memory);
  typed_message->~RigidBody();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RigidBody_message_member_array[2] = {
  {
    "inertia",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Inertia>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs::msg::RigidBody, inertia),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "transform",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Pose>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(locomotion_msgs::msg::RigidBody, transform),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RigidBody_message_members = {
  "locomotion_msgs::msg",  // message namespace
  "RigidBody",  // message name
  2,  // number of fields
  sizeof(locomotion_msgs::msg::RigidBody),
  RigidBody_message_member_array,  // message members
  RigidBody_init_function,  // function to initialize message memory (memory has to be allocated)
  RigidBody_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RigidBody_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RigidBody_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace locomotion_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<locomotion_msgs::msg::RigidBody>()
{
  return &::locomotion_msgs::msg::rosidl_typesupport_introspection_cpp::RigidBody_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, locomotion_msgs, msg, RigidBody)() {
  return &::locomotion_msgs::msg::rosidl_typesupport_introspection_cpp::RigidBody_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
