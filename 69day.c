#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// ---------- Graph ----------
typedef struct Node {
    int v, weight;
    struct Node* next;
} Node;

Node* adj[MAX];

// add edge
void addEdge(int u, int v, int w) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->v = v;
    temp->weight = w;
    temp->next = adj[u];
    adj[u] = temp;
}

// ---------- Min Heap ----------
typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[1000];
int size = 0;

void swap(int i, int j) {
    HeapNode t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

void push(int node, int dist) {
    heap[++size].node = node;
    heap[size].dist = dist;

    int i = size;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(i, i/2);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (1) {
        int smallest = i;
        int l = 2*i, r = 2*i+1;

        if (l <= size && heap[l].dist < heap[smallest].dist)
            smallest = l;
        if (r <= size && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest == i) break;

        swap(i, smallest);
        i = smallest;
    }

    return top;
}

// ---------- Dijkstra ----------
void dijkstra(int n, int src) {
    int dist[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        HeapNode curr = pop();
        int u = curr.node;

        if (curr.dist > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}

// ---------- Main ----------
int main() {
    int n = 5;

    for (int i = 0; i < MAX; i++) adj[i] = NULL;

    addEdge(1, 2, 2);
    addEdge(1, 3, 4);
    addEdge(2, 3, 1);
    addEdge(2, 4, 7);
    addEdge(3, 5, 3);
    addEdge(4, 5, 1);

    int src = 1;
    dijkstra(n, src);

    return 0;
}