#include <stdio.h>
#include <stdlib.h>

typedef struct BinSearchTree
{
    int key;
    struct BinSearchTree *left;
    struct BinSearchTree *right;
} NodeT;

NodeT *root ;

NodeT * Insert(NodeT* root ,int key)
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
        root->right = Insert(root->right,key);
    }
    else if(key < (root->key))
    {
        root->left = Insert(root->left,key);
    }
    return root;

}
NodeT* FindMin(NodeT *node)
{
    if(node==NULL)
    {

        return NULL;
    }
    if(node->left) /* Go to the left sub tree to find the min element */
        return FindMin(node->left);
    else
        return node;

}

NodeT* FindMax(NodeT *node)
{
    if(node==NULL)
    {

        return NULL;
    }
    if(node->right)
        FindMax(node->right);
    else
        return node;
}
NodeT * Delete(NodeT *node, int key)
{
    NodeT *temp;
    if(node==NULL)
    {
        printf("Element Not Found\n");
    }
    else if(key < node->key)
    {
        node->left = Delete(node->left, key);
    }
    else if(key > node->key)
    {
        node->right = Delete(node->right, key);
    }
    else
    {
        /* delete this node and replace with either minimum element
           in the right sub tree or maximum element in the left subtree */
        if(node->right && node->left)
        {
            /* replace with minimum element in the right sub tree */
            temp = FindMin(node->right);
            node -> key = temp->key;
            /* As we replaced it with some other node, we have to delete that node */
            node -> right = Delete(node->right,temp->key);
        }
        else
        {

            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp);
        }
    }
    return node;

}



NodeT * Find(NodeT *node, int key)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(key > node->key)
    {
        /* Search in the right sub tree. */
        return Find(node->right,key);
    }
    else if(key < node->key)
    {
        /* Search in the left sub tree. */
        return Find(node->left,key);
    }
    else
    {

        return node;
    }
}

/*void ShowInorder( NodeT *node )
{
    if ( node!= NULL )
    {

        ShowInorder( node−>left );
         printf("%d ", node->key);
        ShowInorder( node−>right);
    }
}*/
void ShowPreorder(NodeT *node)
{
    if(node!=NULL)
    {

        printf("%d ",node->key);
        ShowPreorder(node->left);
        ShowPreorder(node->right);
    }
}
void ShowPostorder(NodeT *node)
{
    if(node!=NULL)
    {

        ShowPostorder(node->left);
        ShowPostorder(node->right);
        printf("%d ",node->key);
    }
}

int main()
{
    NodeT *root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 11);
    root = Insert(root, 1);
    root = Insert(root, 23);
    root = Insert(root, 26);
    printf("\n");
    ShowPreorder(root);
    printf("\n");
    root = Delete(root,12);
    printf("\n");
    ShowPreorder(root);
    root = Delete(root,20);
    printf("\n");
    ShowPreorder(root);
    root=Delete(root,10);
    printf("\n");
    ShowPreorder(root);
    NodeT * temp;
    temp = Find(root,11);
    if(temp==NULL)
    {
        printf("Element 11 not found\n");
    }
    else
    {
        printf("Element 11 Found\n");
    }
    return 0;
}
