#include <stdio.h>

#define LAST 31 

void pre(int tr[], int r)
{
 if ( r > LAST)
   return;
 if(tr[r] != -1)
{
 printf("%2d ", tr[r]);
 pre(tr, r*2);
 pre(tr, r*2+1);
}

}

void in(int tr[], int r)
{
 if ( r > LAST)
   return;
 if( tr[r] != -1)
 {
 	in(tr, r*2);
 	printf("%2d ", tr[r]);
	 in(tr, r*2+1);
 }

}

void post(int tr[], int r)
{
 if ( r > LAST)
   return;
 if( tr[r] != -1)
 {
 	post(tr, r*2);
 	post(tr, r*2+1);
 	printf("%2d ", tr[r]);
 }

}
/*
void insertRecursive( int a[], int val, int subtreeroot)
{
	if(a[subtreeroot] == -1)
		a[subtreeroot] = val;
	else
	{
		if( val < a[subtreeroot] )
			subtreeroot = subtreeroot * 2;
		else
			subtreeroot = subtreeroot * 2 + 1;

		insertRecursive( a, val, subtreeroot );
	}
}

//Recursive insert
void insert(int a[], int val)
{
	insertRecursive(a, val, 1);
}
*/

// Iterative insert
void insert(int a[], int val)
{
	int r = 1;

	while( a[r] != -1)
	{
		if( val < a[r] )
			r = r * 2;
		else if ( val > a[r] )
			r = r * 2 + 1;

	}
	a[r] = val;
}

int searchIndex(int t[], int val, int subtreeroot) //same as search, but returns the location in the array of the found value
{
	if(t[subtreeroot] == -1 || subtreeroot > LAST)
		return 0;
	if(val < t[subtreeroot])
		return searchIndex(t, val, subtreeroot*2);
	else if(val > t[subtreeroot])
		return searchIndex(t, val, subtreeroot*2+1);
	else if(val == t[subtreeroot])
		return subtreeroot;
}

int search(int t[], int val, int subtreeroot) //Searches the binary tree for a value and returns 1 or 0 if value is in the tree
{
	if(t[subtreeroot] == -1 || subtreeroot > LAST)
		return 0;
	if(val < t[subtreeroot])
		return search(t, val, subtreeroot*2);
	else if(val > t[subtreeroot])
		return search(t, val, subtreeroot*2+1);
	else if(val == t[subtreeroot])
		return 1;
}

int findSmallest(int t[], int location)//finds smallest value in the right subtree. Used in the remove function
{
	int leftChild = t[location * 2];//value in array
	int smallest = location;//index in array

	if(leftChild != -1)//looks through the list until a node does not have a left child
	{
		smallest = smallest * 2; // move the index to left subtree
		return findSmallest(t, smallest);
	}
	else
		return smallest;

}

int shiftLeft(int t[], int location)
{
	if(location < LAST && t[location*2+1] != -1)
	{
		t[location] = t[location*2+1];
		return shiftLeft(t, location*2+1);
	}
	else
	{
		t[location] = -1;
		return;
	}
}

int shiftRight(int t[], int location)
{
	if(location < LAST && t[location*2] != -1)
	{
		t[location] = t[location*2];
		return shiftRight(t, location*2);
	}
	else
	{
		t[location] = -1;
		return;
	}
}

void removeNode(int t[], int val)
{
	int leftChild = -1;
	int rightChild = -1;
	int smallestChild;
	int location;

	location = searchIndex(t, val, 1);

	if(location == 0) //value to delete was not in the list
	{
		printf("Sorry, that value is not in the list.\n");
	}
	else
	{//look for overextension?
		leftChild = t[location * 2]; //looks to see if node has a left child
		rightChild = t[location * 2 + 1];//looks to see if node has a right child

		if(leftChild == -1 && rightChild == -1)//if node has no children (leaf node)
		{
			t[location] = -1;
		}
		else if(leftChild != -1 && rightChild == -1 || leftChild == -1 && rightChild != -1)//if node has one child
		{
			if(leftChild != -1)
			{
				shiftRight(t, location);
			}
			else if(rightChild != -1)
			{
				shiftLeft(t, location);
			}
		}
		else if(leftChild != -1 && rightChild != -1)//if node has two children
		{
			//find the smallest value in the right subtree (rightNode)
			smallestChild = findSmallest(t, location*2+1);
			t[location] = t[smallestChild];
			t[smallestChild] = t[smallestChild*2+1]; //replaces smallest node with its possible right node.
		}
	}
}
int main()
{
 int t[LAST+1];
 int i;
 int val;

 for (i = 1; i < LAST+1; ++i)
   t[i] = -1;

 insert( t, 22 );
 insert( t, 25 );
 insert( t, 14 );
 insert( t, 18 );

 for (i = 1; i < LAST+1; ++i) {
 	if (t[i] != -1) {
 		printf("%2d ", t[i]);
	}

 }

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

//Start of search function calls
 printf("Please enter a value to search for: ");
 scanf("%d", &val);

 if(search(t, val, 1))
 {
   printf("The value is in the tree\n");
 }
 else
 {
   printf("The value is not in the tree\n");
 }

//start of delete function calls
 printf("Please enter a value to delete: ");
 scanf("%d", &val);

 removeNode(t, val);

 for (i = 1; i < LAST+1; ++i) { //print out the list
 	if (t[i] != -1) {
 		printf("%2d ", t[i]);
	}

 }

 printf("\n");

 return 0;
}
