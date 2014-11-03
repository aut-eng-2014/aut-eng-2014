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

typedef struct TREESTACK{
    struct TreeNode *tree; // Basically the value of the node
    struct StackNode *prev;
} StackNode;

typedef struct{
    int value;
    int level;
} Map;

StackNode *first;

int getValue(TreeNode *t){
    return t->value;
}

void initStack(){
    first = NULL;
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


void populateMap(Map m[100], int *l,int lvl, int *lvls, TreeNode *t){
    if (t != NULL){
        m[*l].value = t->value;
        m[*l].level = lvl;
        (*l)++;
        if (lvl > *lvls){
            *lvls = lvl;
        }
        populateMap(m,l,lvl+1,lvls,t->stang);
        populateMap(m,l,lvl+1,lvls,t->drept);
    }
}

void printSpace(int a){
    int i;
    for (i = 0; i < a; i++){
        printf(" ");
    }
}

int pow(int a, int b){
    if (!b) return 1;
    int i;
    int A = a;
    for (i = 1; i < b; i++){
        a*=A;
    }
    return a;
}

void printPrettyTree(TreeNode *t){
    printf("Printig pretty Tree: \n\n");
    Map m[100];
    int mapLength = 0;
    int levels = 0;
    int slevel = 0;
    int level = 0;
    int counter = 0;

    populateMap(m, &mapLength,0 ,&levels,t);
    slevel = levels;

    for (level = 0; level <= levels; level++){
        bool first = true;
        for (counter = 0; counter < mapLength; counter++){
            if (m[counter].level == level){
                if (first){
                    printSpace(pow(2,slevel)-1);
                    first = false;
                }
                else{
                    printSpace(pow(2,slevel+1)-1);
                }
                printf("%c",m[counter].value);
            }

        }
        slevel--;
        printf("\n");
    }
    printf("\n\n\n");
}

TreeNode *buildTreeFromFile_Postorder(FILE *file){
    printf("Building tree...");
    char value = getc(file);
    char scrap = getc(file);
    int input = (int) value;

    initStack();
    TreeNode *tempLeft = NULL;
    TreeNode *tempRight = NULL;
    TreeNode *tempRoot = NULL;

    while (isOK(input)){
        if (isLetter(input)){
                TreeNode *temp = (TreeNode*) malloc(sizeof(TreeNode));
                temp = leaf(input);
                pushToStack(temp);
        }
        else if (isOperator(input)){
            tempLeft = popFromStack();
            tempRight = popFromStack();
            tempRoot = node(input,tempLeft,tempRight);
            pushToStack(tempRoot);
        }
        value = getc(file);
        scrap = getc(file);
        input = (int)value;
    }
    TreeNode *t = popFromStack();
    printf(" -DONE\n");
    return t;
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
    }
    fclose(inputFile);

    printPrettyTree(tree);

    printf("End of program.");
    return Great_Succes;
}
