#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int pq[MAX];   // priority queue array
int size = 0;  // current size

// Insert element into priority queue
void insert(int x) {
    if (size == MAX) {
        printf("Queue overflow\n");
        return;
    }
    pq[size++] = x;
}

// Delete element with highest priority (smallest value)
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    printf("%d\n", pq[minIndex]);
    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek element with highest priority (smallest value)
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    printf("%d\n", pq[minIndex]);
}

int main() {
    int N;
    scanf("%d", &N);
    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    return 0;
}