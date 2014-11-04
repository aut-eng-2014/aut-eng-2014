typedef struct queue
{
    char *content;
    struct queue *next;
} QueueN;

QueueN *head, *last;

QueueN *peek();
void enqueue(char *content);
void dequeue();

