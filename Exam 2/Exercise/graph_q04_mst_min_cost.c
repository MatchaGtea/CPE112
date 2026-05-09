/*
Topic: Graph
Question 4: Minimum Spanning Tree total cost

What to do:
- Complete minCostToConnectCities.
- Given undirected weighted roads [u, v, w].
- Return the minimum total cost to connect all cities.
- Return -1 if the graph is disconnected.
- You can use Prim or Kruskal.

Example:
n = 4
edges = {{0,1,1}, {0,2,4}, {1,2,2}, {1,3,5}, {2,3,3}}

Example output:
Minimum cost: 6
*/

#include <stdio.h>
#include <limits.h>

int minCostToConnectCities(int n, int edges[][3], int edgesSize)
{
    int adj[100][100] = {0};
    int visited[100] = {0};
    int totalCost = 0;
    int edgeCount = 0;

    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u][v] = w;
        adj[v][u] = w;
    }

    visited[0] = 1;

    while (edgeCount < n - 1)
    {
        int minWeight = INT_MAX;
        int nextCity = -1;

        for (int u = 0; u < n; u++)
        {
            if (visited[u])
            {
                for (int v = 0; v < n; v++)
                {
                    if (!visited[v] && adj[u][v] != 0 && adj[u][v] < minWeight)
                    {
                        minWeight = adj[u][v];
                        nextCity = v;
                    }
                }
            }
        }

        if (nextCity == -1)
        {
            return -1;
        }

        visited[nextCity] = 1;
        totalCost += minWeight;
        edgeCount++;
    }

    return totalCost;
}

int main()
{
    int n = 4;
    int edges[][3] = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 3}
    };

    int edgesSize = sizeof(edges) / sizeof(edges[0]);
    int result = minCostToConnectCities(n, edges, edgesSize);

    printf("Minimum cost: %d\n", result);

    return 0;
}
