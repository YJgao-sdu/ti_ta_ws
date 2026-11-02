// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from tita_locomotion_interfaces:msg/MotorsStatus.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "tita_locomotion_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "tita_locomotion_interfaces/msg/detail/motors_status__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace tita_locomotion_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tita_locomotion_interfaces
cdr_serialize(
  const tita_locomotion_interfaces::msg::MotorsStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tita_locomotion_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tita_locomotion_interfaces::msg::MotorsStatus & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tita_locomotion_interfaces
get_serialized_size(
  const tita_locomotion_interfaces::msg::MotorsStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tita_locomotion_interfaces
max_serialized_size_MotorsStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace tita_locomotion_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tita_locomotion_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tita_locomotion_interfaces, msg, MotorsStatus)();

#ifdef __cplusplus
}
#endif

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
