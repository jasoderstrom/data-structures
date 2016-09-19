//Justin Soderstrom

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct listnode
{
        int data;
        listnode *next;
};

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
                listnode *head;
                static const int MAX = 1000;
		int len; 
};

sortedList::sortedList()
{
        head = NULL;
        len = 0;
}

void sortedList::print()
{
        int i = 0;

        listnode *ptr = head;

        for(i=0; i<len; i++)
        {
                cout << ptr->data << " ";
                ptr = ptr->next;
        }

        cout << " -- Len: " << len << endl;
}       

void sortedList::insert( int x)
{
    if (isFull())
    {
        cout << "ERROR: inserting to full list " << endl;
        exit(1);
    }

    listnode *t1;
    t1 = new listnode();
    t1->data = x;
    t1->next = NULL;

    int p = 2; //starts at two becasue ptr starts at the second node

    if(head == NULL) //if there are 0 nodes in the list
        head = t1;
    else if (t1->data < head->data) //if new node is smaller than the head node
    {
          t1->next = head;
          head = t1;
    }
    else if (head->next == NULL)// if there is only 1 node in the list
    {
            head->next = t1;
    }
    else                        // if there is at least 2 nodes in list
    {
        listnode *ptr = head->next;
        listnode *prev = head;

        while ( p < len && ptr->data <= x)
        {
             p++;
             ptr = ptr->next;
             prev = prev->next;
        }
        if(t1->data > ptr->data) //checks for the case where the inserted node is the largest in the list
        {
               ptr->next = t1;
        }
        else
        {
                t1->next = ptr;
                prev->next = t1;
        }
    }
    len++;
}

int sortedList::removeMax()
{
        if( isEmpty() )
        {
                cout << "ERROR:  remove from empty list " << endl;
                exit(2);
        }

        listnode *ptr = head;
        int max;
        int p = 1; //current position within the list

        while(p < len - 1) //find the node right before the maximum value
        {
                ptr = ptr->next;
                p++;
        }
        if(len == 1)//checks for the case of a 1 node list
        {
                max = ptr->data;
                head = NULL;
                free(ptr);
        }
        else
        {
                listnode *tmp = ptr->next;
                max = tmp->data;
                ptr->next = NULL;
                free(tmp);
        }

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

      int min;
      listnode *ptr = head;

      min = ptr->data;
      head = head->next;

      free(ptr);

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
	for (i = 0; i < 10; ++i)
	{
		x = rand() % 100;
		cout << " insert " << setw(2) << x << endl;
		sl.insert(x);
	}
	sl.print();

	// now carry out 50 random insert/delete 
	act = 0;
	while (act < 50)
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


