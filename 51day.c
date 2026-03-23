#include <stdio.h>
#include <stdlib.h>

// BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert in BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);

    return root;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}