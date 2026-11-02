// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tita_system_interfaces:srv/PowerSelfTestSrv.idl
// generated code does not contain a copyright notice

#ifndef TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__FUNCTIONS_H_
#define TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tita_system_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tita_system_interfaces/srv/detail/power_self_test_srv__struct.h"

/// Initialize srv/PowerSelfTestSrv message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tita_system_interfaces__srv__PowerSelfTestSrv_Request
 * )) before or use
 * tita_system_interfaces__srv__PowerSelfTestSrv_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Request__init(tita_system_interfaces__srv__PowerSelfTestSrv_Request * msg);

/// Finalize srv/PowerSelfTestSrv message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
void
tita_system_interfaces__srv__PowerSelfTestSrv_Request__fini(tita_system_interfaces__srv__PowerSelfTestSrv_Request * msg);

/// Create srv/PowerSelfTestSrv message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
tita_system_interfaces__srv__PowerSelfTestSrv_Request *
tita_system_interfaces__srv__PowerSelfTestSrv_Request__create();

/// Destroy srv/PowerSelfTestSrv message.
/**
 * It calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
void
tita_system_interfaces__srv__PowerSelfTestSrv_Request__destroy(tita_system_interfaces__srv__PowerSelfTestSrv_Request * msg);

/// Check for srv/PowerSelfTestSrv message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Request__are_equal(const tita_system_interfaces__srv__PowerSelfTestSrv_Request * lhs, const tita_system_interfaces__srv__PowerSelfTestSrv_Request * rhs);

/// Copy a srv/PowerSelfTestSrv message.
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
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Request__copy(
  const tita_system_interfaces__srv__PowerSelfTestSrv_Request * input,
  tita_system_interfaces__srv__PowerSelfTestSrv_Request * output);

/// Initialize array of srv/PowerSelfTestSrv messages.
/**
 * It allocates the memory for the number of elements and calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence__init(tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence * array, size_t size);

/// Finalize array of srv/PowerSelfTestSrv messages.
/**
 * It calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
void
tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence__fini(tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence * array);

/// Create array of srv/PowerSelfTestSrv messages.
/**
 * It allocates the memory for the array and calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence *
tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence__create(size_t size);

/// Destroy array of srv/PowerSelfTestSrv messages.
/**
 * It calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
void
tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence__destroy(tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence * array);

/// Check for srv/PowerSelfTestSrv message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence__are_equal(const tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence * lhs, const tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence * rhs);

/// Copy an array of srv/PowerSelfTestSrv messages.
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
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence__copy(
  const tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence * input,
  tita_system_interfaces__srv__PowerSelfTestSrv_Request__Sequence * output);

/// Initialize srv/PowerSelfTestSrv message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tita_system_interfaces__srv__PowerSelfTestSrv_Response
 * )) before or use
 * tita_system_interfaces__srv__PowerSelfTestSrv_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Response__init(tita_system_interfaces__srv__PowerSelfTestSrv_Response * msg);

/// Finalize srv/PowerSelfTestSrv message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
void
tita_system_interfaces__srv__PowerSelfTestSrv_Response__fini(tita_system_interfaces__srv__PowerSelfTestSrv_Response * msg);

/// Create srv/PowerSelfTestSrv message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
tita_system_interfaces__srv__PowerSelfTestSrv_Response *
tita_system_interfaces__srv__PowerSelfTestSrv_Response__create();

/// Destroy srv/PowerSelfTestSrv message.
/**
 * It calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
void
tita_system_interfaces__srv__PowerSelfTestSrv_Response__destroy(tita_system_interfaces__srv__PowerSelfTestSrv_Response * msg);

/// Check for srv/PowerSelfTestSrv message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Response__are_equal(const tita_system_interfaces__srv__PowerSelfTestSrv_Response * lhs, const tita_system_interfaces__srv__PowerSelfTestSrv_Response * rhs);

/// Copy a srv/PowerSelfTestSrv message.
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
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Response__copy(
  const tita_system_interfaces__srv__PowerSelfTestSrv_Response * input,
  tita_system_interfaces__srv__PowerSelfTestSrv_Response * output);

/// Initialize array of srv/PowerSelfTestSrv messages.
/**
 * It allocates the memory for the number of elements and calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence__init(tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence * array, size_t size);

/// Finalize array of srv/PowerSelfTestSrv messages.
/**
 * It calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
void
tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence__fini(tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence * array);

/// Create array of srv/PowerSelfTestSrv messages.
/**
 * It allocates the memory for the array and calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence *
tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence__create(size_t size);

/// Destroy array of srv/PowerSelfTestSrv messages.
/**
 * It calls
 * tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
void
tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence__destroy(tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence * array);

/// Check for srv/PowerSelfTestSrv message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence__are_equal(const tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence * lhs, const tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence * rhs);

/// Copy an array of srv/PowerSelfTestSrv messages.
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
ROSIDL_GENERATOR_C_PUBLIC_tita_system_interfaces
bool
tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence__copy(
  const tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence * input,
  tita_system_interfaces__srv__PowerSelfTestSrv_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TITA_SYSTEM_INTERFACES__SRV__DETAIL__POWER_SELF_TEST_SRV__FUNCTIONS_H_
