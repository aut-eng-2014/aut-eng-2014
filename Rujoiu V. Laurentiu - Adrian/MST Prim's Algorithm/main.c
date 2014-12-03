#include <stdio.h>
#include <stdlib.h>

#define V 2

int minKey(int key[])
{
   int min_index,v,min;

   for (v = 0; v < V; v++)
     if (key[v] < min)
         min = min_index = v;

   return min_index;
}

int printMST(int parent[], int n, int graph[V][V])
{
   int i;
   printf("Edge   Weight\n");
   for (i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
     int parent[V],i,j,v,max,key[V];

     for (i = 0; i < V; i++)
        key[i] = max;

     key[0] = 0;
     parent[0] = -1;

     for (j = 0; j < V-1; j++)
     {
        int u = minKey(key);
        for (v = 0; v < V; v++)
          if (graph[u][v] && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
     printMST(parent, V, graph);
}

int main()
{
    int graph[V][V],i,j;
    printf("Enter the graph:");
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    primMST(graph);
    return 0;
}
