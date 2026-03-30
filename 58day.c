#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int *preIndex,
                                int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = createNode(rootVal);

    if (inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    root->left = buildTreeHelper(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = buildTreeHelper(preorder, inorder, preIndex, inIndex + 1, inEnd);

    return root;
}

// Postorder traversal
void postorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    // Input preorder
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    // Input inorder
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct TreeNode* root = buildTreeHelper(preorder, inorder, &preIndex, 0, n - 1);

    // Output postorder
    postorder(root);

    return 0;
}