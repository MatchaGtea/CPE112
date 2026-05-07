/*
Topic: Graph
Question 3: DFS using a stack

What to do:
- Complete dfsStack.
- Use an explicit stack, not recursion.
- Return visited nodes in DFS order until target is found.
- Always visit neighbors in increasing index order.
- With a stack, push neighbors from high index down to low index.
- If target is unreachable, return -1.

Example input:
5
0 1 1 0 0
0 0 0 1 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 4

Example output:
0 1 3 2 4
*/

#include <stdio.h>

#define MAX 100

int dfsStack(int n, int adj[][MAX], int start, int target, int result[])
{
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;
    int size = 0;

    // TODO: push start onto stack

    while (top != -1)
    {
        // TODO: pop current node from stack
        // TODO: skip if already visited
        // TODO: mark visited and save into result[size++]
        // TODO: if current == target, return size
        // TODO: push unvisited neighbors from n - 1 down to 0
    }

    // TODO: return -1 if target not found
    return -1;
}

int main()
{
    int n;
    int adj[MAX][MAX];
    int result[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    int start, target;
    scanf("%d %d", &start, &target);

    int size = dfsStack(n, adj, start, target, result);

    if (size == -1)
    {
        printf("-1\n");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d", result[i]);
            if (i < size - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
