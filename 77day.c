#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** adj, int* adjSize) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next, visited, adj, adjSize);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // allocate adjacency list
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* adjSize = (int*)calloc(n + 1, sizeof(int));

    int u, v;

    // first pass: count sizes
    int (*edges)[2] = malloc(m * sizeof *edges);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    // allocate exact memory
    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    // fill adjacency list
    for (int i = 0; i < m; i++) {
        u = edges[i][0];
        v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // visited array
    int* visited = (int*)calloc(n + 1, sizeof(int));

    // start DFS from node 1
    dfs(1, visited, adj, adjSize);

    // count visited nodes
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) count++;
    }

    if (count == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}