#include <stdio.h>
#include <time.h>

void bubbleSort(int master[], int size)
{
	int bubbleSort[size];
	int i, j,tmp, itr;

	clock_t t1, t2;

	t1 = clock();

	for(itr=0;itr<500;itr++)
	{
		for(i=0; i< size; i++)
			bubbleSort[i] = master[i];

		//sort with bubble sort ascending bubble to right
		for(i=0; i<size; i++)
		{
			for(j = 0; j< size-i-1; j++)
			{
				if( bubbleSort[j] > bubbleSort[j+1])
				{
						//swap the values
						tmp = bubbleSort[j];
						bubbleSort[j] = bubbleSort[j+1];
						bubbleSort[j+1] = tmp;
				}
			}
		}
	}

	t2 = clock();

	printf("Time for a bubble sort list with a size of %d: %f\n" ,size, (t2-t1)/(float)(CLOCKS_PER_SEC));
}

void selectionSort(int master[], int size)
{
	int i, j, tmp, itr;
	int bigloc;
	int selectionSort[size];

	clock_t t1, t2;

	t1 = clock();

	for(itr=0; itr<500; itr++)
	{

		for(i=0; i<size; i++)
			selectionSort[i] = master[i];

		 //sort with selection sort ascending  biggest to right first
	        for(i=0; i<size; i++)
		{
               		 bigloc = 0;
               		 for(j = 0; j< size-i; j++)
               		 {
                       		 if(selectionSort[j] > selectionSort[bigloc])
                        	        bigloc = j;
             	   	 }
               		 //swap value at bigloc with value N-i-1
                	tmp = selectionSort[size-i-1];
                	selectionSort[size-i-1] = selectionSort[bigloc];
                	selectionSort[bigloc] = tmp;

	        }
	}
	t2 = clock();

	printf("Time for a selection sort list with a size of %d: %f\n" ,size, (t2-t1)/(float)(CLOCKS_PER_SEC));

}

void randomList(int master[])
{
	int i;
	int j = 0;

	for (i=0; i< 8000; i++) //fills master array with random list holding values ranging 0-99
		master[i] = rand() % 100;

	printf("Bubble sort times for a randomized list repeated 500 times: \n"); 
	bubbleSort( master, 500);
	bubbleSort( master, 1000);
	bubbleSort( master, 2000);
	bubbleSort( master, 4000);
	bubbleSort( master, 8000);


	printf("Selection sort times for a randomized list repeated 500 times: \n");
	selectionSort( master, 500);
	selectionSort( master, 1000);
	selectionSort( master, 2000);
	selectionSort( master, 4000);
	selectionSort( master, 8000);

}


void nearSort(int master[])
{
	int i;
	int j = 0;

	for( i =0; i<8000; i++)// creates a nearly sorted list holding values up to 1000
	{
		master[i] = rand()%10 + j;

		if(i%10==0)
		{
			j = j+10;
		}
	}

	printf("Bubble sort times for a nearly sorted list repeated 500 times: \n");
	bubbleSort( master, 500);
	bubbleSort( master, 1000);
	bubbleSort( master, 2000);
	bubbleSort( master, 4000);
	bubbleSort( master, 8000);


	printf("Selection sort times for a nearly sorted list repeated 500 times: \n");
	selectionSort( master, 500);
	selectionSort( master, 1000);
	selectionSort( master, 2000);
	selectionSort( master, 4000);
	selectionSort( master, 8000);

}

int main(void)
{
	int master[8000];

	srand(50);

	randomList(master);

	nearSort(master);

	return 0;
}
