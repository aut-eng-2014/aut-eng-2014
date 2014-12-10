#include<stdio.h>
#include<conio.h>
int a[20][20],visited[20],n;

void dfs(int v)
{
    int i;
    visited[v]=1;
    for(i=1;i<=n;i++)
        if(a[v][i] && !visited[i])
        {
            printf("\n %d->%d",v,i);
            dfs(i);
        }
}

int main()
{
    int i,j;
    printf("\n Enter number of vertices:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        for(j=1;j<=n;j++)
        a[i][j]=0;
    }
    printf("\n Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    dfs(1);
    printf("\n");
    getch();
    return 0;
}
