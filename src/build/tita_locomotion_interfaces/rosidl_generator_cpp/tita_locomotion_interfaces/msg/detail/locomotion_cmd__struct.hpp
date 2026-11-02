// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tita_locomotion_interfaces:msg/LocomotionCmd.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__STRUCT_HPP_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tita_locomotion_interfaces__msg__LocomotionCmd __attribute__((deprecated))
#else
# define DEPRECATED__tita_locomotion_interfaces__msg__LocomotionCmd __declspec(deprecated)
#endif

namespace tita_locomotion_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LocomotionCmd_
{
  using Type = LocomotionCmd_<ContainerAllocator>;

  explicit LocomotionCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pose(_init),
    twist(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fsm_mode = "";
    }
  }

  explicit LocomotionCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    fsm_mode(_alloc),
    pose(_alloc, _init),
    twist(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fsm_mode = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _fsm_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fsm_mode_type fsm_mode;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _twist_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _twist_type twist;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__fsm_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fsm_mode = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__twist(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->twist = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_locomotion_interfaces__msg__LocomotionCmd
    std::shared_ptr<tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_locomotion_interfaces__msg__LocomotionCmd
    std::shared_ptr<tita_locomotion_interfaces::msg::LocomotionCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LocomotionCmd_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->fsm_mode != other.fsm_mode) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->twist != other.twist) {
      return false;
    }
    return true;
  }
  bool operator!=(const LocomotionCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LocomotionCmd_

// alias to use template instance with default allocator
using LocomotionCmd =
  tita_locomotion_interfaces::msg::LocomotionCmd_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tita_locomotion_interfaces

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__STRUCT_HPP_
