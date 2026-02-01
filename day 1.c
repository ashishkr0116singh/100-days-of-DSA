#include <stdio.h>

int main() {
    int n, pos, x;
    
    // Read size of array
    scanf("%d", &n);
    
    int arr[n+1]; // Allocate space for n+1 elements
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read position and element to insert
    scanf("%d", &pos);
    scanf("%d", &x);
    
    // Shift elements to the right from pos-1
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    
    // Insert element at position (1-based index)
    arr[pos-1] = x;
    
    // Print updated array
    for (int i = 0; i <= n; i++) {
        printf("%d", arr[i]);
        if (i < n) printf(" ");
    }
    
    return 0;
}