#include "common.h"
#define STACK_SEGMENT_SIZE 1024

/*
	This stack is implemented as linked list of stack segment of size STACK_SEGMENT_SIZE. First and last 
	element of each segment is used for linked list pointers.
*/

typedef struct _mystack_frame_
{
	void *Data;
}MyStackFrame;

typedef struct _mystack_
{
	MyStackFrame	*StackBase;				// Head of LL
	MyStackFrame	*CurrentSegmentBase;	// Ptr to current node
	uint16_t		Top;
}MyStack;

myret MyStack_Init(MyStack *Stack);
myret MyStack_Push(MyStack *Stack, void *Data);
MyStackFrame* MyStack_Pop(MyStack *Stack);
myret MyStack_Exit(MyStack *Stack);