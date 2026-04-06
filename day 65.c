#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices supported

// DFS utility to detect cycle
bool dfsCycle(int v, bool visited[], int parent, int adj[][MAX], int V) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfsCycle(i, visited, v, adj, V))
                    return true;
            }
            else if (i != parent) {
                return true; // Found a cycle
            }
        }
    }
    return false;
}

// Function to check if graph contains cycle
bool isCycle(int edges[][2], int E, int V) {
    if (V <= 0 || E <= 0) return false; // Edge cases

    int adj[MAX][MAX] = {0};     // adjacency matrix
    bool visited[MAX] = {false}; // visited array

    // Build adjacency matrix safely
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Input validation
        if (u < 0 || u >= V || v < 0 || v >= V) {
            return false; // invalid edge
        }

        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    // Check each component
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, visited, -1, adj, V))
                return true;
        }
    }
    return false;
}

// Driver code
int main() {
    int V = 4, E = 4;
    int edges[4][2] = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};

    if (isCycle(edges, E, V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
