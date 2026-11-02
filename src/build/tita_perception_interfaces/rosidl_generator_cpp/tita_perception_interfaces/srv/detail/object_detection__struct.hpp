// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tita_perception_interfaces:srv/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__STRUCT_HPP_
#define TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tita_perception_interfaces__srv__ObjectDetection_Request __attribute__((deprecated))
#else
# define DEPRECATED__tita_perception_interfaces__srv__ObjectDetection_Request __declspec(deprecated)
#endif

namespace tita_perception_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ObjectDetection_Request_
{
  using Type = ObjectDetection_Request_<ContainerAllocator>;

  explicit ObjectDetection_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_init)
  {
    (void)_init;
  }

  explicit ObjectDetection_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_perception_interfaces__srv__ObjectDetection_Request
    std::shared_ptr<tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_perception_interfaces__srv__ObjectDetection_Request
    std::shared_ptr<tita_perception_interfaces::srv::ObjectDetection_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectDetection_Request_ & other) const
  {
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectDetection_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectDetection_Request_

// alias to use template instance with default allocator
using ObjectDetection_Request =
  tita_perception_interfaces::srv::ObjectDetection_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tita_perception_interfaces


// Include directives for member types
// Member 'result'
#include "tita_perception_interfaces/msg/detail/bounding_box_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tita_perception_interfaces__srv__ObjectDetection_Response __attribute__((deprecated))
#else
# define DEPRECATED__tita_perception_interfaces__srv__ObjectDetection_Response __declspec(deprecated)
#endif

namespace tita_perception_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ObjectDetection_Response_
{
  using Type = ObjectDetection_Response_<ContainerAllocator>;

  explicit ObjectDetection_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    (void)_init;
  }

  explicit ObjectDetection_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _result_type =
    tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const tita_perception_interfaces::msg::BoundingBoxArray_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tita_perception_interfaces__srv__ObjectDetection_Response
    std::shared_ptr<tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tita_perception_interfaces__srv__ObjectDetection_Response
    std::shared_ptr<tita_perception_interfaces::srv::ObjectDetection_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectDetection_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectDetection_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectDetection_Response_

// alias to use template instance with default allocator
using ObjectDetection_Response =
  tita_perception_interfaces::srv::ObjectDetection_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tita_perception_interfaces

namespace tita_perception_interfaces
{

namespace srv
{

struct ObjectDetection
{
  using Request = tita_perception_interfaces::srv::ObjectDetection_Request;
  using Response = tita_perception_interfaces::srv::ObjectDetection_Response;
};

}  // namespace srv

}  // namespace tita_perception_interfaces

#endif  // TITA_PERCEPTION_INTERFACES__SRV__DETAIL__OBJECT_DETECTION__STRUCT_HPP_
