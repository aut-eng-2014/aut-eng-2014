#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} NodeT;

NodeT *root;

//the functions maxDepth, getLevel, getLeafCount are for implementing
//the request: "Allow a maximum depth of 5 (note that root is at depth 0),
//and a maximum number of nodes on the last level of 32."

int maxDepth(NodeT* n)/*compute the depth of a tree*/
{
    if (n==NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(n->left);
        int rDepth = maxDepth(n->right);
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth+1);
        else return(rDepth+1);
    }
}

/* Returns level of a given data value */
int getLevel(NodeT *node, int data, int level)
{
    if (node == NULL)
        return 0;
    if (node->data == data)
        return level;
    int downlevel = getLevel(node->left, data, level+1);
    if (downlevel != 0)
        return downlevel;
    /*else*/
    downlevel = getLevel(node->right, data, level+1);
    return downlevel;
}

int getLeafCount(NodeT* node,int maxlevel)//counts the leafs from the last level
{
    int lev=getLevel(node, node->data, 1);//I get the level of the current node
    if(lev==maxlevel)//if the node is on the last level, I count it
    {
        if(node == NULL)
            return 0;
        if(node->left == NULL && node->right==NULL)
            return 1;
        else
            return getLeafCount(node->left, maxlevel)+ getLeafCount(node->right, maxlevel);
    }
    return maxlevel;
}

void insert(int n)
{
    NodeT *p, *q;
    //from here I start checking the conditions imposed by the problem
    int maxlevel = maxDepth(root);
    if(maxlevel>5)//I check if I reached the level 6
    {
        printf("\nYou can't have a depth higher than 5. :( \n");
        return;
    }
    int leafs=getLeafCount(root, maxlevel);
    if (leafs>31)//I check if there are 32 leaves on the last level
    {
        printf("\nYou can't have more than 32 leaves on the last level. :( \n");
        return;
    }

    p=(NodeT*)malloc( sizeof(NodeT) );
    p->data=n;
    p->left=NULL;
    p->right=NULL;
    if (root==NULL)
    {
        root=p;
        return;
    }
    q=root;
    for(;;)
    {
        if (n<q->data)//follow on left subtree
        {
            if(q->left== NULL)
            {
                q->left=p;
                return;
            }

            /*else*/
            q=q->right;
        }
        else if (n> q->data) //follow on right subtree
        {
            if (q->right== NULL)
            {
                q->right=p;
                return;
            }
            /*else*/
            q=q->right;
        }
        else
        {
            printf("Key already present.");
            free(p);
            return;
        }
    }
}


NodeT *delNode(int key )
{
    NodeT *p; /* points to node to delete */
    NodeT *pParent; /* points to parent of p */
    NodeT *pRepl; /* points to node that will replace p */
    NodeT *pReplParent; /* points to parent of node that will replace p */
    int direction ; /* LEFT=0, RIGHT=1 */
    if ( root == NULL )
        return NULL; /* empty tree */
    p = root ;
    pParent = NULL;
    while ( p != NULL&& p->data != key )
    {
        if ( key < p->data )
        {
            /* search left branch */
            pParent = p;
            p = p->left;
            direction = 0;
        }
        else
        {
            /* search right branch */
            pParent = p;
            p = p->right ;
            direction = 1;
        }
    }
    if ( p == NULL )
    {
        printf( " \nNo node of key value=%d\n" , key ) ;
        return root ;
    }
    /* node of key p found */
    if ( p->left == NULL )
        pRepl = p->right ; /* no left child */
    else if ( p->right == NULL)
        pRepl = p->left ; /* no right child */
    else
    {
        /* both children present */
        pReplParent = p;
        pRepl = p->right ; /* search right subtree */
        while ( pRepl->left != NULL )
        {
            pReplParent = pRepl;
            pRepl = pRepl->left ;
        }
        if ( pReplParent != p )
        {
            pReplParent->left = pRepl->right ;
            pRepl->right = p->right ;
        }
        pRepl->left = p->left ;
    }
    free ( p ) ;
    printf ( " \n Deletion of node %d completed. \n" , key) ;
    if ( pParent == NULL )
        return pRepl; /* original root was deleted */
    else
    {
        if ( direction == 0 )
            pParent->left = pRepl;
        else
            pParent->right = pRepl;
        return root ;
    }

}

NodeT *find ( NodeT * root, int key )
{
    NodeT *p;
    if ( root == NULL )
        return NULL; /* empty tree */
    for ( p = root ; p != NULL; )
    {
        if ( key == p->data )
            return p;
        else if ( key < p->data )
            p = p->left ;
        else p = p->right ;
    }
    return NULL; /* not found */
}
/* invoke with : q = find ( root , key ) ; */

void preorder( NodeT *p, int level )
/*
* p = current node;
* level = used for nice printing
*/
{
    int i ;
    if ( p != NULL )
    {
        for ( i = 0; i <= level ; i++ )
            printf ( " " ) ; /* for nice listing */
        printf ( "%2.2d\n" , p->data ) ;
        preorder( p->left , level + 1 ) ;
        preorder( p->right , level + 1 ) ;
    }
}

int main()
{
    char ch;
    int n;
    NodeT *q;
    printf("i. Insert d. Delete f. Find s. Show q. Quit\n");
    while (ch!='q')
    {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'i':
        case 'I':
            printf("\nEnter the key you want to insert.\n");
            scanf("%d%*c", &n);
            insert(n);
            break;
        case 'd':
        case'D':
            printf("\nEnter the key you want to delete.\n");
            scanf("%d%*c", &n);
            root = delNode (n);
            preorder(root,1 );
            break;
        case 'f':
        case 'F':
            printf("\nEnter the key you want to find.\n");
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
            printf("Press a valid key (i, d, f, s, q).\n");
            break;
        }
        printf("\ni. Insert d. Delete f. Find s. Show q. Quit\n");
    }

    return 0;
}
