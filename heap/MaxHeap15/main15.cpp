#include <iostream>
#include <iomanip>
using namespace std;

#include "maxheap15.h"

int main()
{
 heap h;
 int rv, x;

 cout <<  "Value to insert (-1 to stop): ";
 cin >> x;
 while (x != -1)
  {
    h.add( x );
    h.printA();
    cout <<  "Value to insert (-1 to stop): ";
    cin >> x;
  }

 
 cout <<  "-1 to remove 0 to stop: ";
 cin >> x;
 while ( x == -1 )
  {
    rv = h.remove( );
    cout << "removed " << rv << endl;
    h.printA();
    cout <<  "-1 to remove 0 to stop: ";
    cin >> x;
  }
 
 return 0;
}
