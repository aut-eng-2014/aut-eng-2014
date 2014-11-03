#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions_lists.h"
#include "functions_trees.h"

#define MAX_SIZE_OF_CONTENT 100

NodeT *getTreeFromList(NodeL *firstElementOfList);
NodeL *getListFromTree(NodeT *rootOfTree);
