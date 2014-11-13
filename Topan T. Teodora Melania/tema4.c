#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct node
{
    int key;
    struct node *left, *right;
} nodeT;

nodeT* insertNode(nodeT* node, int value)
{
    if (node == NULL)//if the tree is empty we insert a new node
    {
        nodeT *temp=(nodeT *)malloc(sizeof(nodeT));
        temp->key = value;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (value < node->key)//if the value is smaller then the current node we insert it in the left subtree
        node->left  = insertNode(node->left, value);

    else if (value > node->key)
        node->right = insertNode(node->right, value);

    return node;
}

void inorder(nodeT *root)//inorder printing
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

nodeT* searchNode(nodeT* root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return searchNode(root->right, key);
    return searchNode(root->left, key);

}
nodeT* deleteNode(nodeT* root, int key)
{
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            nodeT *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            nodeT *temp = root->left;
            free(root);
            return temp;
        }
        nodeT* temp =root->right;

        while (temp->left != NULL)
            temp = temp->left;
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()
{
    int n;
    do
    {
        printf("\t\nHello!Welcome to the command menu!\n    Please chose one of the following options:\n");
        printf("\n1.Press 1 for delete\n");
        printf("\n2.Press 2 for find\n");
        printf("\n3.Press 3 to show\n");
        printf("\n4.Press 4 to insert\n");
        printf("\n5.Press 5 to quit\n");
        scanf("%d", &n);
        nodeT *root=NULL;
        int n;

        switch(n)
        {
        case 1:
            printf("Please input the node you want to delete:");
            scanf("%d",&n);
            deleteNode(root,n);
            break;
        case 2:
            printf("Please input the node you want to find:");
            scanf("%d",&n);
            searchNode(root,n);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            printf("Please input the node you want to insert:");
            scanf("%d",&n);
            insertNode(root,n);
            break;
        case 5:
            exit(1);
        default:
            printf("\nIncorrect!!!!Please chose one of the commands from the menu!\n\n");
        }
    }
    while(n!=5);

    return 0;
}
