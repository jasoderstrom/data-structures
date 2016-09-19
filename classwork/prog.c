#include <stdio.h>

int countOddVal(int a[], int N, int L)
{
	int i;
	int count = 0;

	for(i=0; i< N; i++)
	{
		if((a[i] % 2 == 1) && i <= L)
		{
			count++;
		}
	}

	return count;
}
int sumOddLoc(int a[], int N, int L)
{
	int i;
	int sum = 0;

	for (i=1; i<=N; i++)
	{
		if((i % 2 == 1) && i <= L)
		{
			sum += a[i];
		}
	}

	return sum;
}
int getone(int a[], int N, int index)
{
	if(index > N - 1)
	{
		return -999;
	}
	else
	{
		return a[index];
	}
}
void fill(int arr[], int N, int H)
{
	int i;
	for (i=0; i < N; i++)
		arr[i] = rand() % H; //(H+1) 0-30
}
void print(int arr[], int N)
{
	int i;
	for (i=0; i < N; i++)
	{
		printf("%d - %d\n", i, arr[i]);
	}
}

int main(void)
{
	int A[100];
	int res;
	int len = 0;

	// A = 18 8 4
	// len = 3

	// put 9 at end of list
	// A[len] = 9;
	// len++;

	// put 2 at end of list
	// A[len] = 2;
	// len ++;

	//put 9 at FRONT of list

	//shift all items to the right by 1 to open the first spot
	for (i=len; i > 0; i--)
		A[i] = A[i-1];

	//A[0] = 9;
	srand( 444 );

	fill(A, 10, 5);
	print(A, 10);

	res = getone(A, 10, 2);
	printf("Value[2] = %d\n", res);

	res = getone(A, 10, 12);
	printf("Value[12] = %d\n", res);

	res = sumOddLoc(A, 10, 5);
	printf("Sum of to 5: %d\n", res);
	res = countOddVal(A, 10, 5);
	printf("Count of odd to 5: %d\n", res);

	res = sumOddLoc(A, 10, 20);
	printf("Sum of to 20: %d\n", res);
	res = countOddVal(A, 10, 20);
	printf("Count of odd to 20: %d\n", res);

	return 0;

}
