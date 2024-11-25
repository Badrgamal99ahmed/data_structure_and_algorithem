

#include "stack.h"

/**
 * @brief check stack is full
 * @param my_stack pointer to the stack
 * @retval status of the stack
 */
static stack_status_t stack_full(stack_ds_t *my_stack){
	if(my_stack->stack_pointer == STACK_MAX_SIZE-1){
		return STACK_FULL;
	}
	else{
		return STACK_NOT_FULL;
	}
}

/**
 * @brief check stack is empty
 * @param my_stack pointer to the stack
 * @retval status of the stack
 */
static stack_status_t stack_empty(stack_ds_t *my_stack){
	if(my_stack->stack_pointer == - 1){
		return STACK_EMPTY;
	}
	else{
		return STACK_NOT_FULL;
	}
}

/**
 * @brief intialization the stack pointer
 * @param my_stack pointer to the stack
 * @retval status of the intialization process
 */
return_status_t stack_init(stack_ds_t *my_stack){
	return_status_t ret = R_NOK;
	if(NULL == my_stack){
		ret = R_NOK;

	}
	else{
		my_stack->stack_pointer = -1;
		ret = R_OK;
	}
	return ret;
}

/**
 * @brief add new element at the stack
 * @param my_stack pointer to the stack
 * @retval status of the stack_push
 */
return_status_t stack_push(stack_ds_t *my_stack, uint32_t value){
	return_status_t ret = R_NOK;
	if((my_stack == NULL) || (STACK_FULL == stack_full(my_stack))){
        #ifdef STACK_DEBUG
		printf("Error!! stack is full, can't push [%i] !! \n", value);
        #endif //STACK_DEBUG
		ret = R_NOK;
	}
	else{
		my_stack->stack_pointer++;
		my_stack->data[my_stack->stack_pointer] = value;
		#ifdef STACK_DEBUG
		printf("Value [%i] Pushed to the stack. \n", value);
		#endif //STACK_DEBUG
		ret = R_OK;
	}
	return ret;
}

/**
 * @brief get the last element pushed at the stack
 * @param my_stack pointer to the stack
 * @retval status of the stack_pop
 */
return_status_t stack_pop(stack_ds_t *my_stack, uint32_t *value){
	return_status_t ret = R_NOK;
	if((my_stack == NULL) || (NULL == value) || (STACK_EMPTY == stack_empty(my_stack))){
        #ifdef STACK_DEBUG
		printf("Error!! stack is empty, can't pop any value !! \n");
        #endif //STACK_DEBUG
		ret = R_NOK;
	}
	else{
		*value = my_stack->data[my_stack->stack_pointer];
		my_stack->stack_pointer--;
		#ifdef STACK_DEBUG
		printf("Value [%i] Popped from the stack. \n", *value);
		#endif //STACK_DEBUG
		ret = R_OK;
	}
	return ret;
}

/**
 * @brief get the last element pushed at the stack
 * @param my_stack pointer to the stack
 * @retval status of the stack_top
 */
return_status_t stack_top(stack_ds_t *my_stack, uint32_t *value){
	return_status_t ret = R_NOK;
	if((my_stack == NULL) || (NULL == value) || (STACK_EMPTY == stack_empty(my_stack))){
        #ifdef STACK_DEBUG
		printf("Error!! stack is empty. !! \n");
        #endif //STACK_DEBUG
		ret = R_NOK;
	}
	else{
		*value = my_stack->data[my_stack->stack_pointer];
		#ifdef STACK_DEBUG
		printf("Value [%i] is the top of the stack. \n", *value);
		#endif //STACK_DEBUG
		ret = R_OK;
	}
	return ret;
}

/**
 * @brief get the size of the stack -> no.of.elements
 * @param my_stack pointer to the stack
 * @param stack_size size of the stack
 * @retval status of the stack_size
 */
return_status_t stack_size(stack_ds_t *my_stack, uint32_t *stack_size){
	return_status_t ret = R_NOK;
	if((my_stack == NULL) || (NULL == stack_size)){
		ret = R_NOK;
	}
	else{
		*stack_size = my_stack->stack_pointer + 1;
		#ifdef STACK_DEBUG
		printf("the size is : [%i]. \n", (*stack_size)*sizeof(uint32_t));
		#endif //STACK_DEBUG
		ret = R_OK;
		ret = R_OK;
	}
	return ret;
}

/**
 * @brief display element at the stack
 * @param my_stack pointer to the stack
 * @retval status of the stack_display
 */
return_status_t stack_display(stack_ds_t *my_stack){
	return_status_t ret = R_NOK;
	sint32_t i = ZERO_INIT;
	if((my_stack == NULL) || (STACK_EMPTY == stack_empty(my_stack))){
		#ifdef STACK_DEBUG
		printf("Error!! stack is empty. !! \n");
        #endif //STACK_DEBUG
		ret = R_NOK;
	}
	else{
		printf("stack data :");
		for(i = my_stack->stack_pointer; i >= 0; i-- ){
			printf("%i \t", my_stack->data[i]);
		}
		printf("\n");
		ret = R_OK;
	}
	return ret;
}
