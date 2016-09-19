// Author:     Justin Soderstrom
// Assignment: ETree
// Due Date:   November 6, 2015
// Purpose:    Create a program which reads a postfix and prefix expression and solves them. It then reads a
//             Postfix expression and displays the notation in Prefix, Infix, and Postfix notations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Binary Search Tree structures
typedef struct treeNode link;
typedef struct stackTree _stackTree;

//BST Nodes
struct treeNode
{
 char val;
 link* lchild;
 link* rchild;
 link* next;
};

//BST Stack
struct stackTree
{
   link* top;
   link* bottom;
};

_stackTree stackTreee; //global tree stack

// stack nodes
struct node{
    int val;
    struct node* next;
};

typedef struct node node;

//stack top and bottom structure
struct stack
{
    node* bottom;
    node* top;
};
typedef struct stack _stack;

_stack stack; //global stacks 


void printPostfix(link* t);


//start of stack based code
int top()
{
        int val;
        val = stack.top->val;
        return val;
}

void push(node* newNode)
{
        if(stack.top == NULL && stack.bottom == NULL)
        {
                stack.top = newNode;
                stack.bottom = newNode;
        }
        else
        {
                newNode->next = stack.top;
                stack.top = newNode;
        }
}

void pop()
{
        node* badNode = stack.top;
        stack.top = stack.top->next;
        free(badNode);
}

void getPostfix(char expression[])
{
        printf("Enter a Postfix expression: ");

        fgets(expression, 100, stdin);
}

void getPrefix(char expression[])
{
        printf("Enter a Prefix expression: ");

        fgets(expression, 100, stdin);
}

int calculate(char op, int val1, int val2)
{
      int result;

        if(op == '+')
        {
                result = val1 + val2;
        }
        else if(op == '-')
        {
                result = val2 - val1;
        }
        else if(op == '*')
        {
                result = val1 * val2;
        }
        else if(op == '/')
        {
                result = val2 / val1;
        }

        return result;
}

void readStackPostfix(char expression[])
{
        int i;
        int val1;
        int val2;
        char op;

        node* newNode;

        for(i=0; i<strlen(expression)-1; i++)
        {
                if(expression[i] <= '9' && expression[i] >= '0')
                {
                        newNode = malloc(sizeof(node));

                        newNode->val = expression[i] - '0';

                        newNode->next = NULL;

                        push(newNode);
                }
                else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
                {
                        op = expression[i];

                        val1 = top();

                        pop();

                        val2 = top();

                        pop();

                        newNode = malloc(sizeof(node));
                        newNode->val = calculate(op, val1, val2);
                        push(newNode);
                }
        }
}

void readStackPrefix(char expression[])
{
        int i;
        int val1;
        int val2;
        char op;

        node* newNode;

        for(i=strlen(expression)-1; i>=0; i--)
        {
                if(expression[i] <= '9' && expression[i] >= '0')
                {
                        newNode = malloc(sizeof(node));

                        newNode->val = expression[i] - '0';

                        newNode->next = NULL;

                        push(newNode);
                }
                else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
                {
                        op = expression[i];

                        val1 = top();

                        pop();

                        val2 = top();

                        pop();

                        newNode = malloc(sizeof(node));
                        newNode->val = calculate(op, val1, val2);
                        push(newNode);
                }
        }
}

//start of the translation functions

link* treeTop()
{
        link* tmp;
        tmp = stackTreee.top;
        return tmp;
}

void treePush(link* newNode)
{
        if(stackTreee.top == NULL)
        {
                stackTreee.top = newNode;
                stackTreee.bottom = newNode;
        }
        else
        {
                newNode->next = stackTreee.top;
                stackTreee.top = newNode;
        }

}

void treePop()
{
        link* badNode = stackTreee.top;
        stackTreee.top = stackTreee.top->next;
}

void readBSTPostfix(char expression[])
{
        int i;

        link* newNode;
        link* lchild;
        link* rchild;

        for(i=0; i<=strlen(expression)-1; i++)
        {
              newNode = malloc(sizeof(link));
              newNode->next = NULL;
              newNode->lchild = NULL;
              newNode->rchild = NULL;

              if(expression[i] <= '9' && expression[i] >= '0')
              {
                        newNode->val = expression[i];
                        treePush(newNode);
              }
              else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
              {
                        newNode->val = expression[i];
                        rchild = treeTop();
                        treePop();

                        lchild = treeTop();
                        treePop();

                        newNode->lchild = lchild;
                        newNode->rchild = rchild;
                        treePush(newNode);
              }
        }
}

void printPrefix(link* t)
{
 if ( t == NULL )
   return;

 printf("%2c ", t->val);
 printPrefix(t->lchild);
 printPrefix(t->rchild);
}

void printInfix(link* t)
{
 if ( t == NULL )
   return;
 else
 {

     if(t->lchild != NULL)
     {
        printf("( ");
     }
     printInfix(t->lchild);
     printf("%2c ", t->val);
     printInfix(t->rchild);

     if(t->rchild != NULL)
     {
        printf(" )");
     }
  }
}

void printPostfix(link* t)
{
 if ( t == NULL )
   return;

 printPostfix(t->lchild);
 printPostfix(t->rchild);
 printf("%2c ", t->val);
}

int main()
{
        char expression[100];

        stack.top = NULL;
        stack.bottom = NULL;

        stackTreee.top = NULL;
        stackTreee.bottom = NULL;

// Read in the Postfix expression and evaluate
        getPostfix(expression);
        readStackPostfix(expression);
        printf("Final Result = %d\n", stack.top->val);

        pop(); //remove the Postfix answer from the stack
        stack.top = NULL; //indicate that the stack is empty
        stack.bottom = NULL;

// Read in the Prefix expression and evaluate
        getPrefix(expression);
        readStackPrefix(expression);
        printf("Final Result = %d\n", stack.top->val);

// Read in the Postfix expression and translate to Prefix, Infix, and Postfix 
        getPostfix(expression);
        readBSTPostfix(expression);

        printf("Prefix Expression: ");
        printPrefix(stackTreee.top);
        printf("\n");

        printf("Infix Expression: ");
        printInfix(stackTreee.top);
        printf("\n");

        printf("Postfix Expression: ");
        printPostfix(stackTreee.top);
        printf("\n");

        return 0;
}
