#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class sortedList
{
	public:
		sortedList();
		void insert( int x );
		int removeMax();
		int removeMin();
		void print();
		bool isEmpty();
		bool isFull();
	private:
		static const int MAX = 1000;
		int A[MAX];
		int len; 
};

sortedList::sortedList()
{
        len = 0;
}

void sortedList::print()
{
        int i = 0;

        for(i=0; i<len; i++)
                cout << A[i] << " ";
        cout << " -- Len: " << len << endl;
}

void sortedList::insert( int x)
{
    if (isFull())
    {
        cout << "ERROR: inserting to full list " << endl;
        exit(1);
    }

    int i, p = 0;

        while ( p < len && A[p] <= x)
                p++;

        for (i = len-1; i >= p; --i)
                A[i+1] = A[i];

        A[p] = x;
        len++;
}

int sortedList::removeMax()
{
        if( isEmpty() )
        {
                cout << "ERROR:  remove from empty list " << endl;
                exit(2);
        }

        int max;
        max = A[len-1];

        len--;

        return max;
}

int sortedList::removeMin()
{
        if( isEmpty() )
        {
                cout << "ERROR:  remove from empty list " << endl;
                exit(2);
        }

        int min = A[0];
        int i;
        for (i=0; i < len; i++)
                A[i] = A[i+1];
        len--;

        return min;
}

bool sortedList::isEmpty()
{
        if (len == 0)
           return true;
        else
           return false;
}

bool sortedList::isFull()
{
        if (len == MAX)
           return true;
        else
           return false;
}



int main()
{
	sortedList sl;
	int i, x, act, opt;

	//srand(time(NULL));
	srand( time(NULL) );

	// prepopulate with 10 values
	//for (i = 0; i < 20; ++i)
	for (i = 0; i < 20; ++i)
	{
		x = rand() % 100;
		cout << " insert " << setw(2) << x << endl;
		sl.insert(x);
	}
	sl.print();

	// now carry out 50 random insert/delete 
	act = 0;
	while (act < 5000)
	{
		opt = rand() % 11;
		switch (opt)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			x = rand() % 100;
			sl.insert(x);
			cout << "Insert " << x << endl;
			break;
		case 6:
		case 7:
			x = sl.removeMax();
			cout << "RemoveMax " << x << endl;
			break;
		case 8:
		case 9:
		case 10:
			x = sl.removeMin();
			cout << "RemoveMin " << x << endl;
			break;
		}

		act++;
	}
	sl.print();

	return 0;
}


