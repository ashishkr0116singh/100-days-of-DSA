#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1;
    int isPalindrome = 1;  // assume true

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;  // mismatch found
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}