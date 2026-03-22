#include <stdio.h>
#include <stdlib.h>

// Define structure for BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search a key in BST
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0; // Not Found
    }
    if (root->data == key) {
        return 1; // Found
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    int n, key;
    scanf("%d", &n);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }

    scanf("%d", &key);

    if (search(root, key)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}