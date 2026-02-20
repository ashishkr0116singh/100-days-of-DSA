#include <stdio.h>
#include <stdlib.h>

// Structure for hashmap entry
typedef struct Node {
    long long key;   // prefix sum
    int value;       // frequency
    struct Node* next;
} Node;

#define SIZE 100003  // large prime for hashing

Node* hashTable[SIZE];

// Hash function
int hash(long long key) {
    return (key % SIZE + SIZE) % SIZE;
}

// Insert or update frequency
void insert(long long key, int* count) {
    int h = hash(key);
    Node* curr = hashTable[h];
    
    while (curr) {
        if (curr->key == key) {
            *count += curr->value;  // add frequency to count
            curr->value++;
            return;
        }
        curr = curr->next;
    }
    
    // New entry
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

int countZeroSumSubarrays(int arr[], int n) {
    long long prefix_sum = 0;
    int count = 0;
    
    // Initialize with prefix sum 0
    insert(0, &count);
    
    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        insert(prefix_sum, &count);
    }
    
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    printf("%d\n", countZeroSumSubarrays(arr, n));
    return 0;
}