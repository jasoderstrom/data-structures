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
  void in( treenode *t);
  void post( treenode *t );
  void insert( treenode *t, treenode *n );
  void remove( treenode *t, treenode *delNode);
  struct treenode *searchNode( treenode *t, int val );
  struct treenode *searchParent( treenode *t, treenode *target );
  struct treenode *findSmallest( treenode *delNode );
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

void bstree::in(treenode * t)
{
 if ( t == NULL )
   return;

 in(t->lchild);
 printf("%2d ", t->dat);
 in(t->rchild);
}

void bstree::in()
{
 in(root);
}

void bstree::post(treenode * t)
{
 if ( t == NULL )
    return;

  post(t->lchild);
  post(t->rchild);
  printf("%2d ", t->dat);

}

void bstree::post()
{
 post(root);
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

struct treenode *bstree::searchNode(treenode *t, int val)
{
     treenode *delNode;

     if(t != NULL)
     {
        if(val == t->dat)
        {
                delNode = t;
        }
        else if(val > t->dat)
        {
                delNode = searchNode(t->rchild, val);
        }
        else if(val < t->dat)
        {
                delNode = searchNode(t->lchild, val);
        }

        return delNode;
    }
    else
    {
                return NULL;
    }
} 

struct treenode *bstree::searchParent(treenode *t, treenode *delNode)  //finds the parent of the n$
{
        if(t->lchild == delNode || t->rchild == delNode)
        {
                return t;
        }
        else
        {
                if(delNode->dat > t->dat)
                {
                        if(t->rchild != NULL)
                        {
                                t = searchParent(t->rchild, delNode);
                        }
                }
                else if(delNode->dat < t->dat)
                {
                        if(t->lchild != NULL)
                        {
                                t = searchParent(t->lchild, delNode);
                        }
                }
        }
}

struct treenode *bstree::findSmallest(treenode *delNode)
{
        if(delNode->lchild != NULL)
        {
                delNode = findSmallest(delNode->lchild);
        }

        return delNode;
}

void bstree::remove(treenode *t, treenode *target) { // t is the subroot

        treenode *parent;
        treenode *smallest;

        if (target == root) { // target node is the root

        if (root->rchild == NULL && root->lchild == NULL) { // root has no children

        delete root;

        } else if (root->rchild != NULL && root->lchild != NULL) { // root has two children

                 smallest = findSmallest(root->rchild);
                 root->dat = smallest->dat;
                 remove(t, smallest);

        } else if (root->rchild != NULL || root->lchild != NULL) { // root has only one child

        if (root->rchild == NULL) { // root has a left child

                root->dat = root->lchild->dat;
                remove(t, root->lchild);

        } else if (root->lchild == NULL) { // root has a right child

                root->dat = root->rchild->dat;
                remove(t, root->rchild);
        }

    }

      } else { // target node is not the root of the tree


        if (target->rchild == NULL && target->lchild == NULL) { // target node is a leaf (no children)

        parent = searchParent(root, target);

        if (parent->rchild == target) { // target node is a right child

        parent->rchild = NULL;

        } else if (parent->lchild == target) { // target node is a left child

        parent->lchild = NULL;

        }

        delete target;

        } else if (target->rchild != NULL && target->lchild != NULL) { // target node has two children

        smallest = findSmallest(target->rchild);
        parent = searchParent(root, smallest);
        target->dat = smallest->dat;

        if (smallest->rchild != NULL) { // if the smallest node has a right child
                smallest = smallest->rchild;
                remove(t, smallest->rchild);
        } else {
        parent->rchild = NULL;
        delete smallest;
}

} else if (target->rchild != NULL || target->lchild != NULL) { // target node has only one child

        if (target->lchild == NULL) { // target node has a right child only

        target->dat = target->rchild->dat;
        // problems!!!!!!
        remove(t, target->rchild);

} else if (target->rchild == NULL) { // target node has a left child only

        target->dat = target->lchild->dat;
        remove(t, target->lchild);

   }

  }

 }

} //end of private remove function

void bstree::remove( int x )
{
        treenode *delNode;
        delNode = searchNode(root, x);

        if(delNode != NULL)
        {
                remove(root, delNode);
        }
        else
        {
                printf("Sorry, I could not remove that value.\n");
        }
}

int main(int argc, char *argv[])
{
 bstree * t;
 int i, x;
 int N;
// int vals[] = {20, 17, 30, 12, 18};
 N = 8;
 int vals[] = {5, 2, 18, -4, 3, 21, 19, 25};
 //int vals[] = {5, 2, 12, -4, 3, 9, 21, 19, 25};
 t = new bstree();
 for ( i = 0; i < N; ++i)
  {
   t->insert( vals[i] );
   printf("Added %d, pre is: ", vals[i] );
   t->pre();
   printf("\n");
  }

 printf("Tree is: \n");
 printf("   Infix: ");
 t->in();
 printf("\n");

 printf("Tree is: \n");
 printf("  Prefix: ");
 t->pre();
 printf("\n");

 printf("Tree is: \n");
 printf(" Postfix: ");
 t->post();
 printf("\n");

   printf("Val to remove: ");
   scanf("%d", &x);
   t->remove( x );
   printf("Tree is: \n");
   printf("   Infix: ");
   t->in();
   printf("\n");


 return 0;

}

