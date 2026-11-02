// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tita_system_interfaces:srv/TailLightControlSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__TAIL_LIGHT_CONTROL_SRV__STRUCT_HPP_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__TAIL_LIGHT_CONTROL_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tita_system_interfaces__srv__TailLightControlSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__tita_system_interfaces__srv__TailLightControlSrv_Request __declspec(deprecated)
#endif

namespace tita_system_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TailLightControlSrv_Request_
{
  using Type = TailLightControlSrv_Request_<ContainerAllocator>;

  explicit TailLightControlSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_control = false;
      std::fill<typename std::array<uint32_t, 36>::iterator, uint32_t>(this->light_rgbl_value.begin(), this->light_rgbl_value.end(), 0ul);
    }
  }

  explicit TailLightControlSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : light_rgbl_value(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_control = false;
      std::fill<typename std::array<uint32_t, 36>::iterator, uint32_t>(this->light_rgbl_value.begin(), this->light_rgbl_value.end(), 0ul);
    }
  }

  // field types and members
  using _is_control_type =
    bool;
  _is_control_type is_control;
  using _light_rgbl_value_type =
    std::array<uint32_t, 36>;
  _light_rgbl_value_type light_rgbl_value;

  // setters for named parameter idiom
  Type & set__is_control(
    const bool & _arg)
  {
    this->is_control = _arg;
    return *this;
  }
  Type & set__light_rgbl_value(
    const std::array<uint32_t, 36> & _arg)
  {
    this->light_rgbl_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_system_interfaces__srv__TailLightControlSrv_Request
    std::shared_ptr<tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_system_interfaces__srv__TailLightControlSrv_Request
    std::shared_ptr<tita_system_interfaces::srv::TailLightControlSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TailLightControlSrv_Request_ & other) const
  {
    if (this->is_control != other.is_control) {
      return false;
    }
    if (this->light_rgbl_value != other.light_rgbl_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const TailLightControlSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TailLightControlSrv_Request_

// alias to use template instance with default allocator
using TailLightControlSrv_Request =
  tita_system_interfaces::srv::TailLightControlSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tita_system_interfaces


#ifndef _WIN32
# define DEPRECATED__tita_system_interfaces__srv__TailLightControlSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__tita_system_interfaces__srv__TailLightControlSrv_Response __declspec(deprecated)
#endif

namespace tita_system_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TailLightControlSrv_Response_
{
  using Type = TailLightControlSrv_Response_<ContainerAllocator>;

  explicit TailLightControlSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit TailLightControlSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_system_interfaces__srv__TailLightControlSrv_Response
    std::shared_ptr<tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_system_interfaces__srv__TailLightControlSrv_Response
    std::shared_ptr<tita_system_interfaces::srv::TailLightControlSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TailLightControlSrv_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const TailLightControlSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TailLightControlSrv_Response_

// alias to use template instance with default allocator
using TailLightControlSrv_Response =
  tita_system_interfaces::srv::TailLightControlSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tita_system_interfaces

namespace tita_system_interfaces
{

namespace srv
{

struct TailLightControlSrv
{
  using Request = tita_system_interfaces::srv::TailLightControlSrv_Request;
  using Response = tita_system_interfaces::srv::TailLightControlSrv_Response;
};

}  // namespace srv

}  // namespace tita_system_interfaces

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__TAIL_LIGHT_CONTROL_SRV__STRUCT_HPP_
