#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NMAX 100

int **a,**p;

int **matrixalloc(int n)
{

    int **a, i;

    a = ( int** )malloc ( n * sizeof ( int* ) );

    for ( i = 0; i < n; i++ )
        a[i] = ( int* ) malloc ( n * sizeof ( int ) );


    if ( a == NULL )
    {
        perror ( "Memory allocation error!" );

        exit( 1 );
    }
    return a;
}
FILE *fileopen( char file_name [ 20 ] )
{
    FILE *f = fopen ( file_name, "r" );


    if ( f == NULL )
    {
        perror ( "\nOpening file error!\n" );
        exit ( 1 );
    }



    return f;

}

int numberofnodes ( FILE *f )
{
    int n = 0, aux;

    while ( ! ( feof ( f ) ) )
    {
        fscanf ( f, "%d", &aux );
        n++;
    }
    n = sqrt ( n );

    return n;

}

FILE *closefile ( FILE *f )
{
    fclose( f );

    return f;
}



void readmatrix( int **a, int n, FILE *f)
{


    int i, j;

    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ )
            fscanf ( f, "%d", &a [ i ][ j ] );


}

void floyd ( int **a, int **p, int n )
{
    int i, j, k;
    for ( k=0; k<n; k++)
        for (i=0; i<n; i++)
            for(j=0; j<n; j++)
                if (a[i][k]!=0 && a[k][j] && i!=j && (a[i][j]==0 || a[i][k]+a[k][j]<=a[i][j]))
                {
                    a[i][j]=a[i][k]+a[k][j];
                    p[i][j]=k;
                }
}

void showMatrix(int **a,int n,char text[NMAX])
{
    int i, j;
    printf( "\n\n%s\n\n",text);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf( "\n" );
    }
}

void way(int **p,int i,int j)
{
    int k;
    k=p[i][j];
    if (k!=0)
    {
        way(p,i,k);
        printf("%d ",k);
        way(p,k,j);
    }
}

int **initmatrix(int **v,int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            v[i][j]=0;
    return v;
}

int main()
{
    FILE *f = fileopen( "date.in" );
    int n = numberofnodes(f);
    closefile(f);
    f=fileopen("date.in");
    a=matrixalloc(n);
    p=matrixalloc(n);
    initmatrix(a,n);
    initmatrix(p,n);
    readmatrix(a,n,f);
    showMatrix(a,n,"Cost matrix before Floyd: ");
    floyd(a,p,n);
    showMatrix(a,n,"Cost matrix after Floyd's algorithm: ");
    int i, j;
    char ch;

    do
    {
        printf("\ninsert i: ");
        scanf("%d",&i);
        printf("insert j: ");
        scanf("%d",&j);
        if (i>=0&&i<n&&j>=0&&j<n)
        {
            printf("%d ",i);
            way(p,i,j);
            printf ("%d  with cost: %d\n",j,a[i][j]);
        }
        else
        {
            printf("\nValues for i and j must be between 0 and %d inclusive!\n\n ",n-1);
        }
        fflush(stdin);
        printf("continue? Y/ any other key");
        scanf("%c",&ch);
    }
    while( ch == 'Y' || ch == 'y' );
    return 0;
}
