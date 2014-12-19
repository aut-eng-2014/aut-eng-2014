#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

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
		int edges[MAXN][2];
		int i, j, k, cost = 0;
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
		//call the prim method
		prim(v, a, edges, cost);

	}

	printf("\n");
	return 0;
}
