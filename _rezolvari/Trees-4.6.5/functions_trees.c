#include "functions.h"

NodeT *createBinTree()
{
    NodeT *p;
    char *content = (char*)malloc(sizeof(char)*MAX_SIZE_OF_CONTENT);

    scanf( "%s" ,content );
    if ( strcmp(content,"*")==0 )
        return NULL;
    else
    {
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->content = content;
        p->left = createBinTree() ;
        p->right = createBinTree() ;
    }
    return p;
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
