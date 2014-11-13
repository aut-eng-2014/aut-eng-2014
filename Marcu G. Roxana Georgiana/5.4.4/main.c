#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left , *right ;
} NodeT;

NodeT *root ;

void NodeInsert(int key)
{
    NodeT *p,*q;
    p=(NodeT*)malloc(sizeof(NodeT));
    p->value=key;
    p->left=p->right=NULL;
    if(root == NULL)
    {
        root=p;
        return;
    }
    q=root;
    for(;;)
    {
        if(key < q->value)
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
            if(key > q->value)
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

void FindNode(int key)
{
    NodeT *p;
    p=root;
    int ok=0;
    while(p!=NULL)
    {
        if(p->value == key)
        {
            printf("The value %d is in the tree\n",p->value);
            ok=1;
            break;
        }
        else if(p->value > key)
            p=p->left;
        else
            p=p->right;
    }
    if(ok == 0)
        printf("The value is not in the tree\n");
}

NodeT *DeleteNode(int key)
{
    NodeT *p;
    NodeT *pParent;
    NodeT *pReplace;
    NodeT *pReplParent;
    int direction;

    if(root == NULL) return NULL;

    p=root;
    pParent=NULL;

    while(p != NULL && p->value != key)
    {
        if(key < p->value)
        {
            pParent=p;
            p=p->left;
            direction=1;
        }
        else
        {
            pParent=p;
            p=p->right;
            direction=2;
        }
    }
    if(p==NULL)
    {
        printf("The number %d wasn't found in the tree",key);
        return root;
    }

    if(p->left == NULL)
        pReplace=p->right;
    else if(p->right == NULL)
        pReplace=p->left;
    else
    {
        pReplParent=p;
        pReplace=p->right;
        while(pReplace->left != NULL)
        {
            pReplParent=pReplace;
            pReplace=pReplace->left;
        }
        if(pReplParent != p)
        {
            pReplParent->left=pReplace->right;
            pReplace->right=p->right;
        }
        pReplace->left=p->left;
    }
    free(p);

    printf ("The node %d was deleted\n",key);

    if(pParent == NULL)
        return pReplace;
    else
    {
        if(direction == 1)
            pParent->left=pReplace;
        else
            pParent->right=pReplace;
        return root;
    }
}

void preorder(NodeT* root)
{
    if(root != NULL)
    {
        printf("%d ",root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

int DepthTree(NodeT* node)
{
    if(node == NULL)
        return 0;
    int nLeft = DepthTree(node->left);
    int nRight = DepthTree(node->right);
    if(nLeft > nRight)
        return (nLeft+1);
    else
        return (nRight+1);
}

int NumberOfLeaves(NodeT *node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return NumberOfLeaves(node->left) + NumberOfLeaves(node->right);
}

int main()
{
    char option;
    int nodevalue,depth,NrOfLeaves;

    do
    {
        printf("\nI. Insert D. Delete F. Find S. Show Q. Quit\n");
        scanf("%c",&option);
        switch(option)
        {
        case 'i':
        case 'I':
            scanf("%*c");
            scanf("%d",&nodevalue);
            NodeInsert(nodevalue);
            break;
        case 'd':
        case 'D':
            scanf("%*c");
            scanf("%d",&nodevalue);
            root=DeleteNode(nodevalue);
            break;
        case 'f':
        case 'F':
            scanf("%*c");
            scanf("%d",&nodevalue);
            FindNode(nodevalue);
            break;
        case 's':
        case 'S':
            preorder(root);
            printf("\n");
            break;
        case 'q':
            return 0;
            break;
        default:
            printf("Type a valid letter\n");
            break;
        }
        depth=DepthTree(root);
        NrOfLeaves=NumberOfLeaves(root);
        scanf("%*c");
    }
    while( (option!='Q' || option!='q') && depth<=5 && NrOfLeaves<=32 );

    return 0;
}
