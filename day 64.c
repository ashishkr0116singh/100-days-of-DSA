#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];   // Array to track visited vertices

// Recursive DFS function
void dfs(int v, int adj[MAX][MAX], int n) {
    visited[v] = 1;   // Mark current vertex as visited
    printf("%d ", v); // Print the vertex

    // Explore all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, adj, n);
        }
    }
}

int main() {
    int n, s;
    int adj[MAX][MAX];

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Input starting vertex
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from vertex %d:\n", s);
    dfs(s, adj, n);

    return 0;
}
