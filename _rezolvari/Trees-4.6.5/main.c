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

/**
* Recursively creates a list from a tree
*/
NodeL *getListFromTree(NodeT *root)
{

    //! if the tree element is not null (a leaf)
    if(root != NULL)
    {
        // always add as last element
        addLast(root->content);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    //! if it is a leaf, add "*" so we can reconstruct it later
    else
    {
        addLast("*");
    }

    return first;
}

/**
* Recursively create a tree from a list
*/
NodeT *getTreeFromList(NodeL *elementOfList)
{
    NodeT *p;
    char *content = elementOfList->content;

    //! if the content is "*" that means it's a leaf node => we can safely delete it from the list
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
        //! trickiest part of the problem was realizing that this is needed
        //! grab pen+paper and trace it to see why it is needed
        deleteNode(elementOfList);
    }
    return p;
}


