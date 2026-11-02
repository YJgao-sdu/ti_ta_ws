// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tita_system_interfaces:srv/FanModeSetSrv.idl
// generated code does not contain a copyright notice
#include "tita_system_interfaces/srv/detail/fan_mode_set_srv__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `fan_mode`
#include "std_msgs/msg/detail/byte__functions.h"

bool
tita_system_interfaces__srv__FanModeSetSrv_Request__init(tita_system_interfaces__srv__FanModeSetSrv_Request * msg)
{
  if (!msg) {
    return false;
  }
  // fan_mode
  if (!std_msgs__msg__Byte__init(&msg->fan_mode)) {
    tita_system_interfaces__srv__FanModeSetSrv_Request__fini(msg);
    return false;
  }
  return true;
}

void
tita_system_interfaces__srv__FanModeSetSrv_Request__fini(tita_system_interfaces__srv__FanModeSetSrv_Request * msg)
{
  if (!msg) {
    return;
  }
  // fan_mode
  std_msgs__msg__Byte__fini(&msg->fan_mode);
}

bool
tita_system_interfaces__srv__FanModeSetSrv_Request__are_equal(const tita_system_interfaces__srv__FanModeSetSrv_Request * lhs, const tita_system_interfaces__srv__FanModeSetSrv_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // fan_mode
  if (!std_msgs__msg__Byte__are_equal(
      &(lhs->fan_mode), &(rhs->fan_mode)))
  {
    return false;
  }
  return true;
}

bool
tita_system_interfaces__srv__FanModeSetSrv_Request__copy(
  const tita_system_interfaces__srv__FanModeSetSrv_Request * input,
  tita_system_interfaces__srv__FanModeSetSrv_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // fan_mode
  if (!std_msgs__msg__Byte__copy(
      &(input->fan_mode), &(output->fan_mode)))
  {
    return false;
  }
  return true;
}

tita_system_interfaces__srv__FanModeSetSrv_Request *
tita_system_interfaces__srv__FanModeSetSrv_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__FanModeSetSrv_Request * msg = (tita_system_interfaces__srv__FanModeSetSrv_Request *)allocator.allocate(sizeof(tita_system_interfaces__srv__FanModeSetSrv_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tita_system_interfaces__srv__FanModeSetSrv_Request));
  bool success = tita_system_interfaces__srv__FanModeSetSrv_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tita_system_interfaces__srv__FanModeSetSrv_Request__destroy(tita_system_interfaces__srv__FanModeSetSrv_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tita_system_interfaces__srv__FanModeSetSrv_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence__init(tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__FanModeSetSrv_Request * data = NULL;

  if (size) {
    data = (tita_system_interfaces__srv__FanModeSetSrv_Request *)allocator.zero_allocate(size, sizeof(tita_system_interfaces__srv__FanModeSetSrv_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tita_system_interfaces__srv__FanModeSetSrv_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tita_system_interfaces__srv__FanModeSetSrv_Request__fini(&data[i - 1]);
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
tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence__fini(tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence * array)
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
      tita_system_interfaces__srv__FanModeSetSrv_Request__fini(&array->data[i]);
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

tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence *
tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence * array = (tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence *)allocator.allocate(sizeof(tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence__destroy(tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence__are_equal(const tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence * lhs, const tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tita_system_interfaces__srv__FanModeSetSrv_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence__copy(
  const tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence * input,
  tita_system_interfaces__srv__FanModeSetSrv_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tita_system_interfaces__srv__FanModeSetSrv_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tita_system_interfaces__srv__FanModeSetSrv_Request * data =
      (tita_system_interfaces__srv__FanModeSetSrv_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tita_system_interfaces__srv__FanModeSetSrv_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tita_system_interfaces__srv__FanModeSetSrv_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tita_system_interfaces__srv__FanModeSetSrv_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
tita_system_interfaces__srv__FanModeSetSrv_Response__init(tita_system_interfaces__srv__FanModeSetSrv_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
tita_system_interfaces__srv__FanModeSetSrv_Response__fini(tita_system_interfaces__srv__FanModeSetSrv_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
tita_system_interfaces__srv__FanModeSetSrv_Response__are_equal(const tita_system_interfaces__srv__FanModeSetSrv_Response * lhs, const tita_system_interfaces__srv__FanModeSetSrv_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
tita_system_interfaces__srv__FanModeSetSrv_Response__copy(
  const tita_system_interfaces__srv__FanModeSetSrv_Response * input,
  tita_system_interfaces__srv__FanModeSetSrv_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

tita_system_interfaces__srv__FanModeSetSrv_Response *
tita_system_interfaces__srv__FanModeSetSrv_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__FanModeSetSrv_Response * msg = (tita_system_interfaces__srv__FanModeSetSrv_Response *)allocator.allocate(sizeof(tita_system_interfaces__srv__FanModeSetSrv_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tita_system_interfaces__srv__FanModeSetSrv_Response));
  bool success = tita_system_interfaces__srv__FanModeSetSrv_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tita_system_interfaces__srv__FanModeSetSrv_Response__destroy(tita_system_interfaces__srv__FanModeSetSrv_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tita_system_interfaces__srv__FanModeSetSrv_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence__init(tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__FanModeSetSrv_Response * data = NULL;

  if (size) {
    data = (tita_system_interfaces__srv__FanModeSetSrv_Response *)allocator.zero_allocate(size, sizeof(tita_system_interfaces__srv__FanModeSetSrv_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tita_system_interfaces__srv__FanModeSetSrv_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tita_system_interfaces__srv__FanModeSetSrv_Response__fini(&data[i - 1]);
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
tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence__fini(tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence * array)
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
      tita_system_interfaces__srv__FanModeSetSrv_Response__fini(&array->data[i]);
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

tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence *
tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence * array = (tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence *)allocator.allocate(sizeof(tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence__destroy(tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence__are_equal(const tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence * lhs, const tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tita_system_interfaces__srv__FanModeSetSrv_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence__copy(
  const tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence * input,
  tita_system_interfaces__srv__FanModeSetSrv_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tita_system_interfaces__srv__FanModeSetSrv_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tita_system_interfaces__srv__FanModeSetSrv_Response * data =
      (tita_system_interfaces__srv__FanModeSetSrv_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tita_system_interfaces__srv__FanModeSetSrv_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tita_system_interfaces__srv__FanModeSetSrv_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tita_system_interfaces__srv__FanModeSetSrv_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
