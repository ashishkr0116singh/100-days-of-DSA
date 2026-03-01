#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate linked list right by k places
struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || k == 0 || k % n == 0) return head;

    // Connect last node to head to form circular list
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head;

    // Find new head: (n-k)th node
    int stepsToNewHead = n - (k % n);
    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL; // Break the circle

    return newHead;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Input list elements
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k, n);

    printList(head);

    return 0;
}