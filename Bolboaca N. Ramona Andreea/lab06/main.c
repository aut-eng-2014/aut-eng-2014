#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/** The maximum number of keys **/
#define MAX 101

/** The maximum number of characters of an element **/
#define CHARS 20

/** The values of the mod for the hash functions **/
#define B1 101
#define B2 53

typedef enum{false,true} bool;

typedef struct
{
    char value[CHARS];
    struct node *next;
}node;


/**Function to create a random string**/
char *mkrndstr(size_t length)
{
    static char charset[]="abcdefghijklmnopqrstuvwxyz";
    char *randomString;
    int n;
    if (length)
    {
        randomString=malloc(length +1);
        if (randomString)
        {
            int l=(int)(sizeof(charset) -1);
            int key;
            for (n=0;n<length;n++)
            {
                key=rand()%l;
                randomString[n]=charset[key];
            }
        randomString[length] = '\0';
        }
    }
    return randomString;
}


/** Inserts a value at the key of the node 'n' **/
node *insertValue(node *n, char in[CHARS])
{
    node *temp=(node*)malloc(sizeof(node));

    if (n==NULL)
    {
        n=(node*) malloc(sizeof(node));
        /** instead of 'n->value=in' **/
        strcpy(n->value,in);
        n->next = NULL;
    }
    else
    {
        /** instead of 'temp->value=in' **/
        strcpy(temp->value,in);
        temp->next = n;
        n = temp;
    }
    return n;
}


/** Searches the character string 'val' in
    the list with the key of the node 'n'**/
/** The function returns 'false' if the character string
    vas not found, and 'true' if it was found **/
bool hasValue(node *n, char val[CHARS])
{
    if (n==NULL)
    {
        return false;
    }
    node *t=n;
    while (t->next!=NULL)
    {
        if (strcmp(val,t->value)==0)
        {
            return true;
        }
        t=t->next;
    }
    if (strcmp(val,t->value)==0)
    {
        return true;
    }
    return false;
}


/** The hash function 1**/
int hashFunction1(char key[CHARS])
{
    int i,sum;
    sum=0;
    for (i=0;i<strlen(key);i++)
        sum+=key[i];
    return (sum%B1);
}

/** The hash function 2**/
int hashFunction2(char key[CHARS])
{
    int i,sum;
    sum=0;
    for (i=0;i<strlen(key);i++)
        sum+=key[i];
    return (sum%B2);
}


/** Initialize the table**/
void clearTable(node *t[MAX])
{
    int i;
    for (i=0;i<MAX;i++)
    {
        t[i]=NULL;
    }
}


/** Counts the elements of the list
    with the key of the node 'n' **/
int countElements(node *n)
{
    int nr=0;
    if (n==NULL)
    {
        return 0;
    }
    else
    {
        node *t=n;
        while (t->next!=NULL)
        {
            nr++;
            t=t->next;
        }
        nr++;
    }
    return nr;
}


/** Prints the hash table with its elements **/
void printList(node *n)
{
    if (n==NULL)
    {
        printf("NULL\n");
    }
    else
    {
        node *t=n;
        while (t->next!=NULL)
        {
            printf("%s ",t->value);
            t=t->next;
        }
        printf("%s\n",t->value);
    }
}
int main()
{
    /** Variables to measure the time **/
    double start,finish;

    node *Table[MAX];
    clearTable(Table);
    char input[CHARS];

    int j,k,i,x;

    /** For Hash function 1, dispersion and time for inserting the elements**/
    start=clock();
    for(k=1;k<=200;k++)
        for(j=1;j<=10;j++)
        {
            strcpy(input,mkrndstr(j));
            x=hashFunction1(input);
            if (hasValue(Table[x],input))
            {
                /**printf("%s is in the table!\n",input);**/
            }
            else
            {
                    Table[x] = insertValue(Table[x],input);
            }
        }
    finish=clock();
    printf("\nThe time (in seconds) for 1st function=%lf \n",(finish-start)/CLOCKS_PER_SEC);

    printf("\nDispersion for 1st function:\n");
    for (i=0;i<MAX;i++)
    {
        printf("[%d]: %d \n",i,countElements(Table[i]));
    }


    /** For Hash function 2, dispersion and time for inserting the elements**/
    clearTable(Table);
    start=clock();
    for(k=1;k<=200;k++)
        for(j=1;j<=10;j++)
        {
            strcpy(input,mkrndstr(j));
            x=hashFunction2(input);
            if (hasValue(Table[x],input))
            {
                /**printf("%s is in the table!\n",input);**/
            }
            else
            {
                    Table[x] = insertValue(Table[x],input);
            }
        }
    finish=clock();
    printf("\nThe time (in seconds) for 2nd function=%lf \n",(finish-start)/CLOCKS_PER_SEC);
    printf("\nDispersion for 2nd function:\n");
    for (i=0;i<MAX;i++)
    {
        printf("[%d]: %d \n",i,countElements(Table[i]));
    }


    /**
    node *Table[MAX];
    clearTable(Table);
    char input[CHARS];
    int in=-1;
    int i;
    while(in!=0)
    {
        printf("(1)Insert\n(2)Search\n(3)Count all\n(4)List all\n(0)Escape\n\n");
        printf(" > ");
        scanf("%d",&in);
        switch(in)
        {
            case 1:
                printf("\tInserting: \n");
                printf("\t > ");
                scanf("%s",input);
                if (hasValue(Table[hashFunction1(input)],input))
                {
                    printf("%s is in the table!\n",input);
                }
                else
                {
                    Table[hashFunction1(input)] = insertValue(Table[hashFunction1(input)],input);
                }
                break;
            case 2:
                printf("\tSearching value: \n");
                printf("\t > ");
                scanf("%s", &input);
                if (hasValue(Table[hashFunction1(input)],input))
                {
                    printf("%s is in the table!\n",input);
                }
                else
                {
                    printf("%s is not in the table!\n",input);
                }
                break;
            case 4:
                for (i = 0; i < MAX; i++)
                {
                    printf("[%d] ",i);
                    printList(Table[i]);
                }
                break;
            case 3:
                for (i = 0; i < MAX; i++)
                {
                    printf("\n[%d]: %d ",i, countElements(Table[i]));
                }
                break;
        }
        printf("_______________________________________________________\n");
    }
    **/
    return 0;
}
