#include <stdio.h>

typedef enum BOOL{false,true}bool; // I like to be able to use bool

typedef struct NODETYPE{
	int key;
	struct NODE *next;
	struct NODE *prev;
} NODE;

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
    In the homework is says 'count', but I kind of do that,
    of course I could just run a while loop and a counter,
    but I decided to apply a bit of theory taught at the
    course if that's alright.
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
    Removes the first element from the list. What did you expect?
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
void ListRemoveLastElement(){
    if (header->key){
        NODE *last = (NODE*) malloc(sizeof(NODE));
        last = header;
        while (last->next != NULL){
            last = last->next;
        }

        NODE *nextToLast = (NODE*) malloc(sizeof(NODE));
        nextToLast = last->prev;
        nextToLast->next = NULL;

        last->prev = NULL;

        header->key = header->key - 1;
    }
    else{
        printf("Cannot remove last element: List is empty!\n\n");
    }
}

/*
    Sorts the list using the bubble sort algorithm. Sort of.
    @param a boolean, if false the function will sort the list and make it decreasing,
    if @param a is true, the list will be made increasing...
*/
void ListSort_Bubble(bool a){
    if (ListLength() <= 1) return;

    NODE *temp1 = (NODE*) malloc(sizeof(NODE));
    NODE *temp2 = (NODE*) malloc(sizeof(NODE));

    bool sortDatList = true;

    while(sortDatList){
        sortDatList = false;
        temp1 = header->next;
        temp2 = temp1->next;

        // This is meant to replace the for loop, because it was coded differently at first,
        // I could change it back to a for loop if necessary...
        int counter = 0;
        do{
            counter++;
            if (a && (temp1->key > temp2->key) || !a && (temp1->key < temp2->key)){
                int tempInt = temp1->key;
                temp1->key = temp2->key;
                temp2->key = tempInt;
                sortDatList = true;
            }
            temp1 = temp2;
            temp2 = temp2->next;
        }while(counter < ListLength() - 1);
    }
    printf("END OF SORT\n\n");
}

/*
    Prints out the list, the index goes from 1 to n(ListLength())
*/
void ListPrint(){
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp = header->next;
    int counter = 1;
    printf("Printing List Elements: \n");
    while (temp->next != NULL){
        printf("[%d] = %d\n",counter++,temp->key);
        temp = temp->next;
    }
    printf("[%d] = %d\n\n",counter,temp->key);
}

/*
    Search by key... I have no idea what to write, as in I know that the @param k is the
    key of the node, but I have no idea what to return. I decided to have 2 functions, one
    returnes a bool wether or not that element is in our list or not...
*/
bool ListHasElement(int k){
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp = header->next;

    while (temp->next != NULL){
        if (temp->key == k) return true;
        temp=temp->next;
    }
    if (temp->key == k) return true;
    return false;
}

/*
    ...and the other one returns the pointer to the respective node.
*/
NODE *ListElement(int k){
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp = header->next;

    while (temp->next != NULL){
        if (temp->key == k) return temp;
        temp=temp->next;
    }
    if (temp->key == k) return temp;
    return NULL;
}

int main(){
    //Everything worked when I tried it. 100%.
	return 0;
}
