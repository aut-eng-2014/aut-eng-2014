#include <stdio.h>
#include <stdio.h>

int n; /* Then number of nodes */
int dist[16][16]; /* dist[i][j] is the length of the edge between i and j if
            it exists, or 0 if it does not */

void printDist() {
    int i, j;
    printf("    ");
    for (i = 0; i < n; ++i)
        printf("%4c", 'A' + i);
    printf("\n");
    for (i = 0; i < n; ++i) {
        printf("%4c", 'A' + i);
        for (j = 0; j < n; ++j)
            printf("%4d", dist[i][j]);
        printf("\n");
    }
    printf("\n");
}
int minim(int dist[], int vis[], int n )
{
    int min, min_index, i;
    for (i = 0; i < n; i++)
        if (vis[i] == 0 && dist[i] <= min)
            {
                min = dist[i];
                min_index = i;
            }
  return min_index;
}

/*
    floyd_warshall()

    after calling this function dist[i][j] will the the minimum distance
    between i and j if it exists (i.e. if there's a path between i and j)
    or 0, otherwise
*/
void floyd_warshall(int n, int dist[n][n]) {
    int i, j, k;
    for (k = 0; k < n; ++k) {
        printDist();
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                /* If i and j are different nodes and if
                    the paths between i and k and between
                    k and j exist, do */
                if ((dist[i][k] * dist[k][j] != 0) && (i != j))
                  {

                    /* See if you can't get a shorter path
                        between i and j by interspacing
                        k somewhere along the current
                        path */
                    if ((dist[i][k] + dist[k][j] < dist[i][j]) ||
                        (dist[i][j] == 0))
                        dist[i][j] = dist[i][k] + dist[k][j];

                      printf("%d goes through %d and then to %d (dist=%d)\n", i,k,j,dist[i][j]);
    }
    printDist();

     printf("\nfloyd warshall, new distance matrix are\n");
   for (i=0; i<n; i++){
       for (j=0; j<n; j++)
               printf("%d ",dist[i][j]); printf("\n"); }
}

int main() {
    FILE *pf;
    pf=fopen("mat.txt", "r");
    int i, j, n;
    fscanf(pf, "%d\n", &n);
    int graph[n][n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            fscanf(pf, "%d", &dist[i][j]);
    fclose(pf);
    floydWarshall(n, graph);

    return 0;
}
}
