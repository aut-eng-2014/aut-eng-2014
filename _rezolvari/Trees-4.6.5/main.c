#include "functions.h"

int main()
{
    NodeT * root = createBinTree();
    NodeL * firstFromList = getListFromTree(root);
    traverseList();
    root = getTreeFromList(firstFromList);
    inorder(root, 0);
    return 0;
}


NodeL *getListFromTree(NodeT *root)
{

    if(root != NULL)
    {
        addLast(root->content);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    else
    {
        addLast("*");
    }

    return first;
}

NodeT *getTreeFromList(NodeL *elementOfList)
{
    NodeT *p;
    char *content = elementOfList->content;

    if ( strcmp(content,"*")==0 ){
        deleteNode(elementOfList);
        return NULL;
    }
    else
    {
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->content = content;
        p->left = getTreeFromList(elementOfList->next) ;
        p->right = getTreeFromList(elementOfList->next) ;
        deleteNode(elementOfList);
    }
    return p;
}


