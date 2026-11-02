// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tita_locomotion_interfaces:msg/MotorsStatus.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__STRUCT_HPP_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__tita_locomotion_interfaces__msg__MotorsStatus __attribute__((deprecated))
#else
# define DEPRECATED__tita_locomotion_interfaces__msg__MotorsStatus __declspec(deprecated)
#endif

namespace tita_locomotion_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorsStatus_
{
  using Type = MotorsStatus_<ContainerAllocator>;

  explicit MotorsStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = 0;
    }
  }

  explicit MotorsStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _key_type =
    uint16_t;
  _key_type key;
  using _value_type =
    std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>>;
  _value_type value;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__key(
    const uint16_t & _arg)
  {
    this->key = _arg;
    return *this;
  }
  Type & set__value(
    const std::vector<bool, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<bool>> & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_locomotion_interfaces__msg__MotorsStatus
    std::shared_ptr<tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_locomotion_interfaces__msg__MotorsStatus
    std::shared_ptr<tita_locomotion_interfaces::msg::MotorsStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorsStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->key != other.key) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorsStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorsStatus_

// alias to use template instance with default allocator
using MotorsStatus =
  tita_locomotion_interfaces::msg::MotorsStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tita_locomotion_interfaces

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__STRUCT_HPP_
