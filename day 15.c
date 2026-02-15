#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    // Input matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (i == j) {   // Primary diagonal condition
                sum += matrix[i][j];
            }
        }
    }

    // Output the sum of primary diagonal
    printf("%d\n", sum);

    return 0;
}