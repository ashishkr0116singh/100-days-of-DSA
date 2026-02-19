#include <stdio.h>

void rotateArray(int arr[], int n, int k) {
    k = k % n;  // Handle cases where k >= n
    int temp[n];

    // Copy last k elements to temp
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Copy first n-k elements to temp
    for (int i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }

    // Copy temp back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    rotateArray(arr, n, k);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}