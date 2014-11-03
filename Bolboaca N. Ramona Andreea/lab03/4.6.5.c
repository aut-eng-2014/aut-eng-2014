#include <stdio.h>
#include <stdlib.h>

typedef struct NodeL
{
    char *content;
    struct NodeL *next , *prev;
} NodeL;

typedef struct NodeT
{
    char *content;
    struct NodeT *left;
    struct NodeT *right ;
}NodeT;

NodeL *first, *last;

/** AddLast for doubly-linked-list **/
void addLast(char *content)
{
    if(first==NULL)
    {
        first=(NodeL*)malloc(sizeof(NodeL));
        first->content=content;
        first->prev=NULL;
    }
    else
        if(last==NULL)
        {
            last=(NodeL*)malloc(sizeof(NodeL));
            last->content=content;
            first->next=last;
            last->prev = first;
            last->next=NULL;
        }
        else
        {
            NodeL *node=(NodeL*)malloc(sizeof(NodeL));
            node->content=content;
            node->prev=last;
            node->next=NULL;
            last->next = node;
            last = node;
        }
}

void deleteNode(NodeL *node)
{
    if(node==first)
    {
        if(node->next==NULL)
        {
            first=NULL;
        }
        else
        {
            if(node->next==last)
            {
                first=last;
            }
            else
            {
                first=node->next;
                first->prev=NULL;
            }
        }
    }
    else
        if(node==last)
        {
            if(node->prev == NULL)
            {
                free(node);
                last=NULL;
            }
            else
            {
                if(node->prev==first)
                {
                    first-> next = NULL;
                    last = NULL;
                }
                else
                {
                    last = node->prev;
                    last->next = NULL;
                }
            }
        }
        /** "in between" node **/
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    free(node);
}
void traverseList()
{
    NodeL *p=first;
    while(p!=NULL)
    {
        printf("%s ",p->content);
        p=p->next;
    }
    printf("\n\n");
}
/** As we worked in laboratory **/
NodeT *createBinTree()
{
    NodeT *p;
    char *content=(char*)malloc(sizeof(char)*100);
    scanf("%s",content);
    if (strcmp(content,"*")==0 )
        return NULL;
    else
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        p->content=content;
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}
/** The traversals as in laboratory **/
void preorder( NodeT *p, int level )
{
    int i;
    if (p!=NULL)
    {
        for (i=0;i<=level;i++)
            printf(" ");
        printf("%s\n", p->content);
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
        printf("%s\n", p->content);
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
        printf("%s\n", p->content);
    }
}

/** Recursively creates a list from a tree **/
NodeL* getListFromTree(NodeT *root)
{
    /** If the tree element is not null (a leaf) **/
    if(root != NULL)
    {
        /** Always add as last element **/
        addLast(root->content);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    /** If it is a leaf, add "*" so we can reconstruct it later **/
    else
    {
        addLast("*");
    }
    return first;
}
/** Recursively create a tree from a list **/
NodeT *getTreeFromList(NodeL *elementOfList)
{
    NodeT *p;
    char *content=elementOfList->content;
    /** If the content is "*" that means it's a leaf node
        => we can safely delete it from the list **/
    if ( strcmp(content,"*")==0 )
    {
        deleteNode(elementOfList);
        return NULL;
    }
    else
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        p->content=content;
        p->left=getTreeFromList(elementOfList->next);
        p->right=getTreeFromList(elementOfList->next);
        /** trickiest part of the problem was realizing that this is needed
            grab pen+paper and trace it to see why it is needed **/
        deleteNode(elementOfList);
    }
    return p;
}

int main()
{
    NodeT * root = createBinTree();
    NodeL * firstFromList = getListFromTree(root);
    traverseList();
    root = getTreeFromList(firstFromList);
    inorder(root, 0);
    return 0;
}
