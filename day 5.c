#include <stdio.h>

int main() {
    int p, q;
    
    // Read size of first log
    scanf("%d", &p);
    int log1[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    
    // Read size of second log
    scanf("%d", &q);
    int log2[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    
    int i = 0, j = 0;
    
    // Merge process
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }
    
    // Print remaining elements
    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }
    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }
    
    return 0;
}