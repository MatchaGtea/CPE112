#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 10

typedef struct Graph_t{
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
}Graph;

Graph *Graph_create(int V){
    Graph *g = malloc(sizeof(Graph));
    g->V = V;
    for(int i = 0 ; i < V ; i++){
    for(int j = 0 ; j < V ; j++){
        g->adj[i][j] = false;
    }
    }
    return g;
}

void Graph_destroy(Graph *g){
    free(g);
}

void Graph_addEdge(Graph *g , int v , int w){
    g->adj[v][w] = true;
}

//Graph BFS !!!!!!!
void Graph_BFS(Graph *g , int s){
    bool visited[MAX_VERTICES];

    for(int i = 0 ; i < g->V ;i++) visited[i] = false;

    //queue front rear
    int front = 0 , rear = 0;
    int queue[MAX_VERTICES];

    queue[rear++] = s;
    visited[s] = true;

    while(front != rear){
        int current = queue[front++];
        printf("%c ",current+65);
        for(int i = 0 ; i < g->V ; i++){
            if(g->adj[current][i] == true && visited[i] == false){
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

////DFS


void DFSearch(Graph *g , int s , bool visited[]){
    visited[s] = true;
    printf("%c ",s+65);

    for(int i = 0 ; i < g->V ; i++){
        if(g->adj[s][i] == true && visited[i] == false){
            DFSearch(g,i,visited);
        }
    }
}

void Graph_DFS(Graph *g , int s){
    bool visited[MAX_VERTICES];

    for(int i = 0 ; i< g->V ; i++){
        visited[i] = false;
    }

    DFSearch(g,s,visited);
}

int main(){
    // int v = 5 , e;

    // Graph *g = Graph_create(v);
    // g->adj[0][1] = true;
    // g->adj[0][3] = true;
    // g->adj[1][3] = true;
    // g->adj[2][1] = true;
    // g->adj[3][4] = true;
    // g->adj[4][2] = true;
    // for(int i = 0; i<v ; i++){
    //     printf("[ ");
    //     for(int j = 0; j<v ;j++){
    //         printf("%d ", g->adj[i][j]);
    //     }
    //     printf("]\n");
    // }
    // free(g);


    // //BFS
    //     int v, e;
    // scanf("%d %d", &v, &e);

    // //Make a graph
    // Graph *g = Graph_create(v);

    // //Insert Edges
    // for (int i = 0; i < e; i++) {
    //     int v, w;
    //     scanf("%d %d", &v, &w);
    //     Graph_addEdge(g, v, w);
    // }

    // int startVertex;
    // scanf("%d", &startVertex);
    // Graph_BFS(g, startVertex);

    // Graph_destroy(g);


    // return 0;
}