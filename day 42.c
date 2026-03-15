#include <stdio.h>
#include <stdlib.h>

// Queue using array
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;

// Stack using array
int stack[MAX];
int top = -1;

// Queue operations
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Stack operations
void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);

    // Input queue elements
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(val);
    }

    // Step 1: Move all queue elements to stack
    while (front != -1 && front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = rear = -1;

    // Step 2: Pop from stack back into queue
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    return 0;
}