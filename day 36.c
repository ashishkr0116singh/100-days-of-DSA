#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global pointers for front and rear
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (front == NULL) {
        front = rear = newNode;
        rear->next = front; // circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // maintain circularity
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front; // maintain circular link
        free(temp);
    }
}

// Display queue elements
void display(int n) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    int n, m, i, val;

    // Input number of elements
    scanf("%d", &n);

    // Enqueue elements
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    // Number of dequeue operations
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        dequeue();
    }

    // Display final queue
    display(n - m);

    return 0;
}