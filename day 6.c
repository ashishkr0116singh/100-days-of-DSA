#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int j = 0; // index for unique elements
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    printf("Unique elements: ");
    for (int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}