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

void getDepth(TreeNode *t, int *d, int lvl){
    if (getExist(t)){
        if (lvl > *d){
            *d = lvl;
        }
        getDepth(t->stang,d,lvl+1);
        getDepth(t->drept,d,lvl+1);
    }
}

void printLevel(TreeNode *t, int lvl, int l){
    if (t != NULL){
        if (t->level == lvl){
            if (t->exist){
                    printf("%d ",t->value);
            }
            else{
                printf("H ");
            }
        }
        printLevel(t->stang,lvl,l+1);
        printLevel(t->drept,lvl,l+1);
    }
}

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
    int depth = 0;
    getDepth(root,&depth,0);
    fillTree(root,0,depth);
    int i;
    for (i = 0; i <= depth; i++){
        printLevel(root, i, 0);
        printf("\n");
    }
}

/*
    Deletes a node with the vaue a.
*/
void deleteNode(int a){
    if(findNode(a,false)){
        //TODO deletion
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

