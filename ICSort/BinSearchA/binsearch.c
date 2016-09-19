#include <stdio.h>

#define N 10

int binsearch(int L[], int t)
{
 int found = 0;
 int keepgoing = 1;
 int low, mid, high;

 low = 0;
 high = N;
 while (keepgoing && !found)
 {
  mid = (high + low) / 2;
  printf("%d  %d  %d\n", low, mid, high);
  if (L[mid] == t)  
    found = 1;
  else if (t < L[mid])
   {
    high = mid-1;
   }
  else if (t > L[mid])
   {
    low = mid + 1;
   }
  else
   printf("oh oh\n");
  
  if (low > high)
    keepgoing = 0;    
 }

 return found;
}

int main()
{
 int A[N];
 int i, x;
 int found;

 A[0] = rand() % 4 + 1;
 for (i = 1; i < N; ++i)
 {
   A[i] = A[i-1] + rand() % 4 + 1;
   printf("%2d ", A[i]);
 }
 printf("\n");

 printf("value to search: ");
 scanf("%d", &x);

 found = binsearch(A, x);
 printf("Search %d returns %d\n", x, found);
 
 return 0;
}
