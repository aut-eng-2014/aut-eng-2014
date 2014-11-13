#include <stdio.h>
#include <stdlib.h>

#define MAX 255
#define CHARS 20

typedef enum{false,true} bool;

typedef struct{
    char value[CHARS];
    struct node *next;
} node;

//TODO the first parameter is not needed.
node *insertValue(node *n, char in[CHARS]){
    if(n == NULL){
        n = (node*) malloc(sizeof(node));
        strcpy(n->value,in); //n->value = in;
        n->next = NULL;
    }
    else{
        node *temp = (node*) malloc(sizeof(node));
        strcpy(n->value,in); //temp->value = in;
        temp->next = n;
        n = temp;
    }
    printf("\n%s inserted succesfully.\n",n->value);
    return n;
}

bool hasValue(node *n, char val[CHARS]){
    printf("searching...\n");
    if (n == NULL){
            return false;
    }
    node *t = n;
    while (t->next != NULL){
        if (!strcmp(val,t->value)) return true;
        t = t->next;
    }
    if (!strcmp(val,t->value)) return true;
}

int hashFunction(char a[CHARS]){
    return (int)a[0];
}

void clearTable(node *t[MAX]){
    int i;
    for (i = 0; i < MAX; i++){
        t[i] = NULL;
    }
}

void printList(node *n){
    if (n == NULL){
        printf("NULL\n");
    }
    else{
        node *t = n;
        while (t->next != NULL){
            printf("%s ",t->value);
            t = t->next;
        }
        printf("%s \n",t->value);
    }
}

int main(){
    node *Table[MAX];
    clearTable(Table);
    char in;
    char input[CHARS];
    int i;
    while(1){
        printf("(I)nsert\n(S)earch\n(L)ist all\n\n");
        printf(" > ");
        scanf("%d",&in);

        switch(in){
            case 1:
            printf("\tInserting: \n");
            printf("\t > "); scanf("%s",input);
            Table[hashFunction(input)] = insertValue(Table[hashFunction(input)],input);
            break;
            case 2:
            printf("\tSearching value: \n");
            printf("\t > "); scanf("%s", &input);
            if (hasValue(Table[hashFunction(input)],input)){
                printf("%s is in the table!\n",input);
            }
            else{
                printf("%s is not in the table!\n",input);
            }
            break;
            case 3:
                for (i = 0; i < MAX; i++){
                    printf("[%d] ",i);
                    printList(Table[i]);
                }
            break;
            default: break; return;
        }
        printf("_______________________________________________________\n");
    }
}
