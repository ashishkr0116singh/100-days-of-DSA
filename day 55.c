#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for level order building
struct Queue {
    struct Node** arr;
    int front, rear, size;
};

// Function to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL; // -1 means NULL
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue functions
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (node != NULL) {
        q->arr[q->rear++] = node;
    }
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == q->rear) return NULL;
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Function to build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct Node* curr = dequeue(q);
        if (i < n) {
            curr->left = newNode(arr[i++]);
            enqueue(q, curr->left);
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            enqueue(q, curr->right);
        }
    }
    return root;
}

// Function to print right view
void rightView(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    while (!isEmpty(q)) {
        int count = q->rear - q->front; // number of nodes at current level
        for (int i = 0; i < count; i++) {
            struct Node* node = dequeue(q);
            // Print the last node of each level
            if (i == count - 1) {
                printf("%d ", node->data);
            }
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);
    rightView(root);

    return 0;
}
