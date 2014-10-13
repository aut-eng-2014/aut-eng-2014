#include <stdio.h>

typedef struct NODETYPE{
    int key;
    struct NODE *next;
}NODE;

NODE *first;
NODE *last;

void ListInit(){
    first = (NODE*) malloc(sizeof(NODE));
    last = (NODE*) malloc(sizeof(NODE));
    first->key = 1337;
    first->next = last;
    last->key = -1337;
    last->next = NULL;
}

void ListAddFirstElement(int x){
    NODE *temp1 = (NODE*) malloc(sizeof(NODE));
    temp1->key = x;
    temp1->next = first;

    first = temp1;
}

void ListPrint(){
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp = first;
    int counter = 0;
    while(temp->next != NULL){
        printf("[%d] = %d\n",counter++,temp->key);
        temp = temp->next;
    }
    printf("[%d] = %d\n\n\n",counter,temp->key);
}

int main(){
    ListInit();
    ListAddFirstElement(80085);
    ListAddFirstElement(123);
    ListPrint();
    printf("Hello World!");
    return 0;
}
