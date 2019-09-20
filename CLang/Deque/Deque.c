#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>



Node* initNode(Node* node) {
	node->data = 0;
	node->next = NULL;
	node->prev = NULL;
}

Node* makeNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode) {
		initNode(newNode);
		newNode->data = data;
	}
	return newNode;
}

void linkNodes(Node* nodeA, Node* nodeB){
	if(nodeA) nodeA->next = nodeB;
	if(nodeB) nodeB->prev = nodeA;
}




void initDeque(Deque* pd) {
	pd->head = NULL;
	pd->tail = NULL;
}

int isEmpty(Deque* pd) {
	return pd->head == NULL;
}

void DQAddFirst(Deque* pd, Data data) {
	Node* newNode = makeNode(data);

	linkNodes(newNode, pd->head);
	if (isEmpty(pd)) {
		linkNodes(pd->tail, newNode);
		pd->tail = newNode;
	}
	pd->head = newNode;

}

void DQAddLast(Deque* pd, Data data){
	Node* newNode = makeNode(data);

	linkNodes(pd->tail, newNode);
	if (isEmpty(pd)) {
		linkNodes(newNode, pd->head);
		pd->head = newNode;
	}
	pd->tail = newNode;
}

Data DQRemoveFirst(Deque* pd){
	Data res;
	Node* dNode;

	if (isEmpty(pd)) {
		printf("비어있음");
		exit(1);
	}
	
	dNode = pd->head;
	res = dNode->data;
	linkNodes(NULL, dNode->next);
	pd->head = dNode->next;

	if (pd->head == NULL)
		pd->tail = NULL;

	free(dNode);
	
	return res;
}

Data DQRemoveLast(Deque* pd){
	Data res;
	Node* dNode;

	if (isEmpty(pd)) {
		printf("비어있음");
		exit(1);
	}
	dNode = pd->tail;
	res = dNode->data;
	linkNodes(dNode->prev, NULL);
	pd->tail = dNode->prev;

	if (pd->tail == NULL)
		pd->head = NULL;

	free(dNode);

	return res;
}

Data DQGetFirst(Deque* pd)
{
	if (isEmpty(pd)) {
		printf("비어있습니다.");
		exit(1);
	}
	return pd->head->data;
}

Data DQGetLast(Deque* pd)
{
	if (isEmpty(pd)) {
		printf("비어있습니다.");
		exit(1);
	}
	return pd->tail->data;
}

void showDeque(Deque* pd){
	Node* node;

	printf("Deque : ");

	if (isEmpty(pd)) {
		printf("비어있습니다.\n");
		return;
	}

	for (node = pd->head; node != NULL; node = node->next) {
		printf("%d ", node->data);
	}
	printf("\n");
}
