#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left,*right;
    int value;
} NodeT;
NodeT *head,*last;

NodeT* cBT()
{
    NodeT *nod;
    nod=(NodeT*)malloc(sizeof(NodeT));
    int val;
    scanf("%d",&val);
    if(val==0)return NULL;
    else
    {
        nod->value=val;
        nod->left=cBT();
        nod->right=cBT();
    }
    return nod;
}

void inorder(NodeT *q)
{
    if(q!=NULL)
    {
        inorder(q->left);
        printf("%d ", q->value);
        inorder(q->right);
    }
}

void PrevNod(NodeT *root)
{
    static NodeT *prev = NULL;

    if (root != NULL)
    {
        PrevNod(root->left);
        root->left = prev;
        prev=root;
        PrevNod(root->right);
    }
}

NodeT *NextNod(NodeT *root)
{
    NodeT *prev = NULL;

    while (root && root->right != NULL)
        root = root->right;

    while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
    return (root);
}

NodeT *BTreeToDobLinList(NodeT *root)
{
    PrevNod(root);

    return NextNod(root);
}


void printlist(NodeT *root)
{
    last=(NodeT*)malloc(sizeof(NodeT));
    while (root != NULL)
    {
        printf("%d ", root->value);
        if(root->right==NULL)
            last=root;
        root = root->right;
    }
}
void Remove(NodeT *node)
{
    if(node==head)
    {
        if(node->right == NULL)
        {
            head=NULL;

            last=NULL;
        }
        else
        {
            if(node->right == last)
            {
                head=last;
            }
            else
            {
                head = node->right;
                head->left = NULL;
            }
        }
    }
    else if(node == last)
    {

        if(node->left == NULL)
        {
            free(node);
            last=NULL;

            head=NULL;
        }
        else
        {
            if(node->left == head)
            {
                head-> right = NULL;
                last = NULL;
            }
            else
            {
                last = node->left;
                last->right = NULL;
            }
        }
    }

    else
    {
        node->left->right = node->right;
        node->right->left = node->left;
    }
    free(node);
}
NodeT *DobLinListToBTree(NodeT *nodlista)
{
    NodeT *nod;
    if(nodlista == NULL) return NULL;
    char val = nodlista->value;

    if (val==0)
    {
        Remove(nodlista);
        return NULL;
    }
    else
    {
        nod = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        nod->value = val;
        nod->left = DobLinListToBTree(nodlista->right) ;
        nod->right = DobLinListToBTree(nodlista->right) ;

        Remove(nodlista);
    }
    return nod;
}

int main()
{

    NodeT *root;
    root=(NodeT*)malloc(sizeof(NodeT));
    root=cBT();

    printf("\nTree:\n");
    inorder(root);

    head = BTreeToDobLinList(root);
    NodeT *head1=head;
    printf("\nDLL:\n");
    printlist(head);
    root = DobLinListToBTree(head1);
    printf("\nTree:\n");
    inorder(root);
    return 0;
}
