#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack
int stack[MAX];
int top = -1;

// Push into stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node, int visited[], int adj[MAX][MAX], int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, visited, adj, V);
        }
    }

    // Push after visiting all neighbors
    push(node);
}

// Topological Sort function
void topologicalSort(int adj[MAX][MAX], int V) {
    int visited[MAX] = {0};

    // Call DFS for all nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, V);
        }
    }

    // Print stack (reverse order)
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Driver code
int main() {
    int V = 6;

    // Adjacency matrix
    int adj[MAX][MAX] = {0};

    // Example graph:
    // 5 → 2, 5 → 0
    // 4 → 0, 4 → 1
    // 2 → 3
    // 3 → 1

    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(adj, V);

    return 0;
}