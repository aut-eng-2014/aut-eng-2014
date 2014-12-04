#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

typedef int bool;
#define true 1
#define false 0

#define FILL_RATIO 0.8

char** hash_table;
int hash_size = 0;
int table_size = 3;

void createHashTable()
{
    hash_table = (char**) calloc(table_size, sizeof(char*));
}

/* returns true if value is prime, else false */
bool isPrime(int value)
{
    bool result = true;
    if(value == 2)
    {
        return result;
    }

    if(value%2 == 0 || value <= 1)
    {
        result = false;
    }
    else
    {
        for(int i=3; i<=sqrt(value); i+=2)
        {
            if(value%i == 0)
            {
                result = false;
            }
        }
    }
    return result;
}

/* returns the next prime after value */
int getNextPrime(int value)
{
    value++;
    if (value%2==0)
    {
        value++;
    }
    while(!isPrime(value))
    {
        value+=2;
    }
    return value;
}

/* resizes hash table if it is full above FILL_RATIO */
void resizeHashTable()
{
    if ((int)(table_size*FILL_RATIO) <= hash_size)
    {
        int new_size = getNextPrime(2 * table_size);
        printf("The table is being resized from [%d] to [%d]\n", table_size, new_size);
        hash_table = (char**) realloc(hash_table, new_size * sizeof(char*));
        for (int i=table_size; i<new_size; i++)
        {
            *(hash_table+i) = 0;
        }
        table_size = new_size;
    }
}

/* returns the hash of the string */
int hash(char* string)
{
    unsigned long hash = 5381;
    for (int i=0; i<strlen(string); i++)
    {
        hash = ((hash << 5) + hash) + *(string+i);
    }
    return (unsigned int) hash % table_size;
}

/* inserts value and returns the number of collisions detected until value inserted */
int insertValue(char* string)
{
    int collisions = 0;
    int pos = hash(string);
    char* buffer = (char*) calloc(strlen(string)+1, sizeof(char));
    strcpy(buffer, string);
    while (*(hash_table+pos) != NULL)
    {
        collisions++;
        buffer = (char*) realloc(buffer, (strlen(buffer)+2) * sizeof(char));
        *(buffer+strlen(buffer)+1) = 0;
        *(buffer+strlen(buffer)) = *(string+(collisions-1)%strlen(string));
        pos = hash(buffer);
    }
    *(hash_table+pos) = string;
    free(buffer);
    hash_size++;
    resizeHashTable();
    return collisions;
}

/* generates random string of specified length, if length <=0 or langth >100, then it randomisez it */
char* randomString(int length)
{
    if ((length <= 0) || (length > 100))
    {
        length = (int) ((double) rand() / RAND_MAX * 99) + 1;
    }
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char* dest = (char*) calloc(length+1, sizeof(char));
    for (int i=0; i<length; i++)
    {
        int index = (int) ((double) rand() / RAND_MAX * (strlen(charset) - 1));
        *(dest+i) = charset[index];
    }
    return dest;
}

/* prints the hash table to specifien file */
void printHashTable(char* filename)
{
    FILE* f = fopen(filename, "w");
    fprintf(f, "*** Hash Table ***\n");
    for (int i=0; i<table_size; i++)
    {
        if (*(hash_table+i) != NULL)
        {
            fprintf(f, "[%d]: %s\n", i, *(hash_table+i));
        }
        else
        {
            fprintf(f, "[%d]:\n", i);
        }
    }
    fclose(f);
}

int main()
{
    printf("Type numbers of values to insert: ");
    int nr_of_values;
    scanf("%d", &nr_of_values);
    srand(time(NULL));
    createHashTable();
    int max = 0;

    printf("Would you like random string length ? (Y/N)\n");
    char key;
    do
    {
        key = getch();
    }
    while ((toupper(key) != 'Y') && (toupper(key) != 'N'));
    int length = -1;
    if (toupper(key) == 'N')
    {
        printf("Type the length of the strings: ");
        scanf("%d", &length);
    }

    for (int i=0; i<nr_of_values; i++)
    {
        char* string = randomString(length);
        int val = insertValue(string);
        if (max < val)
        {
            max = val;
        }
    }
    printf("The max number of collisions: %d\n", max);
    printf("Save the hash table file ? (Y/N)\n");
    do
    {
        key = getch();
    }
    while ((toupper(key) != 'Y') && (toupper(key) != 'N'));
    if (toupper(key) == 'Y')
    {
        char* buffer = (char*) calloc(1024, sizeof(char));
        printf("Type the name of the file (without extension): ");
        scanf("%s", buffer);
        strcat(buffer, ".txt");
        printHashTable(buffer);
    }
    return 0;
}
