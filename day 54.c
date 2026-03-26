 #include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for level order building
struct Queue {
    struct Node **arr;
    int front, rear, size;
};

// Create new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Initialize queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(sizeof(struct Node*) * size);
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    if (node != NULL) {
        q->arr[q->rear++] = node;
    }
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (q->front == q->rear) return NULL;
    return q->arr[q->front++];
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);
    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue(q);
        if (curr) {
            curr->left = newNode(arr[i++]);
            enqueue(q, curr->left);
            if (i < n) {
                curr->right = newNode(arr[i++]);
                enqueue(q, curr->right);
            }
        }
    }
    return root;
}

// Zigzag traversal using two stacks
void zigzagTraversal(struct Node* root) {
    if (!root) return;
    struct Node* stack1[1000]; // left-to-right
    struct Node* stack2[1000]; // right-to-left
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0 || top2 >= 0) {
        while (top1 >= 0) {
            struct Node* node = stack1[top1--];
            printf("%d ", node->data);
            if (node->left) stack2[++top2] = node->left;
            if (node->right) stack2[++top2] = node->right;
        }
        while (top2 >= 0) {
            struct Node* node = stack2[top2--];
            printf("%d ", node->data);
            if (node->right) stack1[++top1] = node->right;
            if (node->left) stack1[++top1] = node->left;
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
    zigzagTraversal(root);

    return 0;
}
