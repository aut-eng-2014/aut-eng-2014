#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void mstPrim(int V, int graph[V][V], int r)
{
    int key[V]; /* cost to reach each vertex from the vertex i am in; updates each time */
    int parent[V]; /* parents for each node */
    int A[V][V]; /* the actual MST, holds edges in a matrix A; if A[i][j]==1 then there is an edge between i and j */
    int Q[V]; /* queue with all the vertices in the graph */

    /* init the matrix A with 0. at first, no edges in the MST */
    int i,j;
    for (i=0; i<V; i++)
        for (j=0; j<V; j++)
            A[i][j]=0;

    /*  init key with inf
        and parent with NULL */
    for (i=0; i<V; i++)
    {
        key[i]=INT_MAX; /* int max is taken as inf */
        parent[i]=-1; /* parent = -1 means that parent = null */
    }

    key[r]=0;   /* the key for the start node is 0. no cost to reach the node from where i am starting */
                /* the other keys are inf, until i discover the reachable nodes */

    for (i=0; i<V; i++)
        Q[i]=i; /* put all the vertices in queue */

    int count=V;
    while (count != 0) /* while loop iterates V times */
    {
        /* i have to find the min key, aka the node that can be reached with the minimum cost */
        int min=INT_MAX; /* comparing with maxint (=inf) at first */
        int u=0;
        for (i=0; i<V; i++)
            if ((Q[i]!=-2) && (key[i]<min))
                {min=key[i]; u=i;}
        /* i have found the next node that can be reached with min cost, that is 'u' and the cost to reach it is 'min'
        /* i remove it from the queue */
        Q[u]=-2;
        /* i consider the node N removed from the queue when Q[N] == -2 */

        if (parent[u]!=-1) /* if the node i found, 'u' , has a parent */
            A[u][parent[u]]=1;  /* add the edge between 'u' and the parent of 'u' to the 'A' matrix */
                                /* remember that matrix A stores the edges of MST */

        /* time to update the key and parent vectors for the new node i am in, that is the node 'u' */
        for (i=0; i<V; i++)
            if (graph[u][i]!=0) /* if 'u' is connected to 'i' */
                if ((Q[i]!=-2) && (graph[u][i]<key[i]))
                /* if (the node is not removed) && (the cost to reach the new node is smaller than the value already registered in key) */
                    {                                    /* that is because at first not all nodes are discovered, aka key==inf */
                        parent[i]=u;
                        key[i]=graph[u][i];
                    }
        count--;
    }

    /* print the edges in MST */
    for (i=0; i<V; i++)
        for (j=0; j<V; j++)
            if (A[i][j]==1)
                printf("%d %d\n",i,j);

}


int main()
{


    FILE *pf;
    pf=fopen("graph.txt", "r");
    if (pf!=NULL)
    {
        /* read graph from file */
        int V; /* number of vertices */
        fscanf(pf,"%d\n",&V);
        int graph[V][V];
        int i,j;
        for (i=0; i<V; i++)
            for (j=0; j<V; j++)
                fscanf(pf,"%d ",&graph[i][j]);
        fclose(pf);

        mstPrim(V,graph,0);
    }
    else
        printf("file not found / return");
    return 0;
}
