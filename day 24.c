#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Function to delete first occurrence of key
struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next; // Move head
        free(temp);        // Free memory
        return head;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL) return head;

    // Unlink node and free memory
    prev->next = temp->next;
    free(temp);

    return head;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
}

int main() {
    int n, key;
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

    // Input key
    scanf("%d", &key);

    // Delete first occurrence
    head = deleteFirstOccurrence(head, key);

    // Print updated list
    printList(head);

    return 0;
}