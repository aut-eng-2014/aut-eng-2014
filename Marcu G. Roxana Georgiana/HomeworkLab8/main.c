#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int NrOfVertices;
char *vertices;  //stores all the vertices from the file
int **matrix; //adjacent matrix af the graph

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

    vertices=(char*)malloc(NrOfVertices*sizeof(char));
    for(i=0; i<NrOfVertices; i++)
    {
        fscanf(f,"%c",vertices+i);
    }

    matrix=(int**)malloc(NrOfVertices*sizeof(int*));
    for(i=0; i<NrOfVertices; i++)
    {
        matrix[i]=(int *)malloc(NrOfVertices*sizeof(int));
    }

    for(i=0; i<NrOfVertices; i++)
    {
        for(j=0; j<NrOfVertices; j++){
            fscanf(f,"%d ", &matrix[i][j] );
        }
        fscanf(f,"\n");
    }
    fclose(f);
}

void PrintMatrix()
{
    int i,j;
    printf("   ");
    for(i=0; i<NrOfVertices; i++)
        printf("  %c",vertices[i]);
    printf("\n");

    for(i=0; i<NrOfVertices; i++)
    {
        printf("%c  ",vertices[i]);
        for(j=0; j<NrOfVertices; j++)
            printf("  %d",matrix[i][j]);
        printf("\n");
    }
}

void Dijkstra(int source,int stop)
{
    int i,j;
    int visited[NrOfVertices];
    int distance[NrOfVertices];

    for(i=0; i<NrOfVertices; i++)
    {
        visited[i]=0;
        distance[i]=INT_MAX;
    }
    distance[source]=0;
    i=0; //counter
    int current;
    while(i<NrOfVertices && visited[stop]==0)
    {
        int minimum=INT_MAX;
        for(j=0; j<NrOfVertices; j++)
        {
            if(visited[j]==0 && distance[j]<minimum)
            {
                current=j;
                minimum=distance[j];
            }
        }
        visited[current]=1;
        for(j=0; j<NrOfVertices; j++)
        {
            if(matrix[current][j]!=0)
            {
                if(distance[j]>distance[current]+matrix[current][j])
                    distance[j]=distance[current]+matrix[current][j];
            }
        }
        i++;
    }
    printf("\nThe minimum distance between %c and %c is %d\n",vertices[source],vertices[stop],distance[current]);
}

void FloydWarshall()
{
    int i,j,k;
    int **FloydMatrix;

    FloydMatrix=(int**)malloc(NrOfVertices*sizeof(int*));
    for(i=0; i<NrOfVertices; i++)
    {
        FloydMatrix[i]=(int *)malloc(NrOfVertices*sizeof(int));
    }

    for(i=0; i<NrOfVertices; i++){      //I build the matrix for algorithm,because in the file I have 0 if there is no edge
        for(j=0; j<NrOfVertices; j++){
            if(i==j)
                FloydMatrix[i][j]=0;
            else{
                if(matrix[i][j]==0)
                    FloydMatrix[i][j]=32767;
                else
                    FloydMatrix[i][j]=matrix[i][j];
            }
        }
    }

    for(k=0; k<NrOfVertices; k++)
        for(i=0; i<NrOfVertices; i++)
            for(j=0; j<NrOfVertices; j++)
            {
                if(FloydMatrix[i][j]>FloydMatrix[i][k]+FloydMatrix[k][j])
                {
                    FloydMatrix[i][j]=FloydMatrix[i][k]+FloydMatrix[k][j];
                }
            }
    for(i=0; i<NrOfVertices; i++)
    {
        for(j=0; j<NrOfVertices; j++)
            printf("  %d",FloydMatrix[i][j]);
        printf("\n");
    }
}

int main()
{
    CreateMatrix();
    printf("The number of vertices is %d\n\n",NrOfVertices);
    printf("The adjacency matrix is:\n");
    PrintMatrix();

    int choice;
    printf("\nChoose which algorithm you want to apply:\n");
    printf("   press 1 for Dijkstra \n         2 for Floyd-Warshall\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        printf("\nDijkstra\n");
        int FirstPosition,LastPosition;

        //I've tried to do what's in the comment,but it didn't work. I couldn't read LastVertex
        //I saw on the internet that are some problems with scanf and char.. and I used gets. But still no success
/*
        int i;
        char FirstVertex,LastVertex;
        printf("\nInput the vertex from which you want to start Dijkstra's algorithm\n");
        //scanf("%d ",&FirstVertex);
        gets(FirstVertex);

        printf("Input the vertex where you want to stop Dijkstra's algorithm\n");
        //scanf("%d ",&LastVertex);
        gets(LastVertex);

        for(i=0; i<NrOfVertices; i++)
        {
            if(FirstVertex==vertices[i])
                FirstPosition=i;
            if(LastVertex==vertices[i])
                LastPosition=i;
        }
*/
        printf("\nInput the number of the vertex from where you want to start\n");
        scanf("%d",&FirstPosition);

        printf("\nInput the number of vertex where you want to stop\n");
        scanf("%d",&LastPosition);

        Dijkstra(FirstPosition,LastPosition);
        break;

    case 2:
        printf("\nThe matrix of Floyd-Warshall algorithm is\n");
        FloydWarshall();
        break;

    default:
        printf("\nInvalid number\n");
    }

    return 0;
}
