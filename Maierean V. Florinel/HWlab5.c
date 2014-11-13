//Binary search tree - Homework 6.4.4

#include <stdio.h>
#include <stdlib.h>

//First we create the node

struct BstNode
{
    int data;
    struct  BstNode* left;
    struct  BstNode* right;
};
struct BstNode* rootPtr;
struct BstNode* rootPtr = NULL;//set tree as empty

void InsertNode(struct BstNode* rootPtr, int data);
void DeleteNode(struct BstNode* rootPtr, int data);
void FindNode(struct BstNode* rootPtr, int data);
void Showinorder(struct Bstnode* node);
void GetNewNode(int data);

//Function to create a new node
void struct BstNode* GetNewNode(int data)
{
    struct BstNode* NewNode;
    NewNode=(struct BstNode*)malloc(sizeof(struct BstNode));
    NewNode->data=data;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}


void BstNode* InsertNode(struct BstNode* rootPtr, int data)
{
    if(rootPtr==NULL)
    {
        //Empty tree
        rootPtr=GetNewNode(data);
    }

    else if(data<=rootPtr->data)
    {
        rootPtr->left=InsertNode(rootPtr->left,data);
    }

                  else
    {
        rootPtr->right=InsertNode(rootPtr->right,data);
    }

    return rootPtr;
}

//To search an element in BST, returns true if element is found
void FindNode(struct BstNode* rootPtr, int data)
{
    if(rootPtr==NULL)
    {
        return printf("False");
    }
    else if(rootPtr->data==data)
    {
        return printf("True");
    }
    else if(data<=rootPtr->data)
    {
        return FindNode(rootPtr->left,data);
    }
    else return FindNode(rootPtr->right,data);

}

//to find minimum in a tree
struct BstNode* FindMin(struct BstNode* rootPtr)
{
    while(rootPtr->left != NULL) rootPtr = rootPtr->left;
    return rootPtr;
}

// delets a node from the binary search tree
struct BstNode* Delete(struct BstNode *rootPtr, int data)
{
    if(rootPtr == NULL) return rootPtr;
    else if(data < rootPtr->data) rootPtr->left = Delete(rootPtr->left,data);
    else if (data > rootPtr->data) rootPtr->right = Delete(rootPtr->right,data);
    // it will get deleted
    else
    {
        //First case where is No child
        if(rootPtr->left == NULL && rootPtr->right == NULL)
        {
            free (rootPtr);
            rootPtr = NULL;
        }
        //Second case with One child
        else if(rootPtr->left == NULL)
        {
            struct BstNode *temp = rootPtr;
            rootPtr = rootPtr->right;
            free (temp);
        }
        else if(rootPtr->right == NULL)
        {
            struct BstNode *temp = rootPtr;
            rootPtr = rootPtr->left;
            free(temp);
        }
        // Third case with 2 children
        else
        {
            struct BstNode *temp = FindMin(rootPtr->right);
            rootPtr->data = temp->data;
            rootPtr->right = Delete(rootPtr->right,temp->data);
        }
    }
    return rootPtr;
}


void Showinorder(struct BstNode* rootPtr)
{
    if(rootPtr == NULL)
    {
        return;
    }
    Showinorder(rootPtr->left);//visit left subtree
    printf("%d",rootPtr->data);//print data
    Showinorder(rootPtr->right);//visit right subtree
}


int main()
{
    int ch;
    int num;
    int q;
    printf("\n ~Chose the key menu  from below~ \n");
    printf("\n i. Insert d. Delete f. Find s. Show q. Quit\n");

    while (ch!='q')
    {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'i':
        case 'I':
            printf("\nEnter the node you want to insert in the binary search tree.\n");
            scanf("%d%", &num);
            InsertNode(num);
            break;
        case 'd':
        case 'D':
            printf("\nEnter the node you want to delete from the binary search tree.\n");
            scanf("%d", &num);
            rootPtr = Delete(num,1);
            Showinorder(rootPtr,1 );
            break;
        case 'f':
        case 'F':
            printf("\nEnter the node you want to find from the binary search tree.\n");
            scanf("%d%", &num);
            q = FindNode( rootPtr,num );
            if ( q != NULL )
                printf ( "Node was found. \n" );
            else
                printf ( "Node was not found. \n" );
            break;
        case 's':
        case 'S':
            scanf("%c");
            Showinorder(rootPtr, 1);
            break;
        case 'q':
        case 'Q':
            exit(1);
            break;
        default:
            scanf("%c");
            printf("Enter a valid key menu from this list: i, d, f, s, q.\n");
            break;
        }

    }
}
