

#ifndef _QUEUE_ARRAY_H
#define _QUEUE_ARRAY_H

#include <stdlib.h>
#include "Platform_types.h"


typedef struct{
	void **QueueArray;
	uint32 QueueMaxSize;
	sint32 ElementCount;
	sint32 QueueFront;
	sint32 QueueRear;
}Queue_t;


typedef enum{
	QUEUE_NOK = 0,
	QUEUE_OK,
	QUEUE_FULL,
	QUEUE_EMPTY,
	QUEUE_NULL_PTR
}QueueStatus_t;

Queue_t *CreatQueue(uint32 maxsize, QueueStatus_t *ret_status);
QueueStatus_t Enqueue(Queue_t *queue_obj, void *item_ptr);
void *Dequeue(Queue_t *queue_obj, QueueStatus_t *ret_status);
void *QueueFront(Queue_t *queue_obj, QueueStatus_t *ret_status);
void *QueueRear(Queue_t *queue_obj, QueueStatus_t *ret_status);
QueueStatus_t GetQueueCount(Queue_t *queue_obj, uint32 *queuecount);
QueueStatus_t DestroyQueue(Queue_t *queue_obj);


#endif  //_QUEUE_ARRAY_H