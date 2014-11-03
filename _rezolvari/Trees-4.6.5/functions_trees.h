typedef struct node_tree
{
    char *content;
    struct node_tree *left , *right ;
} NodeT;

void preorder( NodeT *p, int level );
void inorder( NodeT *p, int level );
void postorder( NodeT *p, int level );
NodeT *createBinTree();
