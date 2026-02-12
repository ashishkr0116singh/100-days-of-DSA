#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // A symmetric matrix must be square
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    // Check symmetry: element[i][j] == element[j][i]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix\n");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix\n");
    return 0;
}