
/*Justin Soderstrom
  CSC-300
  September 2, 2015
*/
#include <stdio.h>

#define MaxList 50

struct listtype
{
 	int L[MaxList]; 
	int last;          // next free spot in list
}; 
 
typedef struct listtype alist;

void insertEnd(alist *A,  int x )
{
	A->L[A->last] = x;
	(A->last)++;
}

void insertFront(alist *A,  int x )
{
	int i = 0;

	for(i=A->last; i>=0; i--)
	{
		A->L[i+1] = A->L[i]; 
	}

	A->L[0] = x;
	(A->last)++;
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


int main()
{
 int x, i;

 alist list;

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
