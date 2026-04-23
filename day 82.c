#include <stdio.h>

// Function to find the lower bound
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

// Function to find the upper bound
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int n, x;
    scanf("%d", &n); // Read size of array
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read sorted array elements
    }

    scanf("%d", &x); // Read target value

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}
