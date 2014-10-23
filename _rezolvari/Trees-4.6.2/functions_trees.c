#include "functions.h"

NodeT *createTreeFromQueue();

NodeT *createTreeFromPrefixExpression(char* prefixExpression)
{
    const char splitter[1] = " ";
    char * token;

    token = strtok(prefixExpression,splitter);

    while(token!=NULL)
    {
        printf("%s\n",token);
        enqueue(token);
        token=strtok(NULL,splitter);
    }

    return createTreeFromQueue();
}

NodeT *createTreeFromQueue()
{
    NodeT * node = (NodeT*) malloc(sizeof(NodeT));

    QueueN * nextElement = peek();
    node->content=nextElement->content;

    dequeue();
    if(!isOperation(nextElement->content))
    {
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    else
    {
        node->left = createTreeFromQueue();
        node->right= createTreeFromQueue();
    }

    return node;
}

int isOperation(char *o)
{
    return ((strcmp(o,"+")==0) || (strcmp(o,"-")==0) || (strcmp(o,"*")==0) || (strcmp(o,"/")==0));
}

void preorder( NodeT *p, int level )
{
    int i ;
    if ( p != NULL )
    {
        for ( i = 0; i <= level ; i++ )
            printf ( " " ) ; /* for nice listing */
        printf ( "%s\n" , p->content ) ;
        preorder( p->left , level + 1 ) ;
        preorder( p->right , level + 1 ) ;
    }
}

void inorder( NodeT *p, int level )
{
    int i ;
    if ( p != NULL )
    {
        inorder( p->left , level + 1 ) ;
        for ( i = 0; i <= level ; i++ )
            printf ( " " ) ; /* for nice listing */
        printf ( "%s\n" , p->content ) ;
        inorder( p->right , level + 1 ) ;
    }
}

void postorder( NodeT *p, int level )
{
    int i ;
    if ( p != NULL )
    {
        postorder( p->left , level + 1 ) ;
        postorder( p->right , level + 1 ) ;
        for ( i = 0; i <= level ; i++ )
            printf ( " " ) ; /* for nice listing */
        printf ( "%s\n" , p->content ) ;
    }
}

