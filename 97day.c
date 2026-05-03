#include <stdio.h>
#include <stdlib.h>

// Structure for interval
struct Interval {
    int start;
    int end;
};

// Comparator for sorting by start time
int compare(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

// Min Heap functions
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index]) break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index) break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

// Push into min heap
void push(int heap[], int* size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

// Pop from min heap
void pop(int heap[], int* size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

// Get min
int top(int heap[]) {
    return heap[0];
}

// Main function
int minMeetingRooms(struct Interval* intervals, int n) {
    if (n == 0) return 0;

    // Step 1: Sort by start time
    qsort(intervals, n, sizeof(struct Interval), compare);

    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;

    // Step 2: Add first meeting end time
    push(heap, &heapSize, intervals[0].end);

    // Step 3: Process remaining meetings
    for (int i = 1; i < n; i++) {
        // If room is free
        if (intervals[i].start >= top(heap)) {
            pop(heap, &heapSize);
        }

        // Allocate current meeting
        push(heap, &heapSize, intervals[i].end);
    }

    int result = heapSize;
    free(heap);
    return result;
}

// Driver code
int main() {
    struct Interval intervals[] = {
        {0, 30}, {5, 10}, {15, 20}
    };

    int n = sizeof(intervals) / sizeof(intervals[0]);

    printf("Minimum meeting rooms required: %d\n", minMeetingRooms(intervals, n));

    return 0;
}