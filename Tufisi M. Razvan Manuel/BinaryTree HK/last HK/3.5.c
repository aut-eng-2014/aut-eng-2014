#include <stdio.h>
#include <stdlib.h>

//we create here the tree
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} nodeT;

nodeT* btree2listutil(nodeT* root)
{
    // base case
    if (root==NULL)
        return root;
    // convert the left subtree and link to root
    if (root->left!=NULL)
    {
        nodeT* left = btree2listutil(root->left);
        // find inorder predecessor... after this loop, left will point to the inorder predecessor
        for (; left->right!=NULL; left=left->right);
        // make root as next of the predecessor
        left->right=root;
        // make predecssor as previous of root
        root->left =left;
    }
    // convert the right subtree and link to root
    if (root->right!=NULL)
    {
        nodeT* right = btree2listutil(root->right);
        // find inorder successor...after this loop, right will point to the inorder successor
        for (; right->left!=NULL; right=right->left);
        // make root as previous of successor
        right->left = root;
        // make successor as next of root
        root->right = right;
    }
    return root;
}

nodeT* btree2list(nodeT *root)
{
    if (root == NULL)
        return root;
    // convert to DLL using btree2listutil()
    root = btree2listutil(root);
    // btree2listutil() returns root node of the converted DLL... we need pointer to the leftmost node which is head
    while (root->left != NULL)
        root = root->left;
    return (root);
}

nodeT* newNode(int data)
{
    nodeT* newnode=(nodeT*)malloc(sizeof(nodeT));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return(newnode);
}

void printlist(nodeT *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->right;
    }
}

int main()
{

    nodeT *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left=newNode(11);
    root->left->right=newNode(9);
    root->right->left=newNode(3);

    nodeT *head = btree2list(root);
    printlist(head);

    return 0;
}
