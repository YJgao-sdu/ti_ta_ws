// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from locomotion_msgs:msg/PlanCommands.idl
// generated code does not contain a copyright notice
#include "locomotion_msgs/msg/detail/plan_commands__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `fsm_state_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `twist_linear`
// Member `twist_linear_int`
// Member `twist_angular`
// Member `twist_angular_int`
// Member `pose_position`
// Member `pose_position_dot`
// Member `pose_rpy`
// Member `pose_rpy_dot`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `joint_positions`
// Member `joint_velocities`
// Member `joint_torques`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
locomotion_msgs__msg__PlanCommands__init(locomotion_msgs__msg__PlanCommands * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // fsm_state_name
  if (!rosidl_runtime_c__String__init(&msg->fsm_state_name)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // twist_linear
  if (!geometry_msgs__msg__Vector3__init(&msg->twist_linear)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // twist_linear_int
  if (!geometry_msgs__msg__Vector3__init(&msg->twist_linear_int)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // twist_angular
  if (!geometry_msgs__msg__Vector3__init(&msg->twist_angular)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // twist_angular_int
  if (!geometry_msgs__msg__Vector3__init(&msg->twist_angular_int)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // pose_position
  if (!geometry_msgs__msg__Vector3__init(&msg->pose_position)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // pose_position_dot
  if (!geometry_msgs__msg__Vector3__init(&msg->pose_position_dot)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // pose_rpy
  if (!geometry_msgs__msg__Vector3__init(&msg->pose_rpy)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // pose_rpy_dot
  if (!geometry_msgs__msg__Vector3__init(&msg->pose_rpy_dot)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // two_wheel_distance
  // two_wheel_distance_dot
  // joint_positions
  if (!rosidl_runtime_c__double__Sequence__init(&msg->joint_positions, 0)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // joint_velocities
  if (!rosidl_runtime_c__double__Sequence__init(&msg->joint_velocities, 0)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  // joint_torques
  if (!rosidl_runtime_c__double__Sequence__init(&msg->joint_torques, 0)) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
    return false;
  }
  return true;
}

void
locomotion_msgs__msg__PlanCommands__fini(locomotion_msgs__msg__PlanCommands * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // fsm_state_name
  rosidl_runtime_c__String__fini(&msg->fsm_state_name);
  // twist_linear
  geometry_msgs__msg__Vector3__fini(&msg->twist_linear);
  // twist_linear_int
  geometry_msgs__msg__Vector3__fini(&msg->twist_linear_int);
  // twist_angular
  geometry_msgs__msg__Vector3__fini(&msg->twist_angular);
  // twist_angular_int
  geometry_msgs__msg__Vector3__fini(&msg->twist_angular_int);
  // pose_position
  geometry_msgs__msg__Vector3__fini(&msg->pose_position);
  // pose_position_dot
  geometry_msgs__msg__Vector3__fini(&msg->pose_position_dot);
  // pose_rpy
  geometry_msgs__msg__Vector3__fini(&msg->pose_rpy);
  // pose_rpy_dot
  geometry_msgs__msg__Vector3__fini(&msg->pose_rpy_dot);
  // two_wheel_distance
  // two_wheel_distance_dot
  // joint_positions
  rosidl_runtime_c__double__Sequence__fini(&msg->joint_positions);
  // joint_velocities
  rosidl_runtime_c__double__Sequence__fini(&msg->joint_velocities);
  // joint_torques
  rosidl_runtime_c__double__Sequence__fini(&msg->joint_torques);
}

bool
locomotion_msgs__msg__PlanCommands__are_equal(const locomotion_msgs__msg__PlanCommands * lhs, const locomotion_msgs__msg__PlanCommands * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // fsm_state_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->fsm_state_name), &(rhs->fsm_state_name)))
  {
    return false;
  }
  // twist_linear
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->twist_linear), &(rhs->twist_linear)))
  {
    return false;
  }
  // twist_linear_int
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->twist_linear_int), &(rhs->twist_linear_int)))
  {
    return false;
  }
  // twist_angular
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->twist_angular), &(rhs->twist_angular)))
  {
    return false;
  }
  // twist_angular_int
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->twist_angular_int), &(rhs->twist_angular_int)))
  {
    return false;
  }
  // pose_position
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->pose_position), &(rhs->pose_position)))
  {
    return false;
  }
  // pose_position_dot
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->pose_position_dot), &(rhs->pose_position_dot)))
  {
    return false;
  }
  // pose_rpy
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->pose_rpy), &(rhs->pose_rpy)))
  {
    return false;
  }
  // pose_rpy_dot
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->pose_rpy_dot), &(rhs->pose_rpy_dot)))
  {
    return false;
  }
  // two_wheel_distance
  if (lhs->two_wheel_distance != rhs->two_wheel_distance) {
    return false;
  }
  // two_wheel_distance_dot
  if (lhs->two_wheel_distance_dot != rhs->two_wheel_distance_dot) {
    return false;
  }
  // joint_positions
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->joint_positions), &(rhs->joint_positions)))
  {
    return false;
  }
  // joint_velocities
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->joint_velocities), &(rhs->joint_velocities)))
  {
    return false;
  }
  // joint_torques
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->joint_torques), &(rhs->joint_torques)))
  {
    return false;
  }
  return true;
}

bool
locomotion_msgs__msg__PlanCommands__copy(
  const locomotion_msgs__msg__PlanCommands * input,
  locomotion_msgs__msg__PlanCommands * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // fsm_state_name
  if (!rosidl_runtime_c__String__copy(
      &(input->fsm_state_name), &(output->fsm_state_name)))
  {
    return false;
  }
  // twist_linear
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->twist_linear), &(output->twist_linear)))
  {
    return false;
  }
  // twist_linear_int
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->twist_linear_int), &(output->twist_linear_int)))
  {
    return false;
  }
  // twist_angular
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->twist_angular), &(output->twist_angular)))
  {
    return false;
  }
  // twist_angular_int
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->twist_angular_int), &(output->twist_angular_int)))
  {
    return false;
  }
  // pose_position
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->pose_position), &(output->pose_position)))
  {
    return false;
  }
  // pose_position_dot
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->pose_position_dot), &(output->pose_position_dot)))
  {
    return false;
  }
  // pose_rpy
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->pose_rpy), &(output->pose_rpy)))
  {
    return false;
  }
  // pose_rpy_dot
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->pose_rpy_dot), &(output->pose_rpy_dot)))
  {
    return false;
  }
  // two_wheel_distance
  output->two_wheel_distance = input->two_wheel_distance;
  // two_wheel_distance_dot
  output->two_wheel_distance_dot = input->two_wheel_distance_dot;
  // joint_positions
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->joint_positions), &(output->joint_positions)))
  {
    return false;
  }
  // joint_velocities
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->joint_velocities), &(output->joint_velocities)))
  {
    return false;
  }
  // joint_torques
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->joint_torques), &(output->joint_torques)))
  {
    return false;
  }
  return true;
}

locomotion_msgs__msg__PlanCommands *
locomotion_msgs__msg__PlanCommands__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  locomotion_msgs__msg__PlanCommands * msg = (locomotion_msgs__msg__PlanCommands *)allocator.allocate(sizeof(locomotion_msgs__msg__PlanCommands), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(locomotion_msgs__msg__PlanCommands));
  bool success = locomotion_msgs__msg__PlanCommands__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
locomotion_msgs__msg__PlanCommands__destroy(locomotion_msgs__msg__PlanCommands * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    locomotion_msgs__msg__PlanCommands__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
locomotion_msgs__msg__PlanCommands__Sequence__init(locomotion_msgs__msg__PlanCommands__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  locomotion_msgs__msg__PlanCommands * data = NULL;

  if (size) {
    data = (locomotion_msgs__msg__PlanCommands *)allocator.zero_allocate(size, sizeof(locomotion_msgs__msg__PlanCommands), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = locomotion_msgs__msg__PlanCommands__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        locomotion_msgs__msg__PlanCommands__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
locomotion_msgs__msg__PlanCommands__Sequence__fini(locomotion_msgs__msg__PlanCommands__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      locomotion_msgs__msg__PlanCommands__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

locomotion_msgs__msg__PlanCommands__Sequence *
locomotion_msgs__msg__PlanCommands__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  locomotion_msgs__msg__PlanCommands__Sequence * array = (locomotion_msgs__msg__PlanCommands__Sequence *)allocator.allocate(sizeof(locomotion_msgs__msg__PlanCommands__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = locomotion_msgs__msg__PlanCommands__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
locomotion_msgs__msg__PlanCommands__Sequence__destroy(locomotion_msgs__msg__PlanCommands__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    locomotion_msgs__msg__PlanCommands__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
locomotion_msgs__msg__PlanCommands__Sequence__are_equal(const locomotion_msgs__msg__PlanCommands__Sequence * lhs, const locomotion_msgs__msg__PlanCommands__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!locomotion_msgs__msg__PlanCommands__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
locomotion_msgs__msg__PlanCommands__Sequence__copy(
  const locomotion_msgs__msg__PlanCommands__Sequence * input,
  locomotion_msgs__msg__PlanCommands__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(locomotion_msgs__msg__PlanCommands);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    locomotion_msgs__msg__PlanCommands * data =
      (locomotion_msgs__msg__PlanCommands *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!locomotion_msgs__msg__PlanCommands__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          locomotion_msgs__msg__PlanCommands__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!locomotion_msgs__msg__PlanCommands__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
