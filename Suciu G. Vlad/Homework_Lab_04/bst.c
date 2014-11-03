#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "bst.h"
#include "util.h"

BSTNodeT** bst_getRoot()
{
    static BSTNodeT* root = NULL;
    return &root;
}

char* bst_getHeight()
{
    static char height = -1;
    return &height;
}

BSTNodeT* bst_createNode(int value, int level)
{
    BSTNodeT* node = (BSTNodeT*) malloc(sizeof(BSTNodeT));
    node->value = value;
    node->level = level;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool bst_insertNode(int value)
{
    BSTNodeT** root = bst_getRoot();
    if (*root == NULL)
    {
        *root = bst_createNode(value, 0);
        return true;
    }
    else
    {
        BSTNodeT* tree = *root;
        while (tree != NULL)
        {
            if(tree->value > value)
            {
                if(tree->left != NULL)
                {
                    tree = tree->left;
                }
                else
                {
                    tree->left = bst_createNode(value, tree->level+1);
                    if (tree->left->level > *bst_getHeight())
                    {
                        *bst_getHeight() = tree->left->level;
                    }
                    return true;
                }
            }
            else if (tree->value < value)
            {
                if(tree->right != NULL)
                {
                    tree = tree->right;
                }
                else
                {
                    tree->right = bst_createNode(value, tree->level+1);
                    if (tree->right->level > *bst_getHeight())
                    {
                        *bst_getHeight() = tree->right->level;
                    }
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }
}

bool bst_findNode(int value)
{
    BSTNodeT* root = *bst_getRoot();
    if (root == NULL)
    {
        return false;
    }
    else
    {
        BSTNodeT* tree = root;
        while (tree != NULL)
        {
            if(tree->value > value)
            {
                if(tree->left == NULL)
                {
                    return false;
                }
                else
                {
                    tree = tree->left;
                }
            }
            else if (tree->value < value)
            {
                if(tree->right == NULL)
                {
                    return false;
                }
                else
                {
                    tree = tree->right;
                }
            }
            else
            {
                return true;
            }
        }
        return false;
    }
}

BSTNodeT* bst_getNextLeftNode(BSTNodeT* node)
{
    if (node->left == NULL)
    {
        return NULL;
    }
    else
    {
        BSTNodeT* before = node;
        node = node->left;
        while (node->right != NULL)
        {
            before = node;
            node = node->right;
        }
        if (before->left == node)
        {
            before->left = node->left;
        }
        else
        {
            before->right = node->right;
        }
        return node;
    }
}

BSTNodeT* bst_getNextRightNode(BSTNodeT* node)
{
    if (node->right == NULL)
    {
        return NULL;
    }
    else
    {
        BSTNodeT* before = node;
        node = node->right;
        while (node->left != NULL)
        {
            before = node;
            node = node->left;
        }
        if (before->left == node)
        {
            before->left = node->left;
        }
        else
        {
            before->right = node->right;
        }
        return node;
    }
}

void bst_recursiveLevel(BSTNodeT* node)
{
    if(node == NULL)
    {
        return;
    }
    if (node->left != NULL)
    {
        node->left->level = node->level+1;
    }
    if (node->right != NULL)
    {
        node->right->level = node->level+1;
    }
    bst_recursiveLevel(node->left);
    bst_recursiveLevel(node->right);
}

char bst_recursiveHeightCheck(BSTNodeT* node)
{
    if (node == NULL)
    {
        return -1;
    }
    char leftHeight = node->level;
    char rightHeight = node->level;
    if (node->left != NULL)
    {
        leftHeight = bst_recursiveHeightCheck(node->left);
    }
    if ((leftHeight <= *bst_getHeight()) && (node->right != NULL))
    {
        rightHeight = bst_recursiveHeightCheck(node->right);
    }
    if (leftHeight < rightHeight)
    {
        return rightHeight;
    }
    else
    {
        return leftHeight;
    }
}

void bst_refreshHeight()
{
    char newHeight = bst_recursiveHeightCheck(*bst_getRoot());
    if (*bst_getHeight() != newHeight)
    {
        *bst_getHeight() = newHeight;
    }
}

bool bst_deleteNode(int value)
{
    BSTNodeT** root = bst_getRoot();
    if (*root == NULL)
    {
        return false;
    }
    else
    {
        BSTNodeT* tree = *root;
        BSTNodeT* before = NULL;
        while (tree != NULL)
        {
            if(tree->value > value)
            {
                if(tree->left == NULL)
                {
                    return false;
                }
                else
                {
                    before = tree;
                    tree = tree->left;
                }
            }
            else if (tree->value < value)
            {
                if(tree->right == NULL)
                {
                    return false;
                }
                else
                {
                    before = tree;
                    tree = tree->right;
                }
            }
            else
            {
                BSTNodeT* changeNode;
                bool random = randBool();
                if (tree != *root)
                {
                    if (random)
                    {
                        changeNode = bst_getNextLeftNode(tree);
                        if (changeNode == NULL)
                        {
                            changeNode = bst_getNextRightNode(tree);
                        }
                    }
                    else
                    {
                        changeNode = bst_getNextRightNode(tree);
                        if (changeNode == NULL)
                        {
                            changeNode = bst_getNextLeftNode(tree);
                        }
                    }

                    if (changeNode != NULL)
                    {
                        if (before->left == tree)
                        {
                            before->left = changeNode;
                            changeNode->left = tree->left;
                            changeNode->right = tree->right;
                        }
                        else
                        {
                            before->right = changeNode;
                            changeNode->left = tree->left;
                            changeNode->right = tree->right;
                        }
                        changeNode->level = tree->level;
                    }
                    else
                    {
                        if (before->left == tree)
                        {
                            before->left = NULL;
                        }
                        else
                        {
                            before->right = NULL;
                        }
                    }
                    bst_recursiveLevel(changeNode);
                    free(tree);
                }
                else
                {
                    if (random)
                    {
                        changeNode = bst_getNextLeftNode(tree);
                        if (changeNode == NULL)
                        {
                            changeNode = bst_getNextRightNode(tree);
                        }
                    }
                    else
                    {
                        changeNode = bst_getNextRightNode(tree);
                        if (changeNode == NULL)
                        {
                            changeNode = bst_getNextLeftNode(tree);
                        }
                    }

                    if (changeNode != NULL)
                    {
                        changeNode->left = tree->left;
                        changeNode->right = tree->right;
                        changeNode->level = 0;
                    }
                    bst_recursiveLevel(changeNode);
                    free(*root);
                    *root = changeNode;
                }
                bst_refreshHeight();
                return true;
            }
        }
        return false;
    }
}

void bst_recursivePrint(BSTNodeT* node, int flag, char indent, char type)
{
    if (node == NULL)
    {
        return;
    }

    /* print the node */
    char str[1] = "";
    switch (type)
    {
        case 'r':
            sprintf(str, "%c", SYMBOL_EW);
            break;
        case 'R':
            sprintf(str, "%c", SYMBOL_ESW);
            break;
        case 'L':
            sprintf(str, "%c", SYMBOL_NE);
            break;
    }
    type = toupper(type);
    char* valueString = (char*) calloc(8, sizeof(char));
    sprintf(valueString, "%c[%d]", type, node->value);
    if ((node->left == NULL) && (node->right == NULL))
    {
        printf("%s", printPadding(strcat(str, valueString), ' '));
    }
    else
    {
        printf("%s", printPadding(strcat(str, valueString), SYMBOL_EW));
    }
    free(valueString);
    /* end */

    if (node->left == NULL)
    {
        flag |= 1<<indent;
        bst_recursivePrint(node->right, flag, indent+1, 'r');
    }
    else
    {
        bst_recursivePrint(node->right, flag, indent+1, 'R');
    }
    if (node->right == NULL)
    {
        if (node->left != NULL)
        {
            printf("%c", SYMBOL_SW);
        }
        printf("\n\t");
    }
    if (node->left != NULL)
    {
        printf("\t");
        for (int i=0; i<indent; i++)
        {
            if (!(flag&(1<<i)))
            {
                printf("%c", SYMBOL_NS);
            }
            printf("\t");
        }
    }
    flag |= 1<<indent;
    bst_recursivePrint(node->left, flag, indent+1, 'L');
}

void bst_showTree()
{
    bst_recursivePrint(*bst_getRoot(), 0, 0, 'O');
}
