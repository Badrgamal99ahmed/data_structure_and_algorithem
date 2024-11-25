

#include "s_arr.h"

static uint8 StackEmpty(stack_t* stack_obj);
static uint8 StackFull(stack_t* stack_obj);


/**
  * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
  * @param  (maxSize) Stack maximum number of elements
  * @param  (ret_status) Status returned while performing this operation
  * @retval  Pointer to the allocated stack in the heap
  */
stack_t *CreatStack(uint32 maxsize, StackStatus_t *ret_status){
	stack_t *my_stack = NULL;
	if(NULL == ret_status){
		*ret_status = STACK_NULL_POINTER;
		my_stack = NULL;
	}
	else{
		my_stack = (stack_t *)malloc(sizeof(stack_t));
		if(!my_stack){
			*ret_status = STACK_NOK;
			my_stack =NULL;
		}
		else{
			my_stack->StackTop = -1;
			my_stack->ElementCount = 0;
			my_stack->StackMaxSize = maxsize;
			my_stack->StackArray = (void **)calloc(my_stack->StackMaxSize, sizeof(void *));
			if(!my_stack->StackArray){
				free(my_stack);
				*ret_status = STACK_NOK;
				my_stack = NULL;
			}
			else{
				*ret_status = STACK_OK;
			}
		}
	}
	return my_stack;
}

/**
  * @brief  This function releases all memory to the heap.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval NULL
  */
stack_t* DestroyStack(stack_t* stack_obj, StackStatus_t *ret_status){
	if((NULL == ret_status) || (NULL == stack_obj)){
		*ret_status = STACK_NULL_POINTER;
	}
	else{
		free(stack_obj->StackArray);
		free(stack_obj);
		*ret_status = STACK_OK;
	}
	return NULL;
}

/**
  * @brief This function pushes an item onto the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (itemPtr) pointer to be inserted
  * @retval Status returned while performing this operation
  */
StackStatus_t Pushstack(stack_t *stack_obj, void *itemptr){
	StackStatus_t stackstatus = STACK_NOK;
	if((NULL == stack_obj) || (NULL == itemptr)){
		stackstatus = STACK_NULL_POINTER;
	}
	else{
		if(StackFull(stack_obj)){
			stackstatus = STACK_FULL;
		}
		else{
			(stack_obj->StackTop)++;
			stack_obj->StackArray[stack_obj->StackTop] = itemptr;
			(stack_obj->ElementCount)++;
			stackstatus = STACK_OK;
		}
	}
	return stackstatus;
}

/**
  * @brief This function pops the item on the top of the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* Popstack(stack_t* stack_obj, StackStatus_t *ret_status){
	void *dataptr = NULL;
	if((NULL == ret_status) || (NULL == stack_obj)){
		*ret_status = STACK_NULL_POINTER;
		dataptr = NULL;
	}
	else{
		if(StackEmpty(stack_obj)){
			*ret_status = STACK_EMPTY;
			dataptr = NULL;
		}
		else{
			dataptr = stack_obj->StackArray[stack_obj->StackTop];
			(stack_obj->StackTop)--;
			(stack_obj->ElementCount)--;
			*ret_status = STACK_OK;
		}
	}
	return dataptr;
}

/**
  * @brief  This function retrieves the data from the top of the
            stack without changing the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* StackTop(stack_t* stack_obj, StackStatus_t *ret_status){
	void *dataptr = NULL;
	if((NULL == ret_status) || (NULL == stack_obj)){
		*ret_status = STACK_NULL_POINTER;
		dataptr = NULL;
	}
	else{
		if(StackEmpty(stack_obj)){
			*ret_status = STACK_EMPTY;
			dataptr = NULL;
		}
		else{
			/* Copy the top element to the user */
			dataptr = stack_obj->StackArray[stack_obj->StackTop];
			*ret_status = STACK_OK;
		}
	}
	return dataptr;
}

/**
  * @brief  Returns number of elements in stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (stack_count) number of elements in stack.
  * @retval Status returned while performing this operation
  */
StackStatus_t StackCount(stack_t* stack_obj, uint32 *stack_count){
	StackStatus_t stackstatus = STACK_NOK;
	if((NULL == stack_obj) || (NULL == stack_count)){
		stackstatus = STACK_NULL_POINTER;	/* poiter passed to the function */
	}
	else{
		*stack_count = stack_obj->ElementCount;
		stackstatus = STACK_OK;
	}
	return stackstatus;
}

static uint8 StackEmpty(stack_t* stack_obj){
	return(stack_obj->ElementCount == 0);
}

static uint8 StackFull(stack_t* stack_obj){
	return(stack_obj->ElementCount == stack_obj->StackMaxSize);
}
