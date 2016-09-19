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
 printf("Please enter a value to search for: \n");
 scanf("%d", &val);

 if(search(t, val, 1))
 {
   printf("The value is in the tree\n");
 }
 else
 {
   printf("The value is not in the tree\n");
 }

 return 0;
}
