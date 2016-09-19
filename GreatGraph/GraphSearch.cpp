/*  Author:      Justin Soderstrom
    Class:       CSC-300
    Date:        November 18, 2015
    Assignment:  Create a undirected adjacency matrix through an input file on the command line, including weights.
                 Perform a Depth First Search (DFS), Breadth First Search (BFS), DFS spanning tree (DFS-ST), and
                 BFS spanning tree (BST-ST) search based on user input on the command line.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


class graph
{
        private:
                struct Edge
                {
                        int src;
                        int dest;
                        int weight;
                };

        public:
                graph();
                void undirectedAdjMatrix(char *fname);
                void breadthFirstSearch(int start2);
                void breadthFirstSearchST(int start2);
                void depthFirstSearch(int start2);
                void depthFirstSearchST(int start2);
                void dijkstra(int start2);
                void prim(int start2);
                void kruskal(char * fname);
                int kruskalSort(struct Edge *sortedEdges[], char *fname);
                void printMatrix();
                int queueRemove( int queue[], int len );
        private:
                int A[100][100];
                int N;                  //N x N matrix
};

graph::graph()
{
        int r, c;
        for(r = 0; r < 100; r++)
        {
                for (c = 0; c < 100; c++)
                        A[r][c] = 0;
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

        cout << "  ";

        for (r = 1; r<=N; r++)  //prints out visual "To" row
        {
                cout << r << " ";
        }

        cout << endl;

        cout << "  ";

        for (r = 1; r <= N; r++)
        {
                cout << "- ";
        }

        cout << endl;

        for (r = 1; r <= N; r++)
        {
                cout << r << "|";
                for(c = 1; c <= N; c++)
                        cout << A[r][c] << " ";
                cout << endl;
        }
}

int graph::queueRemove( int queue[], int len )
{
        int i;
        int front = 0;
        if(queue[0] == 0)
        {
                cout << "Sorry, can't remove a value from an empty queue!" << endl;
        }
        else
        {
                front = queue[0];

                for(i = 0; i <= len; i++)
                {
                        queue[i] = queue[i+1];
                }
        }

        return front;
}

void graph::breadthFirstSearch(int start2)
{
        int mark[100] = {0};
        int queue[100] = {0};

        int r, i;
        int len = 0;

        queue[len] = start2;
        len++;

        while( len != 0 )
        {
                r = queueRemove(queue, len);
                len--;

                if(mark[r] != 1)
                {
                        cout << r << " ";
                        mark[r] = 1;
                        for(i = 1; i <= N; i++)
                        {
                                if( A[r][i] != 0 && mark[i] != 1)
                                {
                                      queue[len] = i;
                                      len++;
                                }
                        }
                }
        }
}

void graph::breadthFirstSearchST(int start2)
{
        int mark[100] = {0};
        int queue[100] = {0};
        int edge[100] = {0};

        int r, i;
        int len = 0;

        queue[len] = start2;
        len++;

        while( len != 0 )
        {
                r = queueRemove(queue, len);
                len--;

                if(mark[r] != 1)
                {
                        mark[r] = 1;
                        for(i = 1; i <= N; i++)
                        {
                                if( A[r][i] != 0 && mark[i] != 1 && edge[i] != 1)
                                {
                                      cout << r << "-" << i << " ";
                                      edge[i] = 1;
                                      queue[len] = i;
                                      len++;
                                }
                        }
                }

        }

}

void graph::depthFirstSearch(int start2)
{
        int mark[100] = {0};
        int stack[100] = {0};

        int r, i;
        int top = 0;

        stack[top] = start2;

        while( top != -1 )
        {
                r = stack[top];
                stack[top] = 0;
                top--;

                if(mark[r] != 1)
                {
                        cout << r << " ";
                        mark[r] = 1;
                        for (i = N; i >= 1; i--)
                        {
                                if( A[r][i] != 0 && mark[i] != 1)
                                {
                                        top++;
                                        stack[top] = i;
                                }
                        }
                }
        }
}

void graph::depthFirstSearchST(int start2)
{
        int mark[100] = {0};
        int stack[100] = {0};
        int stack2[100] = {0};

        int r;
        int i = 0;
        int top = 0;
        int top2 = 0;
        int from = 0;

        stack[1] = start2;
        top++;

        while( top != 0 )
        {
                r = stack[top];

                if(top2 != 0)
                {
                        from = stack2[top2];
                        top2--;
                }
                if(mark[r] != 1)
                {
                        mark[r] = 1;
                        for (i = N; i >= 0; i--)
                        {
                                if( A[r][i] != 0 && mark[i] != 1)
                                {
                                        stack[top] = i;
                                        top++;
                                        top2++;
                                        stack2[top2] = r;
                                }
                        }
                        if(from > 0)
                        {
                                cout << from << "-" << r << " ";
                        }
                }
                top--;
        }
}

void graph::dijkstra(int start2)
{
        int i,j,min;
        int edges=0;
        int infinite=999;//could be any value
        int distance[100];
        int known[100] = {0};

        for(i=0;i<=N;i++) //set the distance array
        {
                distance[i]=infinite;
        }

        distance[start2]=0;

        while(edges <= N-1)
        {
                min=infinite;
                for(j=1;j<=N;j++)
                {
                        if((known[j] != 1) && ((min==infinite) || (distance[j] < distance[min])))
                                min=j;
                }

                known[min]= 1;

                for(j=1;j<=N;j++)
                {
                        if(A[min][j]!=0)
                        {
                                if(distance[min] + A[min][j] < distance[j])
                                {
                                        distance[j] = distance[min] + A[min][j];
                                }
                        }

                }

                edges++;
        }

        cout << endl;

        for(i=1; i<=N;i++)
                cout<<i<<": "<< distance[i]<<endl;

}

void graph::prim(int start2)
{
        int weight[N+1]; //edge weights used to pick minimum edge weights
        bool mstSet[N+1]; //array to represent set of vertices not included in MST
        int i, j, u, v;
        int infinite = 999;
        int total = 0;
        int min, min_index;

        for( i = 1; i <= N; i++)
        {
                weight[i] = infinite;
                mstSet[i] = false;
        }

        weight[start2] = 0; //First node is the root of MST

        for( i = 1; i<= N; i++)
        {
                min = infinite;

                for( j = 1; j <= N; j++) //finds smallest not known vertex
                {
                        if(mstSet[j] == false && weight[j] < min)
                        {
                                min = weight[j];
                                min_index = j;
                        }
                }

                u = min_index;

                for( j = 1; j<=N; j++) //print out the edges used
                {
                                if(mstSet[j] == true && A[j][u] == min)
                                {
                                        cout << j << "-" << u << " ";
                                }
                }

                mstSet[u] = true;

                for (v = 1; v <= N; v++)
                {
                        if(A[u][v] != 0 && mstSet[v] == false && A[u][v] < weight[v])
                        {
                                weight[v] = A[u][v];
                        }
                }

        }

        cout << endl;
        for(i=1; i<=N; i++)
        {
               if(weight[i] != infinite)
               {
                        total = total + weight[i];
               }
        }

        cout << "Prim's Total Results: " << total << endl;

}

int graph::kruskalSort(struct Edge *sortedEdges[], char *fname)
{
        int i, j;
        int len = 0;
        int bigloc;
        int edges, r, c, weight;

        ifstream fin;

        fin.open(fname);

        fin >> N;
        fin >> edges;

        struct Edge * vertex;
        struct Edge * vertex2;

        for(i=0; i < edges; i++) //assumes no zero nodes
        {
              fin >> r >> c >> weight;
              vertex = new Edge();
              vertex->src = r;
              vertex->dest = c;
              vertex->weight = weight;

              sortedEdges[len] = vertex;
              len++;

        }

        for(i=0; i< len; i++) //selection sort, ascending to the right
        {
               bigloc = 0;
               for(j=0; j<len-i; j++)
               {
                        vertex = sortedEdges[bigloc];
                        vertex2 = sortedEdges[j];
                        if(vertex2->weight > vertex->weight)
                        {
                                bigloc = j;
                        }
                        else if( vertex2->weight == vertex->weight)
                        {
                                if(vertex2->src >= vertex->src)
                                {
                                        bigloc = j;
                                }
                        }
               }

               vertex = sortedEdges[len-i-1];
               sortedEdges[len-i-1] = sortedEdges[bigloc];
               sortedEdges[bigloc] = vertex;
        }

/*        cout << "Weight   " << "Src   " << "Dest" << endl; //testing loop, not needed in program
        for(i=0; i< len; i++)
        {
                vertex = sortedEdges[i];

                cout << vertex->weight << "   " << vertex->src << "   " << vertex->dest << endl;
        }
*/


        return len;
}

void graph::kruskal(char * fname)
{
        struct Edge * sortedEdges[100]; //could initialize array to size of edges
        int trees[100] = {0};

        struct Edge *edge;
        int i, len, j;
        int tree = 1;
        int total = 0;
        int source, destination;


        //Sort all the edges in non-decreasing order of their weight
        len = kruskalSort(sortedEdges, fname);

        //Pick the smallest edge and check if it forms a cycle with the current spanning tree.

        for(i=0; i< len; i++) //overall MST will have N-1 edges, where N is the number of vertices
        {
                edge = sortedEdges[i];

                if(trees[edge->dest] == 0 && trees[edge->src] == 0) //if tree doesn't exist, make a new tree
                {
                    cout << edge->src << "-" << edge->dest << " ";
                    trees[edge->dest] = tree;
                    trees[edge->src] = tree;

                    total = total + edge->weight;

                    tree++;
                }
                else if(trees[edge->dest] != trees[edge->src]) // if the vertices are adjacent
                {
                     cout << edge->src << "-" << edge->dest << " ";

                     total = total + edge->weight;

                     if(trees[edge->dest] == 0) //if the destination vertex is not apart of any tree
                     {
                          trees[edge->dest] = trees[edge->src];
                     }
                     else if(trees[edge->src] == 0)//if the source vertex is not apart of any tree
                     {
                          trees[edge->src] = trees[edge->dest];
                     }
                     else //if the destination vertex is apart of another tree
                     {
                        source = trees[edge->src];
                        destination = trees[edge->dest];

                        for(j=1; j<= N; j++)
                        {
                                if(trees[j] == destination) //combine seperate trees to be apart of the same tree
                                {
                                        trees[j] = source;
                                }
                        }
                    }

                }
                //else, if the edge would create a cycle, discard the edge

        }


        cout << endl;
        cout << "Kruskal's Total Results: " << total << endl;

}

int main( int argc, char *argv[] )
{
        if (argc != 2)
        {
                cout << "Error: must supply filename " << endl;
                exit(1);
        }

        int start1;
        graph u;

        cout << endl;
        cout << "Undirected Adjacency Matrix:" << endl;

        u.undirectedAdjMatrix( argv[1] );
        u.printMatrix();

        cout << endl;

        //BFS

        cout << "Breadth First Search (BFS) start: ";
        cin >> start1;

        cout << "Breadth First Search results: ";
        u.breadthFirstSearch(start1);
        cout << endl << endl;

        //DFS

        cout << "Depth First Search (DFS) start: ";
        cin >> start1;

        cout << "Depth First Search results: ";
        u.depthFirstSearch(start1);
        cout << endl << endl;


        //BFSST

        cout << "Breadth First Search Spanning Tree (BFSST) start: ";
        cin >> start1;

        cout << "Breadth First Search ST results: ";
        u.breadthFirstSearchST(start1);
        cout << endl << endl;


        //DFSST

        cout << "Depth First Search Spanning Tree (DFSST) start: ";
        cin >> start1;

        cout << "Depth First Search ST results: ";
        u.depthFirstSearchST(start1);
        cout << endl << endl;

        //dijkstra

        cout << "Dijkstra's start: ";
        cin >> start1;

        cout << "Dijkstra results: ";
        u.dijkstra(start1);
        cout << endl;

        //prim

        cout << "Prim's start: ";
        cin >> start1;

        cout << "Prim's MST Results: ";
        u.prim(start1);
        cout << endl;

        //kruskal

        cout << "Kruskal's MST Results: ";
        u.kruskal(argv[1]);
        cout << endl;

        return 0;
}
