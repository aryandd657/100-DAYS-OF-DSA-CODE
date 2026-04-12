#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int* table;
int m;

// hash function
int hash(int key) {
    return key % m;
}

// insert using quadratic probing
void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
}

// search using quadratic probing
int search(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            return 0; // NOT FOUND
        }

        if (table[idx] == key) {
            return 1; // FOUND
        }
    }

    return 0;
}

int main() {
    int q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    table = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    free(table);
    return 0;
}