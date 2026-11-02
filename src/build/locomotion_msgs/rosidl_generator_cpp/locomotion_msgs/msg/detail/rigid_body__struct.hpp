// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from locomotion_msgs:msg/RigidBody.idl
// generated code does not contain a copyright notice

#ifndef LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__STRUCT_HPP_
#define LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'inertia'
#include "geometry_msgs/msg/detail/inertia__struct.hpp"
// Member 'transform'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__locomotion_msgs__msg__RigidBody __attribute__((deprecated))
#else
# define DEPRECATED__locomotion_msgs__msg__RigidBody __declspec(deprecated)
#endif

namespace locomotion_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RigidBody_
{
  using Type = RigidBody_<ContainerAllocator>;

  explicit RigidBody_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : inertia(_init),
    transform(_init)
  {
    (void)_init;
  }

  explicit RigidBody_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : inertia(_alloc, _init),
    transform(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _inertia_type =
    geometry_msgs::msg::Inertia_<ContainerAllocator>;
  _inertia_type inertia;
  using _transform_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _transform_type transform;

  // setters for named parameter idiom
  Type & set__inertia(
    const geometry_msgs::msg::Inertia_<ContainerAllocator> & _arg)
  {
    this->inertia = _arg;
    return *this;
  }
  Type & set__transform(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->transform = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    locomotion_msgs::msg::RigidBody_<ContainerAllocator> *;
  using ConstRawPtr =
    const locomotion_msgs::msg::RigidBody_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<locomotion_msgs::msg::RigidBody_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<locomotion_msgs::msg::RigidBody_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      locomotion_msgs::msg::RigidBody_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<locomotion_msgs::msg::RigidBody_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      locomotion_msgs::msg::RigidBody_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<locomotion_msgs::msg::RigidBody_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<locomotion_msgs::msg::RigidBody_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<locomotion_msgs::msg::RigidBody_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__locomotion_msgs__msg__RigidBody
    std::shared_ptr<locomotion_msgs::msg::RigidBody_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__locomotion_msgs__msg__RigidBody
    std::shared_ptr<locomotion_msgs::msg::RigidBody_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RigidBody_ & other) const
  {
    if (this->inertia != other.inertia) {
      return false;
    }
    if (this->transform != other.transform) {
      return false;
    }
    return true;
  }
  bool operator!=(const RigidBody_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RigidBody_

// alias to use template instance with default allocator
using RigidBody =
  locomotion_msgs::msg::RigidBody_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace locomotion_msgs

#endif  // LOCOMOTION_MSGS__MSG__DETAIL__RIGID_BODY__STRUCT_HPP_
