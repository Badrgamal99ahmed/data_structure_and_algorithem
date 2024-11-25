
#ifndef STACK_ARRAY_DS_H
#define STACK_ARRAY_DS_H

#include <stdlib.h>


#include "Platform_types.h"

typedef struct{
	void **StackArray;   /* Points to the array that allocated in the heap */
	sint32 ElementCount; /* Has the actual number of elements in the stack */
	uint32 StackMaxSize; /* Has the maximum number of elements in the stack */
	sint32 StackTop;     /* Has the index of the top element in the stack */
}stack_t;

typedef enum{
	STACK_NOK = 0,
	STACK_OK,
	STACK_FULL,
	STACK_EMPTY,
	STACK_NULL_POINTER,
}StackStatus_t;

/**
  * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
  * @param  (maxSize) Stack maximum number of elements
  * @param  (ret_status) Status returned while performing this operation
  * @retval  Pointer to the allocated stack in the heap
  */
stack_t* CreatStack(uint32 maxsize, StackStatus_t *ret_status);

/**
  * @brief  This function releases all memory to the heap.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval NULL
  */
stack_t* DestroyStack(stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief This function pushes an item onto the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (itemPtr) pointer to be inserted
  * @retval Status returned while performing this operation
  */
StackStatus_t Pushstack(stack_t* stack_obj, void* itemptr);

/**
  * @brief This function pops the item on the top of the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* Popstack(stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief  This function retrieves the data from the top of the
            stack without changing the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* StackTop(stack_t* stack_obj, StackStatus_t *ret_status);

/**
  * @brief  Returns number of elements in stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (stack_count) number of elements in stack.
  * @retval Status returned while performing this operation
  */
StackStatus_t StackCount(stack_t* stack_obj, uint32 *stack_count);



#endif  //STACK_ARRAY_DS_H