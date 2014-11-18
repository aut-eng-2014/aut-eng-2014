#include <stdio.h>
#include <stdlib.h>

#define MAX 32000
#define CHARS 20

typedef enum{false,true} bool;
typedef enum{noob,easy,hard,OMGWTFBBQ} Level;

typedef struct{
    char value[CHARS];
    struct node *next;
} node;

//weird, I know; but it works!
node *insertValue(node *n, char in[CHARS]){
    if(n == NULL){
        n = (node*) malloc(sizeof(node));
        strcpy(n->value,in); //n->value = in;
        n->next = NULL;
    }
    else{
        node *temp = (node*) malloc(sizeof(node));
        strcpy(temp->value,in); //temp->value = in;
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

/*
    Simplest hash function.
    Returns the integer value of the first character.
*/
int hashFunction_1(char a[CHARS]){
    return (int)a[0];
}

/*
    A bit better hash function.
    MOD the sum of the characters with 701(yes it's a prime).
*/
int hashFunction_2(char a[CHARS]){
    int sum = 0;
    int i;
    for (i = 0; i < strlen(a); i++){
        sum += (int)a[i];
    }
    return sum % 701;
}

/*
    Somewhat not bad hash function.
    Hey, people who actually knew what they were doing(probably) wrote these functions.
*/
int hashFunction_3(char a[CHARS]){
    srand(hashFunction_2(a));
    return rand() % MAX;
}

/*
    Let's do eet.
*/
int hashFunction_4(char a[CHARS]){
    srand(hashFunction_3(a));
    int wat = rand() % 7919; // yup, prime
    int magicNr = hashFunction_3("GoOd ") - hashFunction_2("mOrNiNg ") + hashFunction_1("vIeTnAm!!!!!!");
    return wat % rand() + hashFunction_3(a) - hashFunction_2(a) + hashFunction_1(a) + magicNr;
}

void clearTable(node *t[MAX]){
    int i;
    for (i = 0; i < MAX; i++){
        t[i] = NULL;
    }
}

void printList(int i, node *n){

    if (n == NULL){
        //printf("NULL\n");
    }
    else{
        printf("[%d] ",i);
        node *t = n;
        while (t->next != NULL){
            printf("%s ",t->value);
            t = t->next;
        }
        printf("%s \n",t->value);
    }
}

int (*hashF)(char[CHARS]); // The hash function that is invoked.

bool isOk(char a){
    if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' || a == ' ') return true;
    else return false;
}

char randomChar(int a){
    srand(a);
    char dummy = 0;
    while (!isOk(dummy)){
        dummy = (char)(rand() % 256);
    }
    return dummy;
}

void randomString(char a[CHARS]){
    strcpy(a,"");
    int i;
    srand(rand());
    int length = rand() % CHARS;
    for (i = 0; i < length; i++){
        a[i] = randomChar(rand());
    }

}

int lengthOfNode(node *t){
    if (t == NULL) return 0;
    int counter = 1;
    while (t->next != NULL){
        t = t->next;
        counter++;
    }
    return counter;
}

int getLongestThingy(node *t[MAX]){
    int i;
    int localMax = 0;
    for (i = 0; i < MAX; i++){
        if (t[i] != NULL){
            if (lengthOfNode(t[i]) > localMax){
                localMax = lengthOfNode(t[i]);
            }
        }
    }
    return localMax;
}

float getAverageThingy(node *t[MAX]){
    int i;
    int nr = 0;
    int sum = 0;
    for (i = 0; i < MAX; i++){
        if (t[i] != NULL){
            nr++;
            sum += lengthOfNode(t[i]);
        }
    }
    return (float)sum / (float)nr;
}

int main(){
    node *Table[MAX];
    clearTable(Table);
    char in;
    char input[CHARS];
    int i,j;
    Level level;

    hashF = &hashFunction_1;

    char a[CHARS] = "NULL";

    while(1){
        printf("1. Insert\n2. Search\n3. List all\n4. Hash Function\n5. Fill With Random Strings\n6. Clear Table\nOther: Exit\n\n");
        printf(" > ");
        scanf("%d",&in);

        switch(in){
            case 1:
            printf("\tInserting: \n");
            printf("\t > "); scanf("%s",input);
            Table[hashF(input)] = insertValue(Table[hashF(input)],input);
            break;
            case 2:
            printf("\tSearching value: \n");
            printf("\t > "); scanf("%s", &input);
            if (hasValue(Table[hashF(input)],input)){
                printf("%s is in the table!\n",input);
            }
            else{
                printf("%s is not in the table!\n",input);
            }
            break;
            case 3:
                for (i = 0; i < MAX; i++){
                    printList(i,Table[i]);
                }
            break;
            case 4:
                printf("\tLevel of hashing: (1,2,3,4)\n");
                printf("\tLevel < "); scanf("%d",&i);
                switch(i){
                    case 1: hashF = &hashFunction_1; break;
                    case 2: hashF = &hashFunction_2; break;
                    case 3: hashF = &hashFunction_3; break;
                    case 4: hashF = &hashFunction_4; break;
                    default: printf("\t[E]:Not a valid input!\n"); break;
                }
            break;
            case 5:
                printf("\tTesting: \nHow many elements to add? ");
                scanf("%d",&i);
                for (j = 0; j < i; j++){
                    randomString(a);
                    Table[hashF(a)] = insertValue(Table[hashF(a)],a);
                }
                printf("\n\tLongest thingy: %d\n",getLongestThingy(Table));
                printf("\tAverage thingy: %f\n\n",getAverageThingy(Table));
            break;
            case 6:
                printf("Clearing Table...");
                clearTable(Table);
                printf("done.\n");
            break;
            default: return; break;
        }
        printf("_______________________________________________________\n");
    }
}
