// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from locomotion_msgs:msg/PlanCommands.idl
// generated code does not contain a copyright notice

#ifndef LOCOMOTION_MSGS__MSG__DETAIL__PLAN_COMMANDS__STRUCT_HPP_
#define LOCOMOTION_MSGS__MSG__DETAIL__PLAN_COMMANDS__STRUCT_HPP_

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
// Member 'twist_linear'
// Member 'twist_linear_int'
// Member 'twist_angular'
// Member 'twist_angular_int'
// Member 'pose_position'
// Member 'pose_position_dot'
// Member 'pose_rpy'
// Member 'pose_rpy_dot'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__locomotion_msgs__msg__PlanCommands __attribute__((deprecated))
#else
# define DEPRECATED__locomotion_msgs__msg__PlanCommands __declspec(deprecated)
#endif

namespace locomotion_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PlanCommands_
{
  using Type = PlanCommands_<ContainerAllocator>;

  explicit PlanCommands_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    twist_linear(_init),
    twist_linear_int(_init),
    twist_angular(_init),
    twist_angular_int(_init),
    pose_position(_init),
    pose_position_dot(_init),
    pose_rpy(_init),
    pose_rpy_dot(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fsm_state_name = "";
      this->two_wheel_distance = 0.0;
      this->two_wheel_distance_dot = 0.0;
    }
  }

  explicit PlanCommands_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    fsm_state_name(_alloc),
    twist_linear(_alloc, _init),
    twist_linear_int(_alloc, _init),
    twist_angular(_alloc, _init),
    twist_angular_int(_alloc, _init),
    pose_position(_alloc, _init),
    pose_position_dot(_alloc, _init),
    pose_rpy(_alloc, _init),
    pose_rpy_dot(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fsm_state_name = "";
      this->two_wheel_distance = 0.0;
      this->two_wheel_distance_dot = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _fsm_state_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fsm_state_name_type fsm_state_name;
  using _twist_linear_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _twist_linear_type twist_linear;
  using _twist_linear_int_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _twist_linear_int_type twist_linear_int;
  using _twist_angular_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _twist_angular_type twist_angular;
  using _twist_angular_int_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _twist_angular_int_type twist_angular_int;
  using _pose_position_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _pose_position_type pose_position;
  using _pose_position_dot_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _pose_position_dot_type pose_position_dot;
  using _pose_rpy_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _pose_rpy_type pose_rpy;
  using _pose_rpy_dot_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _pose_rpy_dot_type pose_rpy_dot;
  using _two_wheel_distance_type =
    double;
  _two_wheel_distance_type two_wheel_distance;
  using _two_wheel_distance_dot_type =
    double;
  _two_wheel_distance_dot_type two_wheel_distance_dot;
  using _joint_positions_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _joint_positions_type joint_positions;
  using _joint_velocities_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _joint_velocities_type joint_velocities;
  using _joint_torques_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _joint_torques_type joint_torques;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__fsm_state_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fsm_state_name = _arg;
    return *this;
  }
  Type & set__twist_linear(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->twist_linear = _arg;
    return *this;
  }
  Type & set__twist_linear_int(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->twist_linear_int = _arg;
    return *this;
  }
  Type & set__twist_angular(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->twist_angular = _arg;
    return *this;
  }
  Type & set__twist_angular_int(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->twist_angular_int = _arg;
    return *this;
  }
  Type & set__pose_position(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->pose_position = _arg;
    return *this;
  }
  Type & set__pose_position_dot(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->pose_position_dot = _arg;
    return *this;
  }
  Type & set__pose_rpy(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->pose_rpy = _arg;
    return *this;
  }
  Type & set__pose_rpy_dot(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->pose_rpy_dot = _arg;
    return *this;
  }
  Type & set__two_wheel_distance(
    const double & _arg)
  {
    this->two_wheel_distance = _arg;
    return *this;
  }
  Type & set__two_wheel_distance_dot(
    const double & _arg)
  {
    this->two_wheel_distance_dot = _arg;
    return *this;
  }
  Type & set__joint_positions(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->joint_positions = _arg;
    return *this;
  }
  Type & set__joint_velocities(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->joint_velocities = _arg;
    return *this;
  }
  Type & set__joint_torques(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->joint_torques = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    locomotion_msgs::msg::PlanCommands_<ContainerAllocator> *;
  using ConstRawPtr =
    const locomotion_msgs::msg::PlanCommands_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<locomotion_msgs::msg::PlanCommands_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<locomotion_msgs::msg::PlanCommands_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      locomotion_msgs::msg::PlanCommands_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<locomotion_msgs::msg::PlanCommands_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      locomotion_msgs::msg::PlanCommands_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<locomotion_msgs::msg::PlanCommands_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<locomotion_msgs::msg::PlanCommands_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<locomotion_msgs::msg::PlanCommands_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__locomotion_msgs__msg__PlanCommands
    std::shared_ptr<locomotion_msgs::msg::PlanCommands_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__locomotion_msgs__msg__PlanCommands
    std::shared_ptr<locomotion_msgs::msg::PlanCommands_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanCommands_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->fsm_state_name != other.fsm_state_name) {
      return false;
    }
    if (this->twist_linear != other.twist_linear) {
      return false;
    }
    if (this->twist_linear_int != other.twist_linear_int) {
      return false;
    }
    if (this->twist_angular != other.twist_angular) {
      return false;
    }
    if (this->twist_angular_int != other.twist_angular_int) {
      return false;
    }
    if (this->pose_position != other.pose_position) {
      return false;
    }
    if (this->pose_position_dot != other.pose_position_dot) {
      return false;
    }
    if (this->pose_rpy != other.pose_rpy) {
      return false;
    }
    if (this->pose_rpy_dot != other.pose_rpy_dot) {
      return false;
    }
    if (this->two_wheel_distance != other.two_wheel_distance) {
      return false;
    }
    if (this->two_wheel_distance_dot != other.two_wheel_distance_dot) {
      return false;
    }
    if (this->joint_positions != other.joint_positions) {
      return false;
    }
    if (this->joint_velocities != other.joint_velocities) {
      return false;
    }
    if (this->joint_torques != other.joint_torques) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanCommands_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanCommands_

// alias to use template instance with default allocator
using PlanCommands =
  locomotion_msgs::msg::PlanCommands_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace locomotion_msgs

#endif  // LOCOMOTION_MSGS__MSG__DETAIL__PLAN_COMMANDS__STRUCT_HPP_
