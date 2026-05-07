/*
Topic: Graph
Question 1: Indegree of a target node

What to do:
- Complete getIndegree.
- Count how many directed edges go into target.
- Each edge is edges[i][0] -> edges[i][1].
- If edges[i][1] == target, increment indegree.

Example input:
4 4
0 1
0 2
1 2
2 3
2

Example output:
2
*/

#include <stdio.h>

#define MAXM 500

int getIndegree(int n, int edges[][2], int m, int target)
{
    int indegree = 0;

    // TODO: loop through all m edges
    // TODO: count edges where edges[i][1] == target

    return indegree;
}

int main()
{
    int n, m;
    int edges[MAXM][2];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int target;
    scanf("%d", &target);

    int result = getIndegree(n, edges, m, target);
    printf("%d\n", result);

    return 0;
}
