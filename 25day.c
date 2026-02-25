#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// create new node
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insert at end
Node* insertEnd(Node* head, int data)
{
    Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// count occurrences
int countKey(Node* head, int key)
{
    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
            count++;

        temp = temp->next;
    }
    return count;
}

int main()
{
    Node* head = NULL;
    int n, x, key;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    scanf("%d", &key);

    printf("%d", countKey(head, key));

    return 0;
}