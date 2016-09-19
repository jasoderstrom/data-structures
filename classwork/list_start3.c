

/*Justin Soderstrom
  CSC-300
  September 9, 2015
*/
#include <stdio.h>
#include <stdlib.h>

#define MaxList 50

struct listtype
{
	int *L;
 	int last; 
	int capacity;          // next free spot in list
}; 
 
typedef struct listtype alist;

int removeFront(alist *A)
{
	int i=0;
	int removedItem = A->L[0];


	if(A->last != 0)
	{
		for(i=0;i< A->last;i++)
		{
			A->L[i] = A->L[i+1];
		}
	}
	else
	{
		printf("Cannot remove element due to empty array. Terminating program...\n");
		exit(0);
	}
	A->last--;
	return removedItem;
}

int removeEnd(alist *A)
{
	int removedItem = A->last;

	if(A->last != 0)
	{
		A->last--;

		return removedItem;
	}
	else
	{
		printf("Cannot remove element due to empty array. Terminating program...\n");
		exit(0);
	}

}

void makeList(alist *A, int cap)
{
	A->L = malloc(cap * sizeof(int));
	A->last = 0;
	A->capacity = cap;
}
void insertEnd(alist *A,  int x )
{
	if(A->last < A->capacity)
	{
		A->L[A->last] = x;
		(A->last)++;
	}
	else
	{
		printf("Cannot add element due to over capacity. Terminating program...\n");
		exit(0);
	}

}

void insertFront(alist *A,  int x )
{
	int i = 0;

	if(A->last < A->capacity)
	{
		for(i=A->last; i>=0; i--)
		{
			A->L[i+1] = A->L[i]; 
		}

		A->L[0] = x;
		(A->last)++;

	}
	else
	{
		printf("Cannot add element due to over capacity. Terminating program...\n");
		exit(0);
	}

}

int isEmpty(alist A)
{
	if (A.last ==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(alist A)
{
	if (A.last == MaxList-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
  
void printList(alist A)
{
 int i;
 for ( i = 0; i < A.last; ++i)
   printf("%3d ", A.L[i]);
 printf("\n");
}


int main(void)
{
 int x, i;

 alist list;

 makeList(&list, 13);

 list.last = 0;

 srand( 3 );

 if (isEmpty(list))
   printf("1 empty\n");
 else
   printf("1 notempty\n");

 if (isFull(list))
   printf("1 full\n");
 else
   printf("1 notfull\n");


 x = rand() % 100;
 insertEnd( &list, x );  
 printList( list );
 x = rand() % 100;
 insertEnd( &list,  x );  
 printList( list );


 if (isEmpty(list))
   printf("2 empty\n");
 else
   printf("2 notempty\n");

 if (isFull(list))
   printf("2 full\n");
 else
   printf("2 notfull\n");

 for (i = 0; i < 5; ++i)
  {
   x = rand() % 100;
   insertEnd( &list, x );  
   printList( list );
  }
 for (i = 0; i < 5; ++i)
  {
   x = rand() % 100;
   insertFront( &list,  x );  
   printList( list );
  }

// removeEnd( &list );
// printList( list );

 if (isEmpty(list))
   printf("3 empty\n");
 else
   printf("3 notempty\n");

 if (isFull(list))
   printf("3 full\n");
 else
   printf("3 notfull\n");

 return 0;
}
