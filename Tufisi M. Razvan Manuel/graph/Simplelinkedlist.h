//header file for simple linked list data structures:queue and stack
typedef struct node
{
    int data;
    struct node* next;
} nodeT;

nodeT* newNode(int data);
int pop(nodeT** root);
void push(nodeT** root, int data);
int peek(nodeT* root);

typedef struct Queue
{
    nodeT *front, *rear;
} queueT;

nodeT* newNodeq(int k);
queueT *createQueue();
void enqueue(queueT *q, int k);
nodeT *dequeue(queueT *q);
