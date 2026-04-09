#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];     // Adjacency matrix
int indegree[MAX];     // Indegree array
int queue[MAX];        // Queue
int front = 0, rear = 0;

// Enqueue
void push(int x) {
    queue[rear++] = x;
}

// Dequeue
int pop() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front == rear;
}

int main() {
    int n, edges;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        indegree[v]++;
    }

    // Push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            push(i);
        }
    }

    int count = 0;
    int topo[MAX];

    // Kahn's Algorithm
    while (!isEmpty()) {
        int node = pop();
        topo[count++] = node;

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    push(i);
                }
            }
        }
    }

    // Check for cycle
    if (count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}