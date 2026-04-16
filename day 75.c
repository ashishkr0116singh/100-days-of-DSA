#include <stdio.h>
#include <stdlib.h>

// Hash map node structure
struct HashNode {
    int sum;
    int index;
    struct HashNode* next;
};

// Hash function
int hashFunction(int sum, int size) {
    if (sum < 0) sum = -sum;
    return sum % size;
}

// Insert into hash map
void insert(struct HashNode** hashTable, int size, int sum, int index) {
    int hashIndex = hashFunction(sum, size);
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

// Search in hash map
int search(struct HashNode** hashTable, int size, int sum) {
    int hashIndex = hashFunction(sum, size);
    struct HashNode* node = hashTable[hashIndex];
    while (node != NULL) {
        if (node->sum == sum) {
            return node->index;
        }
        node = node->next;
    }
    return -1;
}

int longestZeroSumSubarray(int arr[], int n) {
    int maxLen = 0;
    int sum = 0;
    int size = n * 2; // hash table size
    struct HashNode** hashTable = (struct HashNode**)calloc(size, sizeof(struct HashNode*));

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        } else {
            int prevIndex = search(hashTable, size, sum);
            if (prevIndex != -1) {
                if (i - prevIndex > maxLen) {
                    maxLen = i - prevIndex;
                }
            } else {
                insert(hashTable, size, sum, i);
            }
        }
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        struct HashNode* node = hashTable[i];
        while (node != NULL) {
            struct HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(hashTable);

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestZeroSumSubarray(arr, n);
    printf("%d\n", result);

    return 0;
}
