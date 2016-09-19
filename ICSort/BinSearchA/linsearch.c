#include <stdio.h>

#define N 10

int linsearch(int L[], int t)
{
 int i;
 for (i = 0; i < N; ++i)
  {
    if (L[i] == t)
      return 1;
  }
 return 0;
}

int main()
{
 int A[N];
 int i, x;
 int found;
 
 for (i = 0; i < N; ++i)
 {
   A[i] = rand() % 20 + 1;
   printf("%2d ", A[i]);
 }
 printf("\n");

 printf("value to search: ");
 scanf("%d", &x);

 found = linsearch(A, x);
 printf("Search %d returns %d\n", x, found);
 
 return 0;
}
