#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash.h"
/**add ~2000 element
find how many elements has each function
change hash
see dispersion change
calculate insertion time and find time
*/

char * randomString(int maxStringLength)
{
    int l=rand()%maxStringLength;
    char * a=(char*)malloc(l*sizeof(char));
    int i;
    for (i=0;i<l;i++)
    {
        a[i]=rand()%94+32;///32-126 -> i don't like to mess with special characters
    }
    return a;
}

int main()
{
    srand(time(NULL));
    FILE * g=NULL;/// Will be used for graphics, if I finish in time

    hashTable ht;
    int l;
    printf("Please input the desired length of the hash table:\n");
    scanf("%d",&l);
    htInit(&ht,l);
    system("cls");
    int *densityArray=NULL;

    char buff[255];
    char *st;
    char c;
    int cnt=0;
    int i;
    const int RANDOMSTRINGLENGTH=50;
    char **a=NULL;
    clock_t t1,t2;
    printf("Select an option then press enter. Invalid input will be disregarded\n");
    printf("i -> Safe Insert                    |   I -> Quick Insert\n");
    printf("h -> Safe insert random elements    |   H -> Quick insert random elements\n");
    printf("c -> Check existance of value       |   t -> remove duplicaTes\n");
    printf("d -> Density at element    |    a -> density of every element\n");
    printf("e -> Efficiency test for random insertions and searches\n");
    printf("g -> ChanGe Hash Function\n");
    printf("r-> Delete   |   p -> Delete all  |  q -> Quit\n\n");
    while (c!='q')
    {
        printf("->");
        scanf("%c",&c);
        switch (c)
        {
        case 'i':
            printf("Value to insert: \n");
            scanf("%s",buff);
            st=NULL;
            st=malloc((strlen(buff)+1)*sizeof(char));
            strcpy(st,buff);
            htInsert(&ht,st);
            break;
        case 'I':
            printf("Value to insert: \n");
            scanf("%s",buff);
            st=NULL;
            st=malloc((strlen(buff)+1)*sizeof(char));
            strcpy(st,buff);
            htInsertFast(&ht,st);
            break;
        case 'a':
            printf("The percentage of occupied slots in the hash is %.2lf%%\n",htGetDensity(&ht)*100);
            densityArray=htCheckDensityAll(&ht);
            printf("The density for each element, in order:\n");
            g=fopen("values.txt","w");
            if (g==NULL)
                return 0x404;
            for (i=0;i<htGetArrayLength(&ht);i++)
            {
                printf("%4d: %d\n",i,densityArray[i]);
                fprintf(g,"%d ",densityArray[i]);

            }
            fclose(g);
            free(densityArray);
            densityArray=NULL;
            break;
        case 'h':
            printf("Please input the number of random elements to be inserted:\n");
            cnt=0;
            scanf("%d",&cnt);
            t1=clock();
            for (i=0;i<cnt;i++)
            {
                htInsert(&ht,randomString(RANDOMSTRINGLENGTH));
            }
            t2=clock();
            printf("It took %d clock cycles or %.5f seconds\n",(long)(t2-t1),(float)(t2-t1)/CLOCKS_PER_SEC);
            break;
        case 'H':
            printf("Please input the number of random elements to be inserted:\n");
            cnt=0;
            scanf("%d",&cnt);
            t1=clock();
            for (i=0;i<cnt;i++)
            {
                htInsertFast(&ht,randomString(RANDOMSTRINGLENGTH));
            }
            t2=clock();
            printf("It took %d clock cycles or %.5f seconds\n",(long)(t2-t1),(float)(t2-t1)/CLOCKS_PER_SEC);
            break;
        case 'c':
            printf("Value to check: \n");
            scanf("%s",buff);
            st=NULL;
            st=malloc((strlen(buff)+1)*sizeof(char));
            strcpy(st,buff);
            printf("The value does%s%s",(((htCheck(&ht,st)==0)?" not":""))," exist\n");
            break;
        case 'd':
            printf("Value to check density at: \n");
            scanf("%s",buff);
            st=NULL;
            st=malloc((strlen(buff)+1)*sizeof(char));
            strcpy(st,buff);
            printf("The density is: %d\n",htCheckDensity(&ht,st));
            break;
        case 'e':
            printf("Number of random elments to insert and search:\n");
            cnt=0;
            scanf("%d",&cnt);

            a=(char**)malloc(2*cnt*sizeof(char*));
            ///The strings are generated here, so that it doesn't interfere with the test time
            for (i=0;i<cnt;i++)
            {
                a[i]=randomString(RANDOMSTRINGLENGTH);///strings to be inserted
                a[i+cnt]=randomString(RANDOMSTRINGLENGTH);///not-to-be inserted strings for search values
            }

            t1=clock();
            for (i=0;i<cnt;i++)
            {
                htInsertFast(&ht,a[i]);
            }
            t2=clock();
            printf("\nQuick insert took %d clock cycles or %.4lf seconds, with fullness of %.2lf%%\n",(long)(t2-t1),(float)(t2-t1)/CLOCKS_PER_SEC,100*htGetDensity(&ht));

            t1=clock();
            htPurge(&ht);
            t2=clock();
            printf("Purging took took %d clock cycles or %.4lf seconds\n",(long)(t2-t1),(float)(t2-t1)/CLOCKS_PER_SEC);

            t1=clock();
            for (i=0;i<cnt;i++)
            {
                htInsert(&ht,a[i]);
            }
            t2=clock();
            printf("\nSafe insert took %d clock cycles or %.4lf seconds, with fullness of %.2lf%%\n",(long)(t2-t1),(float)(t2-t1)/CLOCKS_PER_SEC,100*htGetDensity(&ht));

            t1=clock();
            for (i=0;i<cnt;i++)
            {
                htCheck(&ht,a[i]);
            }
            t2=clock();
            printf("\nSearching for existing elements took took %d clock cycles or %.4lf seconds,\nwith fullness of %.2lf%%\n",(long)(t2-t1),(float)(t2-t1)/CLOCKS_PER_SEC,100*htGetDensity(&ht));

            t1=clock();
            for (i=cnt;i<cnt*2;i++)
            {
                htCheck(&ht,a[i]);
            }
            t2=clock();
            printf("Searching for non-existant elements took took %d clock cycles or %.4lf seconds, with fullness of %.2lf%%\n",(long)(t2-t1),(float)(t2-t1)/CLOCKS_PER_SEC,100*htGetDensity(&ht));

            t1=clock();
            htPurge(&ht);
            t2=clock();
            printf("\nPurging took took %d clock cycles or %.4lf seconds\n",(long)(t2-t1),(float)(t2-t1)/CLOCKS_PER_SEC);
            break;
        case 'g':
            htChangeHashFuction(&ht);
            printf("Cycled to next hash fuction (hash function %d)\n",htGetHashFunctionIndex(&ht));
            break;
        case 't':
            htRemoveDuplicates(&ht);
            break;
        case 'r':
            printf("Element to remove: \n");
            scanf("%s",buff);
            st=NULL;
            st=malloc((strlen(buff)+1)*sizeof(char));
            strcpy(st,buff);
            if (htRemove(&ht,st))
                printf("The element was succesfully deleted\n");
            else
                printf("The element does not exist\n");
            break;
        case 'p':///purge
            htPurge(&ht);
            htInit(&ht,l);
            break;
        case 'q':
            htPurge(&ht);
            break;
        }
    }
    return 0;
}
