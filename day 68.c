#include <stdio.h>
#include <stdlib.h>

// Function to perform Kahn's Algorithm for Topological Sort
void topologicalSort(int n, int adj[n][n]) {
    int in_degree[n];
    for (int i = 0; i < n; i++)
        in_degree[i] = 0;

    // Calculate in-degree of each vertex
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                in_degree[v]++;
            }
        }
    }

    // Queue for vertices with in-degree 0
    int queue[n], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0; // Count of visited vertices
    int topo_order[n];

    while (front < rear) {
        int u = queue[front++];
        topo_order[count++] = u;

        // Reduce in-degree of neighbors
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // Check if topological sort is possible (no cycle)
    if (count != n) {
        printf("Graph contains a cycle. Topological sort not possible.\n");
        return;
    }

    // Print topological order
    printf("Topological Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", topo_order[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(n, adj);

    return 0;
}
