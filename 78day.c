#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1005

// Structure for adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* adj[MAX];

// Min Heap structure
typedef struct {
    int vertex;
    int weight;
} HeapNode;

HeapNode heap[MAX * MAX];
int heapSize = 0;

// Swap heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Push into min heap
void push(int vertex, int weight) {
    heap[heapSize].vertex = vertex;
    heap[heapSize].weight = weight;
    int i = heapSize++;

    while (i > 0 && heap[i].weight < heap[(i - 1) / 2].weight) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Pop from min heap
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];

    int i = 0;
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;

        if (right < heapSize && heap[right].weight < heap[left].weight)
            smallest = right;

        if (heap[i].weight <= heap[smallest].weight)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return root;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->weight = w;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Prim's Algorithm
int prim(int n) {
    bool visited[MAX] = {false};
    int totalWeight = 0;

    push(1, 0); // start from node 1

    while (heapSize > 0) {
        HeapNode curr = pop();
        int u = curr.vertex;

        if (visited[u]) continue;

        visited[u] = true;
        totalWeight += curr.weight;

        Node* temp = adj[u];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                push(temp->vertex, temp->weight);
            }
            temp = temp->next;
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("%d\n", prim(n));

    return 0;
}