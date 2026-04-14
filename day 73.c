#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);  // Input string

    int freq[256] = {0};  // Frequency array for ASCII characters

    // Count frequency of each character
    for (int i = 0; i < strlen(s); i++) {
        freq[(unsigned char)s[i]]++;
    }

    // Find the first character with frequency 1
    for (int i = 0; i < strlen(s); i++) {
        if (freq[(unsigned char)s[i]] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // If no non-repeating character found
    printf("$\n");
    return 0;
}
