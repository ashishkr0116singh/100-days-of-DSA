#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);  // Input string

    int freq[256] = {0};  // Frequency array for ASCII characters

    for (int i = 0; i < strlen(s); i++) {
        freq[(unsigned char)s[i]]++;
        if (freq[(unsigned char)s[i]] == 2) {  // Second occurrence found
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n");  // No repeated character
    return 0;
}
