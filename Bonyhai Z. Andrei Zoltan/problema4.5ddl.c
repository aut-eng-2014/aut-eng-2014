#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    char* data;
    struct node* left;
    struct node* right;
};
 

struct node* bintree2listUtil(struct node* root)
{

    if (root == NULL)
        return root;
 
    if (root->left != NULL)
    {
     	//Converteste arborele stang
        struct node* left = bintree2listUtil(root->left);
 
        //Gaseste predecesorul din inordine
        for (; left->right!=NULL; left=left->right);
 
       	//Marcheaza-l ca radacina
        left->right = root;
 
        root->left = left;
    }
 
    // Converteste arborele drept (identinc cu algoritmul de mai sus)
    if (root->right!=NULL)
    {
        struct node* right = bintree2listUtil(root->right);
 
       
        for (; right->left!=NULL; right = right->left);
 
        right->left = root;
 
        
        root->right = right;
    }
 
    return root;
}
 
struct node* bintree2list(struct node *root)
{
    if (root == NULL)
        return root;
 
    root = bintree2listUtil(root);
 
    
    
    while (root->left != NULL)
        root = root->left;
 
    return (root);
}
 


struct node* newNode(char* data)
{
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
 

void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%s ", node->data);
        node = node->right;
    }
    printf("\n");
}
 

int main()
{
    struct node *root = newNode("Matilde");
    root->left        = newNode("Sebastian");
    root->right       = newNode("Leonor");
    root->left->left  = newNode("Philip");
    root->left->right = newNode("Marie");
    root->right->left = newNode("Rail");
 
    
    struct node *head = bintree2list(root);
 
    printList(head);
 
    return 0;
}