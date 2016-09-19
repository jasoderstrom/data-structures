//Author: Justin Soderstrom


#include <iostream>
#include <iomanip>
using namespace std;


class heap
{
 public:
   heap();              // default SZ is 32   (default constructor)
   heap( int n );       // specify heap size
   void add( int x );
   int remove();
   void printA();
   bool isEmpty(){ return (len == 0); }
   bool isFull() { return (len == SZ-1); } //-1 because our array goes up to 31 and we start at location 1
 private:
   int *list;
   int SZ;
   int len;
   void upheap();
   void downheap();
};

heap::heap()
{
        SZ=32;
        len = 0;
        list = new int [SZ];
}

heap::heap( int n)
{
        SZ=n;
        len = 0;
        list = new int [SZ];

}

void heap::add( int x )
{
        if ( isFull() ) //if isFull returns a true
        {
                cout << "Trying to add to full heap, ignoring..." << x << endl;
                return;
        }

        len++;
        list[len] = x;
        upheap();       //take the last child and move up to keep heap properties
}

int heap::remove()
{
        int max;
        max = list[1];

        list[1] = list[len];
        len--;
        downheap();

        return max;
}


void heap::printA()
{
 int i;
 for (i = 1; i <= len; ++i)
   cout << setw(3) << list[i];
 cout << endl;
}

void heap::upheap()
{
        int parent, child;
        int tmp;
        bool done = false;

        child = len;
        parent = len / 2;

        while ( !done )
        {
                if ( child == 1 )
                    done = true;
                else if ( list[parent] > list[child] )
                    done = true;
                else            //swap the values at parent & child
                {
                        tmp = list[parent];
                        list[parent] = list[child];
                        list[child] = tmp;

                        child = parent;
                        parent = child / 2;
                }
        }
}

void heap::downheap()
{
        int parent, lchild, rchild;
        int tmp;
        bool done = false;

        parent = 1;         //parent is root
        lchild = parent * 2;
        rchild = parent * 2 + 1; 

        while ( !done )
        {
                if( parent == len ) //if the length of the tree is 1
                        done = true;
                else if( lchild < len && rchild <= len)//if the length of the tree is at least 3
                {
                        if( list[parent] > list[lchild] && list[parent] > list[rchild] )//if the parent node is larger than its children
                        {
                                done = true;
                        }
               
                        else if(list[lchild] > list[rchild]) //if the left child is the larger child node
                        {
                                tmp = list[parent];
                                list[parent] = list[lchild];
                                list[lchild] = tmp;

                                parent = lchild;
                                lchild = parent * 2;
                                rchild = parent * 2 + 1;
                        }
                        else                                //if the right child is the larger child node
                        {
                                tmp = list[parent];
                                list[parent] = list[rchild];
                                list[rchild] = tmp;

                                parent = rchild;
                                lchild = parent * 2;
                                rchild = parent * 2 + 1;

                        }
                }
                else if (rchild > len)//if the length of the tree is 2
                {
                        if(list[lchild] > list[parent])
                        {
                                        tmp = list[parent];
                                        list[parent] = list[lchild];
                                        list[lchild] = tmp;
                        }
                        done = true;
                }

        }
}

int main()
{
 heap h;        // calls the default constructor
// heap bigheap(200);
 int i, x;

 cout << "enter values to add, -1 to quit " ;
 cin >> x;
 while ( x != -1 )
  {
    h.add( x );
    cout << "added " << x << endl;
    h.printA();
    cin >> x;
  }

 while ( !h.isEmpty() )
  {
    x = h.remove( );
    cout << "removed " << x << endl;
    h.printA();
  }
 
 return 0;
}
