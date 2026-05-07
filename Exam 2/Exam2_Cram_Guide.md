# CPE112 Exam 2 Cram Guide

This guide is a memory file for future chats and a one-day study path for Exam 2.
It assumes I know almost nothing yet, but I can learn fast.

Source context:
- Exam guideline: `Exam 2/[Students]-M2-Programming Exam-Exercises-2026.pdf`
- Related assignments: Assignment 6 to Assignment 10
- Exam format from guideline: 3 programming questions, 2 hours
- Language: C or C++, with C templates provided

## Big Picture

Exam 2 is about three families:

1. Trees
2. Graphs
3. Hashing

The main skill is not memorizing huge code. The main skill is recognizing the pattern in the template and filling the missing function correctly.

Assignments connect like this:

| Assignment | Topic | What it trains |
|---|---|---|
| Assignment 6 | Binary Search Tree | Insert, inorder traversal, delete |
| Assignment 7 | Binary Tree Traversal | Preorder, inorder, postorder |
| Assignment 8 | Graph Basics | Adjacency matrix, BFS, DFS |
| Assignment 9 | Graph Algorithms | Matrix sums, Prim, Kruskal, Dijkstra |
| Assignment 10 | Topological Sort, Hashing | Kahn algorithm, linear probing, frequency counting |

## One-Day Cram Schedule

### Hour 1: C Template Survival

Know these before touching algorithms:

- `scanf` reads input.
- Arrays are passed into functions by reference.
- `int edges[][2]` means every edge has 2 values, usually `u` and `v`.
- `int edges[][3]` means every edge has 3 values, usually `u`, `v`, and `w`.
- `visited[i] = 1` means node `i` has already been processed.
- `return -1` usually means not found, impossible, or unreachable.

Common template strategy:

1. Read the function prototype.
2. Identify the input data structure.
3. Ignore `main` unless input/output format matters.
4. Fill only the TODO function.
5. Test with the examples.

## Trees

### Core Ideas

A binary tree node usually looks like:

```c
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
```

A Binary Search Tree has this rule:

- Values smaller than the current node go left.
- Values larger than or equal to the current node go right.

### Traversal Patterns

Preorder:

```c
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
```

Inorder:

```c
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
```

Postorder:

```c
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
```

Important connection:
- Inorder traversal of a BST prints values in sorted order.
- That is why "inorder successor" means the next larger value.

### BST Insert Pattern

```c
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        struct Node* node = malloc(sizeof(struct Node));
        node->data = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}
```

### Find Minimum in Subtree

Used for inorder successor.

```c
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}
```

### Inorder Successor

Two cases:

1. If the node has a right subtree, successor is the minimum node in the right subtree.
2. If the node has no right subtree, successor is the lowest ancestor bigger than the key.

Pattern:

```c
void findSuccessor(struct Node* root, int key) {
    struct Node* current = root;
    struct Node* successor = NULL;

    while (current != NULL) {
        if (key < current->data) {
            successor = current;
            current = current->left;
        } else if (key > current->data) {
            current = current->right;
        } else {
            if (current->right != NULL) {
                successor = findMin(current->right);
            }
            break;
        }
    }

    if (current == NULL) {
        printf("Key not found\n");
    } else if (successor == NULL) {
        printf("No successor\n");
    } else {
        printf("%d\n", successor->data);
    }
}
```

### Count Nodes with Exactly One Child

Recursive idea:

- If root is `NULL`, count is 0.
- If exactly one child is non-NULL, count this node.
- Add left subtree count and right subtree count.

```c
int countSingleChildNodes(struct Node* root) {
    if (root == NULL) return 0;

    int count = 0;
    if ((root->left != NULL && root->right == NULL) ||
        (root->left == NULL && root->right != NULL)) {
        count = 1;
    }

    return count
        + countSingleChildNodes(root->left)
        + countSingleChildNodes(root->right);
}
```

### Delete BST Node with One Child

If found node has only right child, return right child.
If found node has only left child, return left child.

```c
struct Node* deleteOneChild(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deleteOneChild(root->left, key);
    } else if (key > root->data) {
        root->right = deleteOneChild(root->right, key);
    } else {
        if (root->left == NULL && root->right != NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL && root->left != NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        return root;
    }

    return root;
}
```

Tree common bugs:

- Forgetting `if (root == NULL) return`.
- Forgetting to return `root` after recursive insert/delete.
- Using `root.data` instead of `root->data`.
- Losing a subtree when deleting.

## Graphs

### Graph Representations

Edge list for unweighted directed graph:

```c
edges[i][0] = u;
edges[i][1] = v;
```

This means `u -> v`.

Edge list for weighted directed graph:

```c
edges[i][0] = u;
edges[i][1] = v;
edges[i][2] = w;
```

This means `u -> v` with cost `w`.

Adjacency matrix:

```c
adj[u][v] = 1;
```

This means `u -> v`.

For undirected graphs:

```c
adj[u][v] = w;
adj[v][u] = w;
```

### Indegree

Indegree of `target` means count edges going into `target`.

```c
int getIndegree(int n, int edges[][2], int m, int target) {
    int indegree = 0;

    for (int i = 0; i < m; i++) {
        if (edges[i][1] == target) {
            indegree++;
        }
    }

    return indegree;
}
```

Connection:
- Outgoing edge checks `edges[i][0]`.
- Incoming edge checks `edges[i][1]`.

### DFS with Stack

DFS means go deep before trying other branches.

For exam question with adjacency matrix:

- Use `stack`.
- Use `visited`.
- Save visited order into `result`.
- Stop when target is found.
- If target is unreachable, return `-1`.
- To visit neighbors in increasing index order using a stack, push neighbors from high to low.

```c
int dfsStack(int n, int adj[][MAX], int start, int target, int result[]) {
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;
    int size = 0;

    stack[++top] = start;

    while (top != -1) {
        int current = stack[top--];

        if (visited[current]) continue;

        visited[current] = 1;
        result[size++] = current;

        if (current == target) {
            return size;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
            }
        }
    }

    return -1;
}
```

Connection:
- Tree traversal is DFS without `visited`.
- Graph DFS needs `visited` because graphs can have cycles.

### Dijkstra Shortest Path

Used when edges have non-negative weights.

Goal:
- Find minimum distance from `start` to `target`.
- Return `-1` if unreachable.

Core arrays:

- `dist[i]`: best known distance from start to i.
- `visited[i]`: finalized nodes.

Pattern for edge-list version:

```c
int shortestDistanceToTarget(int n, int edges[][3], int m, int start, int target) {
    int dist[MAXN];
    int visited[MAXN] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        int best = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int i = 0; i < m; i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];

            if (from == u && !visited[to] && dist[u] != INT_MAX) {
                if (dist[u] + weight < dist[to]) {
                    dist[to] = dist[u] + weight;
                }
            }
        }
    }

    if (dist[target] == INT_MAX) return -1;
    return dist[target];
}
```

Dijkstra common bugs:

- Forgetting `#include <limits.h>`.
- Not initializing all distances to `INT_MAX`.
- Adding to `INT_MAX`.
- Treating directed edges as undirected when the problem says directed.

### Minimum Spanning Tree

MST connects all nodes with minimum total cost.

Important:
- MST is for undirected weighted graphs.
- If all cities cannot be connected, return `-1`.
- Number of selected edges must be `n - 1`.

Prim-style pattern:

```c
int minCostToConnectCities(int n, int edges[][3], int edgesSize) {
    int adj[100][100] = {0};
    int visited[100] = {0};
    int totalCost = 0;
    int edgeCount = 0;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u][v] = w;
        adj[v][u] = w;
    }

    visited[0] = 1;

    while (edgeCount < n - 1) {
        int minWeight = INT_MAX;
        int next = -1;

        for (int u = 0; u < n; u++) {
            if (visited[u]) {
                for (int v = 0; v < n; v++) {
                    if (!visited[v] && adj[u][v] != 0 && adj[u][v] < minWeight) {
                        minWeight = adj[u][v];
                        next = v;
                    }
                }
            }
        }

        if (next == -1) {
            return -1;
        }

        visited[next] = 1;
        totalCost += minWeight;
        edgeCount++;
    }

    return totalCost;
}
```

Connection:
- Dijkstra finds shortest path from one start.
- Prim finds cheapest total network.
- Both repeatedly choose a minimum value among unvisited nodes.

## Hashing

### Hash Function

```c
index = key % table_size;
```

Hashing turns a large key into an array index.

### Linear Probing

If the calculated index is occupied, move to the next index.

```c
index = (index + 1) % m;
```

The `% m` makes it wrap around to the beginning.

### Insert Hash with Linear Probing

```c
void insertHash(int table[], int m, int keys[], int n) {
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = key % m;
        int tries = 0;

        while (tries < m && table[index] != -1) {
            index = (index + 1) % m;
            tries++;
        }

        if (tries < m) {
            table[index] = key;
        }
    }
}
```

Common bug:
- Forgetting to initialize empty slots to `-1`.

### First Repeating Value

If values are bounded, use a seen array.

For IDs from `0` to `1000`:

```c
int firstRepeating(int arr[], int n) {
    int seen[1001] = {0};

    for (int i = 0; i < n; i++) {
        if (seen[arr[i]]) {
            return arr[i];
        }
        seen[arr[i]] = 1;
    }

    return -1;
}
```

Connection:
- Hash table stores by calculated index.
- Seen/frequency array is a simple direct-address hash table.

## Topic Connections

Trees and graphs:
- A tree is a graph with no cycles.
- Tree traversal does not need `visited`.
- Graph traversal needs `visited`.

DFS and recursion:
- Recursive tree traversal is DFS.
- Recursive graph DFS also works, but the exam may ask for stack DFS.

BST and sorted order:
- BST structure gives sorted order through inorder traversal.
- Inorder successor is the next larger value.

Dijkstra and Prim:
- Both use `visited`.
- Both repeatedly pick a smallest candidate.
- Dijkstra minimizes path distance from a start node.
- Prim minimizes total connection cost.

Hashing and arrays:
- Hashing is array indexing with a formula.
- Linear probing is just controlled movement through the array.

## High-Yield Practice Checklist

Do these without looking:

- [ ] Write `struct Node`.
- [ ] Write BST `insert`.
- [ ] Write `inorder`.
- [ ] Write `findMin`.
- [ ] Explain inorder successor cases.
- [ ] Count nodes with exactly one child.
- [ ] Delete BST node with exactly one child.
- [ ] Count indegree from edge list.
- [ ] Do stack DFS from adjacency matrix.
- [ ] Explain why stack DFS pushes neighbors from high to low.
- [ ] Write Dijkstra from an edge list.
- [ ] Write Prim MST total cost.
- [ ] Initialize hash table with `-1`.
- [ ] Insert with linear probing and wraparound.
- [ ] Find first repeated ID using `seen`.

## Exam-Day Strategy

1. Read the problem and circle the data structure:
   - `edges[][2]`: graph edge list without weights.
   - `edges[][3]`: graph edge list with weights.
   - `adj[][MAX]`: adjacency matrix.
   - `struct Node* root`: tree.
   - `table[]`, `keys[]`, `arr[]`: hashing or frequency.

2. Identify the return rule:
   - Count: return an integer count.
   - Reachability: return size or `-1`.
   - Shortest path: return distance or `-1`.
   - MST: return total cost or `-1`.

3. Use the simplest correct pattern.

4. Test mentally with sample input.

5. Watch for these common bugs:
   - Off-by-one loops.
   - Not initializing arrays.
   - Forgetting `return`.
   - Directed vs undirected edge confusion.
   - Stack order in DFS.
   - `root->data` pointer syntax.

## Minimum Memory Set

If there is almost no time, memorize these:

- BST insert recursion.
- Inorder is left, root, right.
- Graph indegree checks destination.
- DFS stack needs `visited`.
- Dijkstra uses `dist[]` and `visited[]`.
- MST chooses cheapest edge connecting visited to unvisited.
- Hash index is `key % m`.
- Linear probing is `(index + 1) % m`.
- First repeat uses `seen[value]`.

