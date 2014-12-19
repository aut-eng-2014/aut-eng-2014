#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "queue.h"
#include "stack.h"
#include <string.h>
#include <conio.h>

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

/* creates the adjacency matrix with specified size */
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

/* performs Breadth First Search and prints output to stdin */
void graph_BFS(char start_node)
{
    static char* found;
    if (found == NULL)
    {
        found = (char*) calloc(strlen(nodes), sizeof(char));
        printf("BFS: ");
    }

    printf("%c", start_node);
    *(found+start_node-'A')=1;

    char running=1;
    while (running)
    {
        running=0;
        for (int i=0; i<strlen(nodes); i++)
        {
            if (*(found+i) == 0)
            {
                running=1;
                if (start_node == -1)
                {
                    start_node = i+'A';
                    *(found+i)=1;
                    printf("%c", i+'A');
                }
                break;
            }
        }

        for (int i=0; i<strlen(nodes); i++)
        {
            if ((*(found+i) == 0) && (*(*(adj_matrix+start_node-'A')+i) == 1))
            {
                queue_push(nodes+i);
                *(found+i)=1;
                printf("%c", i+'A');
            }
        }

        char* val = (char*) queue_pop();
        if (val != NULL)
        {
            start_node = *val;
        }
        else
        {
            start_node = -1;
        }
    }
    printf("\n");
}

/* performs Depth First Search and prints output to stdin */
void graph_DFS(char start_node)
{
    static char* found;
    if (found == NULL)
    {
        found = (char*) calloc(strlen(nodes), sizeof(char));
        printf("DFS: ");
    }

    printf("%c", start_node);
    *(found+start_node-'A')=1;
    stack_push(nodes+start_node-'A');

    char running=1;
    while (running)
    {
        running=0;
        for (int i=0; i<strlen(nodes); i++)
        {
            if (*(found+i) == 0)
            {
                running=1;
                if (start_node == -1)
                {
                    start_node = i+'A';
                    *(found+i)=1;
                    printf("%c", i+'A');
                }
                break;
            }
        }

        for (int i=0; i<strlen(nodes); i++)
        {
            if ((*(found+i) == 0) && (*(*(adj_matrix+start_node-'A')+i) == 1))
            {
                stack_push(nodes+i);
                *(found+i)=1;
                printf("%c", i+'A');
                start_node = i+'A';
                i=-1;
            }
        }
        char* val = (char*) stack_pop();
        if (val != NULL)
        {
            start_node = *val;
        }
        else
        {
            start_node = -1;
        }
    }
    printf("\n");
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

    read_adj_matrix("adj_matrix.in");
    graph_BFS(start_node);
    graph_DFS(start_node);

    return 0;
}
