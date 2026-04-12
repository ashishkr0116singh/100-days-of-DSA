#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert function using quadratic probing
void insert(int table[], int m, int key) {
    int h = hash(key, m);
    int i = 0;
    int pos;

    while (i < m) {
        pos = (h + i * i) % m;
        if (table[pos] == EMPTY) {
            table[pos] = key;
            return;
        }
        i++;
    }
    // Table full, insertion failed
}

// Search function using quadratic probing
int search(int table[], int m, int key) {
    int h = hash(key, m);
    int i = 0;
    int pos;

    while (i < m) {
        pos = (h + i * i) % m;
        if (table[pos] == EMPTY) {
            return 0; // Not found
        }
        if (table[pos] == key) {
            return 1; // Found
        }
        i++;
    }
    return 0; // Not found
}

int main() {
    int m, n;
    scanf("%d", &m); // table size
    scanf("%d", &n); // number of operations

    int *table = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(table, m, key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    free(table);
    return 0;
}
