#include <stdio.h>

#define MAXDEPTH 5

typedef enum{
    false,
    true
} bool;

typedef struct{
    int value;
    struct TreeNode *stang;
    struct TreeNode *drept;
} TreeNode;

TreeNode *root = NULL;

typedef struct{
    bool print;
    int value;
    struct ListNode *prev;
} ListNode;

ListNode *first;

void printStart(){
    system("CLS");
    system("COLOR A");
    printf("\n\tROBCO INDUSTRIES UNIFIED OPERATING SYSTEM\n\t  COPYRIGHT 2075-2077 ROBCO INDUSTRIES\n\t\t\t-Server 1-\n");
    printf("\t__________________________________________\n");
}

void clearList(){
    free(first);
    first = NULL;
}

void pushToList(int a, bool ex){
    if (first == NULL){
        first->print = ex;
        first->value = a;
        first->prev = NULL;
    }
    else{
        ListNode *tempy = (ListNode*) malloc(sizeof(ListNode));
        tempy->value = a;
        tempy->print = ex;
        tempy->prev = first;
        first = tempy;
    }
}

int lengthOfList(){
    int length = 0;
    ListNode *tempy = first;
    while (tempy->prev != NULL){
        tempy = tempy-> prev;
        length++;
    }
    return length+1;
}

/*
    @returns a lead with the with the value of a
*/
TreeNode *createLeaf(int a){
    TreeNode *tempy = (TreeNode*) malloc(sizeof(TreeNode));
    tempy->value = a;
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
        return;
    }
    else{
        short level = 0;
        TreeNode *temp = root;
        while(temp != NULL){
            if (level >= MAXDEPTH){
                printf("\n\t[W]: Input Failed: The maximum depth of the BST was reached! (%d)",MAXDEPTH);
            }

            if (a > temp->value){
                if (temp->drept == NULL){
                    temp->drept = createLeaf(a);
                    return;
                }
                else{
                    temp = temp->drept;
                    level++;
                }
            }
            else if(a < temp->value){
                    if (temp->stang == NULL){
                        temp->stang = createLeaf(a);
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
    if (root == NULL){
        if (printStuff){
            printf("\n\t[W]: Search Failed: The BST has no elements!\n");
        }
        return false;
    }
    else if (root->value == a){
        if (printStuff){
            printf("\n\tNode Found: RootNode");
            if (root->stang != NULL){
                printf(", left node: %d",getValue(root->stang));
            }
            if (root->drept != NULL){
                printf(", right node: %d",getValue(root->drept));
            }
            printf("\n");
        }
        return true;
    }
    else{
        TreeNode *temp = root;
        while(temp != NULL){
            if (a < temp->value){
                if (temp->stang == NULL){
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
                if (temp->drept == NULL){
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
                    printf("\n\tNode Found");
                    if (temp->stang != NULL){
                        printf(", left node: %d",getValue(temp->stang));
                    }
                    if (temp->drept != NULL){
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
    if (t != NULL){
        if (lvl > *d){
            *d = lvl;
        }
        getDepth(t->stang,d,lvl+1);
        getDepth(t->drept,d,lvl+1);
    }
}

/*
    This needs some major fixing.
*/
void doTheThing(int lvl, int curnt, TreeNode *t){
    if (t != NULL){
        if (curnt == lvl){
            pushToList(t->value,true);
        }
        doTheThing(lvl, curnt+1, t->stang);
        if (lengthOfList() < pow(2,curnt)){
                pushToList(0,true);
        }
        doTheThing(lvl, curnt+1, t->drept);
        if (lengthOfList() < pow(2,curnt)){
            pushToList(0,true);
        }
        int depth = 0;
        getDepth(root,&depth,0);
        if (lengthOfList() == pow(2,depth)){
            return;
        }
    }
}

void printList(){
    if (first == NULL){
        printf("The list is empty.");
        return;
    }
    printf("Printing list: \n");
    ListNode *tempy = first;
    while (tempy->prev != NULL){
        printf("%d ",tempy->value);
    }
    printf("%d\n",tempy->value);
}

void insertLevelFromBST(int lvl){
    clearList();
    doTheThing(lvl,0,root);
}

/*
    I hope it is pretty enough.
*/
void printPrettyTree(){
    if (root == NULL){
        printf("\n\t[W]: Tree is empty.\n");
        return;
    }
    printf("\nPrinting Pretty Tree: \n");
    int counter;
    int depth = 0;
    printf("Getting depth...\n");
    getDepth(root,&depth,0);
    for (counter = 0; counter < depth+1; counter++){
        printf("counter [%d]\n",counter);
        insertLevelFromBST(counter);
        printList();
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

