#include "functions4graphs.h"
#include "limits.h"

void purge(char *a,int n)
{
    int i;
    for (i=0;i<n;i++)
        a[i]=0;
}

char isAllVisited(char *a,int n)
{
    int i;
    for (i=0;(i<n)&&(a[i]!=0);i++);
    if ((i==n) && (a[n-1]!=0))
        return 1;
    else
        return 0;
}

int * BFS(int **a,int n,int startNode)
{
    char *b=(char*)malloc(n*sizeof(char));///visited bool array
    purge(b,n);
    int j=startNode-1;
    stac *s=NULL;
    int *v=(int*)malloc(n*sizeof(int));
    int vi;

    int i;
    stPush(&s,j);
    b[j]=1;
    for(vi=0;vi<n;vi++)
    {
        for (i=0;i<n;i++)
        {
            if ((a[j][i]!=0)&& (b[i]==0))
            {
                stPush(&s,i);
                b[i]=1;
            }
        }
        j=deQ(&s);
        v[vi]=j+1;
        if (j==-1)///fail-safe for graphs, where not all vertices can be reached
            return v;
    }
    return v;
}

stac *DFS(int **a,int n,int startNode)
{
    char *b=(char*)malloc(n*sizeof(char));///visited bool array
    purge(b,n);
    int j=startNode-1;
    stac *s=NULL,*v=NULL;
    int i;

    stPush(&s,j);
    while ((!isAllVisited(b,n)) && (j!=-1))
    {
        do
            j=stPop(&s);
        while (b[j]!=0);
        if (j==-1)///fail-safe for graphs, where not all vertices can be reached
            return v;
        b[j]=1;
        stPush(&v,j+1);
        for (i=n-1;i>=0;i--)
        {
            if ((a[j][i]!=0)&& (b[i]==0))
            {
                stPush(&s,i);
                //b[i]=1;
            }
        }
    }
    return v;
}

void DFSrec(int **a,int n, int startNode, char *boolArray,stac ** visitedList)
{
    int i;
    for (i=0;i<n;i++)
        if ((a[startNode][i]!=0) && (boolArray[i]==0))
        {
            boolArray[i]=1;
            stPush(visitedList,i);
            DFSrec(a,n,i,boolArray,visitedList);
        }
}

edgeList* Prims(int * edgeSequence, int ** a, int n, int se)
{
    char *b=(char*)malloc(n*sizeof(char));///visited bool array
    purge(b,n);

    edgeList *el=(edgeList*)malloc(n*sizeof(edgeList));
    int edgeSequenceIndex=0;
    edgeSequence[edgeSequenceIndex]=se;///Autocomplete FTW
    b[se]=1;
    edgeSequenceIndex++;

    while (!isAllVisited(b,n))
    {
        int i;
        int j;
        int locMin=INT_MAX,locMini=INT_MAX;
        for (i=0;i<edgeSequenceIndex;i++ )
        {
            se=edgeSequence[i];
            for (j=0;j<n;j++)
            {
                if (((a[se][j]<locMin)&&a[se][j]>0) && (!b[j]))
                {
                locMin=a[se][j];
                locMini=j;
                }
            }
        }
        el[edgeSequenceIndex].first=se;
        el[edgeSequenceIndex].next=locMini;
        el[edgeSequenceIndex].val=locMin;
        edgeSequence[edgeSequenceIndex]=locMini;
        edgeSequenceIndex++;
        b[locMini]=1;
    }
    return el;
}

int findMinIndex(int *a,char *b,int n)///returns the index if the smallest element
{
    int t=INT_MAX,index=0;

    int j;
    for (j=0;j<n;j++)
    {
        if ((!b[j]) && (a[j]<t))
        {
            t=a[j];
            index=j;
        }
    }
    return index;
}

int* Dijskra(int ** a, int n, int se)
{
    int* da=(int*)malloc(n*sizeof(int));///distancearray
    char *b=(char*)malloc(n*sizeof(char));///"bool" vector for visited elements
    purge(b,n);
    int i,j;///iterators
    for (i=0;i<n;i++)
        da[i]=INT_MAX;
    da[se]=0;

    for (i=0;i<n;i++)
    {
        se=findMinIndex(da,b,n);
        b[se]=1;

        for (j=0;j<n;j++)
        {
            if ((a[se][j]) && (!b[j]) && (da[j]>a[se][j]+da[se]))///is neighbour && not visited && dist smaller than current one
            {
                da[j]=a[se][j]+da[se];
            }
        }
    }

    return da;
}
