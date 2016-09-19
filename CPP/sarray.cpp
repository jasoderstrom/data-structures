#include <iostream> //got rid of the .h from c
#include <iomanip>
#include <string>
using namespace std;

//#include <cstido>
//Uses #inlcude <stdio.h> from c
//namespace std get rid of the need to call specific functions from a library

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
  int toploc;
  int dat[100];
};

stack::stack()
{
 toploc = 0;
}

void stack::push( int x )
{
  dat[toploc] = x;
  toploc++;
}

int stack::pop( )
{
  toploc--;
  return dat[toploc];
}

int stack::top( )
{
  return dat[toploc-1];
}

bool stack::isEmpty( )
{
  return toploc == 0;
}


void stack::print( )
{
 int i;
 for (i = 0; i < toploc; ++i)
   cout << setw(3) << i ;
 cout << endl;
 for (i = 0; i < toploc; ++i)
   cout << setw(3) << dat[i] ;
 cout << "   <--top ";
 cout << endl;
}

int main()
{
 stack s;
 int x;
 s.push( 4 );   //push(s, 4); in c
 s.push( 6 );
 s.print();
 x = s.top();
 cout << x << " is at top of stack " << endl;
 s.print();
 x = s.pop();
 cout << x << " is at top of stack " << endl;
 s.print();
}
