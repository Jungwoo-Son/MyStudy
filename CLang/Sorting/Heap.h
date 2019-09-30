#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdlib.h>

typedef int Data;

typedef struct _heap {
	Data* datas;
	int size;
}Heap;

void HeapInit(Heap* heap, int size);
void heapInsert(Heap* heap, Data data);
int heapDelete(Heap* heap, Data* res);

void exitHeap(Heap* heap);


#endif // !__HEAP_H__