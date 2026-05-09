#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 10
#define MAX_INT INT_MAX

typedef struct Graph_t{
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph *Graph_create(int V){
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            g->adj[i][j] = 0;
        }
    }
    return g;
}

void Graph_destroy(Graph *g){
    free(g);
}

void Graph_addEdge(Graph *g, int src, int dst,int weight){
    g->adj[src][dst] = weight;
    g->adj[dst][src] = weight;
}

void Prim(Graph *g,int s){
    bool visited[MAX_VERTICES];

    for(int i = 0 ; i < g->V ;i++){
        visited[i] =false;
    }

    visited[s] = true;

    for(int i = 0 ; i < g->V ; i++){
        int min = MAX_INT;
        int x = -1 , y = -1;

        for(int j = 0; ; j < g->V ; j++){
            if(visited[j]){
                for(int k = 0 ;k < g->V ; k++){
                    if(!visited[k] && g->adj != 0){
                        if(g->adj[j][k] < min){
                            min = g->adj[j][k];
                            x = j ;
                            y = k;
                        }
                    }
                }
            }
        }
        if( x != -1  && y != -1){
            printf("%c -> %c = %d",x+65,y+65,g->adj[x][y]);
            visited[y] = true;
        }
    }
}

int main()
{
    int v = 5;
    Graph *g = Graph_create(v); // A=0,B=1,C=2,D=3,E=4

    Graph_addEdge(g, 0, 1, 7);
    Graph_addEdge(g, 0, 2, 3);
    Graph_addEdge(g, 1, 2, 4);
    Graph_addEdge(g, 1, 3, 9);
    Graph_addEdge(g, 1, 4, 11);
    Graph_addEdge(g, 2, 3, 10);

    int starting_v;
    scanf("%d",&starting_v);

    if (starting_v < 0 || starting_v >= v){
        return 1;
    }

    Prim(g,starting_v);

    Graph_destroy(g);
    return 0;
}