#include "Queue.h"

Node* makeNode(Data data){
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) return NULL;
	node->data = data;
	node->next = NULL;

	return node;
}

void Queueinit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

void enque(Queue* pq, Data data) {
	Node* node = makeNode(data);

	node->data = data;
	if (pq->front == NULL)
		pq->front = node;
	else 
		pq->rear->next = node;
	pq->rear = node;
}

int deque(Queue* pq, Data *res){
	Node* temp;
	if (pq->front == NULL)
		return 0;

	temp = pq->front;
	(*res) = temp->data;
	pq->front = temp->next;
	free(temp);

	return 1;
}

void printQ(Queue* pq){
	Node* node;
	for (node = pq->front; node != NULL; node = node->next) {
		printf("%d ", node->data);
	}
	printf("\n");

}
