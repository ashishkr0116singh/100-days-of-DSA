#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the height of the binary tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0; // Empty tree has height 0
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Height is max of left/right subtree + 1 for current node
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    // Example: Constructing a binary tree manually
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Calculate and print the height
    printf("Height of the binary tree: %d\n", height(root));

    return 0;
}