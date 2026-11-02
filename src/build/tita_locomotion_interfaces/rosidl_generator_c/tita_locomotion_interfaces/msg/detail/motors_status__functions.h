// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tita_locomotion_interfaces:msg/MotorsStatus.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__FUNCTIONS_H_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tita_locomotion_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tita_locomotion_interfaces/msg/detail/motors_status__struct.h"

/// Initialize msg/MotorsStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tita_locomotion_interfaces__msg__MotorsStatus
 * )) before or use
 * tita_locomotion_interfaces__msg__MotorsStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
bool
tita_locomotion_interfaces__msg__MotorsStatus__init(tita_locomotion_interfaces__msg__MotorsStatus * msg);

/// Finalize msg/MotorsStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
void
tita_locomotion_interfaces__msg__MotorsStatus__fini(tita_locomotion_interfaces__msg__MotorsStatus * msg);

/// Create msg/MotorsStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tita_locomotion_interfaces__msg__MotorsStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
tita_locomotion_interfaces__msg__MotorsStatus *
tita_locomotion_interfaces__msg__MotorsStatus__create();

/// Destroy msg/MotorsStatus message.
/**
 * It calls
 * tita_locomotion_interfaces__msg__MotorsStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
void
tita_locomotion_interfaces__msg__MotorsStatus__destroy(tita_locomotion_interfaces__msg__MotorsStatus * msg);

/// Check for msg/MotorsStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
bool
tita_locomotion_interfaces__msg__MotorsStatus__are_equal(const tita_locomotion_interfaces__msg__MotorsStatus * lhs, const tita_locomotion_interfaces__msg__MotorsStatus * rhs);

/// Copy a msg/MotorsStatus message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
bool
tita_locomotion_interfaces__msg__MotorsStatus__copy(
  const tita_locomotion_interfaces__msg__MotorsStatus * input,
  tita_locomotion_interfaces__msg__MotorsStatus * output);

/// Initialize array of msg/MotorsStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * tita_locomotion_interfaces__msg__MotorsStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
bool
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__init(tita_locomotion_interfaces__msg__MotorsStatus__Sequence * array, size_t size);

/// Finalize array of msg/MotorsStatus messages.
/**
 * It calls
 * tita_locomotion_interfaces__msg__MotorsStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
void
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__fini(tita_locomotion_interfaces__msg__MotorsStatus__Sequence * array);

/// Create array of msg/MotorsStatus messages.
/**
 * It allocates the memory for the array and calls
 * tita_locomotion_interfaces__msg__MotorsStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
tita_locomotion_interfaces__msg__MotorsStatus__Sequence *
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__create(size_t size);

/// Destroy array of msg/MotorsStatus messages.
/**
 * It calls
 * tita_locomotion_interfaces__msg__MotorsStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
void
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__destroy(tita_locomotion_interfaces__msg__MotorsStatus__Sequence * array);

/// Check for msg/MotorsStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
bool
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__are_equal(const tita_locomotion_interfaces__msg__MotorsStatus__Sequence * lhs, const tita_locomotion_interfaces__msg__MotorsStatus__Sequence * rhs);

/// Copy an array of msg/MotorsStatus messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
bool
tita_locomotion_interfaces__msg__MotorsStatus__Sequence__copy(
  const tita_locomotion_interfaces__msg__MotorsStatus__Sequence * input,
  tita_locomotion_interfaces__msg__MotorsStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__MOTORS_STATUS__FUNCTIONS_H_
