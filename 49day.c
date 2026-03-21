#include <stdio.h>
#include <stdlib.h>

// Define structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    // If tree is empty
    if (root == NULL) {
        return createNode(value);
    }

    // Recursive insertion
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n, value;
    struct Node* root = NULL;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Insert elements
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Output inorder traversal
    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}