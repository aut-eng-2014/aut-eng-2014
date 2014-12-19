#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
}
NodeT;

NodeT *createNewnode(int data)
{
    NodeT *temp= (NodeT*) malloc (sizeof(NodeT));
    temp->key=data;
    temp->left=temp->right=NULL;
    return temp;
}

NodeT *insertNewnode (NodeT *root, int data)
{
    if (root==NULL)
    {
        root = createNewnode(data);
    }
    if (root->key > data)
    {
        root->left=insertNewnode(root->left,data);
    }
    else
    {
        if (root->key < data)
        {
            root->right=insertNewnode(root->right,data);
        }
    }
    return root;
}

void searchBintree (NodeT *root, int data)
{
    if (root==NULL)
        printf("\nThe value has not been found\n");
    if (root->key == data)
    {
        printf ("\nThe value has been found\n");
    }
    if (root->key > data)
    {
        searchBintree (root->left,data);
    }
    else

        if (root->key < data)
        {
            searchBintree (root->right,data);
        }
}

void preorder (NodeT *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->key);
        preorder(temp->left);
        preorder(temp->right);
    }
}

NodeT *Delete (NodeT *root, int data)
{
    if(root == NULL)
        return root;
    else
     if(data < root->key)
     {
        root->left = Delete (root->left,data);
     }
    else
      if (data > root->key)
      {
        root->right = Delete(root->right,data);
      }
    else
    {

        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else
            if(root->left == NULL)
        {
            NodeT *temp = root;
            root = root->right;
            free(temp);
        }
        else
            if(root->right == NULL)
            {
                NodeT *temp = root;
                root = root->left;
                free(temp);
            }
        else
        {
            while(root->left != NULL)
            {
                root = root->left;
            }
            NodeT *temp=root;
            root->key = temp->key;
            root->right = Delete(root->right,temp->key);
        }
    }
    return root;
}

int main()
{
    int data, choice;
    NodeT *root= NULL;
    do
    {
        printf("Main Menu\n1.Insertion\n2.Search\n3.Delete\n4.Write\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf ("The value of the node you want to insert is: ");
            scanf("%d", &data);
            root=insertNewnode(root, data);
            break;

        case 2:
            printf ("Please introduce the value you are searching for: ");
            scanf ("%d", &data);
            searchBintree(root, data);
            break;

        case 3:
            printf ("Please introduce the node you wanna delete: ");
            scanf ("%d", &data);
            root=Delete(root,data);
            break;

        case 4:
            printf ("The nodes are: ");
            preorder(root);
            printf ("\n");
            break;

        case 5:

            break;
        default:
            printf("wrong input");
        }
    }
    while(choice != 5);
    printf("bye");
    return 0;
}
