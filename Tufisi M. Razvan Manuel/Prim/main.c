#include<stdio.h>
#include<conio.h>
#include<limits.h>


int main()
{

int a,b,u,v,n,i,j,ne=0;
int visited[10]={0},min,mincost=0,cost[10][10];

FILE *pf;
    pf=fopen("adjmatrix.txt","r");

fscanf(pf,"%d",&n);

for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
fscanf(pf,"%d ",&cost[i][j]);//we read the matrix from the file

if(cost[i][j]==0)
cost[i][j]=INT_MAX;///we fill the 0's in the matix with the highest value of int INT_MAX
}
visited[0]=1;
printf("\n");
while(ne < n)///while number of edges is lower than the number of edges we inserted
{
for(i=0,min=INT_MAX;i<n;i++)
for(j=0;j<n;j++)
if(cost[i][j]< min)
if(visited[i]!=0)///if the element from the matrix is lower than min and
{			///the visited vector is differnt from 0 (meaning visited)
min=cost[i][j];		///min takes the value of the element from the matrix
u=i;
a=u;
v=j;
b=v;
}
if(visited[u]!=0 || visited[v]!=0)///if visited[u] or visited[v] is visited
{
printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);///print the min edge
mincost+=min;///mincost gets updated each time with + min
visited[b]=1;///the node is marked as visited
}
cost[a][b]=cost[b][a]=INT_MAX;///all the elements from the main diagonal take INT_MAX
}
printf("\n Minimun cost=%d",mincost);///print minimum cost

return 0;

}
