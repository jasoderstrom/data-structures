#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


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
   cout << setw(3) << i ;               //cout << i = printf("%d", i);
 cout << endl;                          //cout << setw(3)<< i printf("%3d", i);
 for (i = 0; i < toploc; ++i)           //cout << "this is i" << i << " and toploc " << toploc << end1; == printf("this is i %d and toploc %d\n", i, toploc);
   cout << setw(3) << dat[i] ;          //cout << endl; printf("\n");
 cout << "   <--top ";
 cout << endl;                          //cin >> x = scanf("%d", &x);
}

int main()
{
 stack s;//calls a constructor
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

