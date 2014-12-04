#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list.h"
#include <string.h>
#include <conio.h>
#include <time.h>

char* nodes;
char** adj_matrix;

/* create the string with node names with specified size */
void set_nodes(int size)
{
    if (nodes == NULL)
    {
        nodes = (char*) calloc(size+1, sizeof(char));
        for (int i=0; i<size; i++)
        {
            *(nodes+i) = 'A'+i;
        }
    }
}

/* creates the adjacency matrix with specified size */
void create_adj_matrix(int size)
{
    if (adj_matrix == NULL)
    {
        set_nodes(size);
        adj_matrix = (char**) malloc(strlen(nodes) * sizeof(char*));
        printf("Insert the adjacency matrix: \n");
        for (int i=0; i<strlen(nodes); i++)
        {
            *(adj_matrix+i) = (char*) malloc(strlen(nodes) * sizeof(char));
            for (int j=0; j<strlen(nodes); j++)
            {
                int val;
                printf("[%d][%d]: ", i+1, j+1);
                scanf("%d", &val);
                *(*(adj_matrix+i)+j) = val;
            }
        }
    }
}

/* reads the adjacency matrix with specified size */
void read_adj_matrix(char* file_name)
{
    if (adj_matrix == NULL)
    {
        FILE* f = fopen(file_name, "r");
        int size;
        fscanf(f, "%d", &size);
        set_nodes(size);
        adj_matrix = (char**) malloc(strlen(nodes) * sizeof(char*));
        for (int i=0; i<strlen(nodes); i++)
        {
            *(adj_matrix+i) = (char*) malloc(strlen(nodes) * sizeof(char));
            for (int j=0; j<strlen(nodes); j++)
            {
                int val;
                fscanf(f, "%d", &val);
                *(*(adj_matrix+i)+j) = val;
            }
        }
        fclose(f);
    }
}

/* returns information on the minimum edge for the list of vertices, the first vertex, second vertex and the weight */
char* get_min_edge(char** MST_adj_matrix, ListT* vertices)
{
    char* result = (char*) calloc(3, sizeof(char));
    char* temp = (char*) calloc(3, sizeof(char));
    for (int i=0; i<vertices->size; i++)
    {
        *temp = *((char*)list_get(vertices, i+1));
        for (int j=0; j<strlen(nodes); j++)
        {
            if (!(list_contains(vertices, nodes+j)) && (*(*(adj_matrix+*temp-'A')+j) != 0) && (*(*(MST_adj_matrix+*temp-'A')+j) != 1) && ((*(temp+1) == 0) || (*(temp+2) > *(*(adj_matrix+*temp-'A')+j))))
            {
                *(temp+1) = j+'A';
                *(temp+2) = *(*(adj_matrix+*temp-'A')+j);
            }
        }
        /* update result after each vertex search */
        if ((*(temp+2) < *(result+2)) || (*(result+1) == 0))
        {
            *result = *temp;
            *(result+1) = *(temp+1);
            *(result+2) = *(temp+2);
        }
    }
    free(temp);
    return result;
}

/* using prim's algorithm generates the minimum spanning tree in a file */
void generate_MST(char* file_name, char start_node)
{
    char** MST_adj_matrix = (char**) malloc(strlen(nodes) * sizeof(char*));
    for (int i=0; i<strlen(nodes); i++)
    {
        *(MST_adj_matrix+i) = (char*) calloc(strlen(nodes), sizeof(char));
    }

    ListT* vertices = list_header();
    list_add(vertices, nodes+start_node-'A');

    while (vertices->size != strlen(nodes))
    {
        char* result = get_min_edge(MST_adj_matrix, vertices);
        if (*(*(adj_matrix+*result-'A')+*(result+1)-'A') == *(*(adj_matrix+*(result+1)-'A')+*result-'A'))
        {
            *(*(MST_adj_matrix+*(result+1)-'A')+*result-'A') = 1;
        }
        *(*(MST_adj_matrix+*result-'A')+*(result+1)-'A') = 1;
        list_add(vertices, nodes+*(result+1)-'A');
        free(result);
    }

    FILE* f = fopen(file_name, "w");
    for (int i=0; i<strlen(nodes); i++)
    {
        for (int j=0; j<strlen(nodes); j++)
        {
            fprintf(f, "%d ", *(*(MST_adj_matrix+i)+j) *= *(*(adj_matrix+i)+j));
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

int main()
{
    printf("Insert starting node: ");
    char start_node;
    char c = 0;
    while ((c < 65) || (c > 90))
    {
        c = getch();
        if (c > 96)
        {
            c -= 32;
        }
    }
    start_node = c;
    printf("%c\n", start_node);

    clock_t begin = clock();

    read_adj_matrix("adj_matrix.txt");
    generate_MST("MST_adj_matrix.txt", start_node);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Algorithm execution time: %.3f s", time_spent);
    return 0;
}
