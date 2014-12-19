#include<stdio.h>
#include<conio.h>
#define MIN 32767


int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,cost[10][10];
void main()
{
	printf("\nThe number of nodes is:");
	scanf("%d",&n);
	printf("The adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
			cost[i][j]=32000;
	}
	printf("The node to start the tree is:");
	scanf("%d", &i);
	visited[i]=1;
	printf("\n");
	while(ne < n)
	{
		for(i=1, min=32000;i<=n;i++)
		for(j=1;j<=n;j++)
		if(cost[i][j]< min)
		if(visited[i]!=0)
		{
			min=cost[i][j];
			u=i; a=u;
			v=j; b=v;
		}
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\n Edge %d:%d-%d cost:%d",ne++,a,b,min);
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=32000;
	}
	getch();
	return 0;
}
