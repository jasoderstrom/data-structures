#include "p1.h"

/* Justin Soderstrom & Jacob Thomas & Jovana Bogdanovic
   Even Number Assignment
   September 14, 2015
*/

int main(void)
{
	int i = 0;
	int x = 0;

	//start of stack calls

	struct stackHeader *stackPtr;

	srand(444);

	stackPtr = makestack();

	printf("\n\n");

	if(isStackEmpty(stackPtr)) //testing isEmpty function
	{
		printf("The stack is empty\n");
	}
	else
	{
		printf("The stack is not empty\n");
	}

	for(i=0;i<10;i++)
	{
		x = rand() % 10;
		push(stackPtr, x);
	}


	printstack(stackPtr);

	x = pop(stackPtr);

	printf("Popped: %d\n", x);

	printstack(stackPtr);

	if(isStackEmpty(stackPtr)) //testing isEmpty function
	{
		printf("The stack is empty\n");
	}
	else
	{
		printf("The stack is not empty\n");
	}

	//start of queue calls

	struct queue *queuePtr;

	queuePtr = makeq();

	printf("\n\n");

	if(isQueueEmpty(queuePtr))
	{
		printf("The queue is empty\n");
	}
	else
	{
		printf("The queue is not empty\n");
	}

	for(i=0; i<10; i++)
	{
		x = rand() % 10;
		enq(queuePtr, x);
	}

	showq(queuePtr);

	x = deq(queuePtr);

	printf("Removed: %d\n", x);

	showq(queuePtr);

	if(isQueueEmpty(queuePtr))
	{
		printf("The queue is empty\n");
	}
	else
	{
		printf("The queue is not empty\n");
	}

	printf("\n\n");

	return 0;
}
