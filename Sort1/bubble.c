#include <stdio.h>

#define N 10

int main()
{
	int A[N];
	int i, j,  tmp;
	int cmp=0, swp=0;


	srand(9);

	for (i=0; i< N; i++)
		A[i] = rand() % 25;

	for (i=0; i < N; i++)
		printf("%2d ", A[i]);
	printf("\n");

	//sort with bubble sort;;; ascending   bubble to right
	for(i=0; i<N; i++)
	{
		for(j = 0; j< N-i-1; j++)
		{
			cmp++;
			if( A[j] > A[j+1])
			{
					swp++;
					//swap the values
					tmp = A[j];
					A[j] = A[j+1];
					A[j+1] = tmp;
			}
			//printf("(%d %d)", i, j);
		}
			for (j=0; j < N; j++)
				printf("%2d ", A[j]);
			printf("\n");

	}

	printf("Compares: %d   Swaps: %d\n", cmp, swp);
	return 0;
}
