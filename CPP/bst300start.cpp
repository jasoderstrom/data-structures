#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


struct treenode
{
 int dat;
 treenode *lchild;
 treenode *rchild;
};

class bstree
{
 public:
  bstree();
  void pre( );
  void in( );
  void post( );
  void insert( int x );//can name functions with the same name. Polymorphism says there is many instances of the same function
  void remove( int x );
 private:
  treenode *root;
  void pre( treenode *t );
  void insert( treenode *t, treenode *n );
};

bstree::bstree()
{  
  root = NULL;
}

void bstree::pre(treenode * t)
{
 if ( t == NULL )
   return;

 printf("%2d ", t->dat);
 pre(t->lchild);
 pre(t->rchild);
}

void bstree::pre()
{
 pre(root);
}

void bstree::insert( int x )
{
 treenode *t1;

 t1 = new treenode();
 t1->dat = x;
 t1->lchild = NULL;
 t1->rchild = NULL;

 if (root == NULL) 
     root = t1;
 else   
     insert( root, t1 );
}

void bstree::insert( treenode *t, treenode *n )
{
 if (n->dat < t->dat)
  {
   if (t->lchild == NULL)
     t->lchild = n;
   else
     insert(t->lchild, n);
  }
 else if (n->dat > t->dat)
  {
   if (t->rchild == NULL)
     t->rchild = n;
   else
     insert(t->rchild, n);
  }
 else
    cout << "BAD INSERT" << endl;
}


int main(int argc, char *argv[])
{
 bstree * t;
 int i, x;
 int N;
 int vals[] = {20, 17, 30, 12, 18};
 N = 5;
 //int vals[] = {5, 2, 18, -4, 3, 21, 19, 25};
 //int vals[] = {5, 2, 12, -4, 3, 9, 21, 19, 25};
 t = new bstree();
 for ( i = 0; i < N; ++i)
  {
   t->insert( vals[i] );
   printf("Added %d, pre is: ", vals[i] );
   t->pre();
   printf("\n");
  }
 /*
 printf("Tree is: \n");
 printf("   Infix: ");
 t->in();
 printf("\n");
 */
 printf("Tree is: \n");
 printf("  Prefix: ");
 t->pre();
 printf("\n");

/*
   printf("Val to remove: ");
   scanf("%d", &x);
   t->remove( x );
   printf("Tree is: \n");
   printf("   Infix: ");
   t->in();
   printf("\n");
*/

 return 0;
}






