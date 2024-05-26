#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

int main()
{

	Queue Q;

	InitQueue(&Q);

	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	EnQueue(&Q, 4);
	EnQueue(&Q, 5);
	
	//printf("%d", Q.rear->data);
	printf("%d",DeQueue(&Q) );
	printf("%d",GetHead(&Q));
	printf("%d", QueueSize(&Q));
	


	return 0;
}