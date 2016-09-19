/* Justin Soderstrom
   CSC-300
   October 7, 2015
   Creates a binary search tree and executes functions based off of number commands in a given file.
*/

#include <stdio.h>

#define LAST 125 

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
	{
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

			if(smallestChild*2+1 != -1)//if the smallest node has a right child
			{
				t[smallestChild] = t[smallestChild*2+1];
				t[smallestChild*2+1] = -1;
			}
			else
			{
				t[smallestChild] = -1;
			}
		}
	}
}

void paren(int t[], int i)
{
	if(i > LAST)
	{
		return;
	}
	else if (t[i] != -1)
	{
		printf("(%2d ", t[i]);
		paren(t, i*2);
		paren(t, i*2+1);
		printf(")");
	}
	else
	{
		printf("()");
	}
}

int main(int argc, char *argv[])
{
 int t[LAST+1];
 int i;
 int cmd = 1;
 int val = 1;

 for (i = 1; i < LAST+1; ++i)
   t[i] = -1;

 FILE *fp;
 fp = fopen(argv[1], "r");

 while(cmd != 0)// 0 is quit
 {
   fscanf(fp, "%d", &cmd);

   if(cmd == 1)// 1 is insert node to tree
   {
	fscanf(fp, "%d", &val);

	insert(t, val);
   }
   else if(cmd == -1)// -1 is delete node from the tree
   {
	fscanf(fp, "%d", &val);

	removeNode(t, val);
   }
   else if(cmd == 3)// 3 is show tree in preorder
   {
	printf("Preorder: ");
	pre(t, 1);
	printf("\n");
   }
   else if(cmd == 4)// 4 is show the tree inorder
   {
	printf("Inorder: ");
	in(t, 1);
	printf("\n");
   }
   else if(cmd == 5)// 5 is show the tree postorder
   {
	printf("Postorder: ");
	post(t, 1);
	printf("\n");
   }
   else if(cmd == 6)// 6 is show the tree using parenthesis
   {
	printf("Paren: ");
	paren(t, 1);
	printf("\n");
   }
 }
 fclose(fp);
 return 0;
}
