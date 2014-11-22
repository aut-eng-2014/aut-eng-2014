#include "stack.h"

///BFS-Queue, DFS - Stack

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

int main()
{
    stac *s=NULL;
    printf("---Search algorithms in graphs---");
    /**test*/
    /*stPush(&s,2);
    stPush(&s,5);
    stPush(&s,10);
    printf("%d | ",stPop(&s));
    printf("%d | ",stPop(&s));
    printf("%d \n",stPop(&s));

    stPush(&s,2);
    stPush(&s,5);
    stPush(&s,10);
    printf("%d | ",deQ(&s));
    printf("%d | ",deQ(&s));
    printf("%d | ",deQ(&s));

    printf("%d \n",stPop(&s));*/
   // printf("%d|%d|%d",stPop(s),stPop(s),stPop(s));///ot goes inversely
/***tests over*/



/**Fileread*/
    FILE *f;
    f=fopen("matrix.txt","r");
    int n;
    fscanf(f,"%d",&n);

    int i,j;
    int **a=(int**)malloc(n*sizeof(int*));
    for (i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
    }

    int *v=NULL;

    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            fscanf(f,"%d",&a[i][j]);
    fclose(f);

    printf("\nThe matrix is:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            printf("%-3d",a[i][j]);
        printf("\n");
    }
    /***/

    /**BFS with QUeue*/
    v=BFS(a,n,1);
    printf("\nBFS using a queue:\n");
    for (i=0;i<n;i++)
    {
        if (v[i]==0)///fail-safe for graphs, where not all vertices can be reached
            break;
        printf("%d | ",v[i]);
    }
    printf("\n");
    /***/

    /**DSF with recursion*/
    s=NULL;
    char b[n];
    purge(b,n);
    b[0]=1;
    stPush(&s,0);
    DFSrec(a,n,0,b,&s);
    printf("\nDFS using recursion:\n");
    for (i=0;i<n;i++)
    {
        int t=deQ(&s)+1;
        if (t==0)///fail-safe for graphs, where not all vertices can be reached
            break;
        printf("%d | ",t);
    }
    printf("\n");
    ///**//

    /**DFS With Stack*/
    stac *vStack=NULL;
    vStack=DFS(a,n,1);
    printf("\nDFS using a stack:\n");
    for (i=0;i<n;i++)
    {
        int t=deQ(&vStack);
        if (t==-1)///fail-safe for graphs, where not all vertices can be reached
            break;
        printf("%d | ",t);
    }
    printf("\n");
    /***/

    printf("\n");
    return 0;
}
