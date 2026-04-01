#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph_t
{
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph *Graph_create(int V)
{
    Graph *g = malloc(sizeof(Graph));
    g->V = V;
    for (int i = 0; i < V; i++)
    {
    for (int j = 0; j < V; j++)
    {
    g->adj[i][j] = false;
    }
    }
    return g;
}

void Graph_destroy(Graph *g)
{
    free(g);
}

void Graph_addEdge(Graph *g, int v, int w)
{
    g->adj[v][w] = true;
}

int main()
{
    int v, e;
    scanf("%d %d", &v, &e);
    Graph *g = Graph_create(v);
    for (int i = 0; i < e; i++)
    {
    int src, dest;
    scanf("%d %d", &src, &dest);
    Graph_addEdge(g, src, dest);
    }
    for (int i = 0; i < v; i++)
    {
    printf("[ ");
    for(int j = 0;j < v; j++){
    printf("%d ", g->adj[i][j]);
    }
    printf("]\n");
    }
    free(g);
    return 0;
}