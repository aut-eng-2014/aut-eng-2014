/*
    Problem 4.6.1
    "Read a mathematical expression, in postfix form, as a character string, from a text file input. The allowed operators
    are the usual binary additive (+, -), multiplicative (*, /), and unary sign change (+, -). Build the tree for that
    expression. Every node should contain either an operator or an operand. A missing operand (for unary operators)
    is signaled by a # character in the input. Operands can be arbitrary alphabetic strings. ."
    Working with trees.
*/
#include <stdio.h>

#define Great_Succes 0

typedef enum BOOL{
    false,
    true
} bool;

typedef struct COPAC{
    int value; // The character as an int, as an ASCII code.
    struct TreeNode *stang; // STANG and DREPT have the same length, and that's awesome.
    struct TreeNode *drept; // bonus: VALUE has the same length as STANG and DREPT. WIN!
} TreeNode;

typedef struct STACK{
    struct TreeNode *tree; // Basically the value of the node
    struct StackNode *prev;
} StackNode;

StackNode *first;

int getValue(TreeNode *t){
    return t->value;
}

void initStack(){
    printf("Initializing Stack... ");
    first = NULL;
    printf("- DONE\n");
}

void pushToStack(TreeNode *t){
    if (first == NULL){
        first = (StackNode*) malloc(sizeof(StackNode));
        first->tree = t;
        first->prev = NULL;
    }
    else{
        StackNode *temp = (StackNode*) malloc(sizeof(StackNode));
        temp->tree = t;
        temp->prev = first;
        first = temp;
    }
}

TreeNode *popFromStack(){
    if (first == NULL){
        printf("[ERROR]: Stack: Trying to pop an empty stack!\n\n");
        return NULL;
    }
    else{
        StackNode *temp = first;
        first = first->prev;
        return temp->tree;
    }
}

void printStack(){
    if (first == NULL){
        printf("[Stack]: The stack is empty!");
    }
    else{
        StackNode *temp = (StackNode*) malloc(sizeof(StackNode));
        temp = first;
        printf("[Stack]:[");
        while (temp->prev != NULL){
            printf("%c ",getValue(temp->tree));
            temp = temp->prev;
        }
        printf("%c]\n",getValue(temp->tree));
    }
}

/*
    @param an integer(ASCII code)
    @return a leaf
*/
TreeNode *leaf(int a){
    TreeNode *temp = (TreeNode*) malloc(sizeof(TreeNode));
    temp->value = a;
    temp->stang = NULL;
    temp->drept = NULL;
    return temp;
}

/*
    @param an integer(ASCII code)
    @param a binary tree (branch1)
    @param another binary tree (branch2)
    @return a node made out of those two trees
*/
TreeNode *node(int a, TreeNode *left, TreeNode *right){
    TreeNode *temp = (TreeNode*) malloc(sizeof(TreeNode));
    temp->value = a;
    temp->stang = left;
    temp->drept = right;
    return temp;
}

bool isLetter(char c){
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '#'){
        return true;
    }
    return false;
}

bool isOperator(char c){
    switch(c){
        case '*': return true; break;
        case '/': return true; break;
        case '+': return true; break;
        case '-': return true; break;
        default: return false;
    }
}

/*
    Used in the prefix binary tree creation.
*/
bool isOK(char c){
    if (isOperator(c) || isLetter(c)){
            return true;
    }
    else{
            return false;
    }
}

/*
    More of some boring prefix tree creation.
*/
TreeNode *initializeTreeFromKeyboard(){
    int input;

    scanf("%d",&input);

    if (input == 35){
        return NULL;
    }
    else{
        TreeNode *temporaryRoot = (TreeNode*) malloc(sizeof(TreeNode));
        temporaryRoot->value = input;
        temporaryRoot->stang = initializeTreeFromKeyboard();
        temporaryRoot->drept = initializeTreeFromKeyboard();
        return temporaryRoot;
    }
}

void printPrettyTree(TreeNode *t){
    //TODO make a pretty tree
}

/*
    Prints the tree as a series in prefix form.
*/
void printPreorder(TreeNode *p){
    if (p != NULL){
        printf("%c ",getValue(p));
        printPreorder(p->stang);
        printPreorder(p->drept);
    }
}

/*
    Prints the tree as a series in infix form.
*/
void printInorder(TreeNode *p){
    if(p != NULL){
        printInorder(p->stang);
        printf("%c ",p->value);
        printInorder(p->drept);
    }
}

/*
    Prints the tree as a series in postfix form.
*/
void printPostorder(TreeNode *p){
    if(p != NULL){
        printPostorder(p->stang);
        printPostorder(p->drept);
        printf("%c ",p->value);
    }
}

TreeNode *buildTreeFromFile_Postorder(FILE *file){
    printf("Building tree...\n");
    char value = getc(file);
    char scrap = getc(file);
    int input = (int) value;

    initStack();
    TreeNode *tempLeft = NULL;
    TreeNode *tempRight = NULL;
    TreeNode *tempRoot = NULL;

    while (isOK(input)){
        printf("\nInput: %c \n",input);
        if (isLetter(input)){
                printf("Letter detected, pushing to stack.\n");
                TreeNode *temp = (TreeNode*) malloc(sizeof(TreeNode));
                temp = leaf(input);
                pushToStack(temp);
                printStack();
        }
        else if (isOperator(input)){
            printf("Operator detected.\n");
            tempLeft = popFromStack();
            tempRight = popFromStack();
            tempRoot = node(input,tempLeft,tempRight);
            pushToStack(tempRoot);
            printStack();
        }
        value = getc(file);
        scrap = getc(file);
        input = (int)value;
    }
    TreeNode *t = popFromStack();
    printPreorder(t);
    return t;
}

/*
    Creating a binary tree in prefix form, nothing fancy.
*/
TreeNode *initializeTreeFromFile_Inorder(FILE *file, int level){
    char value;
    char trash;
    value = getc(file);
    trash = getc(file);
    int input = (int)value;

    printf("[lvl %2d] Read value : ",level);

    if (!isOK(input)){
        printf("NULL\n");
        return NULL;
    }
    else{
        printf("%c\n",input);
        TreeNode *temporaryRoot = (TreeNode*) malloc(sizeof(TreeNode));
        temporaryRoot->stang = initializeTreeFromFile_Inorder(file,level+1);
        temporaryRoot->drept = initializeTreeFromFile_Inorder(file,level+1);
        temporaryRoot->value = input;

        return temporaryRoot;
    }
    return NULL;
}

int main(){
    printf("Starting Porgram: \n\n");
    TreeNode *tree;

    //printf("Initializing from File: \n");
    FILE *inputFile = fopen("input.txt","r");
    if (inputFile == NULL){
            printf("FILE == NULL\n");
            printf("Reading from file: FAIL!!\n\n");
    }
    else{
        tree = buildTreeFromFile_Postorder(inputFile);
        printf("Reading from file: Great Succes!\n\n");
    }
    fclose(inputFile);


    printPrettyTree(tree);

    printf("End of program.");
    return Great_Succes;
}
