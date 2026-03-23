#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Find Lowest Common Ancestor in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val) {
            root = root->left;
        } else if (p > root->val && q > root->val) {
            root = root->right;
        } else {
            return root; // Split point → LCA
        }
    }
    return NULL;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    // Build BST
    struct TreeNode* root = NULL;
    for (int i = 0; i < N; i++) {
        root = insert(root, arr[i]);
    }

    // Find LCA
    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL) {
        printf("%d\n", lca->val);
    }

    return 0;
}