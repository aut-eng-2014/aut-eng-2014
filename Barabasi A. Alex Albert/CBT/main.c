#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
  int key;
  int info;
  struct node_type *left, *right;
} NodeT;
/*----------------------*/
NodeT *root;
/*----------------------*/
void nInsert( int givenKey)
{
  NodeT *p, *q;

  /* build node */
  p = ( NodeT *) malloc ( sizeof ( NodeT ));
  p->key = givenKey;
  /* the info field should be filled in here */
  p->left = p-> right = NULL; /* leaf node */
  if ( root == NULL )
  { /* empty tree */
    root = p;
    return;
  }
  /* if we reach here then the tree is not empty;
     look for parent node of node pointed to by p */
  q = root;
  for ( ; ; )
  {
    if ( givenKey < q->key )
    { /* follow on left subtree */
      if ( q-> left == NULL )
      { /* insert node here */
        q->left = p;
        return;
      }
      /* else */
        q = q->left;
    }
    else
    if ( givenKey > q->key )
    { /* follow on right subtree */
      if ( q-> right == NULL )
      { /* insert node here */
        q->right = p;
        return;
      }
      /* else */
      q = q->right;
    }
    else
    { /* key already present;
         could write a message... */
      printf("Key already present\n");
      free( p );
      return;
    }
  }
}
/*----------------------*/
NodeT *find( NodeT * root, int givenKey )
{
  NodeT *p;
  if ( root == NULL ) return NULL; /* empty tree */
  for ( p = root; p != NULL; )
  {
    if ( givenKey == p->key ) return p;
    else
    if ( givenKey < p->key ) p = p->left;
    else                     p = p->right;
  }
  return NULL; /* not found */
}
NodeT *fparent( NodeT * root, int givenKey )
{
  NodeT *p;
  if ( root == NULL ) return NULL; /* empty tree */
  for ( p = root; p != NULL; )
  {
    if (p->right != NULL)
    {
        if ( givenKey == (p->right)->key )
        {
            return p;
        }
    }
    if (p->left != NULL)
    {
        if ( givenKey == (p->left)->key )
        {
            return p;
        }
    }
    if ( givenKey < p->key ) p = p->left;
    else                     p = p->right;
  }
  return NULL; /* not found */
}
void preorder( NodeT *p, int level )
{
  int i;

  if ( p != NULL )
  {
    for ( i = 0; i <= level; i++ )
      printf( "     " );
    printf( "%d\n", p->key );
    preorder( p->left, level + 1 );
    preorder( p->right, level + 1 );
  }
}
NodeT *replace ( NodeT *q)
{
    for(;;)
    {
        if ( q->right != NULL)
        {
            q = q->right;
        }
        else
        {
            return q;
        }
    }
}
void del (int sigil)
{
    NodeT *p;
    NodeT *parent;
    NodeT *leaf;
    parent = fparent(root, sigil);
    p = find (root, sigil);
    if ( p == NULL)
    {
        return;
    }
    if (( p->left == NULL ) && ( p->right == NULL ))
    {
        if ( p->key < parent->key )
        {
            parent -> left = NULL;
        }
        else
        {
            parent -> right = NULL;
        }
        //p = NULL;
        return;
    }
    if ( p->left == NULL)
    {
        if ( p->key < parent->key )
        {
            parent -> left = p->right;
        }
        else
        {
            parent -> right = p->right;
        }
        //p = p->right;
        return;
    }
    if ( p->right == NULL)
    {
        if ( p->key < parent->key )
        {
            parent -> left = p->left;
        }
        else
        {
            parent -> right = p->left;
        }
        //p = p->left;
        return;
    }
    leaf = replace (p->left);
    parent = fparent(root, leaf->key);
    p->key = leaf -> key;
    if ( leaf->key < parent->key )
    {
        parent -> right = NULL;
    }
    else
    {
        parent -> left = NULL;
    }
    //p = NULL;
    return;

    /*if ( p->key < parent->key )
    {
        parent -> left = replace (p->left);
    }
    else
    {
        parent -> right = replace (p->left);
    }
    //p = replace ( p->left );*/
    return;
}
int main()
{
    char r = ' ';
    int value = 0;
    //NodeT *t;
    printf("Menu:\n");
    printf("1.Command Insert (i).\n");
    printf("2.Command Find (f).\n");
    printf("3.Command Show (s).\n");
    printf("4.Command Delete (d).\n");
    printf("Usage: x v, where x is i,f,s or d and v is the GivenValue.\n");
    while (r != 'q')
    {
        scanf("%c", &r);
        if (r == 'i')
        {
            scanf("%d", &value);
            nInsert(value);
        }
        if (r == 'f')
        {
            scanf("%d", &value);
            if (find(root, value) != NULL )
            {
                printf("Found\n");
            }
            else
            {
                printf("Not Found\n");
            }
        }
        if ( r == 's')
        {
            preorder(root, 0);
        }
        if ( r == 'd')
        {
            scanf("%d", &value);
            //t = find (root, value);
            del (value);
        }
    }
    return 0;
}
