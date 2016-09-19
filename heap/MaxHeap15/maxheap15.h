#include <iostream>
#include <iomanip>
using namespace std;

class heap
{
 public:
   heap();
   heap( int n );
   void add( int x );
   int remove();
   void printA();
   bool isEmpty() { return last==0; };
   bool isFull()  { return last==(SZ-1); };
 private:
   int *arr;
   int SZ; 
   int last;
   void upheap();
   void downheap();
};

