#include <stdio.h>
#include <stdlib.h>

typedef struct BinSearchTree
{
    int key;
    struct BinSearchTree *left;
    struct BinSearchTree *right;
} NodeT;

NodeT *root ;

NodeT * Insert_node(NodeT* root ,int key)
{
    if(root==NULL)
    {
        NodeT *temp;
        temp = (NodeT *)malloc(sizeof(NodeT));
        temp -> key = key;
        temp -> left = temp -> right = NULL;
        return temp;
    }

    if(key >(root->key))
    {
        root->right = Insert_node(root->right,key);
    }
    else if(key < (root->key))
    {
        root->left = Insert_node(root->left,key);
    }
    return root;

}
NodeT* SearchMin(NodeT *root)
{
    if(root==NULL)
    {

        return NULL;
    }
    if(root->left)
        return SearchMin(root->left);
    else
        return root;

}

NodeT* SearchMax(NodeT *root)
{
    if(root==NULL)
    {

        return NULL;
    }
    if(root->right)
        SearchMax(root->right);
    else
        return root;
}

NodeT * Delete_node(NodeT *root, int key)
{
    NodeT *temp;
    if(root==NULL)
    {
        printf("Element Not Found\n");
    }
    else if(key < root->key)
    {
        root->left = Delete_node(root->left, key);
    }
    else if(key > root->key)
    {
        root->right = Delete_node(root->right, key);
    }
    else
    {

        if(root->right && root->left)
        {

            temp = SearchMin(root->right);
            root -> key = temp->key;
            root -> right = Delete_node(root->right,temp->key);
        }
        else
        {

            temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            free(temp);
        }
    }
    return root;

}



NodeT * Find_node(NodeT *root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key > root->key)
    {

        return Find_node(root->right,key);
    }
    else if(key < root->key)
    {

        return Find_node(root->left,key);
    }
    else
    {

        return root;
    }
}


void Preorder(NodeT *node)
{
    if(node!=NULL)
    {

        printf("%d ",node->key);
        Preorder(node->left);
        Preorder(node->right);
    }
}
void Postorder(NodeT *node)
{
    if(node!=NULL)
    {

        Postorder(node->left);
        Postorder(node->right);
        printf("%d ",node->key);
    }
}

int main()
{
    NodeT *root = NULL;
    root = Insert_node(root, 20);
    root = Insert_node(root, 10);
    root = Insert_node(root, 11);
    root = Insert_node(root, 1);
    root = Insert_node(root, 23);
    root = Insert_node(root, 26);
    printf("\n");
    Preorder(root);
    printf("\n");
    root = Delete_node(root,12);
    printf("\n");
    Preorder(root);
    root = Delete_node(root,20);
    printf("\n");
    Preorder(root);
    root=Delete_node(root,10);
    printf("\n");
    Preorder(root);
    NodeT * temp;
    temp = Find_node(root,11);
    if(temp==NULL)
    {
        printf("Element 11 not found.\n");
    }
    else
    {
        printf("Element 11 found.\n");
    }
    printf("Exit.\n");
    return 0;
}
