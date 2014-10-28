#include "functions.h"

NodeT *createTreeFromQueue();

/**
* Constructs the queue from the prefix expression and calls the 'createTreeFromQueue' after this is done.
*/
NodeT *createTreeFromPrefixExpression(char* prefixExpression)
{
    //! 'space' = split element
    const char splitter[1] = " ";
    char * token;

    token = strtok(prefixExpression,splitter);

    //! each token = 1x'word' (ex: "this is a sentence"-> 4 tokens: 'this' + 'is' + 'a' + 'sentence')
    while(token!=NULL)
    {
        printf("%s\n",token);
        enqueue(token);
        token=strtok(NULL,splitter);
    }

    return createTreeFromQueue();
}

/**
* Creates a tree from a queue
*/
NodeT *createTreeFromQueue()
{
    NodeT * node = (NodeT*) malloc(sizeof(NodeT));

    //! get the next element of the queue by 'peeking'
    QueueN * nextElement = peek();
    node->content=nextElement->content;

    //! remove it as we don't need it anymore
    dequeue();

    //! all the leaves are NUMBERS! so if we don't have an operation (i.e, we found a number)
    //! we return it as a node which will end up as a leaf node
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

