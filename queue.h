#include "common.h"

/*
	Queue as Linked List
*/

typedef struct _myqueue_frame_
{
	void *Data;
	struct _myqueue_frame_ *Next, *Prev;
}MyQueueFrame;

typedef struct _myqueue_
{
	MyQueueFrame	*Front, *Rear;				
}MyQueue;

myret MyQueue_Init(MyQueue *Queue);
myret MyQueue_Add(MyQueue *Queue, void *Data);
void* MyQueue_Delete(MyQueue *Queue);
myret MyQueue_Exit(MyQueue *Queue);