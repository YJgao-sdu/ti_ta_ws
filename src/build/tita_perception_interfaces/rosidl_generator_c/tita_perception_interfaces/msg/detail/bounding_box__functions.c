// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tita_perception_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice
#include "tita_perception_interfaces/msg/detail/bounding_box__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `label`
#include "rosidl_runtime_c/string_functions.h"

bool
tita_perception_interfaces__msg__BoundingBox__init(tita_perception_interfaces__msg__BoundingBox * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tita_perception_interfaces__msg__BoundingBox__fini(msg);
    return false;
  }
  // x_min
  // y_min
  // x_max
  // y_max
  // label
  if (!rosidl_runtime_c__String__init(&msg->label)) {
    tita_perception_interfaces__msg__BoundingBox__fini(msg);
    return false;
  }
  return true;
}

void
tita_perception_interfaces__msg__BoundingBox__fini(tita_perception_interfaces__msg__BoundingBox * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // x_min
  // y_min
  // x_max
  // y_max
  // label
  rosidl_runtime_c__String__fini(&msg->label);
}

bool
tita_perception_interfaces__msg__BoundingBox__are_equal(const tita_perception_interfaces__msg__BoundingBox * lhs, const tita_perception_interfaces__msg__BoundingBox * rhs)
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
  // x_min
  if (lhs->x_min != rhs->x_min) {
    return false;
  }
  // y_min
  if (lhs->y_min != rhs->y_min) {
    return false;
  }
  // x_max
  if (lhs->x_max != rhs->x_max) {
    return false;
  }
  // y_max
  if (lhs->y_max != rhs->y_max) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->label), &(rhs->label)))
  {
    return false;
  }
  return true;
}

bool
tita_perception_interfaces__msg__BoundingBox__copy(
  const tita_perception_interfaces__msg__BoundingBox * input,
  tita_perception_interfaces__msg__BoundingBox * output)
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
  // x_min
  output->x_min = input->x_min;
  // y_min
  output->y_min = input->y_min;
  // x_max
  output->x_max = input->x_max;
  // y_max
  output->y_max = input->y_max;
  // label
  if (!rosidl_runtime_c__String__copy(
      &(input->label), &(output->label)))
  {
    return false;
  }
  return true;
}

tita_perception_interfaces__msg__BoundingBox *
tita_perception_interfaces__msg__BoundingBox__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_perception_interfaces__msg__BoundingBox * msg = (tita_perception_interfaces__msg__BoundingBox *)allocator.allocate(sizeof(tita_perception_interfaces__msg__BoundingBox), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tita_perception_interfaces__msg__BoundingBox));
  bool success = tita_perception_interfaces__msg__BoundingBox__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tita_perception_interfaces__msg__BoundingBox__destroy(tita_perception_interfaces__msg__BoundingBox * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tita_perception_interfaces__msg__BoundingBox__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tita_perception_interfaces__msg__BoundingBox__Sequence__init(tita_perception_interfaces__msg__BoundingBox__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_perception_interfaces__msg__BoundingBox * data = NULL;

  if (size) {
    data = (tita_perception_interfaces__msg__BoundingBox *)allocator.zero_allocate(size, sizeof(tita_perception_interfaces__msg__BoundingBox), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tita_perception_interfaces__msg__BoundingBox__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tita_perception_interfaces__msg__BoundingBox__fini(&data[i - 1]);
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
tita_perception_interfaces__msg__BoundingBox__Sequence__fini(tita_perception_interfaces__msg__BoundingBox__Sequence * array)
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
      tita_perception_interfaces__msg__BoundingBox__fini(&array->data[i]);
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

tita_perception_interfaces__msg__BoundingBox__Sequence *
tita_perception_interfaces__msg__BoundingBox__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_perception_interfaces__msg__BoundingBox__Sequence * array = (tita_perception_interfaces__msg__BoundingBox__Sequence *)allocator.allocate(sizeof(tita_perception_interfaces__msg__BoundingBox__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tita_perception_interfaces__msg__BoundingBox__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tita_perception_interfaces__msg__BoundingBox__Sequence__destroy(tita_perception_interfaces__msg__BoundingBox__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tita_perception_interfaces__msg__BoundingBox__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tita_perception_interfaces__msg__BoundingBox__Sequence__are_equal(const tita_perception_interfaces__msg__BoundingBox__Sequence * lhs, const tita_perception_interfaces__msg__BoundingBox__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tita_perception_interfaces__msg__BoundingBox__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tita_perception_interfaces__msg__BoundingBox__Sequence__copy(
  const tita_perception_interfaces__msg__BoundingBox__Sequence * input,
  tita_perception_interfaces__msg__BoundingBox__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tita_perception_interfaces__msg__BoundingBox);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tita_perception_interfaces__msg__BoundingBox * data =
      (tita_perception_interfaces__msg__BoundingBox *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tita_perception_interfaces__msg__BoundingBox__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tita_perception_interfaces__msg__BoundingBox__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tita_perception_interfaces__msg__BoundingBox__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
