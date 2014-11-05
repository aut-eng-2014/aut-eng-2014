#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
}NodeT;


NodeT* insert_node(NodeT* node, int value)
{
    if (node == NULL)
    {
        NodeT *temp=(NodeT*)malloc(sizeof(NodeT));
        temp->key=value;
        temp->left=temp->right=NULL;
        return temp;
    }

    if (value<node->key)
        node->left=insert_node(node->left, value);

    else if (value>node->key)
        node->right=insert_node(node->right, value);

    return node;
}

void in_order(NodeT *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        printf("%d", root->key);
        in_order(root->right);
    }
}



NodeT* delete_node(NodeT* root, int key)
{
    if (root==NULL) return root;

    if (key<root->key)
        root->left=delete_node(root->left,key);
    else if (key>root->key)
        root->right=delete_node(root->right,key);

    else
    {
        if (root->left==NULL)
        {
            NodeT *temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
           NodeT *temp=root->left;
            free(root);
            return temp;
        }

        NodeT* temp=root->right;

        while (temp->left!=NULL)
            temp = temp->left;

        root->key=temp->key;
        root->right=delete_node(root->right,temp->key);
    }
    return root;
}

NodeT* search_node(NodeT* root, int key)
{
    if (root->key==key)
        return root;

    if (root->key<key)
        return search_node(root->right, key);
    return search_node(root->left, key);
}


int main()
{
    char c,d;

    do
    {
        printf("\nPlease select one of the following options: ");
        printf("\n1.Press I to insert.\n");
        printf("\n2.Press F to find.\n");
        printf("\n3.Press D to delete.\n");
        printf("\n4.Press S to show.\n");
        printf("\n5.Press Q to quit.\n");
        c=getche();
        d=toupper(putch(c));
          NodeT *root=NULL;
           int n;

        switch(d)
        {
        case 'I':
            printf("\n Enter the node you want to insert:");
            scanf("%d",&n);
            insert_node(root,n);
            break;
        case 'D':
            printf("\n Enter the node you want to delete:");
            scanf("%d",&n);
            delete_node(root,n);
            break;
        case 'F':
            printf("\n Enter the node you want to find:");
            scanf("%d",&n);
            search_node(root,n);
            break;
        case 'S':
            in_order(root);
            break;

        case 'Q':
            exit(1);
        default:
            printf("\n Error! Select one command from the menu!");
        }
    }
    while(c!='q'||c!='Q');

    return 0;
}
