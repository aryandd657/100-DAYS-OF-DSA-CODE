#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure to represent a node in the adjacency list
struct Node {
    int v, weight;
    struct Node* next;
};

// Structure for the Min-Heap
struct HeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    int capacity;
    struct HeapNode** array;
};

// --- Graph Helper Functions ---
struct Node* createNode(int v, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// --- Min-Heap Helper Functions ---
struct HeapNode* createHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    struct HeapNode* root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void push(struct MinHeap* minHeap, int v, int dist) {
    minHeap->array[minHeap->size] = createHeapNode(v, dist);
    int i = minHeap->size++;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// --- Dijkstra's Main Algorithm ---
void dijkstra(int n, struct Node* adj[], int src) {
    int dist[n + 1];
    for (int i = 1; i <= n; i++) dist[i] = INF;

    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->capacity = 10000; // Adjust based on constraints
    minHeap->size = 0;
    minHeap->array = (struct HeapNode**)malloc(minHeap->capacity * sizeof(struct HeapNode*));

    dist[src] = 0;
    push(minHeap, src, 0);

    while (minHeap->size != 0) {
        struct HeapNode* heapNode = extractMin(minHeap);
        int u = heapNode->v;
        int d = heapNode->dist;
        free(heapNode);

        if (d > dist[u]) continue;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v;
            int weight = temp->weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(minHeap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[n + 1];
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w); // Use only for undirected graph
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, adj, source);

    return 0;
}