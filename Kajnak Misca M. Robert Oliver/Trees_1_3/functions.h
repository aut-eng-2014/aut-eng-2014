#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
    void * val;
    char type; ///'c' for char and 'n' for int and 'f' for float
    struct nd* left,*right;
} node;

FILE * f;///I'm as big a fan of global variables as the next person, but this way, I don't need to set is a parameter for the functions

unsigned long long codeGen(int value);
node* createBinaryTree();
void inorder(node * root);
void preorder(node* root);
void postorder(node *root);

typedef struct st
{
    struct st* next,*prev;///this solves problem 6.5 aswell(it says doubly linked) list
    void * val;
    char type;
} lst;

lst *first,*last,*l;///the l is for the TreeFromList
char firstAcces;

void match(const node* from, lst* to);
void lstInit();
void createListFromTree (node * p);

void initCreateTreeFromList();
node* createTreeFromList();

lst* pop(lst* s);
lst * push(lst * s,lst * source);
float calculate();
void printlst();

#endif // FUNCTIONS_H_INCLUDED
