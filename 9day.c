#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j;
    char temp;

    scanf("%s", s);   // input

    i = 0;
    j = strlen(s) - 1;

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    printf("%s", s);  // output
    return 0;
}
