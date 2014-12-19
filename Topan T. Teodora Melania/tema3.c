#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *value;
    struct node *next;
} nodeT;
//Here we declare a queue
nodeT *head, *last;

void enqueue(char *value)//Here we perform the addfirst operation on a simple linked list
{

    if(head==NULL)
    {
        head = (nodeT*)malloc(sizeof(nodeT));
        head-> value = value;
    }
    else if(last==NULL)
    {
        last = (nodeT*)malloc(sizeof(nodeT));
        last->value= value;
        head->next = last;
        last->next=NULL;
    }
    else
    {
        nodeT *node = (nodeT*) malloc(sizeof(nodeT));
        node->value= value;

        node->next = NULL;
        last->next = node;
        last = node;
    }
}

void dequeue() //Here we perform the remove of the last element from a linked list
{
    if(head!=NULL)
    {
        head = head->next;
    }
}
nodeT *peek()// Here we return the first element of the list
{
    return head;
}

typedef struct tree
{
    char *value;
    struct tree *left , *right ;
} NodeBT;

NodeBT *createfromlist()
{
    NodeBT * node = (NodeBT*) malloc(sizeof(NodeBT));

    nodeT * nextElement = peek();
    node->value=nextElement->value;//The first element of the tree is the head of the list
    dequeue();//Then we remove it
    if(!(strcmp(nextElement->value,"+")==0) || (strcmp(nextElement->value,"-")==0) || (strcmp(nextElement->value,"*")==0) || (strcmp(nextElement->value,"/")==0))
    {
        node->left=NULL;
        node->right=NULL;
        return node;
    }//If the next element isn`t a number, it becomes a parent node(numbers are leafs)
    else
    {
        node->left = createfromlist();
        node->right= createfromlist();
    }

    return node;
}

void preorder( NodeBT *p, int level )//Preorder printing
{
    int i ;
    if ( p != NULL )
    {
        for ( i = 0; i <= level ; i++ )
            printf ( " " ) ;
        printf ( "%s\n" , p->value ) ;
        preorder( p->left , level + 1 ) ;
        preorder( p->right , level + 1 ) ;
    }
}

NodeBT *createTree(char* ch)
{
    const char tab[1] = " ";
    char * c;
    c = strtok(ch,tab);//We tokinise the string to get rid of the white spaces
    while(c!=NULL)
    {
        printf("%s\n",c);
        enqueue(c);
        c=strtok(NULL,tab);
    }

    return createfromlist();
}

int main()
{
   char* ch= (char*) malloc(sizeof(char)*200);
    gets(ch);
    NodeBT * root = createTree(ch);
   preorder(root, 0);
    return 0;
}
