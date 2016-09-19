#include <stdio.h>

#define N 10

int main()
{
	int A[N];
	int i, j,  tmp;
	int cmp=0, swp=0;
	int bigloc;

	srand(9);

	for (i=0; i< N; i++)
		A[i] = rand() % 25;

	for (i=0; i < N; i++)
		printf("%2d ", A[i]);
	printf("\n");

	//sort with selection sort;;; ascending   biggest to right first
	for(i=0; i<N; i++)
	{

		bigloc = 0;
		for(j = 0; j< N-i; j++)
		{
			cmp++;
			if(A[j] > A[bigloc])
				bigloc = j;
		}
		//swap value at bigloc with value N-i-1
		swp++;
		tmp = A[N-i-1];
		A[N-i-1] = A[bigloc];
		A[bigloc] = tmp;

			for (j=0; j < N; j++)
				printf("%2d ", A[j]);
			printf("\n");

	}

	printf("Compares: %d   Swaps: %d\n", cmp, swp);
	return 0;
}
