/*Justin Soderstrom
  CSC-300
  September 9, 2015
*/

#include "lla5.h"

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

 x = isDups( L );

 if( x == 1)
  printf("There are duplicate values in the list \n");
 else
  printf("There are no duplicate values in the list \n");

 return 0;
}
