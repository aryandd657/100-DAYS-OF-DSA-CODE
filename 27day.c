#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);

    if (!head) return newNode;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* findIntersection(Node* h1, Node* h2) {
    int l1 = getLength(h1);
    int l2 = getLength(h2);

    int diff = abs(l1 - l2);

    if (l1 > l2)
        while (diff--) h1 = h1->next;
    else
        while (diff--) h2 = h2->next;

    while (h1 && h2) {
        if (h1 == h2)
            return h1;

        h1 = h1->next;
        h2 = h2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;
    Node *h1 = NULL, *h2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        h1 = insertEnd(h1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        h2 = insertEnd(h2, x);
    }

    /* --------- MANUAL INTERSECTION CREATE (for testing) ---------
       Example: connect last node of list2 to 3rd node of list1
    */
    Node* temp1 = h1;
    for (int i = 1; i < 3 && temp1; i++)
        temp1 = temp1->next;

    Node* temp2 = h2;
    if (temp2) {
        while (temp2->next)
            temp2 = temp2->next;
        temp2->next = temp1;
    }

    Node* inter = findIntersection(h1, h2);

    if (inter)
        printf("%d", inter->data);
    else
        printf("No Intersection");

    return 0;
}