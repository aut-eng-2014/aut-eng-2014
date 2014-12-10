#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int NrOfVertices;
char vertices[20];  //stores all the vertices from the file
int matrix[20][20]; //adjacent matrix af the graph

int a[20][2];   //stores the edges of the minimum spanning tree
                //every line is an edge; the 1st column is the 1st vertex of the edge,and the 2nd column is the 2nd vertex of the edge
int NrOfEdges;  //needed for matrix a

void CreateMatrix()
{
    int i,j;
    FILE *f;

    f=fopen("matrix.txt","r");

    if( f == NULL )
   {
      perror("Error while opening the file\n");
      exit(EXIT_FAILURE);
   }

   fscanf(f,"%d\n",&NrOfVertices);
   //printf("%d\n",NrOfVertices);

    for(i=0;i<NrOfVertices;i++)
        {
            fscanf(f,"%c",vertices+i);
            //printf("%c",vertices[i]);
        }
   fscanf(f,"\n");

   for(i=0;i<NrOfVertices;i++)
   {
       for(j=0;j<NrOfVertices;j++)
        {
            fscanf(f,"%d ", &matrix[i][j] );
            //printf("%d",matrix[i][j]);
        }
   fscanf(f,"\n");
   }
   fclose(f);
}

void PrintMatrix()
{
    int i,j;
    printf("   ");
    for(i=0;i<=NrOfVertices;i++)
        printf("  %c",vertices[i]);
    printf("\n");

    for(i=0;i<NrOfVertices;i++)
    {  printf("%c  ",vertices[i]);
         for(j=0;j<NrOfVertices;j++)
            printf("  %d",matrix[i][j]);
        printf("\n");
    }
}

//in the algorithm i will work with the positions of vertices from 'vertices' vector
void PRIM(int FirstPosition)
{
    int key[NrOfVertices];      //stores the minimum cost from the subtree to the vertex
    int parent[NrOfVertices];   //stores the parent of the vertex,according to the key
    int Q[NrOfVertices]; //stores all the vertices
    int i,j;

    for(i=0;i<NrOfVertices;i++)
    {
        key[i]=INT_MAX;     //because I will need the minimum value
        parent[i]=0;
        Q[i]=1;             //if Q[i]=1 the vertex from position i wasn't used for MST
    }
    key[FirstPosition]=0;   //i begin from the vertex on FirstPosition
                            //it's 0 because we won't have a cost less than 0

    int counter=0;
    while(counter<NrOfVertices)
    {
        int u;  //position of the vertex with the minimum cost
        int minimum=INT_MAX;

        for(i=0;i<NrOfVertices;i++)         //looking for the vertex with the minimum cost
        {
            if(Q[i]==1)
            {
                if(key[i]<minimum)
                    {
                        minimum=key[i];
                        u=i;
                    }
            }
        }
        Q[u]=0;

        if(parent[u]!=0)     //the matrix a is constructed if i have both vertices of an edge
        {
            a[NrOfEdges][0]=vertices[u];
            a[NrOfEdges][1]=vertices[parent[u]];
            NrOfEdges++;
        }

        for(i=0;i<NrOfVertices;i++)     //the vertices are updated
        {
            if(matrix[u][i]!=0)  //looking for all the vertices which are adjacent to the vertex u and are stillin Q
            {
                if(Q[i]==1 && matrix[u][i]<key[i])
                {
                    parent[i]=u;
                    key[i]=matrix[u][i];
                }
            }
        }
        counter++;
    }

    printf("\nThe Edges of the minimum spanning tree for Prim's algorithm are\n");
    for(i=0;i<NrOfEdges;i++)
        {
            printf("(");
            for(j=0;j<2;j++)
            {
                printf("%c",a[i][j]);
            }
        printf(") ");
        }

}

int main()
{
    int i;
    CreateMatrix();
    printf("The number of vertices is %d\n\n",NrOfVertices);
    printf("The adjacency matrix is:\n");
    PrintMatrix();

    char FirstVertex;   //the vertex from where the minimum spanning tree begins
    printf("\nInput the vertex from which you want to start the Minimum Spanning Tree\n");
    scanf("%c",&FirstVertex);
    //printf("%c\n",FirstVertex);

    int position;   //to obtain the position of the FirstVertex from the vector they are stored
    for(i=0;i<NrOfVertices;i++)
        if(FirstVertex==vertices[i])
            {position=i;
             break;}

    PRIM(position);

    return 0;
}
