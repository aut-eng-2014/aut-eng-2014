#include "main.h"


nodeT* insertNode(nodeT* node, int value)
{
    if (node == NULL)//base case:if the tree is empty we insert a new node
    {
        nodeT *temp=(nodeT *)malloc(sizeof(nodeT));
        temp->key = value;
        temp->left = temp->right = NULL;
        return temp;
    }
//otherwise,we recour down the tree searching for the spot where the node should be inserted
    if (value < node->key)//if the value is smaller then the current node we insert it in the left subtree
        node->left  = insertNode(node->left, value);

    else if (value > node->key)//the oposite
        node->right = insertNode(node->right, value);

    return node;
}

void inorder(nodeT *root)//inorder print
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
        return root;//if the node we need is root return root

    if (root->key < key)//if key greater then root's key,search in the right subtree
        return searchNode(root->right, key);
    return searchNode(root->left, key);//the oposite
}


nodeT* deleteNode(nodeT* root, int key)
{
    if (root == NULL) return root;//base case
    //if the key to be deleted is smaller than the root's key then it lies in the left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
//if the key is bigger the it is in the right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else //if key same as root's then this is the node to be deleted
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
        // if it is a node with two children: get the inorder successor (smallest in the right subtree)
        nodeT* temp =root->right;

        while (temp->left != NULL)
            temp = temp->left;

        root->key = temp->key;//copy the content of inorder succesor to the node
        root->right = deleteNode(root->right, temp->key);//delete the inorder succesor
    }
    return root;
}
