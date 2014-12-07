#include "dijkstra.h"


int main() {

	FILE *f;
	f = fopen("graph.txt", "r");
	if (f != NULL)
	{
		int v = 0;
		//number of vertices
		fscanf(f, "%d\n", &v);
		//declare a matrix to hold the costs
		int a[MAXN][MAXN];
		//to hold the edges of MTS
		//int edges[MAXN][2];
		int i, j;
		//read the cost matrix from file
		for (i = 0; i < v; i++)
			for (j = 0; j < v; j++){
				fscanf(f, "%d", &a[i][j]);
			}
		//prints the matrix
		printf("\nMatrix:\n");
		for (i = 0; i < v; i++)
		{
			for (j = 0; j < v; j++){
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		//call dijkstra method
		Dijkstra(v, a, 1);

	}
	printf("\n\n");
	return 0;
}
