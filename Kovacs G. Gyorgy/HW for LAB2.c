#include <stdio.h>

typedef struct NODETYPE{
    int key;
    struct NODE *next;
}NODE;

NODE *first;
NODE *last;

void init(){
    first = (NODE*) malloc(sizeof(NODE));
    last = (NODE*) malloc(sizeof(NODE));
    first->key = 1337;
    first->next = last;
    last->key = -1337;
    last->next = NULL;
}

void add(int x){
    NODE *temp1 = (NODE*) malloc(sizeof(NODE));
    temp1->key = x;
    temp1->next = first;

    //Switch(first,temp1)
    NODE *temp2 = (NODE*) malloc(sizeof(NODE));
    temp2 = temp1;
    temp1 = first;
    first = temp2;
}

void out(){
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp = first;
    int i = 0;
    while(temp->next != NULL){
        printf("[%d] = %d\n",i++,temp->key);
        temp = temp->next;
    }
    printf("[%d] = %d\n\n\n",i++,temp->key);
}

int main(){
    init();
    add(80085);
    out();
    printf("Hello World!");
    return 0;
}
