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

void Graph_BFS(Graph* g, int s) {
    //Created a visited array to note vertices visited
    bool visited[MAX_VERTICES];

    //**Initialize the visited array here(Set every bool in array to false)**
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    //Created a queue array to process the vertices
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    //Check starting Vertex as visited
    visited[s] = true;

    //put the starting Vertex into queue to begin while loop
    queue[rear++] = s;

    while (front != rear) { // until queue is empty
        int current = queue[front++];
        printf("%c ", current+65);//So it prints the Vertex Letter

        for (int i = 0; i < g->V; i++) {
            if(g->adj[current][i] == true && visited[i] == false) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
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
    Graph_BFS(g, startVertex);

    Graph_destroy(g);

    return 0;
}