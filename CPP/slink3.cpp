#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class node
{
 public:
  node(){ ptr = NULL; };
  node(int x ){ dat = x; ptr = NULL; };
 private:
  int dat;
  node *ptr;
 
 friend class stack;//can use public and private components
};

class stack
{
 public:
  stack();
  void push( int );
  int pop( );
  int top( );
  bool isEmpty();
  void print();
 private:
  node *toploc;

};

stack::stack()
{
  toploc = NULL;
}
void stack::push( int x )
{
  node *tmp;
  tmp = new node( x );
  tmp->dat = x;
  tmp->ptr = toploc;
  toploc = tmp;
}

int stack::pop( )
{
  int v;
  node *tmp;
  v = toploc->dat;
  tmp = toploc;
  toploc = toploc->ptr;
  delete tmp;
  return v;
}

int stack::top( )
{
  int v;
  v = toploc->dat;
  return v;
}

bool stack::isEmpty( )
{
  return toploc == NULL;
}


void stack::print( )
{
 int i;
 node *tmp;
 tmp = toploc;

 cout << " top--> ";
 while (tmp != NULL)
  {
   cout << setw(3) << tmp->dat ;
   tmp = tmp->ptr;
  }
 cout << endl;
}

int main()
{
 stack s;
 stack t;
 int x;
 int i;
 for (i = 1; i < 10; ++i)
   t.push( i );
 t.print();

 s.push( 4 );
 s.push( 6 );
 s.print();
 x = s.top();
 cout << x << " is at top of stack " << endl;
 s.print();
 x = s.pop();
 cout << x << " is at top of stack " << endl;
 s.print();

 while ( ! t.isEmpty() )
  {
    x = t.pop();
    cout << " t popped --- " << x << endl;
  }
}
