#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class node
{
 public:
  node()                 { ptr = NULL; };//short functions can be completed inline
  node(int x )           { dat = x; ptr = NULL; };
  int getval()           { return dat; };
  void setval( int x )   { dat = x; };
  node* getptr()         { return ptr; };
  void setptr( node *p)  { ptr = p; };
 private:
  int dat;
  node *ptr;
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
  tmp->setptr( toploc );
  toploc = tmp;
}

int stack::pop( )
{
  int v;
  node *tmp;
  v = toploc->getval();
  tmp = toploc;
  toploc = toploc->getptr();
  delete tmp;
  return v;
}

int stack::top( )
{
  int v;
  v = toploc->getval();
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
   cout << setw(3) << tmp->getval() ;
   tmp = tmp->getptr();
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
