#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* homework 4.6.1 */

typedef int bool;
#define true 1
#define false 0

typedef struct node
{
    char value;
    int level;
    struct node *left;
    struct node *right;
} NodeT;

NodeT **stack;
int stackPointer;
bool debugMode = false;
int treeHeight = 0;
NodeT *printNull;

/* checks if the expression is in accordance to a math expression */
int checkExpression(char* expr)
{
    int pointer = 0;
    while (*(expr+pointer) != 0)
    {
        if (!(isalpha(*(expr+pointer)) || strchr("+-*/ #", *(expr+pointer))))
        {
            return false;
        }
        pointer++;
    }
    return true;
}

/* exits and prints a message */
void exitError(char *string)
{
    printf("[ERROR] %s", string);
    exit(EXIT_FAILURE);
}

/* reads the math expresion (in values) and its size*/
void readExpression(char **values, int *size)
{
    fprintf(stdout, "[INFO] [READ]\tIntroduce the mathematical expression separated by space in\n");
    fprintf(stdout, "\t\tpostfix form with operands in [a-zA-Z], operations in '+-*/'\n");
    fprintf(stdout, "\t\tand use '#' for unary operations:\n");
    fprintf(stdout, "[INFO] [READ]\t");
    char *buffer = (char*) calloc(1024, sizeof(char));
    fgets(buffer, 1024, stdin);

    *size = 0;
    while (*(buffer+*size) != '\n')
    {
        (*size)++;
    }
    *size = (*size+1)/2;

    char *result = (char*) calloc((*size+1), sizeof(char));
    for (int i=0; i<*size; i++)
    {
        *(result+i) = *(buffer+i*2);
    }

    free(buffer);
    if (checkExpression(result))
    {
        *values = result;
    }
    else
    {
        exitError("[READ]\tThe read expression contains invalid characters.\n");
    }
}

/* initializes a stack with size >= 1 */
void initStack(int size)
{
    if(size < 1)
    {
        exitError("[INIT]\tFailed to initialize stack. Size is less than 1.\n");
        return;
    }
    stack = (NodeT**) calloc(size, sizeof(NodeT*));
    stackPointer = -1;
}

void pushStack(NodeT *node)
{
    if (debugMode)
    {
        printf("[DBUG] [PUSH]\t%c @ %d\n", node->value, stackPointer+1);
    }
    stackPointer++;
    *(stack+stackPointer) = node;
}

/* increase levels the NodeT node and its children */
void increaseLevels(NodeT *node)
{
    if(node == NULL)
    {
        return;
    }
    (node->level)++;
    if (node->level > treeHeight)
    {
        treeHeight = node->level;
    }
    increaseLevels(node->left);
    increaseLevels(node->right);
}

/* returns the pointer to popped NodeT node */
NodeT* popStack()
{
    NodeT *result = *(stack+stackPointer);
    increaseLevels(result);
    if (debugMode)
    {
        printf("[DBUG] [POP]\t%c @ %d\n", result->value, stackPointer);
    }
    *(stack+stackPointer) = NULL;
    stackPointer--;
    return result;
}

/* returns a NodeT based on char val with NULL left and right children */
NodeT* createNode(char val)
{
    NodeT *result = (NodeT*) malloc(sizeof(NodeT));
    result->value = val;
    result->level = 0;
    result->left = NULL;
    result->right = NULL;
    return result;
}

/* transforms the values string in a binary tree */
void createTree(char *values, int size)
{
    for (int i=0; i<size; i++)
    {
        NodeT *aux = createNode(*(values+i));
        if (isalpha(aux->value) || (aux->value=='#'))
        {
            pushStack(aux);
        }
        else if (strchr("+-*/", aux->value))
        {
            NodeT *node = createNode(aux->value);
            node->right = popStack();
            node->left = popStack();

            pushStack(node);
        }
    }
}

/* raises the base to the power of exponent, returns -1 if exponent is negative */
int power(int base, int exponent)
{
    if (exponent < 0)
        return -1;
    int result = 1;
    for (int i=0; i<exponent; i++)
        result *= base;
    return result;
}

/* prints the row with the element in the file */
void printValue(FILE *f, NodeT *node)
{
    if (node->value != -1)
    {
        for (int i=0; i<power(2,treeHeight-node->level)-1; i++)
        {
            fprintf(f, " ");
        }
        fprintf(f, "%c", node->value);
        for (int i=0; i<power(2,treeHeight-node->level)-1; i++)
        {
            fprintf(f, " ");
        }
    }
    else
    {
        for (int i=0; i<power(2,treeHeight-node->level+1)-1; i++)
        {
            fprintf(f, " ");
        }
    }
}

/* prints the elements in the same value */
void recursivePrintValue(FILE *f, NodeT *node, int level)
{
    if (level < node->level)
    {
        return;
    }
    if (level == node->level)
    {
        printValue(f, node);
        fprintf(f, " ");
        if (node == printNull)
        {
            return;
        }
    }
    if (node->left->value == -1)
    {
        node->left->level = node->level+1;
    }
    recursivePrintValue(f, node->left, level);
    if (node->value == -1)
    {
        node->level--;
    }
    if (node->right->value == -1)
    {
        node->right->level = node->level+1;
    }
    recursivePrintValue(f, node->right, level);
}

/* prints the link between node and its children in the file */
void printLinks(FILE *f, NodeT *node, int i)
{
    if (node->value != -1)
    {
        for (int j=0; j<power(2, treeHeight-node->level+1)-1; j++)
        {
            if (j == power(2, treeHeight-node->level)-2-i)
            {
                if (node->left->value != -1)
                    fprintf(f, "/");
                else
                    fprintf(f, " ");
            }
            else if (j == power(2, treeHeight-node->level)+i)
            {
                if (node->right->value != -1)
                    fprintf(f, "\\");
                else
                    fprintf(f, " ");
            }
            else
            {
                fprintf(f, " ");
            }
        }
    }
    else
    {
        for (int j=0; j<power(2, treeHeight-node->level+1)-1; j++)
        {
            fprintf(f, " ");
        }
    }
}

/* prints the links between same levels */
void recursivePrintLinks(FILE *f, NodeT *node, int i, int level)
{
    if (level < node->level)
    {
        return;
    }
    if (level == node->level)
    {
        printLinks(f, node, i);
        fprintf(f, " ");
        if (node == printNull)
        {
            return;
        }
    }
    if (node->left->value == -1)
    {
        node->left->level = node->level+1;
    }
    recursivePrintLinks(f, node->left, i, level);
    if (node->value == -1)
    {
        node->level--;
    }
    if (node->right->value == -1)
    {
        node->right->level = node->level+1;
    }
    recursivePrintLinks(f, node->right, i, level);
}

/* recursively changes NULL values with replacement */
void recursiveFormatTree(NodeT *node, NodeT *replacement)
{
    if ((node->left == NULL) || (node->right == NULL))
    {
        if(node->left == NULL)
        {
            node->left = replacement;
        }
        if(node->right == NULL)
        {
            node->right = replacement;
        }
        return;
    }
    recursiveFormatTree(node->left, replacement);
    recursiveFormatTree(node->right, replacement);
}

/* reformats treeto print spaces when null node is encountered */
void reformatTree()
{
    printNull = (NodeT*) malloc(sizeof(NodeT));
    printNull->value = -1;
    printNull->level = -1;
    printNull->left = printNull;
    printNull->right = printNull;

    recursiveFormatTree(*(stack+stackPointer), printNull);
}

/* prints the tree recursively */
void printTree(char *filename)
{
    FILE* f = fopen(filename, "w");
    reformatTree();

    /* start printing */
    for (int k=0; k<=treeHeight; k++)
    {
        printNull->level = k;
        recursivePrintValue(f, *(stack+stackPointer), k);
        fprintf(f, "\n");
        for (int i=0; i<power(2, treeHeight-k-1); i++)
        {
            recursivePrintLinks(f, *(stack+stackPointer), i, k);
            fprintf(f, "\n");
        }
    }

    printf("[INFO] [PRINT]\tThe tree was printed successfully in the file \"%s\".\n", filename);
    fclose(f);
}

int main()
{
    char *values;
    int size;
    readExpression(&values, &size);

    initStack(size);
    createTree(values, size);
    printTree("tree.txt");

    return EXIT_SUCCESS;
}
