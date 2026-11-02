// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from locomotion_msgs:msg/PlanCommands.idl
// generated code does not contain a copyright notice

#ifndef LOCOMOTION_MSGS__MSG__DETAIL__PLAN_COMMANDS__FUNCTIONS_H_
#define LOCOMOTION_MSGS__MSG__DETAIL__PLAN_COMMANDS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "locomotion_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "locomotion_msgs/msg/detail/plan_commands__struct.h"

/// Initialize msg/PlanCommands message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * locomotion_msgs__msg__PlanCommands
 * )) before or use
 * locomotion_msgs__msg__PlanCommands__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
bool
locomotion_msgs__msg__PlanCommands__init(locomotion_msgs__msg__PlanCommands * msg);

/// Finalize msg/PlanCommands message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
void
locomotion_msgs__msg__PlanCommands__fini(locomotion_msgs__msg__PlanCommands * msg);

/// Create msg/PlanCommands message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * locomotion_msgs__msg__PlanCommands__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
locomotion_msgs__msg__PlanCommands *
locomotion_msgs__msg__PlanCommands__create();

/// Destroy msg/PlanCommands message.
/**
 * It calls
 * locomotion_msgs__msg__PlanCommands__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
void
locomotion_msgs__msg__PlanCommands__destroy(locomotion_msgs__msg__PlanCommands * msg);

/// Check for msg/PlanCommands message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
bool
locomotion_msgs__msg__PlanCommands__are_equal(const locomotion_msgs__msg__PlanCommands * lhs, const locomotion_msgs__msg__PlanCommands * rhs);

/// Copy a msg/PlanCommands message.
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
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
bool
locomotion_msgs__msg__PlanCommands__copy(
  const locomotion_msgs__msg__PlanCommands * input,
  locomotion_msgs__msg__PlanCommands * output);

/// Initialize array of msg/PlanCommands messages.
/**
 * It allocates the memory for the number of elements and calls
 * locomotion_msgs__msg__PlanCommands__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
bool
locomotion_msgs__msg__PlanCommands__Sequence__init(locomotion_msgs__msg__PlanCommands__Sequence * array, size_t size);

/// Finalize array of msg/PlanCommands messages.
/**
 * It calls
 * locomotion_msgs__msg__PlanCommands__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
void
locomotion_msgs__msg__PlanCommands__Sequence__fini(locomotion_msgs__msg__PlanCommands__Sequence * array);

/// Create array of msg/PlanCommands messages.
/**
 * It allocates the memory for the array and calls
 * locomotion_msgs__msg__PlanCommands__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
locomotion_msgs__msg__PlanCommands__Sequence *
locomotion_msgs__msg__PlanCommands__Sequence__create(size_t size);

/// Destroy array of msg/PlanCommands messages.
/**
 * It calls
 * locomotion_msgs__msg__PlanCommands__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
void
locomotion_msgs__msg__PlanCommands__Sequence__destroy(locomotion_msgs__msg__PlanCommands__Sequence * array);

/// Check for msg/PlanCommands message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
bool
locomotion_msgs__msg__PlanCommands__Sequence__are_equal(const locomotion_msgs__msg__PlanCommands__Sequence * lhs, const locomotion_msgs__msg__PlanCommands__Sequence * rhs);

/// Copy an array of msg/PlanCommands messages.
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
ROSIDL_GENERATOR_C_PUBLIC_locomotion_msgs
bool
locomotion_msgs__msg__PlanCommands__Sequence__copy(
  const locomotion_msgs__msg__PlanCommands__Sequence * input,
  locomotion_msgs__msg__PlanCommands__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LOCOMOTION_MSGS__MSG__DETAIL__PLAN_COMMANDS__FUNCTIONS_H_
