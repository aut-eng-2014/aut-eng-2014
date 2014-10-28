#include <stdio.h>

#define Great_Succes 0

typedef enum BOOL{
	false,
	true
} bool; // I like to be able to use bool

typedef struct NODETYPE{
	int key;
	struct NODE *next;
	struct NODE *prev;
} NODE; // This is the List type

typedef struct COPAC{
    int value; // The character as an int, as an ASCII code.
    struct TreeNode *stang; // STANG and DREPT have the same length, and that's awesome.
    struct TreeNode *drept; // bonus: VALUE has the same length as STANG and DREPT. WIN!
} TreeNode;

//=================================================================LIST=============================================================
NODE *header; //This stores the number of elements, it is not an element.

/*
    Initializes the List.
*/
void ListInit(){
    header = (NODE*) malloc(sizeof(NODE));

    header->key = 0;
    header->next = NULL;
    header->prev = NULL;
}

/*
    @return the length of the list(excluding the header).
*/
int ListLength(){
    return header->key;
}

/*
    Adds the first element to the list.
*/
void ListAddFirstElement(int a){
    NODE *headerNext = (NODE*) malloc(sizeof(NODE));

    if (!header->key){
        header->key = header->key + 1;
        header->next = headerNext;

        headerNext->key = a;
        headerNext->next = NULL;
        headerNext->prev = header;
    }
    else{
        NODE *temp = (NODE*) malloc(sizeof(NODE));
        header->key = header->key + 1;
        headerNext = header->next;
        headerNext->prev = temp;

        temp->next = headerNext;
        temp->prev = header;
        temp->key = a;

        header->next = temp;
        header->prev = NULL;
    }
}

/*
    Adds an element at the end of the list.
*/
void ListAddLastElement(int a){
  NODE *temp = (NODE*) malloc(sizeof(NODE));

  if (header->next == NULL){
    temp->key = a;
    temp->next = NULL;
    temp->prev = header;

    header->next = temp;
    header->key = header->key + 1;
  }
  else{
    NODE *last = (NODE*) malloc(sizeof(NODE));
    last = header;
    while (last->next != NULL){
        last = last->next;
    }
    temp->key = a;
    temp->next = NULL;
    temp->prev = last;

    last->next = temp;

    header->key = header->key + 1;
  }
}

/*
    Removes the first element from the list.
*/
void ListRemoveFirstElement(){
    if (header->key){
        NODE *headerNext = (NODE*) malloc(sizeof(NODE));
        headerNext = header->next;

        if (headerNext->next == NULL){
            header->key = 0;
            header->next = NULL;

            headerNext->prev = NULL;
        }
        else{
            NODE *headerNextNext = (NODE*) malloc(sizeof(NODE));
            headerNextNext = headerNext->next;
            headerNextNext->prev = header;

            header->next = headerNextNext;
            header->key = header->key - 1;

        }
    }
    else{
        printf("Cannot remove first element: List is empty!\n\n");
    }
}

/*
    This is getting boring...
*/
NODE *ListRemoveLastElement(){
    if (header->key){
        NODE *last = (NODE*) malloc(sizeof(NODE));
        last = header;
        while (last->next != NULL){
            last = last->next;
        }
        NODE *LAST = last;
        NODE *nextToLast = (NODE*) malloc(sizeof(NODE));
        nextToLast = last->prev;
        nextToLast->next = NULL;

        last->prev = NULL;

        header->key = header->key - 1;
        return LAST->key;
    }
    else{
        printf("Cannot remove last element: List is empty!\n\n");
    }
}

/*
    Prints out the list, the index goes from 1 to n(ListLength())
*/
void ListPrint(){
    if (!ListLength()){
        return;
    }
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp = header->next;
    int counter = 1;
    printf("Printing List Elements: \n");
    while (temp->next != NULL){
        printf("[%d] = %c\n",counter++,temp->key);
        temp = temp->next;
    }
    printf("[%d] = %c\n\n",counter,temp->key);
}

//============================================================LIST=END==============================================================


//================================================================TREE==============================================================

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

/*
    More of some boring prefix tree creation.
*/
TreeNode *initializeTreeFromKeyboard(){
    int input;
    scanf("%d",&input);

    if (input == 35){
        return leaf(35);
    }
    else{
        TreeNode *temporaryRoot = (TreeNode*) malloc(sizeof(TreeNode));
        temporaryRoot->value = input;
        temporaryRoot->stang = initializeTreeFromKeyboard();
        temporaryRoot->drept = initializeTreeFromKeyboard();
        return temporaryRoot;
    }
}

/*
    Prints the tree as a series in prefix form.
*/
void printPreorder(TreeNode *p){
    if (p != NULL){
        printf("%c ",p->value);
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

//============================================================TREE=END==============================================================

void convertToList(TreeNode *t){
    if (t != NULL){
        ListAddFirstElement(t->value);
        convertToList(t->stang);
        convertToList(t->drept);
    }
}

TreeNode *convertToTree(){
    if (!ListLength()){
        return NULL;
    }
    else{
        TreeNode *temp = (TreeNode*) malloc(sizeof(TreeNode));
        int input = ListRemoveLastElement();
        if (input == 35){
            return leaf(35);
        }
        else{
            temp->value = input;
            temp->stang = convertToTree();
            temp->drept = convertToTree();
            return temp;
        }
    }
}

int main(){
    TreeNode *tree1 = initializeTreeFromKeyboard();
    ListInit();
    printf("Converting to List...");
    convertToList(tree1);
    printf("-Done\n\n");
    ListPrint();

    TreeNode *tree2 = NULL;
    printf("Converting to BinaryTree...");
    tree2 = convertToTree();
    printf("-Done\n");
    printf("\nPrefix form: \n");
    printPreorder(tree2);
    printf("\nInfix form: \n");
    printInorder(tree2);

    return Great_Succes;
}
