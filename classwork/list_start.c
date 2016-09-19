#include <stdio.h>

#define MaxList 50 

void insertEnd( int L[], int *last, int x )
{
}

void insertFront( int L[], int *last, int x )
{
}

int isEmpty( int L[], int last )
{
}

int isFull( int L[], int last )
{
}
  
void printList( int L[], int last )
{
 int i;
 for ( i = 0; i < last; ++i)
   printf("%3d ", L[i]);
 printf("\n");
}


int main()
{
 int L[MaxList] = {0};
 int last = 0;          // next free spot in list
 int x, i;

 srand( 3 );

 if (isEmpty(L, last))
   printf("1 empty\n");
 else
   printf("1 notempty\n");

 if (isFull(L, last))
   printf("1 full\n");
 else
   printf("1 notfull\n");


 x = rand() % 100;
 insertEnd( L, &last, x );  
 printList( L, last );
 x = rand() % 100;
 insertEnd( L, &last, x );  
 printList( L, last );


 if (isEmpty(L, last))
   printf("2 empty\n");
 else
   printf("2 notempty\n");

 if (isFull(L, last))
   printf("2 full\n");
 else
   printf("2 notfull\n");

 for (i = 0; i < 5; ++i)
  {
   x = rand() % 100;
   insertEnd( L, &last, x );  
   printList( L, last );
  }
 for (i = 0; i < 5; ++i)
  {
   x = rand() % 100;
   insertFront( L, &last, x );  
   printList( L, last );
  }

 if (isEmpty(L, last))
   printf("3 empty\n");
 else
   printf("3 notempty\n");

 if (isFull(L, last))
   printf("3 full\n");
 else
   printf("3 notfull\n");

 return 0;
}
