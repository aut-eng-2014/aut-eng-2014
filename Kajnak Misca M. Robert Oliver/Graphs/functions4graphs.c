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
    char b[n];///visited bool array
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
    char b[n];///visited bool array
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
    char b[n];
    purge(b,n);

    edgeList *el=(edgeList*)malloc(n*sizeof(edgeList));
    int edgeSequenceIndex=0;
    edgeSequence[edgeSequenceIndex]=se;///Autocomplete FTW
    b[se]=1;
    edgeSequenceIndex++;
    /**"Venit Lumen Glorium"
    "Venit Sancte Spiritus"
}   "Halleluia"*/
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
