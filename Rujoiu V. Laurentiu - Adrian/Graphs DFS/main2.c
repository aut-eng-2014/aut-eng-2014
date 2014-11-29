#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

int a[10][10];
Node *L[10],*p;

void matrix( int b[10][10],int x,int y)
{
    b[x][y]=1;
}

void init_mat(int a[10][10], int n)
{
    int i,j;

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            a[i][j]=0;
}

void init_v( int v[100], int n)
{
    int i;

    for(i=1; i<=n; i++)
        v[i]=0;
}

void breadth( int n,int s)
{

#define  DimMax 100
    typedef int Que[DimMax];
    Que C;
    int viz[100];
    int inc,end,top,i;

    inc=0;
    end=-1;
    init_v(viz,n);
    viz[s]=1;

    if (end==DimMax-1)
    {
        printf("There is no space in the que!");
    }
    else
    {
        C[++end] = s;
    }
    printf("BFS is: \n");
    printf("%d ",s);

    while(inc <= end)
    {
        top=C[inc++];

        for(i=n; i>=1; i--)
            if(a[top][i]==1)
                if (viz[i]==0)
                {
                    viz[i]=1;
                    printf("%d ",i);
                    C[++end] = i;
                }
    }
}

void width(int k,int n)
{
    int prim,last,top;
    Node *p;
    int c[100], v[100];

    init_v(v,n);
    v[k]=1;
    prim=1;
    last=1;
    c[prim]=k;
    printf("\n");
    printf("\n%d",k);
    while (prim<=last)
    {
        top=c[prim];
        p=L[top];
        while (p!=0)
        {
            if (v[p->data]==0)
            {
                printf("\n%d",p->data);
                v[p->data]=1;
                last=last+1;
                c[last]=p->data;
            }
            p=p->next;
        }
        prim=prim+1;
    }
}
int main()
{
    FILE *f;
    Node *p;
    int x,y,n,m;


    f = fopen("intraree.txt","r");
    if (f==NULL)
    {
        perror("Error!");
        exit(1);
    }
    fscanf(f,"%d %d",&n,&m);
    init_mat(a,n);
    /*  for(i=1;i<=n;i++)
      {
          L[i]=(Nod *)malloc(sizeof(Nod));
          L[i]->urm=0;
          L[i]->inf=0;

      }
    */
    while(!feof(f))
    {
        fscanf(f,"%d %d",&x,&y);
        matrix(a,x,y);
        p=(Node*)malloc(sizeof(Node));
        p->data=y;
        p->next=L[x];
        L[x]=p;
    }

    breadth(n,1);
    fclose(f);

}
