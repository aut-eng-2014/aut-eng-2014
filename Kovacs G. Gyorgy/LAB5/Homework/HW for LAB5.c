#include <stdio.h>

#define MAXDEPTH 5

typedef enum{
    false,
    true
} bool;

typedef struct{
    int value;
    int level;
    bool exist;
    struct TreeNode *stang;
    struct TreeNode *drept;
} TreeNode;

TreeNode *root = NULL;

void printStart(){
    system("CLS");
    system("COLOR A");
    printf("\n\tROBCO INDUSTRIES UNIFIED OPERATING SYSTEM\n\t  COPYRIGHT 2075-2077 ROBCO INDUSTRIES\n\t\t\t-Server 1-\n");
    printf("\t__________________________________________\n");
}

/*
    @returns a lead with the with the value of a
*/
TreeNode *createLeaf(int a, int lvl){
    TreeNode *tempy = (TreeNode*) malloc(sizeof(TreeNode));
    tempy->value = a;
    tempy->level = lvl;
    tempy->exist = true;
    tempy->stang = NULL;
    tempy->drept = NULL;
    return tempy;
}

TreeNode *createEmptyLeaf(int lvl){
    TreeNode *tempy = (TreeNode*) malloc(sizeof(TreeNode));
    tempy->value = -13;
    tempy->level = lvl;
    tempy->exist = false;
    tempy->stang = NULL;
    tempy->drept = NULL;
    return tempy;
}

//===============================================

// READ THIS READ THIS READ THIS READ THIS READ THIS READ THIS READ THIS READ THIS VVVVVVV

/*
    I have these, because on my computer when I use something like
    tree->stang->value it gives me an error saying "dereferencing pointer to incomplete type"
    this sollutuion seems to fix the problem. I have no idea why.
*/
int getValue(TreeNode *t){
    return t->value;
}

TreeNode *getLeft(TreeNode *t){
    return t->stang;
}

TreeNode *getRight(TreeNode *t){
    return t->drept;
}

bool getExist(TreeNode *t){
    if (t == NULL){
        return false;
    }
    if (!(t->exist)){
        return false;
    }
    return true;
}

//===============================================

/*
    Adds a new node to the BST.
*/
void addNewNode(int a){
    if (root == NULL){
        root = (TreeNode*) malloc(sizeof(TreeNode));
        root->value = a;
        root->stang = NULL;
        root->drept = NULL;
        root->level = 0;
        root->exist = true;
        return;
    }
    else{
        short level = 1;
        TreeNode *temp = root;
        while(temp != NULL){
            if (level >= MAXDEPTH){
                printf("\n\t[W]: Input Failed: The maximum depth of the BST was reached! (%d)",MAXDEPTH);
            }

            if (a > temp->value){
                if (!getExist(temp->drept)){
                    temp->drept = createLeaf(a,level);
                    return;
                }
                else{
                    temp = temp->drept;
                    level++;
                }
            }
            else if(a < temp->value){
                    if (!getExist(temp->stang)){
                        temp->stang = createLeaf(a,level);
                        return;
                    }
                    else{
                        temp = temp->stang;
                        level++;
                    }
            }
            else{
                printf("\n\t[W]: Input Failed: That value already exists in the BST!\n");
                return;
            }
        }
        printf("\t[E]: Something seriously went wrong, you should never see this message...\n\n");
    }
}

/*
    Checks for a value, if found prints out: Node Found and the children of that node.
    If the value is not found it prints "BST does not contain that value."
    @param printStuff if true prints messages, if false it doesn't
*/
bool findNode(int a, bool printStuff){
    if (!getExist(root)){
        if (printStuff){
            printf("\n\t[W]: Search Failed: The BST has no elements!\n");
        }
        return false;
    }
    else if (root->value == a){
        if (printStuff){
            printf("\n\tNode Found: RootNode");
            if (getExist(root->stang)){
                printf(", left node: %d",getValue(root->stang));
            }
            if (getExist(root->drept)){
                printf(", right node: %d",getValue(root->drept));
            }
            printf("\n");
        }
        return true;
    }
    else{
        TreeNode *temp = root;
        while(getExist(temp)){
            if (a < temp->value){
                if (!getExist(temp->stang)){
                    if (printStuff){
                        printf("\n\tBST does not contain that value.\n");
                    }
                    return false;
                }
                else{
                    temp = temp->stang;
                }
            }
            else if (a > temp->value){
                if (!getExist(temp->drept)){
                    if (printStuff){
                        printf("\n\tBST does not contain that value.\n");
                    }
                    return false;
                }
                else{
                    temp = temp->drept;
                }
            }
            else{
                if (printStuff){
                    printf("\n\tNode Found at Level %d",temp->level);
                    if (getExist(temp->stang)){
                        printf(", left node: %d",getValue(temp->stang));
                    }
                    if (getExist(temp->drept)){
                        printf(", right node: %d",getValue(temp->drept));
                    }
                    printf("\n");
                }
                return true;
            }
        }
    }
}

/*
    Returns the longest branch in d, to get the "depth"
*/
void getDepth(TreeNode *t, int *d, int lvl){
    if (getExist(t)){
        if (lvl > *d){
            *d = lvl;
        }
        getDepth(t->stang,d,lvl+1);
        getDepth(t->drept,d,lvl+1);
    }
}

// It prints spaces.
void printSpaces(int n){
    int i;
    for (i = 0; i < n; i++){
        printf(" ");
    }
}

/*
    @param some value a [0..15]
    @return 2^a
*/
int pow(int a){
    if (!a){
        return 1;
    }
    int i;
    int answer = 2;
    for (i = 0; i < a; i++){
        answer *= 2;
    }
    return answer;
}

/*
    Prnts all elements in a give height in the BST.
*/
void printLevel(TreeNode *t, int lvl, int l, int d){
    if (t != NULL){
        if (t->level == lvl){
            if (t->exist){
                    printf("%d",t->value);
            }
            else{
                printf(" ");
            }
            printSpaces(pow(d-l+1)-1);
        }
        printLevel(t->stang,lvl,l+1,d);
        printLevel(t->drept,lvl,l+1,d);
    }
}

/*
    In order to print the tree the way I want, I have to append some empty leaves,
    they dont have usefull data, only to be used in printing the tree.
*/
void fillTree(TreeNode *t, int l, int dep){
   if (t != NULL){
        if (dep > l){
            if (t->stang == NULL){
                t->stang = createEmptyLeaf(l+1);
            }
            if (t->drept == NULL){
                t->drept = createEmptyLeaf(l+1);
            }
        }
        fillTree(t->stang,l+1,dep);
        fillTree(t->drept,l+1,dep);
   }
}

/*
    I hope it is pretty enough.
*/
void printPrettyTree(){
    if (root == NULL){
        printf("\n\t[W]: Tree is empty!");
    }
    int depth = 0;
    getDepth(root,&depth,0);
    fillTree(root,0,depth);
    int i;
    for (i = 0; i <= depth; i++){
        printf("\t");
        printSpaces(pow(depth-i)-2);
        printLevel(root, i, 0,depth);
        printf("\n");
    }
}

/*
    Every node has a level data with it, and when something is deleted,
    I have to make corrections to the level data of each node.
*/
void refreshTree(TreeNode *t, int lvl){
    if (t != NULL){
        t->level = lvl;
        refreshTree(t->stang,lvl+1);
        refreshTree(t->drept,lvl+1);
    }
}

/*
    Deletes a node with the vaue a.
    This works most of the time, although sometimes, -13's appear out of nowhere... weird.
    I don't know how to reproduce the problem.
*/
void deleteNode(int a){
    if(findNode(a,false)){
        TreeNode *tempy = root;
        TreeNode *temp = tempy; // this will store the parent of tempy
        // get to the node we need, and also store the parent
        while(tempy->value !=  a){
            if (tempy->value > a){
                temp = tempy;
                tempy = tempy->stang;
            }
            else if (tempy->value < a){
                temp = tempy;
                tempy = tempy->drept;
            }
        }
        TreeNode *deadNodeWalking = tempy; // this node will be deleted soon
        TreeNode *surviver = deadNodeWalking; // this is the parent of the deadNodeWalking node
        while (deadNodeWalking->drept != NULL){
            surviver = deadNodeWalking;
            deadNodeWalking = deadNodeWalking->drept;
        }
        if (deadNodeWalking == tempy){
            while(deadNodeWalking->stang != NULL){
                surviver = deadNodeWalking;
                deadNodeWalking = deadNodeWalking->stang;
            }
            if (deadNodeWalking == tempy){
                if (temp == deadNodeWalking){
                    // The only possible explanation, that this is the root!
                    root = NULL;
                    printf("\n\tRoot deleted.\n");
                    return;
                }
                else{
                    if (temp->stang == deadNodeWalking){
                        temp->stang = NULL;
                    }
                    else{
                        temp->drept = NULL;
                    }
                }
                refreshTree(root,0);
                printf("\n\tNode deleted.\n");
                return;
            }
        }
        tempy->value = deadNodeWalking->value;
        if (surviver->stang == deadNodeWalking){
            surviver->stang = NULL;
        }
        else{
            surviver->drept = NULL;
        }
        printf("\n\tNode deleted.\n");
        refreshTree(root,0);
        return;
    }
    else{
        printf("\n\t[W]: Deletion Failed: BST does not contain that value.\n");
    }
}

/*
    The menu and input handling.
*/
void menu(){
    bool notBored = true;
    while(notBored){
        printf("\n\tI. Insert D. Delete F. Find S. Show Q. Quit\n");
        printf("\t> ");
        char input[7] = "";
        gets(input);
        input[0] = tolower(input[0]);
        // I keep leaving out the space when inputting stuff...
        if (input[1] != ' '){
            if (input[0] != 'q' && input[0] != 's'){
                    input[0] = '#';
            }
        }
        // input parameter = atoi(input+2)
        switch(input[0]){
            case 'i': addNewNode(atoi(input+2)); break;
            case 'd': deleteNode(atoi(input+2)); break;
            case 'f': findNode(atoi(input+2),true); break;
            case 's': printPrettyTree(); break;
            case 'q': return; break; //break not needed, but eh, for looks.
            default: printf("\n\t[W]: Invalid Input!\n"); break;
        }
    }
}

int main(){
    printStart();
    menu();
    return 0;
}

