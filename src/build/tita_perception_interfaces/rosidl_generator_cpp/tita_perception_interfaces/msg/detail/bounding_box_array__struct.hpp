// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tita_perception_interfaces:msg/BoundingBoxArray.idl
// generated code does not contain a copyright notice

#ifndef TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__STRUCT_HPP_
#define TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__STRUCT_HPP_

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
// Member 'boxes'
#include "tita_perception_interfaces/msg/detail/bounding_box__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tita_perception_interfaces__msg__BoundingBoxArray __attribute__((deprecated))
#else
# define DEPRECATED__tita_perception_interfaces__msg__BoundingBoxArray __declspec(deprecated)
#endif

namespace tita_perception_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BoundingBoxArray_
{
  using Type = BoundingBoxArray_<ContainerAllocator>;

  explicit BoundingBoxArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit BoundingBoxArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _boxes_type =
    std::vector<tita_perception_interfaces::msg::BoundingBox_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tita_perception_interfaces::msg::BoundingBox_<ContainerAllocator>>>;
  _boxes_type boxes;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__boxes(
    const std::vector<tita_perception_interfaces::msg::BoundingBox_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tita_perception_interfaces::msg::BoundingBox_<ContainerAllocator>>> & _arg)
  {
    this->boxes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_perception_interfaces__msg__BoundingBoxArray
    std::shared_ptr<tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_perception_interfaces__msg__BoundingBoxArray
    std::shared_ptr<tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoundingBoxArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->boxes != other.boxes) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoundingBoxArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoundingBoxArray_

// alias to use template instance with default allocator
using BoundingBoxArray =
  tita_perception_interfaces::msg::BoundingBoxArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tita_perception_interfaces

#endif  // TITA_PERCEPTION_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__STRUCT_HPP_
