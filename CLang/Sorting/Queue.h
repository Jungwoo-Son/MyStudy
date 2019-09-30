#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

typedef int Data;


typedef struct _node {
	Data data;
	struct _node* next;
}Node;

typedef struct _queue {
	Node* front;
	Node* rear;
}Queue;


Node* makeNode(Data data);

void Queueinit(Queue* pq);

void enque(Queue* pq, Data data);

int deque(Queue* pq, Data *res);

void printQ(Queue* pq);


#endif // !__QUEUE_H__