#include <stdio.h>
#include <stdlib.h>

int sizeOfTable=1600;

typedef struct node
{
    char *string;
    struct node *next;
}NodeT;

typedef struct hashTable
{
    int size; /* the size of the table */
    NodeT **table;
}hashTableT;

hashTableT *create(int size)
{
    hashTableT *new_table;

    if (size<1) return NULL; /* invalid size for table */

    /* Attempt to allocate memory for the table structure */
    if ((new_table = malloc(sizeof(hashTableT))) == NULL) {
        return NULL;
    }

    /* Attempt to allocate memory for the table itself */
    if ((new_table->table = malloc(sizeof(NodeT *) * size)) == NULL) {
        return NULL;
    }

    /* Initialize the elements of the table */
    int i;
    for(i=0; i<size; i++) new_table->table[i] = NULL;

    /* Set the table's size */
    new_table->size = size;

    return new_table;
}

int hash (const char* word)
{
    unsigned int hash = 0; int i;

    for (i=0 ; word[i] != '\0' ; i++)
    {
        hash = hash + word[i];
    }
    return hash % sizeOfTable;
}

int hash2 (const char* word)
{
    unsigned int hash2 = 0; int i;

    for (i=0 ; word[i] != '\0' ; i++)
    {
        hash2 = ( hash2<<5 ) - hash2 + word[i];
    }
    return hash2 % sizeOfTable;
}

NodeT *searchString(hashTableT *hashtable, char *str)
{
    NodeT *list;
    unsigned int hashval = hash2(str);

    /*
        Search for the list using the hashval for str. If the string is in the list, then
        return a pointer to that list, else return NULL.
    */

    for(list = hashtable->table[hashval]; list != NULL; list = list->next) {
        if (strcmp(str, list->string) == 0) return list;
    }

    /* the item does not exist, return NULL */
    return NULL;
}

int addString(hashTableT *hashtable, char *str)
{
    NodeT *new_list;
    NodeT *current_list;
    unsigned int hashval = hash2(str);

    /* Attempt to allocate memory for the new list */
    if ((new_list = malloc(sizeof(NodeT))) == NULL) return 1;

    /* Check if the item already exists */
    current_list = searchString(hashtable, str);
    if (current_list != NULL) return 2;

    /* Insert into list */
    new_list->string = str;
    new_list->next = hashtable->table[hashval];
    hashtable->table[hashval] = new_list;

    return 0;
}

char *randstring(int length)
{
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char *randomString;
    if (length > 0)
    {
        randomString = malloc(length+1);
        if (randomString != NULL)
        {
            int n;
            for (n = 0; n < length; n++)
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
    int i,k=0;

    /* Create the table structure for the defined size */
    hashTableT *myTable;
    myTable=create(sizeOfTable);

    /*  Generate random strings (of fixed length=6) and put them in a file words.txt
        Also, adds them to the hashtable */
    FILE *fp;
    fp=fopen("words.txt","w");
    for (i=0; i<2000; i++)
    {
            k++; if (k==10) k=1; /* length of the words is k, in order from 0 to 10 */
            addString(myTable,randstring(k));
            fprintf(fp,randstring(k)); /* The string length is also random, but always with less then 10 characters */
            fprintf(fp," ");
    }
    fclose(fp);

    /* Prints the hashtable for each hashvalue in FILE out.txt */
    fp=fopen("out.txt", "w");
    int max=0,hashvalueMax;
    for (i=0; i<sizeOfTable; i++)
    {
        fprintf(fp,"%d> ", i);
        NodeT *temp=myTable->table[i];
        int k=0; /* Counter for the number of words in this list */

        while (temp!=NULL)
        {
            fprintf(fp,"%s ",temp->string);
            k++;
            temp=temp->next;
        }
        if (k > max)
        {
            max=k;
            hashvalueMax=i; /* Retains the hashvalue for the max length list */
        }
        fprintf(fp,"\n");
    }
    fclose(fp);

    /* Prints the number of collisions and the list with those words */
    printf("\nThe longest list has %d words (collisions)\n", max);
    printf("And is this one: %d> ", hashvalueMax);
        NodeT *temp=myTable->table[hashvalueMax];
        while (temp!=NULL)
        {
            printf("%s ",temp->string);
            temp=temp->next;
        }
    printf("\n");

    return 0;
}
