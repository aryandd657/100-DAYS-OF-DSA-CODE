#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int main() {
    int n, m, i, value;

    // Input number of elements to push
    scanf("%d", &n);

    // Push elements
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Input number of pops
    scanf("%d", &m);

    // Perform pop operations
    for (i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack from top to bottom
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }

    return 0;
}