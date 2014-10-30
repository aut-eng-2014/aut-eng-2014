/*Transform a binary tree holding character strings into a doubly-linked list such a way that you can reconstruct the
tree. The input is specified as for Problem 4.3. Output is prefix and infix traversals of the tree on two separate lines.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree
{
    char id;
    struct tree *left;
    struct tree *right;


}TreeNode;

TreeNode* createBinTree()

{
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));;
    char name;
    scanf("%c", &name);
    if(name==0)
        return NULL;  //The tree is empty
    else
    {
        root->id=name;
        root->left=createBinTree();
        root->right=createBinTree();
    }
    return root;
}

void inorder(TreeNode *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%c\n",node->id);
        inorder(node->right);
    }
}


TreeNode* binTreeToDLLaux(TreeNode* root) //Auxiliary function for converting the left and right subtrees and link them to the root.
{
    if(root==NULL)
        return root;

    if(root->left!=NULL)
    {
        TreeNode* left=binTreeToDLLaux(root->left);
        while(left->right!=NULL)
        left=left->right;
        left->right = root;
        root->left = left;
    }

    if(root->right!=NULL)
    {
        TreeNode* right = binTreeToDLLaux(root->right);
        while(right->left!=NULL)
        right = right->left;
        right->left = root;
        root->right = right;
    }
    return root;
}


TreeNode* binTreeToDLL(TreeNode* root) //The function for converting the tree to a dll
{
    if(root==NULL)
        return root;

    root=binTreeToDLLaux(root);
    while(root->left!=NULL)
        root=root->left;
    return(root);
}


void printDLL(TreeNode* root)
{
    while(root!=NULL)
    {
        printf("%c ", root->id);
        root->right=root;
    }
}


int main()
{
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
    root=createBinTree();

    printf("Give the names:\n");
    inorder(root);


    //Convert the tree and print the dll
    TreeNode *head=binTreeToDLL(root);
    printDLL(head);

    return 0;
}
