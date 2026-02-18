#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], result[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n;   // handle large k

    // Copy last k elements to beginning
    for(int i = 0; i < k; i++) {
        result[i] = arr[n - k + i];
    }

    // Copy remaining elements
    for(int i = k; i < n; i++) {
        result[i] = arr[i - k];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
