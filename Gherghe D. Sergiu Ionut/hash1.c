#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 255
#define CHARS 20

typedef enum{false,true} bool;

typedef struct
{
    char value[CHARS];
    struct node *next;
} node;

node *insertValue(node *n, char in[CHARS])
{
    if(n == NULL)
    {
        n = (node*) malloc(sizeof(node));
        strcpy(n->value,in);
        n->next = NULL;
    }
    else
    {
        node *temp = (node*) malloc(sizeof(node));
        strcpy(n->value,in);
        temp->next = n;
        n = temp;
    }
    printf("\n%s inserted succesfully.\n",n->value);
    return n;
}

bool hasValue(node *n, char val[CHARS])
{
    printf("searching...\n");
    if (n == NULL)
    {
        return false;
    }
    node *t = n;
    while (t->next != NULL)
    {
        if (!strcmp(val,t->value))
        {
            return true;
        }
        t = t->next;
    }
    if (!strcmp(val,t->value))
    {
        return true;
    }
}

int hashFunction(char a[CHARS])
{
    return (int)a[0];
}

void clearTable(node *t[MAX])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        t[i] = NULL;
    }
}

void printList(node *n)
{
    if (n == NULL)
    {
    printf("NULL\n");
    }
    else
    {
        node *t = n;
        while (t->next != NULL)
        {
            printf("%s ",t->value);
            t = t->next;
        }
    printf("%s \n",t->value);
    }
}

char *randstring(size_t length)
{
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    char *randomString = NULL;
    int n;
    if (length)
    {
        randomString = malloc(sizeof(char) * (length +1));
        if (randomString)
        {
            for (n=0; n<length; n++)
            {
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }
        randomString[length] = '\0';
        }
    }
    return randomString;
}

int main()
{
    node *Table[MAX];
    clearTable(Table);
    int a[MAX];
    char *str;
    /*char in;
    char input[CHARS];*/
    int i, j;
    double t;
    clock_t t1,t2;
    t1=clock();
    for (j=0;j<MAX;j++)
    {
        a[j]=0;
    }
    for (j=0; j<2000; j++)
    {
        str=randstring(CHARS);
        insertValue(Table[hashFunction(str)], str);
        a[hashFunction(str)]++;
    }
    t2=clock();
    t=(double)(t2-t1);
    printf ("The insertion of 2000 elements took %f seconds.", &t);
    printf ("\n");
    for (j=0; j<MAX; j++)
    {
        printf ("%d ", a[j]);
    }

    /*while(1)
    {
        printf("(I)nsert\n(S)earch\n(L)ist all\n\n");
        printf(" > ");
        scanf("%d",&in);
        switch(in)
        {
            case 1:
                printf("\tInserting: \n");
                printf("\t > "); scanf("%s",input);
                Table[hashFunction(input)] = insertValue(Table[hashFunction(input)],input);
                break;
            case 2:
                printf("\tSearching value: \n");
                printf("\t > "); scanf("%s", &input);
                if (hasValue(Table[hashFunction(input)],input))
                {
                    printf("%s is in the table!\n",input);
                }
                else
                {
                    printf("%s is not in the table!\n",input);
                }
                break;
            case 3:
                for (i = 0; i < MAX; i++)
                {
                    printf("[%d] ",i);
                    printList(Table[i]);
                }
                break;
            default:
                break; return;
        }
        printf("_______________________________________________________\n");
    }*/
}
