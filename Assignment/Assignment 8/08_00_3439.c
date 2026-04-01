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
    for (int i = 0; i < V; i++){
    for (int j = 0; j < V; j++){
    g->adj[i][j] = false;
    }
    }
    return g;
}

void Graph_destroy(Graph *g){
    free(g);
}

int main()
{
    int v = 5, e;
    //scanf("%d %d", &v, &e);
    Graph *g = Graph_create(v);
    g->adj[0][1] = true;
    g->adj[0][3] = true;
    g->adj[1][3] = true;
    g->adj[2][1] = true;
    g->adj[3][4] = true;
    g->adj[4][2] = true;
    for (int i = 0; i < v; i++){
    printf("[ ");
    for(int j = 0;j < v; j++){
    printf("%d ", g->adj[i][j]);
    }
    printf("]\n");
    }
    free(g);
    return 0;
}