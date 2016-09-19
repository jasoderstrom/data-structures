#include <stdio.h>

#define LAST 7 

void pre(int tr[], int r)
{
 if ( r > LAST)
   return;
 printf("%2d ", tr[r]);
 pre(tr, r*2);
 pre(tr, r*2+1);
}

void in(int tr[], int r)
{
 if ( r > LAST)
   return;
 in(tr, r*2);
 printf("%2d ", tr[r]);
 in(tr, r*2+1);
}

void post(int tr[], int r)
{
 if ( r > LAST)
   return;
 post(tr, r*2);
 post(tr, r*2+1);
 printf("%2d ", tr[r]);
}

int main()
{
 int t[LAST+1];
 int i;

 for (i = 1; i < LAST+1; ++i)
   t[i] = i;

 for (i = 1; i < LAST+1; ++i)
   printf("%2d ", t[i]);
 printf("\n");

 printf(" preorder: "); 
 pre( t, 1 );
 printf("\n");

 printf("  inorder: "); 
 in( t, 1 );
 printf("\n");

 printf("postorder: "); 
 post( t, 1 );
 printf("\n");

 return 0;
}
