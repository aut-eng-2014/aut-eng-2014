//bintree_to_doublylinkedlist


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree
{
    char name ;
    struct tree *left;
    struct tree *right;


}NodeT;

NodeT*createBinTree()

{
    NodeT* root;
   char nume;
   scanf("%c", &nume);
    if(nume=='*')
        return NULL;/* empty tree*/
    else
    {
        root=(NodeT*)malloc(sizeof(NodeT));
        //if(root==NULL)
        root->name=nume;
        root->left=createBinTree();
        root->right=createBinTree();
    }
    return root;
}

void preorder(NodeT *root, int level)
{
int i;
    if(root!=NULL)
    {
        for ( i = 0; i <= level ; i++ )
        printf ( " " ) ;
        printf("%c\n", root->name);
        preorder(root->left, level+1);
        preorder(root->right, level+1);
    }
}
void inorder(NodeT *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c\n",root->name);
        inorder(root->right);
    }
}

NodeT* bintreeto2listUtil(NodeT* root)
{
    if (root == NULL)
        return root;
    if (root->left != NULL)
    {
        NodeT* left = bintreeto2listUtil(root->left);
        while (left->right!=NULL)
         left=left->right;
        left->right = root;
        root->left = left;
    }

    if (root->right!=NULL)
    {

        NodeT* right = bintreeto2listUtil(root->right);
        while (right->left!=NULL)
        right = right->left;
        right->left = root;
        root->right = right;
    }

    return root;
}

NodeT* bt_to_2list(NodeT* root)
{
    if (root == NULL)
        return root;

    // Converts to doublyll using bintree2listUtil()
    root = bintreeto2listUtil(root);
    while (root->left != NULL)
        root = root->left;

    return (root);
}


void printList(NodeT* root)
{
    while (root!=NULL)
    {
        printf("%c ", root->name);
        root->right=root;
    }
}

int main()
{
      NodeT* root=(NodeT*)malloc(sizeof(NodeT));
      printf("Input the nodes.\n");
    root= createBinTree();
    printf("\nPreorder Tree \n");
    preorder(root,0);
    printf("\nInorder Tree \n");
    inorder(root);

    NodeT* head= bt_to_2list(root);
printf ( "Press Enter to continue.\n " ) ;
    printf(" this is the list\n");
    printList(head);

    return 0;
}
