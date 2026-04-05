#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void BFS(int n, int adj[MAX][MAX], int s) {
    int visited[MAX] = {0};

    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, m, u, v, s;

    scanf("%d", &n);
    int adj[MAX][MAX] = {0};

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // remove for directed graph
    }

    scanf("%d", &s);

    BFS(n, adj, s);

    return 0;
}