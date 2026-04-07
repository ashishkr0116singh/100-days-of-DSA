#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];   // adjacency matrix
int visited[MAX];      // visited array
int recStack[MAX];     // recursion stack
int V;                 // number of vertices

// DFS helper function
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int u = 0; u < V; u++) {
        if (graph[v][u]) {
            if (!visited[u] && dfs(u)) {
                return 1; // cycle found
            } else if (recStack[u]) {
                return 1; // cycle found
            }
        }
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

// Function to detect cycle
int isCyclic() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i)) return 1;
        }
    }
    return 0;
}

int main() {
    int E; // number of edges
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
        recStack[i] = 0;
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed edge u -> v
    }

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
