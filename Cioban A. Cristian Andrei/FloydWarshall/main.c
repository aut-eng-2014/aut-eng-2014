#include "floydwarshall.h"


int main() {

	FILE *f;
	f = fopen("graph.txt", "r");
	if (f != NULL)
	{
		int v ,i , j;
		//number of vertices
		fscanf(f, "%d\n", &v);
		//declare a matrix to hold the costs
		int **graph = (int **)malloc(sizeof(int)*v);
        for(i = 0; i < v; i++){
            graph[i] = (int **)malloc(sizeof(int)*v);
        }
		//read the cost matrix from file
		for (i = 0; i < v; i++)
			for (j = 0; j < v; j++){
				fscanf(f, "%d", &graph[i][j]);
			}
		//prints the matrix
		printf("\nMatrix:\n");
		for (i = 0; i < v; i++)
		{
			for (j = 0; j < v; j++){
				printf("%d ", graph[i][j]);
			}
			printf("\n");
		}
		//call floydWarshall method
		floydWarshall(v, graph);

	}
	printf("\n\n");
	return 0;
}
