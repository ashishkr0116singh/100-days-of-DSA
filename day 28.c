#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* createCircularList(int arr[], int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* last = NULL;

    for (int i = 0; i < n; i++) {
        // Allocate memory for new node
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    // Make it circular
    last->next = head;

    return head;
}

// Function to traverse circular linked list
void traverseCircularList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = createCircularList(arr, n);

    traverseCircularList(head);

    return 0;
}