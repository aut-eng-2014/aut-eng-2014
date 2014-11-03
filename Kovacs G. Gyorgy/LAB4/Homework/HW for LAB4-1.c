/*
4.6.1
Read a mathematical expression, in postfix form, as a character string, from a text file input. The allowed operators
are the usual binary additive (+, -), multiplicative (*, /), and unary sign change (+, -). Build the tree for that
expression. Every node should contain either an operator or an operand. A missing operand (for unary operators)
is signaled by a # character in the input. Operands can be arbitrary alphabetic strings. .
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
    struct StackNode *prev; // in my mind, it is prev
} StackNode;

typedef struct{
    int value;
    int level; // The level of the value, as in the height from the root, so to say (root is level 0, first child is 1 etc)
} Map; // This is for the displaying of the tree, the tree's nodes values will populate it, and it is easier to make the tree appear

StackNode *first;

/*
    I need this little get function to get the treenode value, so I don't use: stack->tree->value (it doesn't work!)
*/
int getValue(TreeNode *t){
    return t->value;
}

//========================Stack Related Stuff================================
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

//========================End of Stack Stuff===========================================

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
    Each value from the nodes of the tree, will be saved in m(the value and the level)
    @param Map m[100]: the array wich stores the node info
    @param/return int *l: the length of the array m
    @param int lvl: the current level, or height
    @param TreeNode *t: the tree in question
*/
void populateMap(Map m[100], int *l,int lvl, TreeNode *t){
    if (t != NULL){
        m[*l].value = t->value;
        m[*l].level = lvl;
        (*l)++;
        populateMap(m,l,lvl+1,t->stang);
        populateMap(m,l,lvl+1,t->drept);
    }
}

//Prints a number of spaces.
void printSpace(int a){
    int i;
    for (i = 0; i < a; i++){
        printf(" ");
    }
}

/*
    @param a
    @param b
    @return a^b
*/
int pow(int a, int b){
    if (!b) return 1;
    int i;
    int A = a;
    for (i = 1; i < b; i++){
        a*=A;
    }
    return a;
}

/*
    @return The height of the tree.
*/
void getTreeLevel(int *lvls,int lvl, TreeNode *t){
    if (t != NULL){
        if (lvl > *lvls){
            *lvls = lvl;
        }
        getTreeLevel(lvls,lvl+1,t->stang);
        getTreeLevel(lvls,lvl+1,t->drept);
    }
}

/*
    Appends empty leaves to some leaves.
    In order to save the tree in the array Map m[100], in order to print the nodes correctly, I need to add blank spaces
    to the leaves, that are not at the max height of the tree, so when I print everything, the leaves will have no
    nodes under them.

    TL:DR; Basically its a hack.
*/
void mutilateTree(TreeNode *t, int lvl, int lvls){
    if (t != NULL){
        if (lvl < lvls && (t->stang == NULL || t->drept == NULL)){
            t->stang = leaf((int)' ');
            t->drept = leaf((int)' ');
        }
        mutilateTree(t->stang,lvl+1,lvls);
        mutilateTree(t->drept,lvl+1,lvls);
    }
}

/*
    I hope it is pretty enough.
*/
void printPrettyTree(TreeNode *tree){
    TreeNode *t = tree; // the tree I am about to mutilate
    Map m[100]; // the array of the nodes with the respective heights(levels)
    int mapLength = 0; // the length of the array
    int levels = 0; // the tree height (longest subtree)
    int slevel = 0; // a variable, used in printing the nodes in the right order, it decreases from levels to 0
    int level = 0; // used in the first for loop, that goes throught the levels
    int counter = 0; // used in the second for loop
    getTreeLevel(&levels,0,t); // sets the levels(height of the tree)
    mutilateTree(t,0,levels); // appends empty leaves
    slevel = levels; // remember, slevel goes from levels to 0
    populateMap(m, &mapLength, 0, t); // populates m

    for (level = 0; level <= levels; level++){
        bool first = true; // the first space is different from the rest, if it is the first value from the level, it is trated separately
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

/*
    This builds the tree from the inputfile using stacks(the input is in postfix)
    @param an inputfile!
    @return a tree!
*/
TreeNode *buildTreeFromFile_Postorder(FILE *file){
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
    return t;
}

int main(){
    TreeNode *tree;

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
    return Great_Succes;
}
