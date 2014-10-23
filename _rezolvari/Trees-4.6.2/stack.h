typedef struct stack
{
    char *content;
    struct stack *next;
} NodeS;

NodeS *head;

NodeS* peek();
void pop();
void push(char* content);
