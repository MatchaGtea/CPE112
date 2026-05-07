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

#define MAXN 100
#define MAXM 500

int shortestDistanceToTarget(int n, int edges[][3], int m, int start, int target)
{
    int dist[MAXN];
    int visited[MAXN] = {0};

    // TODO: initialize dist[i] to INT_MAX
    // TODO: set dist[start] = 0
    // TODO: repeat n times:
    // TODO: choose the unvisited node with the smallest dist
    // TODO: relax all outgoing edges from that node
    // TODO: return dist[target], or -1 if unreachable

    return -1;
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
