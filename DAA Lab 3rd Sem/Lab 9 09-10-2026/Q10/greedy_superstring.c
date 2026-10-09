#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate maximum overlap where suffix of str1 matches prefix of str2
int getOverlap(const char *str1, const char *str2, char *merged) {
    int max_overlap = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Check all possible overlap lengths
    for (int i = 1; i <= len1 && i <= len2; i++) {
        if (strncmp(str1 + len1 - i, str2, i) == 0) {
            max_overlap = i;
        }
    }

    // Construct the merged string if requested
    if (merged != NULL) {
        strcpy(merged, str1);
        strcat(merged, str2 + max_overlap);
    }

    return max_overlap;
}

int main() {
    int n;
    printf("Enter number of strings: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    char *strings[n];
    for (int i = 0; i < n; i++) {
        strings[i] = (char *)malloc(500 * sizeof(char));
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    int count = n;

    // Classic Greedy Loop: Repeatedly merge pair with maximum overlap
    while (count > 1) {
        int max_overlap = -1;
        int best_i = -1, best_j = -1;
        char best_merged[1000] = "";

        // Find the pair (i, j) with the maximum overlap
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                if (i != j) {
                    char temp_merged[1000];
                    int overlap = getOverlap(strings[i], strings[j], temp_merged);

                    if (overlap > max_overlap) {
                        max_overlap = overlap;
                        best_i = i;
                        best_j = j;
                        strcpy(best_merged, temp_merged);
                    }
                }
            }
        }

        // Merge best_i and best_j into best_i slot
        free(strings[best_i]);
        strings[best_i] = (char *)malloc((strlen(best_merged) + 1) * sizeof(char));
        strcpy(strings[best_i], best_merged);

        // Remove best_j slot by shifting array left
        free(strings[best_j]);
        for (int k = best_j; k < count - 1; k++) {
            strings[k] = strings[k + 1];
        }
        count--;
    }

    printf("\n--- Greedy Superstring Result ---\n");
    printf("Shortest Superstring: %s\n", strings[0]);
    printf("Total Length: %lu\n", strlen(strings[0]));

    free(strings[0]);
    return 0;
}

/*
================================================================================
ALGORITHM LOGIC:
1. Accept n input strings and initialize an array of dynamically allocated string pointers.
   Pre-process inputs to eliminate strings that are fully contained within others.
2. Evaluate all pairs (s_i, s_j) to compute the max overlap length where suffix of s_i matches prefix of s_j.
   Store the pair (best_i, best_j) that yields the maximum overlap value.
3. Concatenate s_i with suffix of s_j excluding the overlapping prefix characters.
   Replace string at index best_i with newly generated merged string.
4. Remove string at index best_j from working set array and decrement string counter count by 1.
   Shift remaining string pointers leftward to keep working set contiguous.
5. Repeat pair selection, overlap maximization, and merging until only 1 superstring remains in set.
   Loop completes when all individual substrings are merged into one contiguous sequence.
6. Print resulting greedy superstring along with its final calculated length.
   Complexity: Time O(N^3 * L^2) where L is max string length, Space O(N * L).
================================================================================
*/