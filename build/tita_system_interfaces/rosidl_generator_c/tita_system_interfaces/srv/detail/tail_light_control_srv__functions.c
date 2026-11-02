// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tita_system_interfaces:srv/TailLightControlSrv.idl
// generated code does not contain a copyright notice
#include "tita_system_interfaces/srv/detail/tail_light_control_srv__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
tita_system_interfaces__srv__TailLightControlSrv_Request__init(tita_system_interfaces__srv__TailLightControlSrv_Request * msg)
{
  if (!msg) {
    return false;
  }
  // is_control
  // light_rgbl_value
  return true;
}

void
tita_system_interfaces__srv__TailLightControlSrv_Request__fini(tita_system_interfaces__srv__TailLightControlSrv_Request * msg)
{
  if (!msg) {
    return;
  }
  // is_control
  // light_rgbl_value
}

bool
tita_system_interfaces__srv__TailLightControlSrv_Request__are_equal(const tita_system_interfaces__srv__TailLightControlSrv_Request * lhs, const tita_system_interfaces__srv__TailLightControlSrv_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_control
  if (lhs->is_control != rhs->is_control) {
    return false;
  }
  // light_rgbl_value
  for (size_t i = 0; i < 36; ++i) {
    if (lhs->light_rgbl_value[i] != rhs->light_rgbl_value[i]) {
      return false;
    }
  }
  return true;
}

bool
tita_system_interfaces__srv__TailLightControlSrv_Request__copy(
  const tita_system_interfaces__srv__TailLightControlSrv_Request * input,
  tita_system_interfaces__srv__TailLightControlSrv_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // is_control
  output->is_control = input->is_control;
  // light_rgbl_value
  for (size_t i = 0; i < 36; ++i) {
    output->light_rgbl_value[i] = input->light_rgbl_value[i];
  }
  return true;
}

tita_system_interfaces__srv__TailLightControlSrv_Request *
tita_system_interfaces__srv__TailLightControlSrv_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__TailLightControlSrv_Request * msg = (tita_system_interfaces__srv__TailLightControlSrv_Request *)allocator.allocate(sizeof(tita_system_interfaces__srv__TailLightControlSrv_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tita_system_interfaces__srv__TailLightControlSrv_Request));
  bool success = tita_system_interfaces__srv__TailLightControlSrv_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tita_system_interfaces__srv__TailLightControlSrv_Request__destroy(tita_system_interfaces__srv__TailLightControlSrv_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tita_system_interfaces__srv__TailLightControlSrv_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence__init(tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__TailLightControlSrv_Request * data = NULL;

  if (size) {
    data = (tita_system_interfaces__srv__TailLightControlSrv_Request *)allocator.zero_allocate(size, sizeof(tita_system_interfaces__srv__TailLightControlSrv_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tita_system_interfaces__srv__TailLightControlSrv_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tita_system_interfaces__srv__TailLightControlSrv_Request__fini(&data[i - 1]);
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
tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence__fini(tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence * array)
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
      tita_system_interfaces__srv__TailLightControlSrv_Request__fini(&array->data[i]);
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

tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence *
tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence * array = (tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence *)allocator.allocate(sizeof(tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence__destroy(tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence__are_equal(const tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence * lhs, const tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tita_system_interfaces__srv__TailLightControlSrv_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence__copy(
  const tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence * input,
  tita_system_interfaces__srv__TailLightControlSrv_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tita_system_interfaces__srv__TailLightControlSrv_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tita_system_interfaces__srv__TailLightControlSrv_Request * data =
      (tita_system_interfaces__srv__TailLightControlSrv_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tita_system_interfaces__srv__TailLightControlSrv_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tita_system_interfaces__srv__TailLightControlSrv_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tita_system_interfaces__srv__TailLightControlSrv_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
tita_system_interfaces__srv__TailLightControlSrv_Response__init(tita_system_interfaces__srv__TailLightControlSrv_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
tita_system_interfaces__srv__TailLightControlSrv_Response__fini(tita_system_interfaces__srv__TailLightControlSrv_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
tita_system_interfaces__srv__TailLightControlSrv_Response__are_equal(const tita_system_interfaces__srv__TailLightControlSrv_Response * lhs, const tita_system_interfaces__srv__TailLightControlSrv_Response * rhs)
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
tita_system_interfaces__srv__TailLightControlSrv_Response__copy(
  const tita_system_interfaces__srv__TailLightControlSrv_Response * input,
  tita_system_interfaces__srv__TailLightControlSrv_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

tita_system_interfaces__srv__TailLightControlSrv_Response *
tita_system_interfaces__srv__TailLightControlSrv_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__TailLightControlSrv_Response * msg = (tita_system_interfaces__srv__TailLightControlSrv_Response *)allocator.allocate(sizeof(tita_system_interfaces__srv__TailLightControlSrv_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tita_system_interfaces__srv__TailLightControlSrv_Response));
  bool success = tita_system_interfaces__srv__TailLightControlSrv_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tita_system_interfaces__srv__TailLightControlSrv_Response__destroy(tita_system_interfaces__srv__TailLightControlSrv_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tita_system_interfaces__srv__TailLightControlSrv_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence__init(tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__TailLightControlSrv_Response * data = NULL;

  if (size) {
    data = (tita_system_interfaces__srv__TailLightControlSrv_Response *)allocator.zero_allocate(size, sizeof(tita_system_interfaces__srv__TailLightControlSrv_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tita_system_interfaces__srv__TailLightControlSrv_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tita_system_interfaces__srv__TailLightControlSrv_Response__fini(&data[i - 1]);
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
tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence__fini(tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence * array)
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
      tita_system_interfaces__srv__TailLightControlSrv_Response__fini(&array->data[i]);
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

tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence *
tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence * array = (tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence *)allocator.allocate(sizeof(tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence__destroy(tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence__are_equal(const tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence * lhs, const tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tita_system_interfaces__srv__TailLightControlSrv_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence__copy(
  const tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence * input,
  tita_system_interfaces__srv__TailLightControlSrv_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tita_system_interfaces__srv__TailLightControlSrv_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tita_system_interfaces__srv__TailLightControlSrv_Response * data =
      (tita_system_interfaces__srv__TailLightControlSrv_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tita_system_interfaces__srv__TailLightControlSrv_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tita_system_interfaces__srv__TailLightControlSrv_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tita_system_interfaces__srv__TailLightControlSrv_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
