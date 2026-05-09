#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Max_Vertice 10

// typedef struct Graph_t{
//     int V;
//     bool adj[Max_Vertice][Max_Vertice];
// }Graph;

// Graph *Graph_create(int V){
//     Graph *g = malloc(sizeof(Graph));
//     g->V = V;
//     for(int i = 0 ; i < V ; i++){
//         for(int j = 0 ; j < V ; j++){
//             g->adj[i][j] = false;
//         }
//     }
//     return g;
// }

typedef struct Graph_t{
    int V;
    bool adj[Max_Vertice][Max_Vertice];
}Graph;

Graph *Graph_create(int V){
    Graph *g = malloc(sizeof(Graph));
    g->V = V;
    for(int i = 0 ; i<V ; i++){
        for(int j = 0 ; j < V ; j++){
            g->adj[i][j] = false;
        }
    }
    return g;
}

// void Graph_BFS(Graph *g , int key){
//     bool visited[Max_Vertice];

//     for(int i = 0 ; i< g->V ; i++){
//         visited[i] = false;
//     }

//     int queue[Max_Vertice];
//     int front = 0,rear = 0;

//     visited[key] = true;

//     queue[rear++] = key;

//     while(front != rear){
//         int current = queue[front++];
//         printf("%c ",current + 65);

//         for(int i = 0 ; i< g->V ;i++){
//             if(g->adj[current][i] == true && visited[i] == false){
//                 visited[i] = true;
//                 queue[rear++] = i;
//             }
//         }
//     }
// }

// void DFSearch(Graph *g , int key , bool visited[]){
//     visited[key] = true;
//     printf("%c ",key + 65);

//     for(int i = 0 ; i< g->V ; i++){
//         if(g->adj[key][i] == true && visited[i] == false){
//             DFSearch(g,i,visited);
//         }
//     }
// }

// void Graph_DFS(Graph *g , int key){
//     bool visited[Max_Vertice];

//     for(int i = 0 ; i < g->V ; i++){
//         visited[i] = false;
//     }
//     DFSearch(g,key,visited);
// }

// void DFSearch(Graph *g , int key , bool visited[]){
//     printf("%c ", key+65);
//     visited[key] = true;
//     for(int i = 0  ; i< g->V ; i++){
//         if(g->adj[key][i] == true && visited[i] == false){
//             DFSearch(g,i,visited);
//         }
//     }
// }

// void Graph_DFS(Graph *g , int key){
//     bool visited[Max_Vertice];
//     for(int i = 0 ; i < g->V ;i++){
//         visited[i] = false;
//     }
//     DFSearch(g,key,visited);
// }

// void Graph_BFS(Graph *g , int key){
//     bool visited[Max_Vertice];
//     for(int i = 0 ; i< g->V ;i++){
//         visited[i] = false;
//     }

//     int queue[Max_Vertice];
//     int front = 0 , rear = 0;

//     queue[rear++] = key;
//     visited[key] = true;

//     while(front != rear){
//         int current = queue[front++];
//         printf("%c ",current+65);
//         for(int i = 0 ; i< g->V ; i++){
//             if(g->adj[current][i] == true && visited[i] == false){
//                 visited[i] = true;
//                 queue[rear++] = i;
//             }
//         }
//     }
// }

// void DFSearch(Graph *g , int key , bool visited[]){
//     visited[key] = true;
//     printf("%c ",key +65);
//     for(int i = 0 ; i < g->V ; i++){
//         if(g->adj[key][i] == true && visited[i] == false){
//             DFSearch(g,i,visited);
//         }
//     }
// }

// void Graph_DFS(Graph *g , int key){
//     bool visited[Max_Vertice];
//     for(int i = 0 ; i < g->V ;i++){
//         visited[i] = false;
//     }
//     DFSearch(g,key,visited);
// }

// void Graph_BFS(Graph* g , int key){
//     bool visited[Max_Vertice];
//     for(int i = 0 ; i < g->V ; i++){
//         visited[i] = false;
//     }
    
//     int queue[Max_Vertice];
//     int front = 0 , rear = 0;

//     queue[rear++] = key;
//     visited[key] = true;

//     while(front != rear){
//         printf("%c ", key+65);
//         int current = queue[front++];
//         for(int i = 0 ; i< g->V ;i++){
//             if(g->adj[current][i] == true && visited[i] == false){
//                 visited[i] = true;
//                 queue[rear++] = i;
//             }
//         }
//     }
// }

void BFS(Graph *g , int key){
    bool visited[Max_Vertice];
    for(int i = 0 ; i < Max_Vertice ; i++){
        visited[i] = false;
    }

    int queue[Max_Vertice];
    int front = 0 , rear = 0;

    queue[rear++] = key;
    visited[key] = true;

    while(rear != true){
        int current = queue[front++];
        printf("%d ",current+65);

        for(int i = 0 ; i < g->V ;i++){
            if(g->adj[current][i] == true && visited[i] == false){
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    return g;
}
void Graph_addEdge(Graph *g , int v , int w){
    g->adj[v][w] = true;
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);

    //Make a graph
    Graph *g = Graph_create(v);

    //Insert Edges
    for(int i = 0 ; i < e ; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        Graph_addEdge(g, from, to);
    }

    int startVertex;
    scanf("%d", &startVertex);
    Graph_BFS(g, startVertex);



    return 0;
}
