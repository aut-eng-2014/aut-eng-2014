#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n,**m,i,j,*visited;
    int ne=0,min=INT_MAX ,mincost=0;

    FILE *pf;
    pf=fopen("adjmatrix.txt","r");

    fscanf(pf,"%d\n",&n);


    m=(int**)malloc(n*sizeof(int*));///We dinamycally allocate a matrix of size n*n
    for(i=0; i<n; i++)
        *(m+i)=(int*)malloc(n*sizeof(int));

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            fscanf(pf,"%d ",(*(m+i)+j));///we read the matrix from the file

        }


    visited=(int*)malloc(10*sizeof(int));
    for(i=0; i<n; i++)
        *(visited+i)=0;///we create a list of size 10 and we fill it with zeros meaning not unvisited

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ",*(*(m+i)+j));///we print the adjancy matrix
        printf("\n");
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            if(*(*(m+i)+j)==0)
                *(*(m+i)+j)=INT_MAX;}///we fill the 0's in the matix with the highest value of int INT_MAX


    *(visited+0)=1;///we make first element of the list 1
    int a,b,u,v;

    while(ne<n)///while number of edges is lower than the number of edges we inserted
    {
        for(i=0,min=INT_MAX; i<n; i++)
            for(j=0; j<n; j++)
                if(*(*(m+i)+j)<min)
                    if(*(visited+i)!=0)///if the element from the matrix is lower than min and
                    {                       ///the visited vector is differnt from 0 (meaning visited)
                        min=*(*(m+i)+j);///min takes the value of the element from the matrix
                        u=i; ///u takes the value of i
                        a=u;///a takes the value of u
                        v=j;///v takes the value of j
                        b=v;///b takes the value of v
                    }
        if((*(visited+u))!=0||(*(visited+v))!=0)///if visited[u] or visited[v] is visited
        {
            printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);///print the min edge
            mincost+=min;///mincost gets updated each time with + min
            *(visited+b)=1;///the node is marked as visited
        }
        *(*(m+i)+j)=*(*(m+j)+i)=INT_MAX;///source of crash(This should make all the elements from the main diagonal take INT_MAX
    }

    printf("\n Minimun cost=%d",mincost);
    return 0;
}
