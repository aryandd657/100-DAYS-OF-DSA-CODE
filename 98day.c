#include <stdio.h>
#include <stdlib.h>

// Interval structure
struct Interval {
    int start;
    int end;
};

// Comparator for sorting by start time
int compare(const void* a, const void* b) {
    struct Interval* x = (struct Interval*)a;
    struct Interval* y = (struct Interval*)b;
    return x->start - y->start;
}

// Function to merge intervals
struct Interval* mergeIntervals(struct Interval arr[], int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Step 1: Sort intervals by start
    qsort(arr, n, sizeof(struct Interval), compare);

    // Step 2: Allocate result array
    struct Interval* result = (struct Interval*)malloc(n * sizeof(struct Interval));
    int idx = 0;

    // Initialize first interval
    result[idx] = arr[0];

    for (int i = 1; i < n; i++) {
        // If overlapping → merge
        if (arr[i].start <= result[idx].end) {
            if (arr[i].end > result[idx].end)
                result[idx].end = arr[i].end;
        }
        // No overlap → move to next
        else {
            idx++;
            result[idx] = arr[i];
        }
    }

    *returnSize = idx + 1;
    return result;
}

// Driver code
int main() {
    struct Interval arr[] = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    int n = sizeof(arr) / sizeof(arr[0]);
    int newSize;

    struct Interval* res = mergeIntervals(arr, n, &newSize);

    printf("Merged intervals:\n");
    for (int i = 0; i < newSize; i++) {
        printf("[%d, %d] ", res[i].start, res[i].end);
    }

    free(res);
    return 0;
}