#include <stdio.h>
#include "Deque.h"


int main() {
	
	Deque dq;

	initDeque(&dq);
	DQAddFirst(&dq, 5);
	DQAddFirst(&dq, 6);
	DQAddFirst(&dq, 9);

	showDeque(&dq);

	DQAddLast(&dq, 8);
	DQAddLast(&dq, 10);
	DQAddLast(&dq, 50);

	showDeque(&dq);

	DQRemoveFirst(&dq);
	showDeque(&dq);

	DQRemoveLast(&dq);
	showDeque(&dq);



	return 0;
}