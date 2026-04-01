#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 10
#define INF INT_MAX

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

int minDistance(int dist[], bool visited[], int V){
    int min = INF, min_index = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printPath(int parent[], int j){
    if (parent[j] == -1){
        printf("%c ", j + 65);
        return;
    }
    printPath(parent, parent[j]);
    printf("%c ", j + 65);
}

void dijkstra(Graph *g, int src, int dst){
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];
    bool visited[MAX_VERTICES] = {false};

    //Initialize
    for (int i = 0; i < g->V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    //Main loop
    for (int count = 0; count < g->V - 1; count++) {
        int u = minDistance(dist, visited, g->V);

        if (u == -1) break; //No reachable node

        visited[u] = true;

        for (int v = 0; v < g->V; v++) {
            if (!visited[v] &&
                g->adj[u][v] != 0 &&
                dist[u] != INF &&
                dist[u] + g->adj[u][v] < dist[v]) {

                dist[v] = dist[u] + g->adj[u][v];
                parent[v] = u;
            }
        }
    }

    //Output
    if (dist[dst] == INF) {
        printf("No path exists.\n");
        return;
    }

    //print path
    printPath(parent, dst);
    //distance
    printf("\n%d", dist[dst]);
}

int main() 
{ 
    int v = 5; 
    Graph *g = Graph_create(v);//A=0,B=1,C=2,D=3,E=4 
    Graph_addEdge(g, 0, 1, 3);//A-B 3 
    Graph_addEdge(g, 0, 3, 7);//A-D 7 
    Graph_addEdge(g, 1, 2, 4);//B-C 4 
    Graph_addEdge(g, 1, 3, 2);//B-D 2 
    Graph_addEdge(g, 2, 3, 5);//C-D 5 
    Graph_addEdge(g, 2, 4, 6);//C-E 6 
    Graph_addEdge(g, 3, 4, 4);//D-E 4 
    int starting_v,dst; 
    scanf("%d %d",&starting_v,&dst); 
    dijkstra(g, starting_v, dst); 
    Graph_destroy(g);  
    return 0; 
} 