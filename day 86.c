#include <stdio.h>

int integerSquareRoot(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid == n) {
            return mid;  // Perfect square
        }

        if ((long long)mid * mid < n) {
            ans = mid;       // Store possible answer
            low = mid + 1;   // Search right half
        } else {
            high = mid - 1;  // Search left half
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int result = integerSquareRoot(n);
    printf("%d\n", result);

    return 0;
}
