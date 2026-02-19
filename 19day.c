#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Sort array
    qsort(a, n, sizeof(int), cmp);

    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int x = 0, y = 0;

    while (left < right)
    {
        int sum = a[left] + a[right];

        if (abs(sum) < abs(minSum))
        {
            minSum = sum;
            x = a[left];
            y = a[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", x, y);
    return 0;
}
