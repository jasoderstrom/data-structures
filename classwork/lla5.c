/*Justin Soderstrom
  CSC-300
  September 9, 2015
*/
#include "lla5.h"

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

int isDups( struct lheader *L )
{
	int dups = 0;
	int i = 0;
	int val = 0;

	struct lnode *tmp;
	struct lnode *ptr;

	tmp = L->start;
	ptr = L->start;

	for(i=0; i<= L->len; i++)
	{
		val = ptr->data;

		while(tmp->next != NULL)
		{
			if(tmp->data == val)
			{
				dups = 1;
				return dups;
			}
			else
			{
				tmp = tmp->next;
			}
		}

		tmp = L->start;
		ptr = ptr->next;
	}

	return dups;

}
