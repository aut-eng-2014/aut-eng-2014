#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node_list
{
    char *value;
    struct node_list *next , *prev;
} NodeL;
NodeL *first, *last;

typedef struct node_tree
{
    char *value;
    struct node_tree *left , *right ;
} NodeT;

void read(char ***matrix,int r,int c)
{
    char ch;
    int i=0,j;
    FILE *file;

    file = fopen("family_tree.txt","r");
    if( file == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    while( ( ch = fgetc(file) ) != EOF )
    {
        j=0;
        while(ch!= '\0')
        {
            while(ch=='(' || ch==')')
                ch = fgetc(file);
            fscanf(file,"%s",matrix[i][j]);
            printf("%s",matrix[i][j]);
            j++;
            ch=fgetc(file);
        }
        i++;
    }
    printf("\n");
    fclose(file);
    r=i--;
    c=j--;
}

NodeL *first1,*last1;

void createlist(char ***matrix, NodeL *node,int i,int r)
{
    int j;
    for(j=i+1; j<r; j++)
    {
        if( strcmp( matrix[i][1] , matrix[j][0]) == 0)
        {
            node=node->next;
            strcpy( node->value, matrix[j][0] );
            createlist(matrix,node,i++,r);
        }
        if( strcmp( matrix[i][2] , matrix[j][0]) == 0)
        {
            node=node->next;
            strcpy(node->value,matrix[j][0]);
            createlist(matrix,node,i++,r);
        }
        node=node->next;
        strcpy( node->value, matrix[i][1] );
        node=node->next;
        strcpy(node->value, "*");
        node=node->next;
        strcpy( node->value, matrix[i][2] );
        strcpy(node->value, "*");
    }
    if(j+1 == r)
    {
        node->next=NULL;
        node=last1;
    }
}

void special_traversal_for_prev()
{
    NodeL *temp = first1->next;
    first1->prev=NULL;
    temp->prev=first1;
    NodeL *temp2 = temp->next;

    while(temp2 !=NULL)
    {
        temp = temp2->prev;
        temp2= temp2->next;
    }
}

void traversal()
{
    NodeL *temp = first;

    while(temp!=NULL)
    {
        printf("%s ",temp->value);
        temp = temp->next;
    }
    printf("\n\n");
}

void removenode(NodeL *node)
{
    if(node==first)
    {
        if(node->next == NULL)
        {
            first=NULL;
            last=NULL;
        }
        else
        {
            if(node->next == last)
            {
                first=last;
            }
            else
            {
                first = node->next;
                first->prev = NULL;
            }
        }
    }
    else if(node == last)
    {
        if(node->prev == NULL)
        {
            free(node);
            last=NULL;
            first=NULL;
        }
        else
        {
            if(node->prev == first)
            {
                first-> next = NULL;
                last = first;
            }
            else
            {
                last = node->prev;
                last->next = NULL;
            }
        }
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    free(node);
}



void preorder( NodeT *p, int level )
{
    int i ;
    if ( p != NULL )
    {
        for ( i = 0; i <= level ; i++ )
            printf ( " " ) ;
        printf ( "%s\n" , p->value ) ;
        preorder( p->left , level + 1 ) ;
        preorder( p->right , level + 1 ) ;
    }
}

void inorder( NodeT *p, int level )
{
    int i;
    if ( p != NULL )
    {
        inorder( p->left , level + 1 ) ;
        for ( i = 0; i <= level ; i++ )
            printf ( " " ) ;
        printf ( "%s\n" , p->value ) ;
        inorder( p->right , level + 1 ) ;
    }
}


NodeT *getTreeFromList(NodeL *elementOfList)
{
    NodeT *p;
    char *content = elementOfList->value;

    if ( strcmp(content,"*")==0 )
    {
        removenode(elementOfList);
        return NULL;
    }
    else
    {
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->value = content;
        p->left = getTreeFromList(elementOfList->next) ;
        p->right = getTreeFromList(elementOfList->next) ;
        removenode(elementOfList);
    }
    return p;
}

int main()
{
    char **matrix[100];
    int r,c; //rows&columns
    read(matrix,&r,&c);

    strcpy(first1->value,matrix[0][0]);
    createlist(matrix,first1,0,r);
    special_traversal_for_prev();

    NodeL *firstFromList=first1;
    printf("\nThe doubly-linked list of the tree is:\n");
    traversal();
    NodeT *root = getTreeFromList(firstFromList);

    printf("\nThe prefix traversal of the tree is\n");
    preorder(root,0);
    printf("\nThe infix traversal of the tree is\n");
    inorder(root, 0);

    return 0;
}

