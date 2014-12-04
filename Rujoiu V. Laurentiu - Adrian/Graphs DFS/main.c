#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

}Node;
Node *L[10],*p;
void depth(int n, int s);

void init_v( int v[100], int n)
{
    int i;

    for(i=1; i<=n; i++)
        v[i]=0;
}

void depth(int n, int s)
{
    #define DimMax 10
    typedef int Stack[DimMax];
    Stack ST;
    int viz[100];
    int vf,i,top;
    Node *w;


    init_v(viz,n);

    vf=-1;
    viz[s]=1;

    if(vf==DimMax-1)
        printf("there is no place in the stack");
    else
        ST[++vf] = s;
        printf("\nDFS is:");
        printf("%d ",s);
        while(vf>=0)
        {
            top=ST[vf--];
            w=L[top];
            while(w!=0)
            {
                if(viz[w->data]==0) break;
                w=w->next;
            }
            if (w!=0)
            {
                printf("%d ",w->data);
                viz[w->data]=1;
                ST[++vf]=w->data;
            }
            else
                vf--;


        }
}

FILE *f;
int main()
{
    int i,n,m,x,y;
    Node *q;
    f = fopen("intraree.txt","r");

    if(f==NULL)
    {
        perror("File opening error!");
        exit(1);
    }
    fscanf(f,"%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        L[i]=(Node*)malloc(sizeof(Node*));
        L[i]->data=i;
        L[i]->next=0;
    }
    for(i=1; i<=m; i++)
    {
            fscanf(f,"%d %d",&x,&y);
            q=(Node*)malloc(sizeof(Node));
            q->data=y;
            q->next=L[x]->next;
            L[x]->next=q;
    }
    depth(n,2);

    fclose(f);


}
