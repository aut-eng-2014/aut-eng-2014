typedef struct node_list
{
    char *content;
    struct node_list *next , *prev;
} NodeL;

NodeL *first, *last;

void addLast(char *key);
void traverseList();
void deleteNode(NodeL *node);
