#include <stdio.h>
#include <stdlib.h>

// Define structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to traverse and print the list in forward order
void traverseForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, i, value;
    struct Node* head = NULL;

    // Input size
    scanf("%d", &n);

    // Input elements and insert into list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    // Output elements in forward order
    traverseForward(head);

    return 0;
}