#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    char* prefixExpression = (char*) malloc(sizeof(char)*400);
    gets(prefixExpression);
    NodeT * root = createTreeFromPrefixExpression(prefixExpression);
    inorder(root,0);
    return 0;
}
