#include <stdio.h>
#include <stdlib.h>

/* Justin Soderstrom & Jacob Thomas & Jovana Bogdanovic
   Even Account Assignment
   September 14, 2015
*/

struct stackHeader
{
	int len;
	struct stack *start;
};

struct stack
{
	int data;
	struct stack *next;

};

struct queue
{
	int A[20];
	int len;
};

// Stack Functions
void push( struct stackHeader *st, int num );// O(1)
int pop ( struct stackHeader *st ); // O(1)
void printstack ( struct stackHeader *st );// O(n)
struct stackHeader *makestack () ;// O(1)
int isStackEmpty ( struct stackHeader *st );// O(1)


// Queue Functions
void enq( struct queue *q, int num );// O(1)
int deq( struct queue *q );// O(n)
void showq( struct queue *q );// O(n)
struct queue *makeq( );// O(1)
int isQueueEmpty( struct queue *q );// O(1)
