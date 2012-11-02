#include "common.h"

/*
	Stack as Linked List
*/

typedef struct _mystack_frame_
{
	void *Data;
	struct _mystack_frame_ *Next;
}MyStackFrame;

typedef struct _mystack_
{
	MyStackFrame	*Top;				// Top ptr
}MyStack;

myret MyStack_Init(MyStack *Stack);
myret MyStack_Push(MyStack *Stack, void *Data);
void* MyStack_Pop(MyStack *Stack);
myret MyStack_Exit(MyStack *Stack);