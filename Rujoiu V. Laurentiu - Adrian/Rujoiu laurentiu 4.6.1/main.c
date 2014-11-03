#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *value;
    struct node *left, *right;
}Node;

typedef struct que
{
    char *data;
    struct que *next;
}Que;

Que *head, *last;

void enqueue(char *data)
{
    if(head==NULL)
    {
        head = (Que*)malloc(sizeof(Que));
        head-> data = data;
    }
    else if(last==NULL)
    {
        last = (Que*)malloc(sizeof(Que));
        last->data= data;
        head->next = last;
        last->next=NULL;
    }
    else
    {
        Que *node = (Que*) malloc(sizeof(Que));
        node->data= data;
        node->next = NULL;
        last->next = node;
        last = node;
    }
}

int sign(char *c)
{
    return ((strcmp(c,"+")==0) || (strcmp(c,"-")==0) || (strcmp(c,"*")==0) || (strcmp(c,"/")==0));
}

Node *CreateTree()
{
    Node *p = (Node*)malloc(sizeof(Node));
    Que *elem = head;
    p->value = elem->data;
    if(head != NULL)
        head = head->next;

    if(!sign(elem->data))
    {
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    else
    {
        p->left = CreateTree();
        p->right = CreateTree();
    }
    return p;
}

Node *Create(char *sentence)
{
    char *c;
    c = strtok(sentence , " ");
    while(c != NULL)
    {
        //printf("%s ", c);
        enqueue(c);
        c = strtok(NULL, " ");
    }
    return CreateTree();
}

void postorder(Node *p)
{
    if(p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%s ", p->value);
    }
}

int main()
{
    char *sentence = (char*) malloc(sizeof(char)*400);
    gets(sentence);
    Node * root = Create(sentence);

    postorder(root);

    return 0;
}
