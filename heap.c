#include "heap.h"

myret MyHeap_Init(MyHeap *Heap)
{
	if(!Heap)
		return MYRET_FAIL;
	Heap->Root = (MyHeapFrame *)malloc(sizeof(MyHeapFrame) * SEGMENT_SIZE_FROM_LEVEL(MYHEAP_SEGMENT_LEVELS));
	Heap->Current = Heap->Root;
	
	if(!Heap->Root)
		return MYRET_FAIL;
	Heap->Total_Count = 0;
	Heap->Segment_Data.Current_Segment_Count = 0;
	Heap->Segment_Data.Current_Segment_Size = SEGMENT_SIZE_FROM_LEVEL(MYHEAP_SEGMENT_LEVELS);
	Heap->Segment_Data.Current_Level = 0;
	return MYRET_SUCCESS;
}

myret MyHeap_ReAdjust(MyHeap *Heap)
{
	if(!Heap)
		return MYRET_FAIL;
}

myret MyHeap_Add(MyHeap *Heap, uint32_t Key, void *Data)
{
	MyHeapFrame *temp = NULL;
	if(!Heap)
		return MYRET_FAIL;
	
	if(Heap->Segment_Data.Current_Segment_Count == Heap->Segment_Data.Current_Segment_Size)
	{
		/* New Segment Needed */
	}
	else
	{
		temp = &Heap->Current[Heap->Segment_Data.Current_Segment_Count];
		temp->Key = Key;
		temp->Data = Data;
		temp->Next = NULL;
		temp->Prev = NULL;
		
		Heap->Segment_Data.Current_Segment_Count++;
		Heap->Total_Count++;
		if(Heap->Total_Count && !(Heap->Total_Count & (Heap->Total_Count - 1)))
		{
			/* New Level */
			Heap->Segment_Data.Current_Level++;
		}




	}
	return MyHeap_ReAdjust(Heap);
}

void* MyHeap_Delete(MyHeap *Heap, uint32_t Key)
{
}

void* MyHeap_GetRoot(MyHeap *Heap, uint32_t *Key)
{
}

uint32_t MyHeap_GetCount(MyHeap *Heap)
{
}

void MyHeap_Sort(MyHeap *Heap, void *DataArray[])
{
}

myret MyHeap_Exit(MyHeap *Heap)
{
}