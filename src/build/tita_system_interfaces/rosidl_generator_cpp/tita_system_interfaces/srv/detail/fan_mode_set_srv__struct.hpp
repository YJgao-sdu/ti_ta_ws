// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tita_system_interfaces:srv/FanModeSetSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__FAN_MODE_SET_SRV__STRUCT_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__FAN_MODE_SET_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'fan_mode'
#include "std_msgs/msg/detail/byte__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tita_system_interfaces__srv__FanModeSetSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__tita_system_interfaces__srv__FanModeSetSrv_Request __declspec(deprecated)
#endif

namespace tita_system_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FanModeSetSrv_Request_
{
  using Type = FanModeSetSrv_Request_<ContainerAllocator>;

  explicit FanModeSetSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fan_mode(_init)
  {
    (void)_init;
  }

  explicit FanModeSetSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fan_mode(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _fan_mode_type =
    std_msgs::msg::Byte_<ContainerAllocator>;
  _fan_mode_type fan_mode;

  // setters for named parameter idiom
  Type & set__fan_mode(
    const std_msgs::msg::Byte_<ContainerAllocator> & _arg)
  {
    this->fan_mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_system_interfaces__srv__FanModeSetSrv_Request
    std::shared_ptr<tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_system_interfaces__srv__FanModeSetSrv_Request
    std::shared_ptr<tita_system_interfaces::srv::FanModeSetSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FanModeSetSrv_Request_ & other) const
  {
    if (this->fan_mode != other.fan_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const FanModeSetSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FanModeSetSrv_Request_

// alias to use template instance with default allocator
using FanModeSetSrv_Request =
  tita_system_interfaces::srv::FanModeSetSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tita_system_interfaces


#ifndef _WIN32
# define DEPRECATED__tita_system_interfaces__srv__FanModeSetSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__tita_system_interfaces__srv__FanModeSetSrv_Response __declspec(deprecated)
#endif

namespace tita_system_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FanModeSetSrv_Response_
{
  using Type = FanModeSetSrv_Response_<ContainerAllocator>;

  explicit FanModeSetSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit FanModeSetSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_system_interfaces__srv__FanModeSetSrv_Response
    std::shared_ptr<tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_system_interfaces__srv__FanModeSetSrv_Response
    std::shared_ptr<tita_system_interfaces::srv::FanModeSetSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FanModeSetSrv_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const FanModeSetSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FanModeSetSrv_Response_

// alias to use template instance with default allocator
using FanModeSetSrv_Response =
  tita_system_interfaces::srv::FanModeSetSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tita_system_interfaces

namespace tita_system_interfaces
{

namespace srv
{

struct FanModeSetSrv
{
  using Request = tita_system_interfaces::srv::FanModeSetSrv_Request;
  using Response = tita_system_interfaces::srv::FanModeSetSrv_Response;
};

}  // namespace srv

}  // namespace tita_system_interfaces

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__FAN_MODE_SET_SRV__STRUCT_HPP_
