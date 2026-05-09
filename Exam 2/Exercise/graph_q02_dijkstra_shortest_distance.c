/*
Topic: Graph
Question 2: Single source shortest path to target

What to do:
- Complete shortestDistanceToTarget.
- Use Dijkstra-style logic for non-negative weighted directed edges.
- edges[i][0] = from, edges[i][1] = to, edges[i][2] = weight.
- Return the minimum distance from start to target.
- Return -1 if target is unreachable.

Example input:
5 6
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1
0 4

Example output:
6
*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 100
#define MAXM 500
#define INF INT_MAX

typedef struct Graph_t
{
    int V;
    int adj[MAXN][MAXN];
} Graph;

Graph *Graph_create(int V)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            g->adj[i][j] = 0;
        }
    }

    return g;
}

void Graph_destroy(Graph *g)
{
    free(g);
}

void Graph_addEdge(Graph *g, int src, int dst, int weight)
{
    g->adj[src][dst] = weight;
}

int minDistance(int dist[], bool visited[], int V)
{
    int min = INF;
    int min_index = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

int dijkstra(Graph *g, int src, int dst)
{
    int dist[MAXN];
    bool visited[MAXN] = {false};

    for (int i = 0; i < g->V; i++)
    {
        dist[i] = INF;
    }

    dist[src] = 0;

    for (int count = 0; count < g->V - 1; count++)
    {
        int u = minDistance(dist, visited, g->V);

        if (u == -1)
        {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < g->V; v++)
        {
            if (!visited[v] &&
                g->adj[u][v] != 0 &&
                dist[u] != INF &&
                dist[u] + g->adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + g->adj[u][v];
            }
        }
    }

    if (dist[dst] == INF)
    {
        return -1;
    }

    return dist[dst];
}

int shortestDistanceToTarget(int n, int edges[][3], int m, int start, int target)
{
    Graph *g = Graph_create(n);

    for (int i = 0; i < m; i++)
    {
        Graph_addEdge(g, edges[i][0], edges[i][1], edges[i][2]);
    }

    int result = dijkstra(g, start, target);
    Graph_destroy(g);

    return result;
}

int main()
{
    int n, m;
    int edges[MAXM][3];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    int start, target;
    scanf("%d %d", &start, &target);

    int result = shortestDistanceToTarget(n, edges, m, start, target);
    printf("%d\n", result);

    return 0;
}
