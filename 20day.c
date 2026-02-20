#include <stdio.h>

#define MAX 1000

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix = 0, count = 0;

    // simple hashmap using arrays (since constraints usually small in college DSA)
    int freq[2 * MAX + 1] = {0};   
    int offset = MAX;   // to handle negative prefix sums

    freq[offset] = 1;   // prefix sum 0 initially

    for(int i = 0; i < n; i++)
    {
        prefix += arr[i];

        if(freq[prefix + offset] > 0)
            count += freq[prefix + offset];

        freq[prefix + offset]++;
    }

    printf("%d", count);
    return 0;
}