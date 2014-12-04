#include <stdio.h>
#include <stdlib.h>
#define INF 9999

void Function(int **graph,int n)
{
    int i,j,ok;
    int node1,node2;
    int visited[n],k;
    int totalcost=0,minimum;
    for(i=0;i<n;i++)
    {
        /** no nodes are visited at the beginning **/
        visited[i]=0;

        /** if there is no edge from a node to another
            the weight is infinity (=9999) **/
        for(j=0;j<n;j++)
        {
            if(graph[i][j]==0)
            {
                graph[i][j]=INF;
            }
        }
    }
    /** the first node is marked as visited **/
    visited[0]=1;

    /** number of nodes visited **/
    k=1;

    /** while there still are nodes to be visited **/
    while (k<n)
    {
        for(i=0;i<n;i++)
        {
            /** search for the minimum weight of an edge
                from node i to another non-visited node **/
            ok=0;
            if(visited[i]==1)
            {
                minimum=INF;
                for(j=0;j<n;j++)
                {
                    if(graph[i][j]<minimum && visited[j]==0)
                    {
                        /** minimum found **/
                        minimum=graph[i][j];
                        ok=1;

                        /** memorize the vertices **/
                        node1=i;
                        node2=j;
                    }
                }
            }

            /** if minimum was found **/
            if(ok)
            {
                /** mark the node as visited **/
                visited[node2]=1;

                /** add the cost **/
                totalcost+=minimum;

                printf("\n path (%d->%d) with cost: %d",node1,node2,minimum);

                /** increase the number of nodes visited **/
                k++;

                /** the edge was used, can't use it anymore **/
                graph[node1][node2]=graph[node2][node1]=INF;
            }
        }
    }

    printf("\nTotal cost= %d",totalcost);

}
int main()
{
    int n,j,i;
    scanf("%d",&n);
    int **a=(int**)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    Function(a,n);
    return 0;
}
