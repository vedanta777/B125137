#include <stdio.h>
#include <string.h>

void printLCS(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--; j--; index--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Length of LCS: %d\n", L[m][n]);
    printf("Reconstructed LCS String: %s\n", lcs);
}

int main() {
    char X[100], Y[100];
    printf("Enter string X: ");
    scanf("%s", X);
    printf("Enter string Y: ");
    scanf("%s", Y);

    printLCS(X, Y);

    printf("\n--- Complexity Analysis ---\n");
    printf("Time Complexity: O(m * n)\n");
    printf("Space Complexity: O(m * n)\n");

    return 0;
}

/*
Algorithm Logic & Code Flow:
1. Accept input strings X and Y dynamically from user prompt and calculate their sequence lengths.
2. Build dynamic matrix L[m+1][n+1] storing LCS lengths for prefixes of input sequences.
3. Match characters and add 1 diagonal-wise on match, otherwise store maximum from adjacent top/left cells.
4. Allocate character array based on maximum value present at matrix coordinate L[m][n].
5. Trace back through matrix state decisions backwards from corner L[m][n] to reconstruct exact string.
6. Display final sequence string and length with O(m*n) space and time complexity bounds.
*/
