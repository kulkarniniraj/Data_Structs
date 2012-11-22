#include "common.h"

/*
	Heap as Segmented Linked List
*/
#define MYHEAP_SEGMENT_LEVELS 3
#define SEGMENT_SIZE_FROM_LEVEL(x) ((1 << (x)) - 1)

#ifdef MYHEAP_MAX_HEAP
#define OP(x, y) ((x) > (y))
#else
#define OP(x, y) ((x) < (y))
#endif

typedef struct _myheap_frame_
{
	uint32_t				Key; 
	void					*Data;
	struct _myheap_frame_	*Next, *Prev;
}MyHeapFrame;

typedef struct _myqueue_
{
	MyHeapFrame		*Root, *Current;				
	uint32_t		Total_Count;
	struct{
		uint32_t	Current_Segment_Count;
		uint32_t	Current_Segment_Size;
		uint32_t	Current_Level;
	}Segment_Data;
}MyHeap;

myret MyHeap_Init(MyHeap *Heap);
myret MyHeap_Add(MyHeap *Heap, uint32_t Key, void *Data);
void* MyHeap_Delete(MyHeap *Heap, uint32_t Key);
void* MyHeap_GetRoot(MyHeap *Heap, uint32_t *Key);
uint32_t MyHeap_GetCount(MyHeap *Heap);
void MyHeap_Sort(MyHeap *Heap, void *DataArray[]);
myret MyHeap_Exit(MyHeap *Heap);