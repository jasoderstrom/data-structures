/* Author:  Justin Soderstrom
   Class:   CSC-300
   Date:    December 7, 2015
   Purpose: Demonstrates All-Point-Shortest-Path graph traversals for the Final7 assignment using the Floyd-Warshall algorithm.
	    The string search function can be found in the stringSearch.cpp program, and the other 4 functions can be found in the
	    soderstromFinal.cpp program.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define INF 999

class graph
{
        public:
                graph();
                void undirectedAdjMatrix(char *fname);
                void printMatrix();
                void floydWarshell();
        private:
                void printFW();
                void printPath(int u, int v);
        private:
                int A[100][100];
                int dist[100][100];
                int next[100][100];
                int N;                  //N x N matrix
                int U;                  //used to fine path from U to V on floyd Warshell algorithm
                int V;
};

graph::graph()
{
        cout << endl;
        cout << "Enter a starting vertex (U): ";
        cin >> U;

        cout << "Enter an ending vertex (V): ";
        cin >> V;
        cout << endl;

        int r, c;
        for(r = 0; r < 100; r++)
        {
                for (c = 0; c < 100; c++)
		{
                        A[r][c] = INF;
	                next[r][c] = 0;
		}

        }
}

void graph::undirectedAdjMatrix( char *fname )
{
        int edges, r, c, i, weight; //r = row

        ifstream fin;

        fin.open( fname );

        fin >> N;
        fin >> edges;
        for (i = 0; i < edges; i++)
        {
                fin >> r >> c >> weight;
                A[r][c] = weight;
                A[c][r] = weight;
        }
}

void graph::printMatrix()
{
        int r, c;

        cout << "Graph Matrix: " << endl;

        cout << "  ";

        for (r = 1; r<=N; r++)  //prints out visual "To" row
        {
                cout << r << " ";
        }

        cout << endl;

        for (r = 1; r <= N; r++)
        {
		cout << r << " ";

                for(c = 1; c <= N; c++)
                {
                        if(A[r][c] == INF)
                        {
                                cout << 0 << " ";
                        }
                        else
                        {
                                cout << A[r][c] << " ";
                        }
                }
                cout << endl;
        }

	cout << endl;
}

void graph::floydWarshell()
{
        int i, j, k;

        for(i=1; i <= N; i++)// initialize the distance array to be the same as the graph array
        {
                for (j = 1; j <= N; j++)
                {
                        next[i][j] = i;

                        if(i == j) //the cost from a vertex to itself is always zero
                        {
                                dist[i][j] = 0;
                        }
                        else
                        {
                                dist[i][j] = A[i][j];
                        }

                }
        }

	for(i=1; i<=N; i++) //initialize the next array to hold the parent vertices of an edge
	{
		for(j=1; j<=N; j++)
		{
			if(A[i][j] == INF)
			{
				next[i][j] = 0;
			}
			else
			{
				next[i][j] = i;
			}
		}
	}

        for( k = 1; k <= N; k++ )
        {
                for( i = 1; i <= N; i++ ) //pick all vertices as the source, one by one
                {
                        for( j = 1; j <= N; j++ )//pick all vertices as the destination for the above picked source
                        {
                                if( dist[i][k] + dist[k][j] < dist[i][j] )// If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                                {
                                        dist[i][j] = dist[i][k] + dist[k][j];
                                        next[i][j] = next[k][j];
                                }
                        }
                }
        }

        printFW();

        cout << "Path from " << U << " to " << V << ": " << endl;

        printPath(U, V);

	cout << endl;
	cout << "Cost from " << U << " to " << V << ": " << dist[U][V] << endl;
        cout << endl << endl;

}

void graph::printPath(int u, int v)
{
	if(u == v)
	{
		cout << u << " ";
	}
        else if(next[u][v] == 0)
        {
                cout << "There is no path to those vertices" << endl;
        }
        else
        {
                printPath(u, next[u][v]);

                cout << v << " ";
        }

	return;
}

void graph::printFW()
{
        int i, j;

        cout << "All-Points-Shortest-Path Matrix:" << endl;

        for(i = 1; i <= N; i++)//print out column numbers
        {
                cout << "   " << i << " ";
        }

        cout << endl;

        for(i = 1; i <= N; i++) //print out the matrix to sow the shortest distances between every pair of vertices
        {
                cout << i;
                for(j = 1; j <= N; j++)
                {
                        if(dist[i][j] == INF)
                                cout << " INF ";
                        else
                                cout << "  " << dist[i][j] << "  ";
                }

                cout << endl;
        }


        cout << endl;
}

int main(int argc, char *argv[])
{
        graph g;

        g.undirectedAdjMatrix(argv[1]);

        g.printMatrix();

        g.floydWarshell();

}


