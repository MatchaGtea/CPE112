#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct {
    int src, dst, weight;
} Edge;

typedef struct Graph_t {
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph *Graph_create(int V){
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
    return g;
}

void Graph_destroy(Graph *g){
    free(g);
}

void Graph_addEdge(Graph *g, int src, int dst, int weight){
    g->adj[src][dst] = weight;
    g->adj[dst][src] = weight;
}

int find(int parent[], int i){
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unite(int parent[], int rank[], int x, int y){
    int rx = find(parent, x);
    int ry = find(parent, y);

    if (rx != ry) {
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if (rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
}

int compare(const void *a, const void *b){
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void Kruskal(Graph *g, int start){
    Edge edges[MAX_VERTICES * MAX_VERTICES];
    int edgeCount = 0;

    for (int i = 0; i < g->V; i++) {
        for (int j = i + 1; j < g->V; j++) {
            if (g->adj[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dst = j;
                edges[edgeCount].weight = g->adj[i][j];
                edgeCount++;
            }
        }
    }

    for (int i = 0; i < edgeCount; i++) {
        if (edges[i].src == start || edges[i].dst == start) {
            edges[i].weight -= 1;
        }
    }

    qsort(edges, edgeCount, sizeof(Edge), compare);

    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];

    for (int i = 0; i < g->V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstEdges = 0;

    for (int i = 0; i < edgeCount && mstEdges < g->V - 1; i++) {
        Edge e = edges[i];

        int setU = find(parent, e.src);
        int setV = find(parent, e.dst);

        if (setU != setV) {
            printf("%c - %c \t%d\n", e.src+65, e.dst+65, g->adj[e.src][e.dst]);

            unite(parent, rank, setU, setV);
            mstEdges++;
        }
    }
}

int main() {
    int v = 5;
    int start;

    Graph *g = Graph_create(v); // A=0,B=1,C=2,D=3,E=4

    Graph_addEdge(g, 0, 1, 7);
    Graph_addEdge(g, 0, 2, 3);
    Graph_addEdge(g, 1, 2, 4);
    Graph_addEdge(g, 1, 3, 9);
    Graph_addEdge(g, 1, 4, 11);
    Graph_addEdge(g, 2, 3, 10);
    
    scanf("%d", &start);

    if (start < 0 || start >= v) {
        return 1;
    }

    Kruskal(g, start);

    Graph_destroy(g);
    return 0;
}