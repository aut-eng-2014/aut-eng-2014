#include <stdlib.h>
#include <stdio.h>
#include "SnQ.h"
#include "graph.h"

int main() {

	FILE *f;
	f = fopen("graph.txt", "r");
	if (f != NULL)
	{
		int v = 0, i;
		fscanf(f, "%d\n", &v);

		//initialize graph with null
		for (i = 0; i < v; i++){

			graph[i] = NULL;
		}
		int j, val;
		for (i = 0; i<v; i++)
			for (j = 0; j<v; j++)
			{
				fscanf(f, "%d", &val);
				if (val == 1)
					addEdge(i, j);
			}
		//print adjacence lists
		printGraph(v);
		for (i = 0; i < v; i++) {
			reach[i] = 0;
		}
		printf("DFS: ");
		DFS(0);
		for (i = 0; i < v; i++) {
			reach[i] = 0;
		}
		printf("\nBFS: ");
		BFS(0);
	}

	printf("\n");
	return 0;
}
