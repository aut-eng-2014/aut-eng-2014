#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    char c;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} TreeT;
TreeT *root, *back;
char ok = 0;
TreeT *Create(char *in)
{
    TreeT *p;
    static int i = 0;
    if (in[i] != '\0')
    {
        if ((*(in+i)=='+') || (*(in+i)=='-') || (*(in+i)=='*') || (*(in+i)=='/'))
        {
            p = (TreeT*) malloc (sizeof(TreeT));
            p->c = *(in+i);
            //printf(" %d %c ",i, *(in+i));
            i++;
            p->left = Create(in);
            p->right = Create(in);
        }
        else
        {
            p = (TreeT*) malloc (sizeof(TreeT));
            p->c = *(in+i);
            //printf(" %d %c ",i, *(in+i));
            i++;
            p->left = NULL;
            p->right = NULL;
        }
    }
    return p;
}
void preorder( TreeT *p, int level )
{
  int i;

  if ( p != NULL )
  {
    for ( i = 0; i <= level; i++ )
      printf( " " );
    printf( "%c\n", p->c );
    preorder( p->left, level + 1 );
    preorder( p->right, level + 1 );
  }
}
int main()
{
    /* String Initialization ************************************************** */
    char *string;
    string = (char*) malloc ( 100 * sizeof(char));
    scanf("%s", string);
    realloc ( string, (strlen(string)+1) * sizeof(char));

    /* Tests ****************************************************************** */
    //printf("%s %d", string, strlen(string));
    root = Create(string);
    //printf(" %c ", root->c);
    printf("\n");
    preorder( root, 0);
    return 0;
}
