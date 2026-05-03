#include <stdio.h>
#include <stdlib.h>

// Structure to store car info
struct Car {
    int position;
    double time;
};

// Comparator: sort by position descending
int compare(const void* a, const void* b) {
    struct Car* x = (struct Car*)a;
    struct Car* y = (struct Car*)b;
    return y->position - x->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    struct Car* cars = (struct Car*)malloc(n * sizeof(struct Car));

    // Step 1: compute time for each car
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: sort by position descending
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double maxTime = 0.0;

    // Step 3: process from closest to farthest
    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}

// Driver code
int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;

    printf("Number of fleets: %d\n", carFleet(target, position, speed, n));
    return 0;
}