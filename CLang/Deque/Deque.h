#ifndef __Deque_H__
#define __Deque_H__


typedef int Data;


typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _dllDeque {
	Node* head;
	Node* tail;
}DLDeque;

typedef DLDeque Deque;

//Nodes function
Node* initNode(Node* node);
Node* makeNode(int data);
void linkNodes(Node* nodeA, Node* nodeB);


//Deques function
void initDeque(Deque* pd);
int isEmpty(Deque* pd);

void DQAddFirst(Deque* pd, Data data);
void DQAddLast(Deque* pd, Data data);
Data DQRemoveFirst(Deque* pd);
Data DQRemoveLast(Deque* pd);

Data DQGetFirst(Deque* pd);
Data DQGetLast(Deque* pd);

void showDeque(Deque* pd);

#endif // !__Deque_H__
