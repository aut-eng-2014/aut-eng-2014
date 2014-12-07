#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define INFTY 32000

void Dijkstra(int n, int c[MAXN][MAXN], int start) {

    /*
        n = nr of vertices
        c = cost matrix
        start = starting node
    */
    // allocate memory for vis and dis
	int *vis = (int *)malloc(sizeof(int)*n);
	int *dis = (int *)malloc(sizeof(int)*n);

	int i, j,minn, v = -1;
	for (i = 0; i < n; i++) {
		*(vis + i) = 0;// no edge is in MST
		*(dis + i) = INFTY;// infinity dist
	}
	// distance to first node is obviously 0
	dis[start] = 0;

    for (i = 0; i < n; i++){
		//min = ininity at each loop step
		minn = INFTY;

		for (j = 0; j < n; j++){
			if (*(dis + j) < minn && *(vis + j) != 1){
				minn = *(dis + j);
				v = j;
			}
		}
		// mark v as visited
		*(vis+v) = 1;
        /* if there is a shorter road we replace current
           with that one
        */
		for (j = 0; j < n; j++) {
			if (*(dis + v) + c[v][j] != 0){
                if (*(dis + j) > *(dis + v) + c[v][j]) {
                    *(dis + j) = *(dis + v) + c[v][j];
                }
			}

		}
		printf("\n");
	}
	// print the costs;
	printf("\nthe costs are: ");
	for (i = 0; i < n; i++) {
		printf("%d ", *(dis + i));
	}


}







