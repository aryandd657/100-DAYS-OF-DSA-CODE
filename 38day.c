#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if(empty()) return 0;
    if(rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

void push_front(int x) {
    if((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        front = MAX-1;
    }
    else {
        front--;
    }

    deque[front] = x;
}

void push_back(int x) {
    if((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else if(rear == MAX-1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = x;
}

void pop_front() {
    if(empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if(front == rear) {
        front = rear = -1;
    }
    else if(front == MAX-1) {
        front = 0;
    }
    else {
        front++;
    }
}

void pop_back() {
    if(empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if(front == rear) {
        front = rear = -1;
    }
    else if(rear == 0) {
        rear = MAX-1;
    }
    else {
        rear--;
    }
}

void getFront() {
    if(empty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

void getBack() {
    if(empty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

void clearDeque() {
    front = rear = -1;
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);

    getFront();  
    getBack();   

    pop_front(); 
    pop_back();  

    printf("Size: %d\n", size());

    return 0;
}