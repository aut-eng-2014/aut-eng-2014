#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

#define INFINITY RAND_MAX

short** adj_matrix;
int size;

/* dijkstra */
short* vis;
int* dist;

short src;

/* reads the adjacency matrix with specified size */
void read_adj_matrix(char* file_name)
{
    if (adj_matrix == NULL)
    {
        FILE* f = fopen(file_name, "r");
        fscanf(f, "%d", &size);
        adj_matrix = (short**) malloc(size * sizeof(short*));
        for (int i=0; i<size; i++)
        {
            *(adj_matrix+i) = (short*) malloc(size * sizeof(short));
            for (int j=0; j<size; j++)
            {
                int val;
                fscanf(f, "%d", &val);
                *(*(adj_matrix+i)+j) = val;
            }
        }
        fclose(f);
    }
}

/* reads and returns the starting node position */
short read_start_node()
{
    printf("Insert starting node: ");
    char c = 0;
    while ((c < 65) || (c > 90))
    {
        c = getch();
        if (c > 96)
        {
            c -= 32;
        }
    }
    printf("%c\n", c);
    return c-'A';
}

/* initializes dijkstra minimum distance algorithm */
void init_dijkstra(short val)
{
    for (int i=0; i<size; i++)
    {
        dist[i] = INFINITY;
        vis[i] = 0;
    }

    if (val >= 0)
    {
        src = val;
    }
    else
    {
        src = read_start_node();
    }
    dist[src] = 0;
}

/* returns the node whose distance is minimum and is unvisited */
short current_min_dist_node()
{
    int min = INFINITY;
    short pos = -1;
    for (int i=0; i<size; i++)
    {
        if ((vis[i]==0) && (min>dist[i]))
        {
            min = dist[i];
            pos = i;
        }
    }
    return pos;
}

/* calculates the minimum distances from src to all nodes */
void compute_dijkstra()
{
    for (int i=0; i<size-1; i++)
    {
        short node = current_min_dist_node();
        vis[node] = 1;
        for (int j=0; j<size; j++)
        {
            if ((adj_matrix[node][j]!=0) && (dist[j]>dist[node]+adj_matrix[node][j]))
            {
                dist[j] = dist[node]+adj_matrix[node][j];
            }
        }
    }
}

/* prints the min from src to all nodes in the specified file */
void print_dijkstra(FILE* f)
{
    if (f == stdin)
    {
        static short print = 1;
        if (print)
        {
            fprintf(f, "Minimum distances:\n", src+'A');
            print = 0;
        }
        fprintf(f, "\n");
        for (int i=0; i<size; i++)
        {
            fprintf(f, "%c-%c: %d\n", src+'A', i+'A', dist[i]);
        }
    }
    else
    {
        for (int i=0; i<size; i++)
        {
            fprintf(f, "%d\t",dist[i]);
        }
        fprintf(f, "\n");
    }
}

/* prints the minimum matrix from each node to another in a file */
void print_floyd_warshall(FILE* f)
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            fprintf(f, "%d\t", adj_matrix[i][j]);
        }
        fprintf(f, "\n");
    }
}

/* calculates the minimum distances from every node to every other */
void compute_floyd_warshall()
{
    for (int k=0; k<size-1; k++)
    {
        for (int i=0; i<size; i++)
        {
            for (int j=0; j<size; j++)
            {
                if (((i!=j)||(i!=k)||(j!=k)) && (adj_matrix[i][j]>adj_matrix[i][k]+adj_matrix[k][j]))
                {
                    adj_matrix[i][j]=adj_matrix[i][k]+adj_matrix[k][j];
                }
            }
        }
    }
}

/* initializes floyd-warshall minimum distance algorithm */
void init_floyd_warshall()
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            if ((adj_matrix[i][j]==0) && (i != j))
            {
                adj_matrix[i][j] = INFINITY;
            }
        }
    }
}

int main()
{
    printf("[INFO]\tPlease insert in the file \"adj_matrix.txt\" the adjacency matrix and\n");
    printf("\tpress \'r\' or \'R\' when ready.\n\n");
    char c;
    do
    {
        c = getch();
        c = toupper(c);
    }
    while(c!='R');

    read_adj_matrix("adj_matrix.txt");
    vis = (short*) malloc(size * sizeof(short));
    dist = (int*) malloc(size * sizeof(int));
    FILE *f = fopen("min_dist.txt", "w");

    printf("[INFO]\tMinimum distance from each node to the others was computed using \n");
    printf("\tDIJKSTRA'S algorithm in \"min_dist.txt\"\n\n");
    fprintf(f, "Minimum distance adjacency matrix using dijkstra's algorithm:\n");

    for (int i=0; i<size; i++)
    {
        init_dijkstra(i);
        compute_dijkstra();
        print_dijkstra(f);
    }

    printf("[INFO]\tMinimum distance from each node to the others was computed using the\n");
    printf("\tFLOYD-WARSHALL algorithm in \"min_dist.txt\"\n");
    fprintf(f, "\n\nMinimum distance adjacency matrix using floyd-warshall algorithm:\n");

    init_floyd_warshall();
    compute_floyd_warshall();
    print_floyd_warshall(f);

    fclose(f);
    return EXIT_SUCCESS;
}
