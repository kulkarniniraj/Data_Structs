#include "stack.h"

myret MyStack_Init(MyStack *Stack)
{
	if(!Stack)
		return MYRET_FAIL;
	Stack->Top = NULL;
	return MYRET_SUCCESS;
}

myret MyStack_Push(MyStack *Stack, void *Data)
{
	MyStackFrame* temp = NULL;
	if(!Stack)
		return MYRET_FAIL;
	temp = (MyStackFrame*) malloc(sizeof(MyStackFrame));
	if(temp == NULL)
		return MYRET_FAIL;
	temp->Data = Data;
	temp->Next = Stack->Top->Next;
	Stack->Top = temp;
	return MYRET_SUCCESS;
}

void* MyStack_Pop(MyStack *Stack)
{
	MyStackFrame* temp = NULL;
	void *Data = NULL;
	if(!Stack || !Stack->Top)
		return NULL;
	temp = Stack->Top;
	Data = temp->Data;
	Stack->Top = Stack->Top->Next;
	free(temp);
	return Data;
}

myret MyStack_Exit(MyStack *Stack)
{
	MyStackFrame* temp = NULL;
	if(!Stack)
		return MYRET_FAIL;
	while(Stack->Top)
	{
		temp = Stack->Top;
		Stack->Top = Stack->Top->Next;
		free(temp);
	}
	return MYRET_SUCCESS;
}