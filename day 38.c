#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check if deque is empty
int empty() {
    return (front == -1);
}

// Check size
int size() {
    if (empty()) return 0;
    return (rear - front + 1);
}

// Push at front
void push_front(int x) {
    if (front <= 0) {
        printf("Deque overflow at front\n");
        return;
    }
    deque[--front] = x;
}

// Push at back
void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Deque overflow at rear\n");
        return;
    }
    if (empty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// Pop from front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Pop from back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// Get front element
void front_elem() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);
}

// Get back element
void back_elem() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);
}

// Clear deque
void clear() {
    front = rear = -1;
}

// Reverse deque
void reverse() {
    if (empty()) return;
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

// Sort deque (ascending)
void sort() {
    if (empty()) return;
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    char op[20];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        } else if (strcmp(op, "front") == 0) {
            front_elem();
        } else if (strcmp(op, "back") == 0) {
            back_elem();
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", empty());
        } else if (strcmp(op, "clear") == 0) {
            clear();
        } else if (strcmp(op, "reverse") == 0) {
            reverse();
        } else if (strcmp(op, "sort") == 0) {
            sort();
        }
    }

    // Print final state of deque
    if (!empty()) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }

    return 0;
}