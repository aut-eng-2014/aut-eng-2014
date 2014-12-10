#include <stdio.h>
#include <stdlib.h>

#define MAXN 10

void prim(int v, int c[MAXN][MAXN], int e[MAXN][2], int cost) {

	/*
	v= number of vertices
	c = cost matrix
	e = edges of MST
	cost = cost of MST
	*/
	int T[MAXN];
	/*
	T[i] = 0 i f i is in the MST;
	T[i] = j if i is not in the MST;
	j is a node of the tree such that(i, j)  is a minimum cost edge * /
	*/
	int i, j, k, min,l = 0;
	//total cost initially 0
	cost = 0;
	for (i = 0; i < v; i++) {
		T[i] = 1;// no edge is in MST
	}
	T[0] = 0;// index is in MST
	for (i = 0; i <  v - 1 ; i++) {
		//initialize min at each iteration
		min = 99999;
		// we go over each node`s neighbours
		for (k = i+1 ; k < v; k++) {
			if (T[k] != 0) {

				if (c[i][k] < min && c[i][k] != 0) {
					j = k;
					min = c[i][k];
				}
			}
		}
		// we memorise each vertice in order of aparition
		e[l][0] = i;
		e[l][1] = j;
		l++;
		// we compute total cost
		cost += min;
		// mark i as visited
		T[i] = 0;
	}

	printf("\n\nedges of MTS are: ");
	for (i = 0; i < l; i++){
		printf( "%d-%d ", e[i][0], e[i][1]);
	}
	printf("\n\ncost is: %d", cost);
	printf("\n");
}



