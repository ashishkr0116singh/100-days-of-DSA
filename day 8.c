#include <math.h>
#include <stdio.h>

int power(int a, int b);

int main() {

    int a, b;
    scanf("%d %d", &a, &b);
    int exp = power(a, b);
    printf("%d\n", exp);

    return 0;
}

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * power(a, b - 1);
}