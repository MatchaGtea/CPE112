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
    int totalCost = 0;

    // TODO: choose Prim or Kruskal MST
    // TODO: select n - 1 edges with minimum total cost
    // TODO: if not all cities can be connected, return -1

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
