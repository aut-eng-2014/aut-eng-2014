#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "util.h"
#include "bst.h"

//@override
void insertNode()
{
    int val;
    printf("Type the value to be inserted: ");
    scanf("%d", &val);
    if (bst_insertNode(val))
    {
        if (*bst_getHeight()>5)
        {
            bst_deleteNode(val);
            printf("\tInsertion failed. Tree height cannot increase over 5.");
        }
        else
        {
            printf("\tValue %d was inserted successfully.", val);
        }
    }
    else
    {
        printf("\tInsertion failed. Value %d already in BST.", val);
    }
}

//@override
void deleteNode()
{
    int val;
    printf("Type the value to be deleted: ");
    scanf("%d", &val);
    if (bst_deleteNode(val))
    {
        printf("\tValue %d was deleted successfully.", val);
    }
    else
    {
        printf("\tDeletion failed. Value %d not in BST.", val);
    }
}

//@override
void findNode()
{
    int val;
    printf("Type the value to find: ");
    scanf("%d", &val);
    if (bst_findNode(val))
    {
        printf("\tValue %d was successfully found in the BST.", val);
    }
    else
    {
        printf("\tSearch failed. Value %d was not found.", val);
    }
}

//@override
void showTree()
{
    if (*bst_getRoot() == NULL)
    {
        printf("BST is uninitialized.");
    }
    else
    {
        printf("Height of the BST: %d.\n\tPrint of the BST:\n\t", *bst_getHeight());
        bst_showTree();
    }
}

int main()
{
    runMenu();
    return EXIT_SUCCESS;
}
