#include "maxheap15.h"

heap::heap()
{
 last = 0;
 SZ = 32;
 arr = new int [SZ];
}

heap::heap( int n )
{
 last = 0;
 SZ = n;
 arr = new int [SZ];
}


void heap::add( int x )
{
 if ( isFull() )
  {
    cout << "Heap is full, doing nothing" << endl;
    return;
  }

 last++;
 arr[last] = x;
 upheap();
}

int heap::remove()
{
 if ( isEmpty() )
  {
    cout << "Heap is empty, doing nothing" << endl;
    return -1;
  }

 int max = arr[1];
 arr[1] = arr[last];
 last--;
 downheap();
 return max;
}


void heap::printA()
{
 int i;
 for (i = 1; i <= last; ++i)
    cout << setw(4) << arr[i] ;
 cout << endl;
}

// start at item last, move it up until 
//   heap property is restored 
void heap::upheap()
{
 int p, c;
 int tmp;
 bool done = false;

 c = last;
 p = c/2;

 while (!done)
 {
   if (c == 1)
     done = true;
   else if (arr[p] > arr[c])
     done = true;
   else
     {
      tmp = arr[p];
      arr[p] = arr[c];
      arr[c] = tmp;
      c = p;
      p = c/2;    
     }
 }
}


// start at item 1, move it down until 
//   heap property is restored 
// ** swap with larger child & repeat
void heap::downheap()
{
 int p, c;
 int lc, lv, rc, rv, mc;
 int tmp;
 bool done = false;

 p = 1;
 lc = p*2;
 rc = p*2 + 1;

 done = true;
 if (lc <= last && arr[p] < arr[lc])
   done = false;
 if (rc <= last && arr[p] < arr[rc])
   done = false;

 while (!done)
  {
    if (rc > last && arr[p] < arr[lc])         // 1 child
      mc = lc;
    else if (rc <= last && arr[lc] > arr[rc])  // 2 child left bigger
      mc = lc;
    else if (rc <= last && arr[lc] < arr[rc])  // 2 child right bigger
      mc = rc;

    tmp = arr[p];
    arr[p] = arr[mc];
    arr[mc] = tmp;

    p = mc;
    lc = p*2;
    rc = p*2 + 1;

    done = true;    
    if (lc <= last && arr[p] < arr[lc])
      done = false;
    if (rc <= last && arr[p] < arr[rc])
      done = false;
  } 

}



