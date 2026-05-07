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

## Fast Recognition Table

Use this when you freeze during the exam.

| Words in problem | Data shape | Pattern to use |
|---|---|---|
| sorted output from inserted values | `struct Node* root` | BST insert + inorder |
| next larger value | BST | inorder successor |
| remove a leaf | BST | search, then return `NULL` when found |
| preorder/inorder/postorder | binary tree | recursive traversal |
| adjacency matrix | `adj[MAX][MAX]` | nested loops over `u` and `v` |
| visit all reachable vertices | graph | BFS queue or DFS recursion/stack |
| shortest path | weighted graph | Dijkstra |
| connect all cities/minimum network | undirected weighted graph | Prim or Kruskal MST |
| prerequisite order | directed acyclic graph | Kahn topological sort |
| index from key | array table | `key % TABLE_SIZE` |
| collision | hash table | linear probing |
| count repeated IDs | hash entry has `frequency` | increment if same key found |

## C Syntax That Saves Time

### Arrays

```c
int arr[100] = {0};      // all zeros
int visited[100] = {0};  // all unvisited
```

For a 2D matrix:

```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        matrix[i][j] = 0;
    }
}
```

### Struct Pointers

Use `->` when you have a pointer:

```c
root->left = NULL;
root->key = value;
```

Use `.` when you have the actual struct variable:

```c
edge.weight = 10;
```

### Queue Template

Used by BFS and Kahn topological sort.

```c
int queue[MAX];
int front = 0;
int rear = 0;

queue[rear++] = start;

while (front < rear) {
    int current = queue[front++];
}
```

### Stack Template

Used by iterative DFS.

```c
int stack[MAX];
int top = -1;

stack[++top] = start;

while (top != -1) {
    int current = stack[top--];
}
```

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

### Graph Format From `Prepare/Graph.c`

Use this format first when thinking about graph questions in this course:

```c
#define MAX_VERTICES 10

typedef struct Graph_t {
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;
```

Meaning:
- `Graph *g` is a pointer to the graph.
- `g->V` is the number of vertices.
- `g->adj[from][to]` tells whether there is an edge `from -> to`.
- Vertices are stored as numbers: `0 = A`, `1 = B`, `2 = C`.

Create an empty graph:

```c
Graph *Graph_create(int V) {
    Graph *g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }

    return g;
}
```

Add a directed edge:

```c
void Graph_addEdge(Graph *g, int v, int w) {
    g->adj[v][w] = true;
}
```

This means:

```text
v -> w
```

Example:

```c
Graph_addEdge(g, 0, 1);
```

means:

```text
A -> B
```

If the graph is undirected, add both directions:

```c
Graph_addEdge(g, v, w);
Graph_addEdge(g, w, v);
```

### Reading `g->adj[current][i]`

The course graph format uses:

```c
g->adj[row][column]
```

For graph traversal:

```c
g->adj[current][i]
```

Meaning:
- `current` is the current row.
- `i` is the column being checked.
- `g->adj[current][i] == true` means `current -> i`.

Matrix view:

```text
          i
          A  B  C  D  E
current
A         0  1  1  0  0
B         0  0  0  1  0
C         0  0  0  0  1
D         0  0  0  0  0
E         0  0  0  0  0
```

If `current = A`, the loop checks the whole row of A:

```text
A -> A
A -> B
A -> C
A -> D
A -> E
```

### Matrix Loop Patterns In `Graph`

These show up when the graph is stored as a matrix, or when the question is a simple 2D array task.

Print the adjacency matrix:

```c
void Graph_print(Graph *g) {
    for (int i = 0; i < g->V; i++) {
        printf("[ ");
        for (int j = 0; j < g->V; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("]\n");
    }
}
```

Count outgoing edges from `v`:

```c
int getOutdegree(Graph *g, int v) {
    int count = 0;

    for (int i = 0; i < g->V; i++) {
        if (g->adj[v][i] == true) {
            count++;
        }
    }

    return count;
}
```

Key idea:

```text
outdegree(v) = count row v
g->adj[v][i] means v -> i
```

### Indegree

Indegree of `target` means count edges going into `target`.

In this graph format, count the column of `target`:

```c
int getIndegree(Graph *g, int target) {
    int indegree = 0;

    for (int i = 0; i < g->V; i++) {
        if (g->adj[i][target] == true) {
            indegree++;
        }
    }

    return indegree;
}
```

Connection:
- Outgoing edge: `g->adj[target][i]`, row of `target`.
- Incoming edge: `g->adj[i][target]`, column of `target`.

Example:

```text
A -> C
B -> C
D -> C
C -> E
```

For `C`, check the column of C:

```text
A -> C = true
B -> C = true
C -> C = false
D -> C = true
E -> C = false
```

So:

```text
indegree(C) = 3
```

### BFS With Queue

```c
void Graph_BFS(Graph *g, int s) {
    bool visited[MAX_VERTICES];

    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    int front = 0;
    int rear = 0;
    int queue[MAX_VERTICES];

    queue[rear++] = s;
    visited[s] = true;

    while (front != rear) {
        int current = queue[front++];
        printf("%c ", current + 65);

        for (int i = 0; i < g->V; i++) {
            if (g->adj[current][i] == true && visited[i] == false) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}
```

Purpose of each variable:
- `visited[i]` prevents visiting the same vertex again.
- `queue[]` stores vertices waiting to be processed.
- `front` points to the next queue item to pop.
- `rear` points to the next queue slot to push.
- `current` is the vertex being processed now.
- `i` scans every possible neighbor of `current`.

Important lines:

```c
queue[rear++] = s;
visited[s] = true;
```

Put the starting vertex into the queue.

```c
int current = queue[front++];
```

Pop the next vertex from the queue.

```c
if (g->adj[current][i] == true && visited[i] == false)
```

If there is an edge `current -> i` and `i` was not visited, push `i` into the queue.

Example input:

```text
5 4
0 1
0 2
1 3
2 4
0
```

Meaning:

```text
A -> B
A -> C
B -> D
C -> E
start = A
```

Output:

```text
A B C D E
```

Flow:

| Step | current | New vertices pushed | Queue waiting | Output |
|---|---|---|---|---|
| start | - | A | A | - |
| 1 | A | B, C | B, C | A |
| 2 | B | D | C, D | A B |
| 3 | C | E | D, E | A B C |
| 4 | D | - | E | A B C D |
| 5 | E | - | empty | A B C D E |

### Recursive Graph DFS In Same Format

DFS means go deep first. It is the graph version of tree traversal, but with `visited`.

```c
void DFSearch(Graph *g, int s, bool visited[]) {
    visited[s] = true;
    printf("%c ", s + 65);

    for (int i = 0; i < g->V; i++) {
        if (g->adj[s][i] == true && visited[i] == false) {
            DFSearch(g, i, visited);
        }
    }
}
```

Wrapper:

```c
void Graph_DFS(Graph *g, int s) {
    bool visited[MAX_VERTICES];

    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    DFSearch(g, s, visited);
}
```

Connection:
- BFS uses `queue`.
- DFS uses recursion or stack.
- Both scan neighbors with `for (int i = 0; i < g->V; i++)`.
- Both need `visited` because graphs can have cycles.

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

### Dijkstra with Path Printing

If the exam asks for the actual path, store `parent[to] = u` when relaxing an edge.

```c
void printPath(int parent[], int node) {
    if (parent[node] == -1) {
        printf("%d ", node);
        return;
    }

    printPath(parent, parent[node]);
    printf("%d ", node);
}
```

Dijkstra update with parent:

```c
if (dist[u] != INT_MAX && dist[u] + weight < dist[to]) {
    dist[to] = dist[u] + weight;
    parent[to] = u;
}
```

Initialization:

```c
for (int i = 0; i < n; i++) {
    dist[i] = INT_MAX;
    parent[i] = -1;
}
dist[start] = 0;
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

### Kruskal MST

Kruskal sorts edges by weight and adds an edge only if it connects two different sets.

Core idea:
- `parent[i] = i` means each node starts in its own set.
- `find(parent, i)` returns the representative of node `i`.
- If two endpoints have different representatives, adding the edge will not create a cycle.

Union-find:

```c
int find(int parent[], int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unite(int parent[], int rank[], int a, int b) {
    int rootA = find(parent, a);
    int rootB = find(parent, b);

    if (rootA == rootB) return;

    if (rank[rootA] < rank[rootB]) {
        parent[rootA] = rootB;
    } else if (rank[rootA] > rank[rootB]) {
        parent[rootB] = rootA;
    } else {
        parent[rootB] = rootA;
        rank[rootA]++;
    }
}
```

Edge sort helper:

```c
typedef struct {
    int src;
    int dst;
    int weight;
} Edge;

int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}
```

Kruskal total cost pattern:

```c
int kruskalMST(int n, Edge edges[], int edgeCount) {
    int parent[MAX];
    int rank[MAX] = {0};
    int total = 0;
    int chosen = 0;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    for (int i = 0; i < edgeCount && chosen < n - 1; i++) {
        int a = edges[i].src;
        int b = edges[i].dst;

        if (find(parent, a) != find(parent, b)) {
            unite(parent, rank, a, b);
            total += edges[i].weight;
            chosen++;
        }
    }

    if (chosen != n - 1) return -1;
    return total;
}
```

Kruskal vs Prim:
- Prim grows one connected tree from a start node.
- Kruskal sorts all edges first.
- Both must select exactly `n - 1` edges for a connected graph.

### Topological Sort with Kahn Algorithm

Use this for prerequisite/order problems.

Rules:
- Directed graph only.
- Works only if there is no cycle.
- Start with all nodes that have indegree 0.

Pattern:

```c
int topoSort(int n, int adj[][MAX], int order[]) {
    int indegree[MAX] = {0};
    int queue[MAX];
    int front = 0;
    int rear = 0;
    int count = 0;

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        order[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != n) return -1;
    return count;
}
```

Connection:
- Indegree is the number of prerequisites still blocking a node.
- When a node is processed, it removes its outgoing edges.
- If not all nodes are processed, there is a cycle.

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

### Hash Table with Frequency Count

Use this when the table stores both an ID and a count.

```c
typedef struct {
    int id;
    int frequency;
} HashEntry;

HashEntry table[TABLE_SIZE];
```

Initialize:

```c
void initTable(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].id = -1;
        table[i].frequency = 0;
    }
}
```

Insert or increment:

```c
void insertAndCount(int id) {
    int index = id % TABLE_SIZE;

    while (table[index].id != -1 && table[index].id != id) {
        index = (index + 1) % TABLE_SIZE;
    }

    if (table[index].id == -1) {
        table[index].id = id;
        table[index].frequency = 1;
    } else {
        table[index].frequency++;
    }
}
```

Print entries above a threshold:

```c
void printAtLeast(int threshold) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].id != -1 && table[i].frequency >= threshold) {
            printf("%d %d\n", table[i].id, table[i].frequency);
        }
    }
}
```

Important difference:
- Plain hash insert stops only at an empty slot.
- Frequency hash insert stops at an empty slot or the same ID.

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

## Last-Hour Drills

Do these quickly on paper or in a blank C file.

### Drill 1: BST

Input values:

```text
50 30 70 20 40 60 80
```

Expected inorder:

```text
20 30 40 50 60 70 80
```

Questions:
- What is the successor of `40`? Answer: `50`.
- What is the successor of `50`? Answer: `60`.
- What is the successor of `80`? Answer: no successor.

### Drill 2: Traversal

Tree:

```text
        A
       / \
      B   C
     / \   \
    D   E   F
```

Answers:
- Preorder: `A B D E C F`
- Inorder: `D B E A C F`
- Postorder: `D E B F C A`

### Drill 3: Graph Indegree

Using `Graph_addEdge`:

```c
Graph_addEdge(g, 0, 1);
Graph_addEdge(g, 0, 2);
Graph_addEdge(g, 1, 2);
Graph_addEdge(g, 3, 2);
```

`getIndegree(g, 2)` returns `3` because `0 -> 2`, `1 -> 2`, and `3 -> 2`.

### Drill 4: BFS vs DFS

Adjacency:

```text
0 -> 1, 2
1 -> 3
2 -> 4
```

Starting from `0` and scanning neighbors from low to high:
- BFS order: `0 1 2 3 4`
- Recursive DFS order: `0 1 3 2 4`

### Drill 5: Linear Probing

Table size `5`, insert:

```text
12 7 17
```

Indexes:
- `12 % 5 = 2`, put 12 at index 2.
- `7 % 5 = 2`, collision, put 7 at index 3.
- `17 % 5 = 2`, collision at 2 and 3, put 17 at index 4.

Final table:

```text
0: -1
1: -1
2: 12
3: 7
4: 17
```

### Drill 6: Kahn Topological Sort

Edges:

```text
0 -> 2
1 -> 2
2 -> 3
```

Initial indegrees:

```text
0: 0
1: 0
2: 2
3: 1
```

One valid order is:

```text
0 1 2 3
```

`1 0 2 3` is also valid because both `0` and `1` start with indegree 0.

## High-Yield Practice Checklist

Do these without looking:

- [ ] Write `struct Node`.
- [ ] Write BST `insert`.
- [ ] Write `inorder`.
- [ ] Write `findMin`.
- [ ] Explain inorder successor cases.
- [ ] Count nodes with exactly one child.
- [ ] Delete BST node with exactly one child.
- [ ] Write `Graph_create`.
- [ ] Write `Graph_addEdge`.
- [ ] Count indegree with `g->adj[i][target]`.
- [ ] Do `Graph_BFS` with `queue`, `front`, and `rear`.
- [ ] Explain `g->adj[current][i]`.
- [ ] Write Dijkstra from an edge list.
- [ ] Write Prim MST total cost.
- [ ] Initialize hash table with `-1`.
- [ ] Insert with linear probing and wraparound.
- [ ] Find first repeated ID using `seen`.

## Exam-Day Strategy

1. Read the problem and circle the data structure:
   - `Graph *g`: course graph struct with `g->V` and `g->adj[from][to]`.
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
- `g->adj[from][to]` means `from -> to`.
- Graph indegree checks the column: `g->adj[i][target]`.
- Graph BFS uses `queue`, `front`, `rear`, and `visited`.
- Dijkstra uses `dist[]` and `visited[]`.
- MST chooses cheapest edge connecting visited to unvisited.
- Hash index is `key % m`.
- Linear probing is `(index + 1) % m`.
- First repeat uses `seen[value]`.

