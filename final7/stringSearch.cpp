/* Name:    Justin Soderstrom
   Class:   CSC-300
   Date:    December 7, 2015
   Purpose: Demonstrates the string search function for the Final7 assignment. The APSP function can be found in the APSP.cpp program,
	    and the other 4 functions can be found in the soderstromFinal.cpp program.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void stringSearch(string pattern, char *fname)
{
        ifstream F;

        F.open(fname);

        int lineCount = 0;

        string line;
        int pos=0;
        int i;
        int match = 0;

        while( !F.eof() ) //read until the end of the file
        {
                lineCount++;

                getline(F, line);

                pos=line.find(pattern);

                if(pos != string::npos)
                {
                        while(pos != string::npos)
                        {
                                cout << "Match found on line " << lineCount;
                                cout<<" at index "<<pos<<endl;
                                pos=line.find(pattern,pos+1);
                                match++;

                        }
                }
        }

        cout << "Total Matches: " << match << endl;
}

int main(int argc, char *argv[])
{
  //start of the string search function
       ifstream P;

       string pattern;

       P.open(argv[2]); //points to the pattern string

       getline(P, pattern);

       stringSearch(pattern, argv[1]);

}
