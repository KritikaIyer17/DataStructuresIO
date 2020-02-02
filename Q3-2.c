#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int items[10];
    int f;
    int r;
};
struct queue* createQueue()
{
    struct queue* q = malloc(sizeof(struct queue));
    q->f = -1;
    q->r = -1;
    return q;
}
int isEmpty(struct queue* q)
{
    if(q->r == -1) 
        return 1;
    else 
        return 0;
}
void enqueue(struct queue* q, int value)
{
    if(q->f == -1)
        q->f = 0;
    q->r++;
    q->items[q->r] = value;
}
int dequeue(struct queue* q)
{
    int item;
    if(isEmpty(q))
    {
        item = -1;
    }
    else
    {
        item = q->items[q->f];
        q->f++;
        if(q->f > q->r)
        {
            q->f = q->r = -1;
        }
    }
    return item;
}
struct node
{
    int vertex;
    struct node* next;
};
struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct Graph
{
    int n;
    struct node** adjLists;
    int* visited;
};
struct Graph* createGraph(int v)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->n = v;
    graph->adjLists = malloc(v * sizeof(struct node*));
    graph->visited = malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) 
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph* graph, int s, int d)
{
    struct node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
    newNode = createNode(s);
    newNode->next = graph->adjLists[d];
    graph->adjLists[d] = newNode;
}
void bfs(struct Graph* graph, int s)
{
    struct queue* q = createQueue();
    graph->visited[s] = 1;
    enqueue(q, s);
    while(!isEmpty(q))
    {
        int c = dequeue(q);
        printf("%c ==> ", (c%26)+65);
        struct node* temp = graph->adjLists[c];
        while(temp)
        {
            int a = temp->vertex;
            if(graph->visited[a] == 0)
            {
                graph->visited[a] = 1;
                enqueue(q, a);
            }
            temp = temp->next;
        }
    }
}
int main()
{
	struct Graph* graph = createGraph(10);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 7);
    addEdge(graph, 1, 6);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 9);
    addEdge(graph, 5, 8);
    addEdge(graph, 6, 7);
    addEdge(graph, 6, 8);
    bfs(graph, 0);
	printf("\n");
    return 0;
}
