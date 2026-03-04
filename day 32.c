#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

// Function to pop an element
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        top--;
    }
}

int main() {
    int n, m, i, x;

    // Input number of elements to push
    scanf("%d", &n);

    // Push n elements
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // Input number of pops
    scanf("%d", &m);

    // Perform m pops
    for (i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack elements from top to bottom
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}