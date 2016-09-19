#include "p1.h"

/*Justin Soderstrom & Jacob Thomas & Jovana Bogdanovic Assignment
  Even account
  September 14, 2015

  Big O Notation for each function
*/


// Stack Functions
void push( struct stackHeader *st, int num ) // O(1)
{
	struct stack *tmp;
	tmp = malloc( sizeof(struct stack) );
	tmp->data = num;

	if(st->start == NULL)
	{
		st->start = tmp;
		tmp->next = NULL;
		st->len++;
	}
	else
	{
		tmp->next = st->start;
		st->start = tmp;
		st->len++;
	}
}

int pop( struct stackHeader *st ) // O(1)
{
	struct stack *ptr;
	ptr = st->start;

	int val = 0;
	val = ptr->data;

	st->start = ptr->next;

	st->len--;

	return val;

}

void printstack( struct stackHeader *st )// O(n)
{
	struct stack *ptr;

	ptr = st->start;

	while(ptr->next != NULL)
	{
		printf("| %d |\n", ptr->data);

		ptr = ptr->next;
	}
}

struct stackHeader *makestack( )//O(1)
{
	struct stackHeader *head;
	head = malloc( sizeof(struct stackHeader) );
	head->len = 0;
	head->start = NULL;
	return head;
}

int isStackEmpty( struct stackHeader *st )// O(1)
{
	int empty = 0;

	if(st->start == NULL)
	{
		empty = 1;
	}
	else
	{
		empty = 0;
	}

	return empty;
}


// Queue Functions
void enq( struct queue *q, int num ) // O(1)
{
	int i = q->len;

	q->A[i] = num;

	q->len++;

}

int deq( struct queue *q ) // O(n)
{
	int i = 0;

	int dq = q->A[0];

	for(i=0; i< q->len; i++)
	{
		q->A[i] = q->A[i+1];
	}

	q->len--;

	return dq;
}

void showq( struct queue *q ) // O(n)
{
	int i = 0;

	for(i=0; i< q->len; i++)
	{
		printf("%d ", q->A[i]);
	}

	printf("\n");

}

struct queue *makeq( ) // O(1)
{
	struct queue *q;

	q = malloc(sizeof(struct queue));

	q->len = 0;

	return q;

}

int isQueueEmpty( struct queue *q )// O(1)
{
	int empty = 0;

	if(q->len == 0)
	{
		empty = 1;
	}

	return empty;
}

