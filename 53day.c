#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* createNode(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Pair queue[2000];
    int front = 0, rear = 0;

    int map[4000][100];   // store nodes
    int size[4000] = {0};

    int offset = 2000;
    int minHD = 2000, maxHD = 2000;

    queue[rear++] = (struct Pair){root, offset};

    while (front < rear) {
        struct Pair temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd;

        map[hd][size[hd]++] = node->data;

        if (node->left)
            queue[rear++] = (struct Pair){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct Pair){node->right, hd + 1};

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;
    }

    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}