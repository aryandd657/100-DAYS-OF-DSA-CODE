#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// create node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// insert at end
struct Node *insertEnd(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// merge sorted lists
struct Node *mergeLists(struct Node *l1, struct Node *l2)
{
    struct Node dummy;              // dummy node
    struct Node *tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// print list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        l1 = insertEnd(l1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        l2 = insertEnd(l2, x);
    }

    struct Node *merged = mergeLists(l1, l2);
    printList(merged);

    return 0;
}