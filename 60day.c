#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order array
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Count nodes
int countNodes(struct Node* root) {
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
int isCBT(struct Node* root, int index, int total) {
    if (!root)
        return 1;

    if (index >= total)
        return 0;

    return isCBT(root->left, 2*index + 1, total) &&
           isCBT(root->right, 2*index + 2, total);
}

// Check Heap Property
int isHeap(struct Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right) {
        return (root->data <= root->left->data) && isHeap(root->left);
    }

    if (root->data <= root->left->data &&
        root->data <= root->right->data) {
        return isHeap(root->left) && isHeap(root->right);
    }

    return 0;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    int total = countNodes(root);

    if (isCBT(root, 0, total) && isHeap(root))
        printf("YES");
    else
        printf("NO");

    free(arr);
    return 0;
}