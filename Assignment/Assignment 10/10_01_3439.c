#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define NUM_COURSES 11

const char* course_names[] = {
    "CPE100", "CPE112", "CPE231", "CPE232", "CPE241",
    "CPE223", "CPE333", "CPE334", "CPE314", "CPE401", "CPE402"
};

// Structure to represent a graph
struct Graph {
    int V;                 // Number of vertices
    int adj[MAX][MAX];     // Adjacency matrix
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// Function to add a directed edge from u to v
void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
}

// Function to perform Kahn’s Algorithm
void kahnTopologicalSort(struct Graph* graph) {
    int in_degree[MAX] = {0};

    // TODO 1: Compute in-degrees of all vertices
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    int queue[MAX], front = 0, rear = 0;

    // TODO 2: Enqueue all vertices with in-degree 0
    for (int i = 0; i < graph->V; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int top_order[MAX];

    // TODO 3: Process vertices in the queue
    while (front < rear) {
        int u = queue[front++];
        top_order[count++] = u;

        for (int i = 0; i < graph->V; i++) {
            if (graph->adj[u][i] == 1) {
                in_degree[i]--;

                if (in_degree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Check if there was a cycle in the graph
    if (count != graph->V) {
        printf("Error: Circular prerequisite detected! Not a DAG.\n");
        return;
    }

    // Print the topological order using course string names
    for (int i = 0; i < count; i++) {
        printf("%s", course_names[top_order[i]]);
        if (i < count - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

void solve(void) {
    struct Graph* graph = createGraph(NUM_COURSES);

    /* Building the DAG based on the curriculum diagram */
    addEdge(graph, 0, 1);   /* CPE100 -> CPE112 */

    addEdge(graph, 1, 2);   /* CPE112 -> CPE231 */
    addEdge(graph, 1, 3);   /* CPE112 -> CPE232 */
    addEdge(graph, 1, 5);   /* CPE112 -> CPE223 */

    addEdge(graph, 3, 4);   /* CPE232 -> CPE241 */

    addEdge(graph, 5, 6);   /* CPE223 -> CPE333 */
    addEdge(graph, 2, 6);   /* CPE231 -> CPE333 */

    addEdge(graph, 2, 7);   /* CPE231 -> CPE334 */
    addEdge(graph, 4, 7);   /* CPE241 -> CPE334 */

    addEdge(graph, 6, 8);   /* CPE333 -> CPE314 */
    addEdge(graph, 7, 8);   /* CPE334 -> CPE314 */

    addEdge(graph, 7, 9);   /* CPE334 -> CPE401 */
    addEdge(graph, 9, 10);  /* CPE401 -> CPE402 */

    /* Run Kahn’s Algorithm */
    kahnTopologicalSort(graph);

    free(graph);
}

int main(void) {
    solve();
    return 0;
}