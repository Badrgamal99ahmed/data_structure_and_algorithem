#include <stdio.h>
#include <stdlib.h>

#include "stack.c"

stack_ds_t stack1;
stack_ds_t stack2;

uint32_t pop_value = ZERO_INIT;
uint32_t top_value = ZERO_INIT;
uint32_t size = ZERO_INIT;

int main()
{
	return_status_t ret = R_NOK;
	ret = stack_init(&stack1);
	if(R_NOK == ret){
		printf("Stack1 failed to be intialized !! \n");
	}
	else{
		ret = stack_push(&stack1, 11);
		ret = stack_push(&stack1, 22);
		ret = stack_push(&stack1, 33);
		ret = stack_push(&stack1, 44);
		ret = stack_push(&stack1, 55);
		
		ret = stack_size(&stack1, &size);
		
		ret = stack_push(&stack1, 66);
		ret = stack_push(&stack1, 77);
		
		ret = stack_display(&stack1);
		
		ret = stack_top(&stack1, &top_value);
		printf("top_value = %i \n", top_value);
		
		ret = stack_pop(&stack1, &pop_value);
		printf("pop_value = %i \n", pop_value);
		ret = stack_pop(&stack1, &pop_value);
		printf("pop_value = %i \n", pop_value);
		ret = stack_pop(&stack1, &pop_value);
		printf("pop_value = %i \n", pop_value);
		ret = stack_display(&stack1);
		ret = stack_pop(&stack1, &pop_value);
		printf("pop_value = %i \n", pop_value);
		ret = stack_pop(&stack1, &pop_value);
		printf("pop_value = %i \n", pop_value);
		
		ret = stack_pop(&stack1, &pop_value);
		if(R_OK == ret){
			printf("pop_value = %i \n", pop_value);
		}
		ret = stack_pop(&stack1, &pop_value);
		if(R_OK == ret){
			printf("pop_value = %i \n", pop_value);
		}
	}
	ret = stack_init(&stack2);
	if(R_NOK == ret){
		printf("Stack2 failed to be intialized !! \n");
	}
	else{

	}
	return 0;
}
