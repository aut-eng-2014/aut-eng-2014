#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hashtable[100003][10];

int hashfunction(char *s, int i)
{
    int sum, j;
    sum=0;
    int c=strlen(s);
    for (j=0; j<c; j++)
    {
        sum=sum+(int)s[j];
    }
    sum=(sum*i)%100003;
    return sum;
}

char temp[9];

char* random()
{
    int j, run;
    run=rand()%7 + 3;
    for(j=0; j< run ; j++)
    {
        temp[j]= rand()%26+'a';
    }
    temp[run] = '\0';
    return temp;

}

int main()
{
    int i,j, sum=0, insertion, contor, maxim=0;
    char istring[10];
    for(j=0; j<50000; j++)
    {
        insertion=0;
        contor=0;
        i=0;
        strcpy(istring, random());
        while(insertion==0)
        {
            if (strcmp(hashtable[sum],"")==0)
            {
                strcpy(hashtable[sum],istring);
                insertion=1;
            }
            else
            {
                i++;
                contor++;
                sum=hashfunction(istring,i);
            }
        }
        if (maxim<contor)
            maxim=contor;
    }
    printf("Numarul maxim de coliziuni: %d", maxim);
    return 0;
}
