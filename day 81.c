#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    scanf("%d", &n); // Read size of array
    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read array elements
    }

    bubbleSort(arr, n);

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print sorted array
    }

    return 0;
}
