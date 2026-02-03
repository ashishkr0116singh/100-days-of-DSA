#include <stdio.h>

int main() {
    int n, k, i, comparisons = 0;
    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", comparisons);
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Comparisons = %d\n", comparisons);

    return 0;
}