#include <stdio.h>
#define INF 1000000000  // A large value to represent infinity

int main() {
    int n;
    scanf("%d", &n);

    int graph[n][n];

    // Read adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1 && i != j) {
                graph[i][j] = INF;  // Replace -1 with INF for no edge
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Print shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                printf("-1 ");
            } else {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
