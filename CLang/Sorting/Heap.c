#include "Heap.h"

#include <stdio.h>


void HeapInit(Heap* heap, int size) {
	heap->datas = (Data*)malloc(sizeof(Data) * size);
	heap->size = 0;
}


void heapInsert(Heap* heap, Data data){
	int idx = heap->size;
	int parents;

	for (parents = (idx - 1) / 2; idx > 0; parents = (idx - 1) / 2) {
		if (heap->datas[parents] > data) {
			heap->datas[idx] = heap->datas[parents];
			idx = parents;
		}
		else
			break;

	}


	heap->datas[idx] = data;
	heap->size++;
}

int heapDelete(Heap* heap, Data* res) {
	int temp;
	int cur;
	int child1Idx, child2Idx;

	if (heap->size == 0)
		return 0;



	(*res) = heap->datas[0];

	cur = heap->size - 1;
	temp = heap->datas[cur];

	heap->size--;

	cur = 0;
	while (1) {
		child1Idx = cur * 2 + 1;
		child2Idx = cur * 2 + 2;

		//printf("--%d(%d-%d) %d %d\n",temp ,heap->datas[cur], cur ,child1Idx, child2Idx);

		if (child1Idx >= heap->size)
			break;

		if (heap->datas[child1Idx] < temp || heap->datas[child2Idx] < temp) {
			if (heap->datas[child1Idx] < heap->datas[child2Idx]) {
				heap->datas[cur] = heap->datas[child1Idx];
				cur = child1Idx;
			}
			else {
				heap->datas[cur] = heap->datas[child2Idx];
				cur = child2Idx;

			}

		}
		else
			break;


	}

	heap->datas[cur] = temp;


	return 1;
}

void exitHeap(Heap* heap) {
	free(heap->datas);
}