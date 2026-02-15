#include <stdio.h>

int main() {
    int m, n;
    int matrix[100][100];
    int sum = 0;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    // Input matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if matrix is square
    if(m != n) {
        printf("Primary diagonal is defined only for square matrices.");
        return 0;
    }

    // Calculate primary diagonal sum
    for(int i = 0; i < m; i++) {
        sum += matrix[i][i];
    }

    // Output result
    printf("%d", sum);

    return 0;
}
