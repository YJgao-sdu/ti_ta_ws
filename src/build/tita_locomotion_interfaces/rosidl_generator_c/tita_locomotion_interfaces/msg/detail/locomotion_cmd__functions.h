// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tita_locomotion_interfaces:msg/LocomotionCmd.idl
// generated code does not contain a copyright notice

#ifndef TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__FUNCTIONS_H_
#define TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tita_locomotion_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tita_locomotion_interfaces/msg/detail/locomotion_cmd__struct.h"

/// Initialize msg/LocomotionCmd message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tita_locomotion_interfaces__msg__LocomotionCmd
 * )) before or use
 * tita_locomotion_interfaces__msg__LocomotionCmd__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
bool
tita_locomotion_interfaces__msg__LocomotionCmd__init(tita_locomotion_interfaces__msg__LocomotionCmd * msg);

/// Finalize msg/LocomotionCmd message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
void
tita_locomotion_interfaces__msg__LocomotionCmd__fini(tita_locomotion_interfaces__msg__LocomotionCmd * msg);

/// Create msg/LocomotionCmd message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tita_locomotion_interfaces__msg__LocomotionCmd__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
tita_locomotion_interfaces__msg__LocomotionCmd *
tita_locomotion_interfaces__msg__LocomotionCmd__create();

/// Destroy msg/LocomotionCmd message.
/**
 * It calls
 * tita_locomotion_interfaces__msg__LocomotionCmd__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
void
tita_locomotion_interfaces__msg__LocomotionCmd__destroy(tita_locomotion_interfaces__msg__LocomotionCmd * msg);

/// Check for msg/LocomotionCmd message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
bool
tita_locomotion_interfaces__msg__LocomotionCmd__are_equal(const tita_locomotion_interfaces__msg__LocomotionCmd * lhs, const tita_locomotion_interfaces__msg__LocomotionCmd * rhs);

/// Copy a msg/LocomotionCmd message.
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
tita_locomotion_interfaces__msg__LocomotionCmd__copy(
  const tita_locomotion_interfaces__msg__LocomotionCmd * input,
  tita_locomotion_interfaces__msg__LocomotionCmd * output);

/// Initialize array of msg/LocomotionCmd messages.
/**
 * It allocates the memory for the number of elements and calls
 * tita_locomotion_interfaces__msg__LocomotionCmd__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
bool
tita_locomotion_interfaces__msg__LocomotionCmd__Sequence__init(tita_locomotion_interfaces__msg__LocomotionCmd__Sequence * array, size_t size);

/// Finalize array of msg/LocomotionCmd messages.
/**
 * It calls
 * tita_locomotion_interfaces__msg__LocomotionCmd__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
void
tita_locomotion_interfaces__msg__LocomotionCmd__Sequence__fini(tita_locomotion_interfaces__msg__LocomotionCmd__Sequence * array);

/// Create array of msg/LocomotionCmd messages.
/**
 * It allocates the memory for the array and calls
 * tita_locomotion_interfaces__msg__LocomotionCmd__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
tita_locomotion_interfaces__msg__LocomotionCmd__Sequence *
tita_locomotion_interfaces__msg__LocomotionCmd__Sequence__create(size_t size);

/// Destroy array of msg/LocomotionCmd messages.
/**
 * It calls
 * tita_locomotion_interfaces__msg__LocomotionCmd__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
void
tita_locomotion_interfaces__msg__LocomotionCmd__Sequence__destroy(tita_locomotion_interfaces__msg__LocomotionCmd__Sequence * array);

/// Check for msg/LocomotionCmd message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_locomotion_interfaces
bool
tita_locomotion_interfaces__msg__LocomotionCmd__Sequence__are_equal(const tita_locomotion_interfaces__msg__LocomotionCmd__Sequence * lhs, const tita_locomotion_interfaces__msg__LocomotionCmd__Sequence * rhs);

/// Copy an array of msg/LocomotionCmd messages.
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
tita_locomotion_interfaces__msg__LocomotionCmd__Sequence__copy(
  const tita_locomotion_interfaces__msg__LocomotionCmd__Sequence * input,
  tita_locomotion_interfaces__msg__LocomotionCmd__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TITA_LOCOMOTION_INTERFACES__MSG__DETAIL__LOCOMOTION_CMD__FUNCTIONS_H_
