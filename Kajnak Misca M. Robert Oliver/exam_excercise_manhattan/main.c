#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct e
{
    int h;
    int x1,x2;
} element;



int main()
{
    ///read from file and store
    int n;
    FILE * f;
    f=fopen("data.txt","r");
    fscanf(f,"%d",&n);

    element *a;
    int maxx=INT_MIN;
    a=(element*)malloc(n*sizeof(element));
    int i,j;
    for (i=0;i<n;i++)
    {
        fscanf(f,"%d %d %d",&a[i].x1,&a[i].x2,&a[i].h);
        if (a[i].x2>maxx)
            maxx=a[i].x2;
    }
    fclose(f);
    ///*/

    ///Check input
    /*for (i=0;i<n;i++)
        printf("%d %d %d\n",a[i].x1,a[i].x2,a[i].h);
    printf("%d",maxx);*/
    ///*/

    int *b=(int*)malloc(maxx*sizeof(int));
    for (i=0;i<maxx;i++)
        b[i]=0;

    /**INsert*/
    for (i=0;i<n;i++)
    {
        for (j=0;j<a[i].x2-a[i].x1;j++)
        {
            if (a[i].h>b[a[i].x1+j])
                b[a[i].x1+j]=a[i].h;
        }
    }
    /**/

    /**Test*/

    printf("\n----\n\n");
    for (i=1;i<maxx;i++)
    {
        //printf("%d\n",b[i]);
        if (b[i-1]!=b[i])
        {
            printf("(%d,%d) \n",i,b[i-1]);
            printf("(%d,%d) \n",i,b[i]);
        }
    }
    /**///printf("TOtal%d",i);

    return 0;
}
