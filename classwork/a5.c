/*Justin Soderstrom
  CSC-300
  September 9, 2015
*/

#include <stdio.h>
#include <stdlib.h>

struct lnode
{
 int data;
 struct lnode *next;
};


struct lheader
{
 struct lnode *start;
 int len;
};


struct lheader *makelist( )
{
 struct lheader *alist;
 alist = malloc( sizeof( struct lheader ) );
 alist->len = 0;
 alist->start = NULL;
 return alist;
}

struct lnode *makenode( int val )
{
 struct lnode *box;
 box = malloc( sizeof( struct lnode ) );
 box->data = val;
 box->next = NULL;
 return box;
}


void insertFront( struct lheader *L, int val )
{
 struct lnode *tmp;

 tmp = makenode( val );
 tmp->next = L->start;
 L->start = tmp;
 L->len++;
}


void insertBack( struct lheader *L, int val )
{
 struct lnode *tmp;
 tmp = makenode( val );

 struct lnode *mov;
 mov = L->start;

 if(mov == NULL)
 {
  L->start = tmp;
 }
 else
 {
     while (mov->next != NULL)
     {
  	 mov = mov->next;
     }

   mov->next = tmp;

 }
  L->len++; 
}


int isInList( struct lheader *L, int val )
{
 struct lnode *mov;
 mov = L->start;

 while (mov != NULL)
 {
   if (mov->data == val)
	return 1;

   mov = mov->next;
 }

 return 0;
}

struct lnode *findNode( struct lheader *L, int val )
{
	struct lnode *mov;
	mov = L->start;

	while(mov != NULL)
	{
		if(mov->data == val)
		{
			return mov;
		}
		mov = mov->next;
	}
	return mov;
}


void insertAfter( struct lheader *L, int val, struct lnode *p )
{
 struct lnode *tmp;
 tmp = makenode( val );

 tmp->next = p->next;
 p->next = tmp;

 L->len++;
}


void insertBefore( struct lheader *L, int val, struct lnode *p )
{
 struct lnode *prev;
 struct lnode *tmp;
 tmp = makenode( val );

 if(p == L->start)
 {
   tmp->next = L->start;
   L->start = tmp;
 }
 else
 {
  prev = L->start;

  while (prev->next != p)
   prev = prev->next;

  tmp->next = p;
  prev->next = tmp;
 }

 L->len++;
}


void printlist( struct lnode *front )
{
 struct lnode *mov;
 mov = front;
 while (mov != NULL)
 {
  printf("%d  ", mov->data);
  mov = mov->next; 
 }
 printf("\n");
}


void printer( struct lheader *alist )
{
 struct lnodev *mov;
 printf("--------------------------\n");
 printf("List print, len %d\n", alist->len); 
 printlist( alist->start ); 
 printf("--------------------------\n");
}


int main()
{
 struct lheader *L;
 struct lnode  *head, *tmp;
 struct lnode  *mark;
 int i, x;

 L = makelist();
 
 for (i = 0; i < 5; ++i)
 {
   x = rand() % 25 + 1;
   printf("-- Adding -- %d\n", x);
  insertFront( L, x );
  // insertBack( L, x );
   printer( L );
 }


 printf(">>>>Value to search: ");
 scanf("%d", &x);
 i = isInList(L, x);
 printf("I is %d\n", i);
 tmp = findNode(L, x);
 if (tmp == NULL) 
  printf("NOPE\n");
 else  
  printf("Found node %d\n", tmp->data);

 // figure out insertBefore and insertAfter

 if(tmp != NULL)
 {
   mark = tmp;
 }
 else
 {
   mark = L->start;
 }

 printf("Enter a value to insert before searched value: ");
 scanf("%d", &x);

 insertBefore(L, x, mark);
 printer( L );

 printf("Enter a value to insert after searched value: ");
 scanf("%d", &x);

 insertAfter(L, x, mark);
 printer( L );


 return 0;
}
