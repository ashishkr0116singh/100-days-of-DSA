#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node for building tree from level order
struct QueueNode {
    struct Node *node;
    int index;
};

// Create new tree node
struct Node* newNode(int data) {
    if (data == -1) return NULL; // -1 means NULL
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct QueueNode queue[n];
    int front = 0, rear = 0;

    queue[rear++] = (struct QueueNode){root, 0};

    while (front < rear) {
        struct QueueNode qn = queue[front++];
        int i = qn.index;

        // Left child
        if (2*i+1 < n && arr[2*i+1] != -1) {
            qn.node->left = newNode(arr[2*i+1]);
            queue[rear++] = (struct QueueNode){qn.node->left, 2*i+1};
        }
        // Right child
        if (2*i+2 < n && arr[2*i+2] != -1) {
            qn.node->right = newNode(arr[2*i+2]);
            queue[rear++] = (struct QueueNode){qn.node->right, 2*i+2};
        }
    }
    return root;
}

// Structure for storing nodes by horizontal distance
struct DLLNode {
    int hd; // horizontal distance
    int data;
    struct DLLNode *next;
    struct DLLNode *down;
};

// Recursive helper to fill vertical order
void verticalOrderUtil(struct Node* root, int hd, struct DLLNode** head) {
    if (!root) return;

    // Find or create column for this hd
    struct DLLNode* temp = *head, *prev = NULL;
    while (temp && temp->hd != hd) {
        prev = temp;
        temp = (hd < temp->hd) ? temp->next : temp->next;
    }

    if (!temp) {
        temp = (struct DLLNode*)malloc(sizeof(struct DLLNode));
        temp->hd = hd;
        temp->data = root->data;
        temp->down = NULL;
        temp->next = NULL;

        if (!*head) *head = temp;
        else {
            if (hd < (*head)->hd) {
                temp->next = *head;
                *head = temp;
            } else {
                prev->next = temp;
            }
        }
    } else {
        struct DLLNode* downNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
        downNode->hd = hd;
        downNode->data = root->data;
        downNode->down = NULL;
        downNode->next = NULL;

        struct DLLNode* d = temp;
        while (d->down) d = d->down;
        d->down = downNode;
    }

    verticalOrderUtil(root->left, hd-1, head);
    verticalOrderUtil(root->right, hd+1, head);
}

// Print vertical order
void printVerticalOrder(struct Node* root) {
    struct DLLNode* head = NULL;
    verticalOrderUtil(root, 0, &head);

    // Print columns
    struct DLLNode* temp = head;
    while (temp) {
        struct DLLNode* d = temp;
        while (d) {
            printf("%d ", d->data);
            d = d->down;
        }
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, N);
    printVerticalOrder(root);

    return 0;
}
