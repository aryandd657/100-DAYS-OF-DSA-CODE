#include <stdio.h>

// Check if possible within maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        // If one board itself exceeds maxTime
        if (arr[i] > maxTime)
            return 0;

        if (currentTime + arr[i] > maxTime) {
            painters++;
            currentTime = arr[i];

            if (painters > k)
                return 0;
        } else {
            currentTime += arr[i];
        }
    }
    return 1;
}

// Main function
int minTime(int arr[], int n, int k) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max;
    int high = sum;
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1; // try better answer
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minTime(arr, n, k));
    return 0;
}