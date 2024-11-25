

#include "queue.h"

static Queue_Full(Queue_t *queue_obj){
	return(queue_obj->ElementCount == queue_obj->QueueMaxSize);
}

static Queue_Empty(Queue_t *queue_obj){
	return(0 == queue_obj->ElementCount);
}








Queue_t *CreatQueue(uint32 maxsize, QueueStatus_t *ret_status){
	Queue_t *my_queue;
	/* Creat queue object in the heap to hold the queue information */
	my_queue = (Queue_t *)malloc(sizeof(Queue_t));
	if(NULL == my_queue){
		*ret_status = QUEUE_NULL_PTR;
		my_queue == NULL;
	}
	else{
		/* Creat array of <void *1> to hold addresses of the queue data */
		my_queue->QueueArray = (void **)calloc(maxsize, sizeof(void *));
		if(NULL == my_queue->QueueArray){
		*ret_status = QUEUE_NOK;
		my_queue == NULL;
		}
		else{
			my_queue->ElementCount = 0;
			my_queue->QueueFront = -1;
			my_queue->QueueRear = -1;
			my_queue->QueueMaxSize = maxsize;
			*ret_status = QUEUE_OK;
		}
	}
	return my_queue;
}

QueueStatus_t Enqueue(Queue_t *queue_obj, void *item_ptr){
	QueueStatus_t status = QUEUE_NOK;
	if((NULL == queue_obj) || (NULL == item_ptr)){
		status = QUEUE_NULL_PTR;
	}
	else{
		if(Queue_Full){
			status = QUEUE_FULL;
		}
		else{
			(queue_obj->QueueRear)++;
			if(queue_obj->QueueRear == queue_obj->QueueMaxSize){
				queue_obj->QueueRear = 0;
				queue_obj->QueueArray[queue_obj->QueueRear] = item_ptr;
			}
			if(queue_obj->ElementCount == 0){
				queue_obj->QueueFront = 0;
				queue_obj->ElementCount = 1;
			}
			else{
				(queue_obj->ElementCount)++;
			}
			status = QUEUE_OK;
		}
	}
	return status;
}

void *Dequeue(Queue_t *queue_obj, QueueStatus_t *ret_status){
	void *ReturnElem = NULL;
	if((NULL == queue_obj) || (NULL == ret_status)){
		*ret_status = QUEUE_NULL_PTR;
	}
	else{
		if(!queue_obj->ElementCount){
			*ret_status = QUEUE_EMPTY;
			ReturnElem = NULL;
		}	
		else{
			ReturnElem = queue_obj->QueueArray[queue_obj->QueueFront];
			(queue_obj->QueueFront)++;
			
			if(queue_obj->QueueFront == queue_obj->QueueMaxSize){
				queue_obj->QueueFront = 0;
			}
			else{
				
			}
			if(1 == queue_obj->ElementCount){
				queue_obj->QueueFront = -1;
				queue_obj->QueueRear = -1;
			}
			else{}
			(queue_obj->ElementCount)--;
			*ret_status = QUEUE_OK;
		}
	}
	return ReturnElem;
}

void *QueueFront(Queue_t *queue_obj, QueueStatus_t *ret_status){
	void *ReturnElem = NULL;
	if((NULL == queue_obj) || (NULL == ret_status)){
		*ret_status = QUEUE_NULL_PTR;
	}
	else{
		if(!queue_obj->ElementCount){
			*ret_status = QUEUE_EMPTY;
			ReturnElem = NULL;
		}	
		else{
			ReturnElem = queue_obj->QueueArray[queue_obj->QueueFront];
			*ret_status = QUEUE_OK;
		}
	}
	return ReturnElem;
}

void *QueueRear(Queue_t *queue_obj, QueueStatus_t *ret_status){
	void *ReturnElem = NULL;
	if((NULL == queue_obj) || (NULL == ret_status)){
		*ret_status = QUEUE_NULL_PTR;
	}
	else{
		if(!queue_obj->ElementCount){
			*ret_status = QUEUE_EMPTY;
			ReturnElem = NULL;
		}	
		else{
			ReturnElem = queue_obj->QueueArray[queue_obj->QueueRear];
			*ret_status = QUEUE_OK;
		}
	}
	return ReturnElem;
}

QueueStatus_t GetQueueCount(Queue_t *queue_obj, uint32 *queuecount){
	QueueStatus_t status = QUEUE_NOK;
	if((NULL == queue_obj) || (NULL == queuecount)){
		status = QUEUE_NULL_PTR;
	}
	else{
		if(!queue_obj->ElementCount){
			*queuecount = 0;
		}	
		else{
			*queuecount = queue_obj->ElementCount;
		}
		status = QUEUE_OK;
	}
	return status;
}

QueueStatus_t DestroyQueue(Queue_t *queue_obj){
	QueueStatus_t status = QUEUE_NOK;
	if(NULL == queue_obj){
		status = QUEUE_NULL_PTR;
	}
	else{
		free(queue_obj->QueueArray);
		free(queue_obj);
		status = QUEUE_OK;
	}
	return status;
}
