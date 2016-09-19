/* Author:  Justin Soderstrom
   Class:   CSC-300
   Date:    December 7, 2015
   Purpose: Demonstrates the unique list, IP range, and recursive operations functions for the Final7 assignment.
	    The APSP function can be found in the APSP.cpp program, and the String Search function can be found
	    in the stringSearch.cpp program.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;

class ip
{
        public:
                ip();
                void ipRange();
        private:
        int A, B, C, D; // (A.B.C.D representation of starting ip address)
        int E, F, G, H; // (E.F.G.H representation of ending ip address)

};

class recursive
{
        public:
                recursive();
                ~recursive();
                void countUp(int i);
                void countDown(int i);
                void countDownStart();
                void fibonacciCall();
                int fibonacciRec(int position, int prev, int prev2);
                void fibonacciDynamic(int position);
        private:
                int N;
                int fib;
                int calls;
                int *prev;
};

class uniqueList
{
        public:
                uniqueList();
                ~uniqueList();
                void generateList();

        private:
                void printList();
                int *list;   //array to hold the generated list
                int *unique; //array to determine unique values
                int U, N;

};

recursive::recursive()
{
	cout << endl;
        cout << "Starting Recurisive Functions Sections..." << endl;
        cout << "Enter a number to count to (0 - N): ";
        cin >> N;
        cout << "Enter fibonacci number to find: ";
        cin >> fib;

        prev = new int[fib + 1];
}

recursive::~recursive()
{
        delete[] prev;
}

ip::ip()
{
	cout << endl;
        cout << "Starting IP address section..." << endl;

        string tempNum;
        cout << "Enter a starting ip address: " ;
        getline(cin, tempNum, '.');
        stringstream(tempNum) >> A;

        getline(cin, tempNum, '.');
        stringstream(tempNum) >> B;

        getline(cin, tempNum, '.');
        stringstream(tempNum) >> C;

        getline(cin, tempNum);
        stringstream(tempNum) >> D;

        cout << "Enter an ending ip address: " ;
        getline(cin , tempNum, '.');
        stringstream(tempNum) >> E;

        getline(cin, tempNum, '.');
        stringstream(tempNum) >> F;

        getline(cin, tempNum, '.');
        stringstream(tempNum) >> G;

        getline(cin, tempNum);
        stringstream(tempNum) >> H;

}

uniqueList::uniqueList()
{
        srand(time(NULL));

	cout << endl;
        cout << "Starting Unique List Section..." << endl;
        cout << "Enter the amount of numbers to generate (N): ";
        cin >> N;
        cout << "Enter the range of numbers (1 to U): ";
        cin >> U;

        list = new int[N];
        unique = new int[U+1];

}

uniqueList::~uniqueList()
{
        delete[] list;
        delete[] unique;
}

void recursive::fibonacciCall()
{
        int fibonacci, time;
        clock_t t1, t2;

        if(fib == 0)
        {
            cout << "Fibonnacci(0) is 0" << endl;
        }
        else if(fib == 1)
        {
            cout << "Fibonacci(1) is 1" << endl;
        }
        else
        {
               calls = 0;
               t1 = clock();
               fibonacci=fibonacciRec(2, 1, 0);
               t2 = clock();
               time = (t2-t1)/(float)(CLOCKS_PER_SEC);

               cout << "Recursive Fibonacci:" << endl;
               cout << "Fibonacci(" << fib << ") is " << fibonacci << endl;
               cout << "Amount of recursive calls: " << calls << endl;
               cout << "Amount of time to complete fibonacci recursion: " << time << endl;
		cout << endl;

               prev[0] = 0;
               prev[1] = 1;

               calls = 0;
               t1 = clock();
               fibonacciDynamic(2);
               t2 = clock();
               time = (t2-t1)/(float)(CLOCKS_PER_SEC);


               cout << "Dynamic Recursive Fibonacci:" << endl;
               cout << "Fibonacci(" << fib << ") is " << prev[fib] << endl;
               cout << "Amount of dynamic recursive calls: " << calls << endl;
               cout << "Amount of time to complete dynamic fibonacci recursion: " << time << endl << endl;

        }
}

void recursive::fibonacciDynamic(int position)
{
        int newNum;

        if(position <= fib)
        {
                newNum = prev[position-1] + prev[position-2];

                prev[position] = newNum;

                position++;
                calls++;

                fibonacciDynamic(position);
        }

        return;
}

int recursive::fibonacciRec(int position, int prev, int prev2 )
{
        int newNum;

        if(position <= fib)
        {
                newNum = prev + prev2;

                prev2 = prev;
                prev = newNum;

                position++;
                calls++;
                prev = fibonacciRec(position, prev, prev2);
        }

        return prev;

}

void recursive::countUp(int i)
{
        if(i <= N)
        {
                cout << i << " ";
                i++;
                countUp(i);
        }

        return;
}

void recursive::countDown(int i)
{
        if(i >= 0)
        {
                cout << i << " ";
                i--;
                countDown(i);
        }

        return;
}

void recursive::countDownStart()
{
        countDown(N);
}

void ip::ipRange()
{
        int i = A;
        int j = B;
        int k = C;
        int m = D;
	int calls = 0;

        cout << "Valid IP Address Range starting from " << A << "." << B << "." << C << "." << D << " to " << E << "." << F << "." << G << "." << H << endl;

        if( A == E && B == F && C == G && D == H) //if the starting and ending ip addresses are the same
        {
                cout << A << "." << B << "." << C << "." << D << endl;
        }
        else
        {

                while( i != E || j != F || k != G || m != H ) //while the starting ip address does not equal the ending ip address
                {
                        cout << i << "." << j << "." << k << "." << m << endl;

                        m++;

                        if(m == 256)
                        {
                                m = 0;
                                k++;
                        }
                        if(k == 256)
                        {
                                k = 0;
                                j++;
                        }
                        if(j == 256)
                        {
                                j = 0;
                                i++;
                        }
                        if (i == 256)
                        {
                                i = 0;
                        }

			calls++;
                }

                cout << E << "." << F << "." << G << "." << H << endl; //corrects the off by 1 error
        }
		calls++;
		cout << "Amount of IP addresses generated: " << calls << endl;

}

void uniqueList::generateList()
{
        int randVal, j;
        int count = 0; //loop counter
        int cmp = 0; //amount of random number attemps
        int i = 0;
        float time;

        clock_t t1, t2;

        if( U >= N ) //check to make sure generating the list is possible
        {
                for(j=1; j<= U; j++) //initialize the unique array to zero
                {
                        unique[j] = 0;
                }

                t1 = clock();
                while( count < N )
                {
                        randVal = rand() % U + 1;

                        if(unique[randVal] == 0) //if the number has not already been used in the generated list
                        {
                                list[i] = randVal;
                                unique[randVal] = 1;
                                i++;
                                count++;
                        }
                        //else, don't put the random value in the list and go through the loop again
                        cmp++;
                }
                t2 = clock();

                time = (t2-t1)/(float)(CLOCKS_PER_SEC);

                cout << "Amount of Random Number Attempts: " << cmp << endl;
                cout << "Time to create the unique list: " << time << endl;

                printList();
        }
        else
        {
                cout << "U is too small! Must be U >= N." << endl;
        }

}

void uniqueList::printList()
{
        int i;

        if(N <= 100)
        {
                for(i=0; i < N; i++)
                {
                        cout << list[i] << " ";
                }

                cout << endl;

        }
        else
        {
                cout << "The list is to big to print out!" << endl;
        }
}

int main(void)
{
        // start of the unique list functions
      uniqueList u;

      u.generateList();

        // start of the ip range functions
      ip i;

      i.ipRange();

        // start of the recursive functions
      recursive r;

      cout << endl;
      cout << "Recursive Counting from 0 to N and N to 0: " << endl;
      r.countUp(0);
      cout << endl;

      r.countDownStart();
      cout << endl << endl;

      r.fibonacciCall();

}
