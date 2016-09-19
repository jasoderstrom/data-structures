/*  Author:      Justin Soderstrom
    Class:       CSC-300
    Date:        November 13, 2015
    Assignment:  Create a undirected and directed adjacency matrix and list based on the an input file on the command line.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class graph
{
        public:
                graph();
                void undirectedAdjMatrix(char *fname);
                void directedAdjMatrix(char *fname);
                void undirectedAdjList(char *fname);
                void directedAdjList(char *fname);
                void printMatrix();
                void printList();
        private:
                int A[100][100];
                int N;                  //N x N matrix
                struct node 
                {
                        int data;
                        struct node *next;
                };
                struct node *list[100];

};

graph::graph()
{
        int r, c;
        for(r = 0; r < 100; r++)
        {
                list[r] = NULL;
                for (c = 0; c < 100; c++)
                        A[r][c] = 0;
        }
}

void graph::directedAdjMatrix( char *fname )  //same thing as char fname[]
{
        int edges, r, c, i; //r = row

        ifstream fin;

        fin.open( fname );

        fin >> N;
        fin >> edges;
        for (i = 0; i < edges; i++)
        {
                fin >> r >> c;
                A[r][c] = 1;
        }

}

void graph::undirectedAdjMatrix( char *fname )
{
        int edges, r, c, i; //r = row

        ifstream fin;

        fin.open( fname );

        fin >> N;
        fin >> edges;
        for (i = 0; i < edges; i++)
        {
                fin >> r >> c;
                A[r][c] = 1;
                A[c][r] = 1;
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

void graph::directedAdjList( char *fname )
{
        int edges, i, r, c;

        struct node* head;
        struct node* newNode;
        struct node* walker;

        ifstream fin;

        fin.open( fname );

        fin >> N;
        fin >> edges;

        for(i = 1; i <= edges; i++)
        {
                newNode = new node();
                fin >> r >> c;
                newNode->data = c;
                newNode->next = NULL;

                if(list[r] == NULL) //if there is nothing existing in the adjacency list
                {
                        head = newNode;
                        list[r] = head;
                }
                else
                {
                        walker = list[r]; //walker equals the head of the linked list

                        while( walker->next != NULL)
                        {
                                walker = walker->next;
                        }

                        walker->next = newNode;
                }
        }
}

void graph::undirectedAdjList(char *fname)
{
        int edges, i, r, c;

        struct node* head;
        struct node* newNode;
        struct node* newNode2;
        struct node* walker;

        ifstream fin;

        fin.open( fname );

        fin >> N;
        fin >> edges;

        for(i = 1; i <= edges; i++)
        {
                newNode = new node();
                fin >> r >> c;
                newNode->data = c;
                newNode->next = NULL;

                if(list[r] == NULL) //if there is nothing existing in the adjacency list
                {
                        head = newNode;
                        list[r] = head;
                }
                else
                {
                        walker = list[r]; //walker equals the head of the linked list

                        while( walker->next != NULL)
                        {
                                walker = walker->next;
                        }

                        walker->next = newNode;
                }

                newNode2 = new node();  //flipped the r and c since the graph is undirected
                newNode2->data = r;
                newNode2->next = NULL;

                if(list[c] == NULL) //if there is nothing existing in the adjacency list
                {
                        head = newNode2;
                        list[c] = head;
                }
                else
                {
                        walker = list[c]; //walker equals the head of the linked list

                        while( walker->next != NULL)
                        {
                                walker = walker->next;
                        }

                        walker->next = newNode2;
                }

        }

}

void graph::printList()
{
        int i;
        struct node* walker;

        for(i = 1; i <= N; i++)
        {
                if(list[i] != NULL)
                {
                        cout << i << ": ";
                        walker = list[i];
                        while( walker != NULL )
                        {
                                cout << walker->data << " ";
                                walker = walker->next;
                        }
                        cout << endl;
                }
        } 
}

int main( int argc, char *argv[] )
{
        if (argc != 2)
        {
                cout << "Error: must supply filename " << endl;
                exit(1);
        }

//      d = directed graphs
//      u = undirected graphs

        graph d;
        graph u;

        cout << "Undirected Adjacency Matrix:" << endl;

        u.undirectedAdjMatrix( argv[1] );
        u.printMatrix();

        cout << "Undirected Adjacency List:" << endl;
        u.undirectedAdjList( argv[1] );
        u.printList();

        cout << "Directed Adjacency Matrix:" << endl;

        d.directedAdjMatrix( argv[1] );
        d.printMatrix();

        cout << "Directed Adjacency List:" << endl;
        d.directedAdjList( argv[1] );
        d.printList();

        return 0;
}
