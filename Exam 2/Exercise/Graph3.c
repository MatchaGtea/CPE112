#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 100
#define MAXM 500
#define INF INT_MAX

typedef struct Graph_t{
    int V;
    int adj[MAXM][MAXM];
}Graph;

Graph *Graph_create(int V){
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = V;
    for(int i = 0 ; i< V ; i++){
        for(int j = 0 ; j< V ; j++){
            g->adj[i][j] =0;
        }
    }
    return g;
}

int minDistance(int dist[] , bool visited[] , int V){
    int min = INF;
    int min_index = -1;

    for(int i = 0 ; i < V ; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int dijkstra(Graph *g , int key , int dst){
    int dist[MAXM];
    bool visited[MAXM] ={ false};

    for(int i = 0 ; i< g->V ; i++){
        dist[i] = INF;
    }

    dist[key] = 0;

    for(int count = 0 ; count < g->V ; count++){
        int u = minDistance(dist,visited,g->V);

        if(u == -1) break;

        visited[u] = true;

        for(int v = 0 ; v< g->V ; v++){
            if(!visited[v] && g->adj[u][v] == 1 && dist[u] != INF && dist[u] + g->adj[u][v] < dist[v]){
                dist[v] = dist[u] + g->adj[u][v];
            }
        }
    }

    if(dist[dst] == INF) return -1;

    return dist[dst];


}