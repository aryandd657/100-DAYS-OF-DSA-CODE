#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Rotate Right by k
Node* rotateRight(Node* head, int k) {
    if (head == NULL || k == 0)
        return head;

    Node* temp = head;
    int length = 1;

    // Count length
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make it circular
    temp->next = head;

    k = k % length;

    if (k == 0) {
        temp->next = NULL;
        return head;
    }

    int steps = length - k;
    Node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, value;
    Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}