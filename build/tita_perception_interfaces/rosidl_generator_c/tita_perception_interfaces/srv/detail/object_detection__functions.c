// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tita_perception_interfaces:srv/ObjectDetection.idl
// generated code does not contain a copyright notice
#include "tita_perception_interfaces/srv/detail/object_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
tita_perception_interfaces__srv__ObjectDetection_Request__init(tita_perception_interfaces__srv__ObjectDetection_Request * msg)
{
  if (!msg) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    tita_perception_interfaces__srv__ObjectDetection_Request__fini(msg);
    return false;
  }
  return true;
}

void
tita_perception_interfaces__srv__ObjectDetection_Request__fini(tita_perception_interfaces__srv__ObjectDetection_Request * msg)
{
  if (!msg) {
    return;
  }
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
}

bool
tita_perception_interfaces__srv__ObjectDetection_Request__are_equal(const tita_perception_interfaces__srv__ObjectDetection_Request * lhs, const tita_perception_interfaces__srv__ObjectDetection_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
tita_perception_interfaces__srv__ObjectDetection_Request__copy(
  const tita_perception_interfaces__srv__ObjectDetection_Request * input,
  tita_perception_interfaces__srv__ObjectDetection_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

tita_perception_interfaces__srv__ObjectDetection_Request *
tita_perception_interfaces__srv__ObjectDetection_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_perception_interfaces__srv__ObjectDetection_Request * msg = (tita_perception_interfaces__srv__ObjectDetection_Request *)allocator.allocate(sizeof(tita_perception_interfaces__srv__ObjectDetection_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tita_perception_interfaces__srv__ObjectDetection_Request));
  bool success = tita_perception_interfaces__srv__ObjectDetection_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tita_perception_interfaces__srv__ObjectDetection_Request__destroy(tita_perception_interfaces__srv__ObjectDetection_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tita_perception_interfaces__srv__ObjectDetection_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tita_perception_interfaces__srv__ObjectDetection_Request__Sequence__init(tita_perception_interfaces__srv__ObjectDetection_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_perception_interfaces__srv__ObjectDetection_Request * data = NULL;

  if (size) {
    data = (tita_perception_interfaces__srv__ObjectDetection_Request *)allocator.zero_allocate(size, sizeof(tita_perception_interfaces__srv__ObjectDetection_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tita_perception_interfaces__srv__ObjectDetection_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tita_perception_interfaces__srv__ObjectDetection_Request__fini(&data[i - 1]);
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
tita_perception_interfaces__srv__ObjectDetection_Request__Sequence__fini(tita_perception_interfaces__srv__ObjectDetection_Request__Sequence * array)
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
      tita_perception_interfaces__srv__ObjectDetection_Request__fini(&array->data[i]);
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

tita_perception_interfaces__srv__ObjectDetection_Request__Sequence *
tita_perception_interfaces__srv__ObjectDetection_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_perception_interfaces__srv__ObjectDetection_Request__Sequence * array = (tita_perception_interfaces__srv__ObjectDetection_Request__Sequence *)allocator.allocate(sizeof(tita_perception_interfaces__srv__ObjectDetection_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tita_perception_interfaces__srv__ObjectDetection_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tita_perception_interfaces__srv__ObjectDetection_Request__Sequence__destroy(tita_perception_interfaces__srv__ObjectDetection_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tita_perception_interfaces__srv__ObjectDetection_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tita_perception_interfaces__srv__ObjectDetection_Request__Sequence__are_equal(const tita_perception_interfaces__srv__ObjectDetection_Request__Sequence * lhs, const tita_perception_interfaces__srv__ObjectDetection_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tita_perception_interfaces__srv__ObjectDetection_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tita_perception_interfaces__srv__ObjectDetection_Request__Sequence__copy(
  const tita_perception_interfaces__srv__ObjectDetection_Request__Sequence * input,
  tita_perception_interfaces__srv__ObjectDetection_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tita_perception_interfaces__srv__ObjectDetection_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tita_perception_interfaces__srv__ObjectDetection_Request * data =
      (tita_perception_interfaces__srv__ObjectDetection_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tita_perception_interfaces__srv__ObjectDetection_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tita_perception_interfaces__srv__ObjectDetection_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tita_perception_interfaces__srv__ObjectDetection_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
#include "tita_perception_interfaces/msg/detail/bounding_box_array__functions.h"

bool
tita_perception_interfaces__srv__ObjectDetection_Response__init(tita_perception_interfaces__srv__ObjectDetection_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!tita_perception_interfaces__msg__BoundingBoxArray__init(&msg->result)) {
    tita_perception_interfaces__srv__ObjectDetection_Response__fini(msg);
    return false;
  }
  return true;
}

void
tita_perception_interfaces__srv__ObjectDetection_Response__fini(tita_perception_interfaces__srv__ObjectDetection_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  tita_perception_interfaces__msg__BoundingBoxArray__fini(&msg->result);
}

bool
tita_perception_interfaces__srv__ObjectDetection_Response__are_equal(const tita_perception_interfaces__srv__ObjectDetection_Response * lhs, const tita_perception_interfaces__srv__ObjectDetection_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!tita_perception_interfaces__msg__BoundingBoxArray__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
tita_perception_interfaces__srv__ObjectDetection_Response__copy(
  const tita_perception_interfaces__srv__ObjectDetection_Response * input,
  tita_perception_interfaces__srv__ObjectDetection_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!tita_perception_interfaces__msg__BoundingBoxArray__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

tita_perception_interfaces__srv__ObjectDetection_Response *
tita_perception_interfaces__srv__ObjectDetection_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_perception_interfaces__srv__ObjectDetection_Response * msg = (tita_perception_interfaces__srv__ObjectDetection_Response *)allocator.allocate(sizeof(tita_perception_interfaces__srv__ObjectDetection_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tita_perception_interfaces__srv__ObjectDetection_Response));
  bool success = tita_perception_interfaces__srv__ObjectDetection_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tita_perception_interfaces__srv__ObjectDetection_Response__destroy(tita_perception_interfaces__srv__ObjectDetection_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tita_perception_interfaces__srv__ObjectDetection_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tita_perception_interfaces__srv__ObjectDetection_Response__Sequence__init(tita_perception_interfaces__srv__ObjectDetection_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_perception_interfaces__srv__ObjectDetection_Response * data = NULL;

  if (size) {
    data = (tita_perception_interfaces__srv__ObjectDetection_Response *)allocator.zero_allocate(size, sizeof(tita_perception_interfaces__srv__ObjectDetection_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tita_perception_interfaces__srv__ObjectDetection_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tita_perception_interfaces__srv__ObjectDetection_Response__fini(&data[i - 1]);
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
tita_perception_interfaces__srv__ObjectDetection_Response__Sequence__fini(tita_perception_interfaces__srv__ObjectDetection_Response__Sequence * array)
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
      tita_perception_interfaces__srv__ObjectDetection_Response__fini(&array->data[i]);
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

tita_perception_interfaces__srv__ObjectDetection_Response__Sequence *
tita_perception_interfaces__srv__ObjectDetection_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_perception_interfaces__srv__ObjectDetection_Response__Sequence * array = (tita_perception_interfaces__srv__ObjectDetection_Response__Sequence *)allocator.allocate(sizeof(tita_perception_interfaces__srv__ObjectDetection_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tita_perception_interfaces__srv__ObjectDetection_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tita_perception_interfaces__srv__ObjectDetection_Response__Sequence__destroy(tita_perception_interfaces__srv__ObjectDetection_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tita_perception_interfaces__srv__ObjectDetection_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tita_perception_interfaces__srv__ObjectDetection_Response__Sequence__are_equal(const tita_perception_interfaces__srv__ObjectDetection_Response__Sequence * lhs, const tita_perception_interfaces__srv__ObjectDetection_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tita_perception_interfaces__srv__ObjectDetection_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tita_perception_interfaces__srv__ObjectDetection_Response__Sequence__copy(
  const tita_perception_interfaces__srv__ObjectDetection_Response__Sequence * input,
  tita_perception_interfaces__srv__ObjectDetection_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tita_perception_interfaces__srv__ObjectDetection_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tita_perception_interfaces__srv__ObjectDetection_Response * data =
      (tita_perception_interfaces__srv__ObjectDetection_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tita_perception_interfaces__srv__ObjectDetection_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tita_perception_interfaces__srv__ObjectDetection_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tita_perception_interfaces__srv__ObjectDetection_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
