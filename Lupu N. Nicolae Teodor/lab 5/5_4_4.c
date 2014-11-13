#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *left, *right;
} NodeT;

NodeT *root;

void Insert(int key)
{
    NodeT *p,*q;
    p=(NodeT*)malloc(sizeof(NodeT));
    p->val=key;
    p->left=p->right=NULL;
    if(root == NULL)
    {
        root=p;
        return;
    }
    q=root;
    for(;;)
    {
        if(key < q->val)
        {
            if(q->left == NULL)
            {
                q->left=p;
                return;
            }
            q=q->left;
        }
        else
        {
            if(key > q->val)
            {
                if(q->right == NULL)
                {
                    q->right=p;
                    return;
                }
                q=q->right;
            }
            else
            {
                free(p);
                return;
            }
        }
    }
}

int Depth(NodeT* n)
{
    if (n==NULL)
        return 0;
    else
    {
        int DLeft = Depth(n->left);
        int DRight = Depth(n->right);

        if (DLeft > DRight)
            return(DLeft+1);
        else return(DRight+1);
    }
}


int Level(NodeT *node, int val, int level)
{
    if (node == NULL)
        return 0;
    if (node->val == val)
        return level;
    int downlevel = Level(node->left, val, level+1);
    if (downlevel != 0)
        return downlevel;
    downlevel = Level(node->right, val, level+1);
    return downlevel;
}

int Count(NodeT* node,int maxlevel)
{
    int lev=Level(node, node->val, 1);
    if(lev==maxlevel)
    {
        if(node == NULL)
            return 0;
        if(node->left == NULL && node->right==NULL)
            return 1;
        else
            return Count(node->left, maxlevel)+ Count(node->right, maxlevel);
    }
    return maxlevel;
}



NodeT *delNode(int key )
{
    NodeT *p;
    NodeT *Parent;
    NodeT *R;
    NodeT *RParent;
    int order ;
    if ( root == NULL )
        return NULL;
    p = root ;
    Parent = NULL;
    while ( p != NULL&& p->val != key )
    {
        if ( key < p->val )
        {
            Parent = p;
            p = p->left;
            order = 0;
        }
        else
        {
            Parent = p;
            p = p->right ;
            order = 1;
        }
    }
    if ( p == NULL )
    {
        printf( " \nNo node of key value=%d\n" , key ) ;
        return root ;
    }
    if ( p->left == NULL )
        R = p->right ;
    else if ( p->right == NULL)
        R = p->left ;
    else
    {
        RParent = p;
        R = p->right ;
        while ( R->left != NULL )
        {
            RParent = R;
            R = R->left ;
        }
        if ( RParent != p )
        {
            RParent->left = R->right ;
            R->right = p->right ;
        }
        R->left = p->left ;
    }
    free ( p ) ;
    printf ( " \n Deletion of node %d completed. \n" , key) ;
    if ( Parent == NULL )
        return R;
    else
    {
        if ( order == 0 )
            Parent->left = R;
        else
            Parent->right = R;
        return root ;
    }

}

NodeT *find ( NodeT * root, int key )
{ printf("I. Insert D. Delete F. Find S. Show Q. Quit\n");
    NodeT *p;
    if ( root == NULL )
        return NULL;
    for ( p = root ; p != NULL; )
    {
        if ( key == p->val )
            return p;
        else if ( key < p->val )
            p = p->left ;
        else p = p->right ;
    }
    return NULL;
}

void preorder( NodeT *p, int level )
{
    int i ;
    if ( p != NULL )
    {
        for ( i = 0; i <= level ; i++ )
            printf ( " " ) ;
        printf ( "%2.2d\n" , p->val ) ;
        preorder( p->left , level + 1 ) ;
        preorder( p->right , level + 1 ) ;
    }
}

int main()
{
    char key;
    int n;
    NodeT *q;
    printf("I. Insert D. Delete F. Find S. Show Q. Quit\n");
    while (key!='q')
    {
        scanf("%c", &key);
        switch (key)
        {
        case 'i':
        case 'I':
            scanf("%d%*c", &n);
            Insert(n);
            break;
        case 'd':
        case'D':
            scanf("%d%*c", &n);
            root = delNode (n);
            preorder(root,1 );
            break;
        case 'f':
        case 'F':
            scanf("%d%*c", &n);
            q = find ( root , n ) ;
            if ( q != NULL )
                printf ( "Node found. \n" );
            else
                printf ( "Node NOT found. \n" );
            break;
        case 's':
        case 'S':
            scanf("%*c");
            preorder(root,1 );
            break;
        case 'q':
        case 'Q':
            return 0;
            break;
        default:
            scanf("%*c");
            printf("The key you pressed is not one of the correct commands.\n");
            break;
        }
        printf("\nI. Insert D. Delete F. Find S. Show Q. Quit \n");
    }
    return 0;
}
