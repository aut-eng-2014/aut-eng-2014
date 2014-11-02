#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT
{
    int content;
    struct NodeT *left;
    struct NodeT *right ;
}NodeT;

NodeT *root;

NodeT *FindMinimum (NodeT *node)
{
    NodeT *Iterator=node;
    while(Iterator->left!=NULL)
    {
        Iterator=Iterator->left;
    }
    return Iterator;
}
void InsertNode(int content)
{
    NodeT *parentNode;
    NodeT *newNode=(NodeT*)malloc(sizeof(NodeT));
    newNode->content=content;
    newNode->right=NULL;
    newNode->left=NULL;

    if(root==NULL)
    {
        root=newNode;
        return;
    }

    parentNode=root;
    while(1)
    {
        if(newNode->content<parentNode->content)
        {
            /** go to the left subtree **/
            if(parentNode->left==NULL)
            {
                parentNode->left=newNode;
                return;
            }
            else
            {
                parentNode=parentNode->left;
            }
        }
        else
        {
            if(newNode->content>parentNode->content)
            {
                /** go to the right subtree **/
                if(parentNode->right==NULL)
                {
                    parentNode->right=newNode;
                    return;
                }
                else
                {
                    parentNode=parentNode->right;
                }
            }
            else
            {
                printf("\nElement already exists in the tree!\n");
                return;
            }
        }
    }
}

void preorder( NodeT *p, int level )
{
    int i;
    if (p!=NULL)
    {
        for (i=0;i<=level;i++)
            printf(" ");
        printf("%d\n", p->content);
        preorder(p->left, level+1);
        preorder(p->right, level+1);
    }
}

void inorder(NodeT *p, int level )
{
    int i;
    if (p!=NULL)
    {
        inorder(p->left, level+1);
        for (i=0;i<=level;i++)
            printf(" ");
        printf("%d\n", p->content);
        inorder(p->right, level+1);
    }
}

void postorder(NodeT *p, int level )
{
    int i;
    if (p!=NULL)
    {
        postorder(p->left , level+1);
        postorder(p->right, level+1);
        for (i=0;i<=level;i++)
            printf(" ");
        printf("%d\n", p->content);
    }
}

NodeT* FindNode (NodeT* root, int content)
{
    NodeT *Iterator;

    if(root==NULL)
    {
        return NULL;
    }
    for(Iterator=root;Iterator!=NULL;)
    {
        if(content==Iterator->content)
        {
            return Iterator;
        }
        else
        {
            if(content<Iterator->content)
            {
                Iterator=Iterator->left;
            }
            else
            {
                Iterator=Iterator->right;
            }
        }
    }
    return NULL;
}

NodeT *DeleteNode(NodeT *root, int content)
{
    if(root==NULL)
    {
        return root;
    }
    else if(content<root->content)
    {
        root->left=DeleteNode(root->left,content);
    }
    else if(content>root->content)
    {
        root->right=DeleteNode(root->right,content);
    }
    else
    {
        /** no child **/
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        /** one child **/
        else if(root->left == NULL)
        {
            NodeT *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            NodeT *temp = root;
            root = root->left;
            free(temp);
        }
        /** 2 children **/
        else
        {
            NodeT *temp=FindMinimum(root->right);
            root->content=temp->content;
            root->right=DeleteNode(root->right,temp->content);
        }
    }
    return root;
}



NodeT *q;
int main()
{
    int nr=0,in,out,srch;
    printf("--->WELCOME!<----");
    printf("\nPress 1 to insert a new node in the BST!\n");
    printf("Press 2 to delete a node from the BST!\n");
    printf("Press 3 to show the BST in INORDER traversal\n");
    printf("Press 4 to show the BST in PREORDER traversal\n");
    printf("Press 5 to show the BST in POSTORDER traversal\n");
    printf("Press 6 to search a node in the BST!\n");
    printf("Press 7 to EXIT!\n");
    while(nr!=7)
    {
        scanf("%d",&nr);
        if(nr==1)
        {
            printf("Please insert the value you want to add in the BST:\n");
            scanf("%d",&in);
            InsertNode(in);
        }
        if(nr==2)
        {
            printf("Please insert the value you want to delete from the BST:\n");
            scanf("%d",&out);
            q=DeleteNode(root,out);
        }
        if(nr==3)
        {
            printf("\nINORDER:\n");
            inorder(root,0);
        }
        if(nr==4)
        {
            printf("\nPREORDER:\n");
            preorder(root,0);
        }
        if(nr==5)
        {
            printf("\nPOSTORDER:\n");
            postorder(root,0);
        }
        if(nr==6)
        {
            printf("Please insert the value you want to search in the BST:\n");
            scanf("%d",&srch);
            q=FindNode(root,srch);
            if(q==NULL)
                printf("No node found.\n");
            else
                printf("Node found.\n");

        }
    }
    return 0;
}
