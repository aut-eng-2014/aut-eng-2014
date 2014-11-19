#include "hash.h"
///private:
int hashFunction0(char *c,hashTable *ht)
{
    int n=0,i;
    for (i=0;*(c+i)!='\0';i++)
    {
        n+=*(c+i);
    }
    n=n%(ht->hashTableLenght);
    return n;
}

int hashFunction1(char *c,hashTable *ht)
{
    int n=1,i;
    for (i=0;*(c+i)!='\0';i++)
    {
        n*=*(c+i)+i;///if it overflows, it will overflow the next time, witht the same amount
    }
    n=n%ht->hashTableLenght;
    return n;
}
int hashFunction2(char *c,hashTable *ht)
{
    int n=1,i;
    for (i=0;*(c+i)!='\0';i++)
    {
        if (i%2)
            n+=*(c+i);
        else
            n*=c[i];
    }
    n=n%ht->hashTableLenght;
    return n;
}
int hashFunction3(char *c,hashTable *ht)
{
    int n=0,i;
    for (i=0;c[i]!='\0';i++)
    {
        n+=c[i]*(1+i);
    }
    n=n%ht->hashTableLenght;
    return n;
}
int hashFunction4(char *c,hashTable *ht)
{
    int n=strlen(c),i;
    for (i=1;c[i]!='\0';i++)
    {
        n+=c[i]*i-c[i-1]/10;
    }
    n=n%ht->hashTableLenght;
    return n;
}


int hfunc(char * c,hashTable *ht)
{
    int n;///this suppresses the "control reaches end of non-void function" error
    switch (ht->hFunction)
    {
        case 1:
            n=hashFunction1(c,ht);
            break;
        case 2:
            n=hashFunction2(c,ht);
            break;
        case 3:
            n=hashFunction3(c,ht);
            break;
        case 4:
            n=hashFunction4(c,ht);
            break;
        default:///hopefully only 0
            n=hashFunction0(c,ht);
            break;

    }
    return n;
}
///public:

void htInit(hashTable *ht,int n)
{
    ht->hFunction=0;
    ht->maxHFuction=4;
    ht->hashTableLenght=n;
    ht->h=(hashElement*)malloc(n*sizeof(hashElement));
    int i;
    for (i=0;i<n;i++)
    {
        ht->h[i].first=(stac*)malloc(sizeof(stac));
        ht->h[i].first->next=NULL;
        ht->h[i].last=ht->h[i].first;
        ht->h[i].first->val=NULL;///OK, I admit maybe this is a bit too "Modular"
    }
}

void htChangeHashFuction(hashTable *ht)
{
    if (ht->hFunction<ht->maxHFuction)
        ht->hFunction++;
    else
        ht->hFunction=0;
}

int htGetHashFunctionIndex(hashTable *ht)
{
    return ht->hFunction;
}

char htInsert(hashTable *ht,char * ne)
{
    int n=hfunc(ne,ht);
    return sInsert(&ht->h[n].first,&ht->h[n].last,ne);
}

void htInsertFast(hashTable *ht,char * ne)
{
    int n=hfunc(ne,ht);
    sInsertFast(&ht->h[n].last,ne);
}

int htCheck(hashTable *ht,char * val)
{
    int n=hfunc(val,ht);
    return sCheck(ht->h[n].first,val);
}

int htCheckDensity(hashTable *ht,char * val)
{
    int n=hfunc(val,ht);
    return sLength(ht->h[n].first);
}

int *htCheckDensityAll(hashTable *ht)
{
    int i;
    int *a=(int*)malloc(ht->hashTableLenght*sizeof(int));
    for (i=0;i<ht->hashTableLenght;i++)
    {
        a[i]=sLength(ht->h[i].first);
    }
    return a;
}

double htGetDensity(hashTable * ht)
{
    int i,sum=0;
    for (i=0;i<ht->hashTableLenght;i++)
    {
        if (sLength(ht->h[i].first)!=0)
            sum++;
    }
    return (double)sum/(double)(ht->hashTableLenght);
}

int htGetArrayLength(hashTable *ht)
{
    return ht->hashTableLenght;
}

void htRemoveDuplicates(hashTable *ht)
{
    int i;
    for (i=0;i<ht->hashTableLenght;i++)
    {
        sRemoveDuplicates(ht->h[i].first,&ht->h[i].last);
    }
}

char htRemove(hashTable *ht,char * e)
{
    int n=hfunc(e,ht);
    return sRemove(&ht->h[n].first,e);
}

void htPurge(hashTable* ht)
{
    int i;
    for (i=0;i<ht->hashTableLenght;i++)
    {
        sWipe(&ht->h[i].first);
    }
}

