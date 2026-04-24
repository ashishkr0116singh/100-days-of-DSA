#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, i;
    scanf("%d", &n); // Read number of elements
    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read array elements
    }

    selectionSort(arr, n);

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print sorted array
    }

    return 0;
}
