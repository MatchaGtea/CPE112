#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

typedef struct Graph_t {
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph *Graph_create(int V){
    Graph *g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }

    return g;
}

void Graph_destroy(Graph *g){
    free(g);
}

void Graph_addEdge(Graph *g, int v, int w){
    g->adj[v][w] = true;
}

void DFSearch(Graph* g, int s, bool visited[]) {
    visited[s] = true;
    printf("%c ", s+65);

    //*Add implementation here
    //*Reminder: DFSearch uses recursion
    for (int i = 0 ; i < g->V; i++) {
        if (g->adj[s][i] == true && !visited[i]) {
            DFSearch(g, i, visited);
        }
    }
}

void Graph_DFS(Graph* g, int s) {
    //initialize and make visited array
    bool visited[MAX_VERTICES];

    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    DFSearch(g, s, visited);//start DFS recursion
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);

    //Make a graph
    Graph *g = Graph_create(v);

    //Insert Edges
    for (int i = 0; i < e; i++) {
        int v, w;
        scanf("%d %d", &v, &w);
        Graph_addEdge(g, v, w);
    }

    int startVertex;
    scanf("%d", &startVertex);
    Graph_DFS(g, startVertex);
    Graph_destroy(g);

    return 0;
}