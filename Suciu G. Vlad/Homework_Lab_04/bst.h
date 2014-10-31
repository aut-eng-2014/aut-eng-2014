#ifndef BST_HEADER
#define BST_HEADER

#include "util.h"

typedef struct bst_node
{
    int value;
    char level;
    struct bst_node *left;
    struct bst_node *right;
} BSTNodeT;

/* used to store the root of the tree */
BSTNodeT** bst_getRoot();

/* used to store the height of the tree */
char* bst_getHeight();

/* creates new node based on the given value and level*/
BSTNodeT* bst_createNode(int value, int level);

/* inserts the value in the bst and returns true if succeeded, false if not */
bool bst_insertNode(int value);

/* returns true/false whether the node is found or not */
bool bst_findNode(int value);

/* returns the rightmost node of the left branch, NULL if none */
BSTNodeT* bst_getNextLeftNode(BSTNodeT* node);

/* returns the leftmost node of the right branch, NULL if none */
BSTNodeT* bst_getNextRightNode(BSTNodeT* node);

/* restores the corect levels to the subtree with root node, where the node has correct level */
void bst_recursiveLevel(BSTNodeT* node);

/* returns current height of the tree calculated recursively */
char bst_recursiveHeight(BSTNodeT* node);

/* restores the correct height for the tree */
void bst_refreshHeight();

/* delets the node by specified value, returns false if no element with value is found, otherwise true */
bool bst_deleteNode(int value);

/* prints recursively the tree with flag indicating whether to print horizontal lines between children or
not, indent being the number of tabs before print and type being the node type (left/right) */
void bst_recursivePrint(BSTNodeT* node, int flag, char indent, char type);

/* shows the entire tree */
void bst_showTree();

#endif
