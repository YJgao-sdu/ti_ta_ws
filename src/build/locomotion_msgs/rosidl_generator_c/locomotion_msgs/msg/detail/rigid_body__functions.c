// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from locomotion_msgs:msg/RigidBody.idl
// generated code does not contain a copyright notice
#include "locomotion_msgs/msg/detail/rigid_body__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `inertia`
#include "geometry_msgs/msg/detail/inertia__functions.h"
// Member `transform`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
locomotion_msgs__msg__RigidBody__init(locomotion_msgs__msg__RigidBody * msg)
{
  if (!msg) {
    return false;
  }
  // inertia
  if (!geometry_msgs__msg__Inertia__init(&msg->inertia)) {
    locomotion_msgs__msg__RigidBody__fini(msg);
    return false;
  }
  // transform
  if (!geometry_msgs__msg__Pose__init(&msg->transform)) {
    locomotion_msgs__msg__RigidBody__fini(msg);
    return false;
  }
  return true;
}

void
locomotion_msgs__msg__RigidBody__fini(locomotion_msgs__msg__RigidBody * msg)
{
  if (!msg) {
    return;
  }
  // inertia
  geometry_msgs__msg__Inertia__fini(&msg->inertia);
  // transform
  geometry_msgs__msg__Pose__fini(&msg->transform);
}

bool
locomotion_msgs__msg__RigidBody__are_equal(const locomotion_msgs__msg__RigidBody * lhs, const locomotion_msgs__msg__RigidBody * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // inertia
  if (!geometry_msgs__msg__Inertia__are_equal(
      &(lhs->inertia), &(rhs->inertia)))
  {
    return false;
  }
  // transform
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->transform), &(rhs->transform)))
  {
    return false;
  }
  return true;
}

bool
locomotion_msgs__msg__RigidBody__copy(
  const locomotion_msgs__msg__RigidBody * input,
  locomotion_msgs__msg__RigidBody * output)
{
  if (!input || !output) {
    return false;
  }
  // inertia
  if (!geometry_msgs__msg__Inertia__copy(
      &(input->inertia), &(output->inertia)))
  {
    return false;
  }
  // transform
  if (!geometry_msgs__msg__Pose__copy(
      &(input->transform), &(output->transform)))
  {
    return false;
  }
  return true;
}

locomotion_msgs__msg__RigidBody *
locomotion_msgs__msg__RigidBody__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  locomotion_msgs__msg__RigidBody * msg = (locomotion_msgs__msg__RigidBody *)allocator.allocate(sizeof(locomotion_msgs__msg__RigidBody), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(locomotion_msgs__msg__RigidBody));
  bool success = locomotion_msgs__msg__RigidBody__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
locomotion_msgs__msg__RigidBody__destroy(locomotion_msgs__msg__RigidBody * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    locomotion_msgs__msg__RigidBody__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
locomotion_msgs__msg__RigidBody__Sequence__init(locomotion_msgs__msg__RigidBody__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  locomotion_msgs__msg__RigidBody * data = NULL;

  if (size) {
    data = (locomotion_msgs__msg__RigidBody *)allocator.zero_allocate(size, sizeof(locomotion_msgs__msg__RigidBody), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = locomotion_msgs__msg__RigidBody__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        locomotion_msgs__msg__RigidBody__fini(&data[i - 1]);
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
locomotion_msgs__msg__RigidBody__Sequence__fini(locomotion_msgs__msg__RigidBody__Sequence * array)
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
      locomotion_msgs__msg__RigidBody__fini(&array->data[i]);
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

locomotion_msgs__msg__RigidBody__Sequence *
locomotion_msgs__msg__RigidBody__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  locomotion_msgs__msg__RigidBody__Sequence * array = (locomotion_msgs__msg__RigidBody__Sequence *)allocator.allocate(sizeof(locomotion_msgs__msg__RigidBody__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = locomotion_msgs__msg__RigidBody__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
locomotion_msgs__msg__RigidBody__Sequence__destroy(locomotion_msgs__msg__RigidBody__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    locomotion_msgs__msg__RigidBody__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
locomotion_msgs__msg__RigidBody__Sequence__are_equal(const locomotion_msgs__msg__RigidBody__Sequence * lhs, const locomotion_msgs__msg__RigidBody__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!locomotion_msgs__msg__RigidBody__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
locomotion_msgs__msg__RigidBody__Sequence__copy(
  const locomotion_msgs__msg__RigidBody__Sequence * input,
  locomotion_msgs__msg__RigidBody__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(locomotion_msgs__msg__RigidBody);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    locomotion_msgs__msg__RigidBody * data =
      (locomotion_msgs__msg__RigidBody *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!locomotion_msgs__msg__RigidBody__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          locomotion_msgs__msg__RigidBody__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!locomotion_msgs__msg__RigidBody__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
