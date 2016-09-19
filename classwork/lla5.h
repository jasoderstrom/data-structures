/*Justin Soderstrom
  CSC-300
  September 9, 2015
*/

#include <stdio.h>
#include <stdlib.h>

struct lnode
{
 int data;
 struct lnode *next;
};


struct lheader
{
 struct lnode *start;
 int len;
};


struct lheader *makelist( );
struct lnode *makenode( int val );
void insertFront( struct lheader *L, int val );
void insertBack( struct lheader *L, int val );
int isInList( struct lheader *L, int val );
struct lnode *findNode( struct lheader *L, int val );
void insertAfter( struct lheader *L, int val, struct lnode *p );
void insertBefore( struct lheader *L, int val, struct lnode *p );
void printlist( struct lnode *front );
void printer( struct lheader *alist );
int isDups( struct lheader *L);

