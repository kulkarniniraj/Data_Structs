#include "queue.h"

myret MyQueue_Init(MyQueue *Queue)
{
	if(!Queue)
		return MYRET_FAIL;
	Queue->Front = NULL;
	Queue->Rear = NULL;
	return MYRET_SUCCESS;
}


myret MyQueue_Add(MyQueue *Queue, void *Data)
{
	MyQueueFrame* temp = NULL;
	if(!Queue)
		return MYRET_FAIL;
	temp = (MyQueueFrame*) malloc(sizeof(MyQueueFrame));
	if(temp == NULL)
		return MYRET_FAIL;
	temp->Data = Data;
	temp->Next = Queue->Rear;
	temp->Prev = NULL;
	Queue->Rear->Prev = temp;
	Queue->Rear = temp;

	if(Queue->Front == NULL)
	{
		Queue->Front = Queue->Rear;
	}
	return MYRET_SUCCESS;
}

void* MyQueue_Delete(MyQueue *Queue)
{
	MyQueueFrame* temp = NULL;
	void *Data = NULL;
	if(!Queue || !Queue->Front)
		return NULL;
	temp = Queue->Front;
	Data = temp->Data;
	Queue->Front = Queue->Front->Prev;
	if(Queue->Front == NULL)
	{
		Queue->Rear = NULL;
	}
	free(temp);
	return Data;
}

myret MyQueue_Exit(MyQueue *Queue)
{
	MyQueueFrame* temp = NULL;
	if(!Queue)
		return MYRET_FAIL;
	while(Queue->Rear)
	{
		temp = Queue->Rear;
		Queue->Rear = Queue->Rear->Next;
		free(temp);
	}
	return MYRET_SUCCESS;
}