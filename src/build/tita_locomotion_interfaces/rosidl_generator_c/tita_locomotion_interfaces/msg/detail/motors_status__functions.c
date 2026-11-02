// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tita_locomotion_interfaces:msg/MotorsStatus.idl
// generated code does not contain a copyright notice
#include "tita_locomotion_interfaces/msg/detail/motors_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `value`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
tita_locomotion_interfaces__msg__MotorsStatus__init(tita_locomotion_interfaces__msg__MotorsStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tita_locomotion_interfaces__msg__MotorsStatus__fini(msg);
    return false;
  }
  // key
  // value
  if (!rosidl_runtime_c__boolean__Sequence__init(&msg->value, 0)) {
    tita_locomotion_interfaces__msg__MotorsStatus__fini(msg);
    return false;
  }
  return true;
}

void
tita_locomotion_interfaces__msg__MotorsStatus__fini(tita_locomotion_interfaces__msg__MotorsStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // key
  // value
  rosidl_runtime_c__boolean__Sequence__fini(&msg->value);
}

bool
tita_locomotion_interfaces__msg__MotorsStatus__are_equal(const tita_locomotion_interfaces__msg__MotorsStatus * lhs, const tita_locomotion_interfaces__msg__MotorsStatus * rhs)
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
  // key
  if (lhs->key != rhs->key) {
    return false;
  }
  // value
  if (!rosidl_runtime_c__boolean__Sequence__are_equal(
      &(lhs->value), &(rhs->value)))
  {
    return false;
  }
  return true;
}

bool
tita_locomotion_interfaces__msg__MotorsStatus__copy(
  const tita_locomotion_interfaces__msg__MotorsStatus * input,
  tita_locomotion_interfaces__msg__MotorsStatus * output)
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
  // key
  output->key = input->key;
  // value
  if (!rosidl_runtime_c__boolean__Sequence__copy(
      &(input->value), &(output->value)))
  {
    return false;
  }
  return true;
}

tita_locomotion_interfaces__msg__MotorsStatus *
tita_locomotion_interfaces__msg__MotorsStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_locomotion_interfaces__msg__MotorsStatus * msg = (tita_locomotion_interfaces__msg__MotorsStatus *)allocator.allocate(sizeof(tita_locomotion_interfaces__msg__MotorsStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tita_locomotion_interfaces__msg__MotorsStatus));
  bool success = tita_locomotion_interfaces__msg__MotorsStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tita_locomotion_interfaces__msg__MotorsStatus__destroy(tita_locomotion_interfaces__msg__MotorsStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tita_locomotion_interfaces__msg__MotorsStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__init(tita_locomotion_interfaces__msg__MotorsStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_locomotion_interfaces__msg__MotorsStatus * data = NULL;

  if (size) {
    data = (tita_locomotion_interfaces__msg__MotorsStatus *)allocator.zero_allocate(size, sizeof(tita_locomotion_interfaces__msg__MotorsStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tita_locomotion_interfaces__msg__MotorsStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tita_locomotion_interfaces__msg__MotorsStatus__fini(&data[i - 1]);
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
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__fini(tita_locomotion_interfaces__msg__MotorsStatus__Sequence * array)
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
      tita_locomotion_interfaces__msg__MotorsStatus__fini(&array->data[i]);
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

tita_locomotion_interfaces__msg__MotorsStatus__Sequence *
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_locomotion_interfaces__msg__MotorsStatus__Sequence * array = (tita_locomotion_interfaces__msg__MotorsStatus__Sequence *)allocator.allocate(sizeof(tita_locomotion_interfaces__msg__MotorsStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tita_locomotion_interfaces__msg__MotorsStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__destroy(tita_locomotion_interfaces__msg__MotorsStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tita_locomotion_interfaces__msg__MotorsStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__are_equal(const tita_locomotion_interfaces__msg__MotorsStatus__Sequence * lhs, const tita_locomotion_interfaces__msg__MotorsStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tita_locomotion_interfaces__msg__MotorsStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__copy(
  const tita_locomotion_interfaces__msg__MotorsStatus__Sequence * input,
  tita_locomotion_interfaces__msg__MotorsStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tita_locomotion_interfaces__msg__MotorsStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tita_locomotion_interfaces__msg__MotorsStatus * data =
      (tita_locomotion_interfaces__msg__MotorsStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tita_locomotion_interfaces__msg__MotorsStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tita_locomotion_interfaces__msg__MotorsStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tita_locomotion_interfaces__msg__MotorsStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
