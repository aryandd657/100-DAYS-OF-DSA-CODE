#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency list
int size[MAX];       // number of neighbors
int visited[MAX];

// DFS function
int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return 1;
        }
        else if (neighbor != parent) {
            return 1; // cycle found
        }
    }
    return 0;
}

int main() {
    int V, E;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    // initialize
    for (int i = 0; i < V; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u; // undirected graph
    }

    int cycle = 0;

    // handle multiple components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}