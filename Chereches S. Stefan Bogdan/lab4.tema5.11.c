#include <stdio.h>
#include <stdlib.h>
typedef struct tree_tree
{
    int x;
    struct tree_tree* left;
    struct tree_tree* right;

} tree;

tree *root;

tree* Getnew(int x)
{
    root=(tree*)malloc(sizeof(tree*));
    root->x=x;
    root->left=NULL;
    root->right=NULL;
    return root;

}
tree* insert(tree* root, int x)
{
    if(root==NULL)
    {
        root= Getnew(x);
    }
    else if(root->x>x)

    {
        root->right=insert(root->right,x);
    }
    else
    {
        root->left=insert(root->left,x);
    }
    return root;
}

tree* search(tree *root,int x)// nu stiu de ce nu merge :-??
{
    if(root==NULL)
    {
        printf("Node not found");
    }
    else
    {
        if(root->x==x)
        {
            printf("Node found");

        }

        ;
        if(root->x  > x)
        {
            return search(root->left,x);
            printf("Node found");
        }
        else
        {
            return search(root->right,x);
            printf("Node found");
        }

    }
return 0;
}

void inorder(tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\n",root->x);
        inorder(root->right);
    }

}

/*tree* Delete(tree* root,int x) // tentativa de functie de delete, nu merge search
{
 if (root==NULL)
    return root;

 {
 if(search(root,x)==0)
 {
 printf("No root");
 }
 else
 {
 if (x<root->x)
 {root->left=Delete(root->left,x);}
 else{if(x>root->x)
    {root->right=Delete(root->right,x);}
 }
 }
}
*/
int main()
{
    int sw;
    int w,s;
    tree *root=NULL;
    do
    {
        printf("Select 1.Insert 2.Find 3.Show 4.Exit: ");
        scanf("%d",&sw);
        switch(sw)
        {
        case 1:
            printf("Insert node: ");
            scanf("%d",&w);
            root=insert(root,w);
            break;
        case 2:
            printf("Insert node: ");
            scanf("%d",&s);
            search(root,s);
            break;
        case 3:
            inorder(root);
            break;

        }
    }
    while(sw!=4);


    return 0;
}
