// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tita_system_interfaces:srv/PowerHeartBeatSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_HEART_BEAT_SRV__STRUCT_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_HEART_BEAT_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'power_heart_beat'
#include "diagnostic_msgs/msg/detail/diagnostic_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tita_system_interfaces__srv__PowerHeartBeatSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__tita_system_interfaces__srv__PowerHeartBeatSrv_Request __declspec(deprecated)
#endif

namespace tita_system_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PowerHeartBeatSrv_Request_
{
  using Type = PowerHeartBeatSrv_Request_<ContainerAllocator>;

  explicit PowerHeartBeatSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : power_heart_beat(_init)
  {
    (void)_init;
  }

  explicit PowerHeartBeatSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : power_heart_beat(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _power_heart_beat_type =
    diagnostic_msgs::msg::DiagnosticArray_<ContainerAllocator>;
  _power_heart_beat_type power_heart_beat;

  // setters for named parameter idiom
  Type & set__power_heart_beat(
    const diagnostic_msgs::msg::DiagnosticArray_<ContainerAllocator> & _arg)
  {
    this->power_heart_beat = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_system_interfaces__srv__PowerHeartBeatSrv_Request
    std::shared_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_system_interfaces__srv__PowerHeartBeatSrv_Request
    std::shared_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PowerHeartBeatSrv_Request_ & other) const
  {
    if (this->power_heart_beat != other.power_heart_beat) {
      return false;
    }
    return true;
  }
  bool operator!=(const PowerHeartBeatSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PowerHeartBeatSrv_Request_

// alias to use template instance with default allocator
using PowerHeartBeatSrv_Request =
  tita_system_interfaces::srv::PowerHeartBeatSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tita_system_interfaces


#ifndef _WIN32
# define DEPRECATED__tita_system_interfaces__srv__PowerHeartBeatSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__tita_system_interfaces__srv__PowerHeartBeatSrv_Response __declspec(deprecated)
#endif

namespace tita_system_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PowerHeartBeatSrv_Response_
{
  using Type = PowerHeartBeatSrv_Response_<ContainerAllocator>;

  explicit PowerHeartBeatSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit PowerHeartBeatSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_system_interfaces__srv__PowerHeartBeatSrv_Response
    std::shared_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_system_interfaces__srv__PowerHeartBeatSrv_Response
    std::shared_ptr<tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PowerHeartBeatSrv_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const PowerHeartBeatSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PowerHeartBeatSrv_Response_

// alias to use template instance with default allocator
using PowerHeartBeatSrv_Response =
  tita_system_interfaces::srv::PowerHeartBeatSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tita_system_interfaces

namespace tita_system_interfaces
{

namespace srv
{

struct PowerHeartBeatSrv
{
  using Request = tita_system_interfaces::srv::PowerHeartBeatSrv_Request;
  using Response = tita_system_interfaces::srv::PowerHeartBeatSrv_Response;
};

}  // namespace srv

}  // namespace tita_system_interfaces

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_HEART_BEAT_SRV__STRUCT_HPP_
