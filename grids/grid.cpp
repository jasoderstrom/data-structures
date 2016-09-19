#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class mat
{
        public:
                mat();
                void load(char *fname); //could do char *
                void print();
        private:
                int A[100][100];
                int N;                  //N x N matrix

};

mat::mat()
{
        int r, c;
        for(r = 0; r < 100; r++)
        {
                for (c = 0; c < 100; c++)
                        A[r][c] = 0;
        }
}

void mat::load( char *fname )  //same thing as char fname[]
{
        int many, r, c, i; //r = row

        ifstream fin;

        fin.open( fname );

        fin >> N;
        fin >> many;
        for (i = 0; i < many; i++)
        {
                fin >> r >> c;
                A[r][c] = 1;
        }


}

void mat::print()
{
        int r, c;

        for (r = 1; r <= N; r++)
        {
                for(c = 1; c <= N; c++)
                        cout << A[r][c] << "  ";
                cout << endl;
        }
}

int main( int argc, char *argv[] )
{

        if (argc != 2)
        {
                cout << "Error: must supply filename " << endl;
                exit(1);
        }

        mat m;

        m.load( argv[1] );
        m.print();

        return 0;
}
