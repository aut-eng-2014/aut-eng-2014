#include "stack.h"
#include "functions4graphs.h"
#include "limits.h"

///BFS-Queue, DFS - Stack
///Kruskal
///Floyd Warshaw

int main()
{
    stac *s=NULL;
    printf("---Search algorithms in graphs---");

/**Fileread*/
    FILE *f;
    f=fopen("matrix.txt","r");
    int n;
    fscanf(f,"%d",&n);

    int i,j;
    int **a=(int**)malloc(n*sizeof(int*));
    for (i=0;i<n;i++)
    {
        *(a+i)=(int*)malloc(n*sizeof(int));
    }

    int *v=NULL;

    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            fscanf(f,"%d",&a[i][j]);
    fclose(f);

    printf("\nThe matrix is:\n");
    printf("\n\n    A   B   C   D   E   F   G\n");
    for (i=0;i<n;i++)
    {
        printf("%c ",65+i);
        for (j=0;j<n;j++)
            printf("%3d ",a[i][j]);
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
    char *b=(char*)malloc(n*sizeof(char));
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

    printf("\nPrim's algorithm:\n");
    int *edges=(int*)malloc(n*sizeof(int));
    edgeList* el=Prims(edges,a,n,6);
    for (i=0;i<n;i++)
    {
        printf("%c | ",edges[i]+97);
    }
    printf("\n");
    for (i=1;i<n;i++)
    {
        printf("%c%c=%d| ",el[i].first+97,el[i].next+97,el[i].val);
    }

    /***/
    ///I'm not sure if I understood correcty, but isn't this basically Floyd-Warshaw?
    int *shortestDistanceArray;
    printf("\n\n    A   B   C   D   E   F   G\n");
    for (i=0;i<n;i++)
    {
        printf("%c ",65+i);
        shortestDistanceArray=Dijskra(a,n,i);
        for (j=0;j<n;j++)
        {
            printf("%3d ",shortestDistanceArray[j]);
        }
        printf("\n");
        free(shortestDistanceArray);
        shortestDistanceArray=NULL;

    }
    printf("\n");
    return 0;
}
