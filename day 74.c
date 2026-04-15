#include <stdio.h>
#include <string.h>

#define MAX 1000   // maximum number of votes
#define LEN 50     // maximum length of candidate name

// Function to find the winner
void findWinner(char votes[][LEN], int n) {
    char candidates[MAX][LEN];
    int count[MAX];
    int uniqueCount = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(votes[i], candidates[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(candidates[uniqueCount], votes[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find max votes
    int maxVotes = 0;
    char winner[LEN];
    for (int i = 0; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, candidates[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(candidates[i], winner) < 0) {
                strcpy(winner, candidates[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);
}

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    findWinner(votes, n);

    return 0;
}
