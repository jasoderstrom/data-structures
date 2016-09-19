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
  struct treenode *searchParent( treenode *t, treenode *delNode );
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
void bstree::remove(treenode *t, treenode *delNode)
{
        treenode *parNode;//the parent node to the node to delete
        treenode *smallNode;//the smallest node in the left subtree

        if (delNode == t) { // target node is the root

        if (t->rchild == NULL && t->lchild == NULL) { // root has no children

                delete t;

        } else if (t->rchild != NULL && t->lchild != NULL) { // root has two children

                smallNode = findSmallest(t->rchild);
                t->dat = smallNode->dat;
                remove(t, smallNode);

        } else if (t->rchild != NULL || t->lchild != NULL) { // root has only one child

        if (t->rchild == NULL) { // root has a left child

                t->dat = t->lchild->dat;
                remove(t, t->lchild);

        } else if (t->lchild == NULL) { // root has a right child

                t->dat = t->rchild->dat;
                remove(t, t->rchild);
        }

}

} else { // target node is not the root of the tree

        if(delNode->lchild == NULL && delNode->rchild == NULL) //if the node is a leaf
        {
                parNode = searchParent(t, delNode);

                if(parNode->lchild == delNode)//if the leaf is a left node
                {
                        parNode->lchild = NULL;
                }
                else//if the leaf is a right node
                {
                       parNode->rchild = NULL;
                }

                delete delNode;
        }
        else if(delNode->lchild != NULL && delNode->rchild != NULL) //if the node has two children
        {
                smallNode = findSmallest(delNode->rchild);
                parNode = searchParent(t, delNode);
                delNode->dat = smallNode->dat;

          if (smallNode->rchild != NULL) 
          { // if the smallest node has a right child
                smallNode = smallNode->rchild;
                remove(t, smallNode->rchild);
          }
          else 
          {
                parNode->rchild = NULL;
                delete smallNode;
          }

        }
        else if(delNode->lchild != NULL || delNode->rchild != NULL) //if the node has one child
        {
                if (delNode->lchild == NULL) { // target node has a right child only

                delNode->dat = delNode->rchild->dat;
                // problems!!!!!!
                remove(t, delNode->rchild);

        } else if (delNode->rchild == NULL) { // target node has a left child only

                delNode->dat = delNode->lchild->dat;
                remove(t, delNode->lchild);
        }


        }
   }
}

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
 printf(" Inorder: ");
 t->in();
 printf("\n");
 printf(" Postorder: ");
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

