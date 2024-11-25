

#ifndef _STACK_H
#define _STACK_H

#include "std_typ.h"

#define STACK_MAX_SIZE 5

#define STACK_DEBUG

typedef struct stack_ds{
	uint32_t stack_pointer;
	uint32_t data[STACK_MAX_SIZE];
}stack_ds_t;

typedef enum stack_status{
	STACK_EMPTY,
	STACK_FULL,
	STACK_NOT_FULL
}stack_status_t;

/**
 * @brief initialization the stack pointer
 * @param my_stack pointer to the stack
 * @retval status of the initialization process
 */
return_status_t stack_init(stack_ds_t *my_stack);
/**
 * @brief add new element at the stack
 * @param my_stack pointer to the stack
 * @retval status of the stack_push
 */
return_status_t stack_push(stack_ds_t *my_stack, uint32_t value);
/**
 * @brief get the last element pushed at the stack
 * @param my_stack pointer to the stack
 * @retval status of the stack_pop
 */
return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *value);
/**
 * @brief get the last element pushed at the stack
 * @param my_stack pointer to the stack
 * @retval status of the stack_top
 */
return_status_t stack_top(stack_ds_t *my_stack, uint32_t *value);
/**
 * @brief get the size of the stack -> no.of.elements
 * @param my_stack pointer to the stack
 * @param stack_size size of the stack
 * @retval status of the stack_size
 */
return_status_t stack_size(stack_ds_t *my_stack, uint32_t *stack_size);
/**
 * @brief display element at the stack
 * @param my_stack pointer to the stack
 * @retval status of the stack_display
 */
return_status_t stack_display(stack_ds_t *my_stack);

#endif
