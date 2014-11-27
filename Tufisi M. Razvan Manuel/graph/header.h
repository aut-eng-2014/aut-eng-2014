
// a structure to represent an adjacency list node
typedef struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
}AdjListNodeT;

//a structure to represent an adjacency list
typedef struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
}AdjListT;

// a graph is an array of adjacency lists.

typedef struct Graph
{
    int V;//  V -number of vertices in graph
    struct AdjList* array;
}GraphT;

AdjListNodeT* newAdjListNode(int dest);
GraphT* createGraph(int V);
void addEdge(GraphT* graph, int src, int dest);
void printGraph(GraphT* graph);
void bfs(int V,int src, GraphT* graph);
void dfs(int V, int src,GraphT* graph);
