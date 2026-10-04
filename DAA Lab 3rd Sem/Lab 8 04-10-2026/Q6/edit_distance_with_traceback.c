#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

void editDistance(char A[], char B[]) {
    int m = strlen(A);
    int n = strlen(B);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    printf("Minimum Edit Distance: %d\n", dp[m][n]);
    printf("Traceback Operations (reverse order):\n");

    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && A[i - 1] == B[j - 1]) {
            i--; j--;
        } else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + 1) {
            printf("Substitute '%c' with '%c'\n", A[i - 1], B[j - 1]);
            i--; j--;
        } else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            printf("Delete '%c'\n", A[i - 1]);
            i--;
        } else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
            printf("Insert '%c'\n", B[j - 1]);
            j--;
        }
    }
}

int main() {
    char A[100], B[100];
    printf("Enter string A: ");
    scanf("%s", A);
    printf("Enter string B: ");
    scanf("%s", B);

    editDistance(A, B);

    printf("\n--- Complexity Analysis ---\n");
    printf("Time Complexity: O(m * n)\n");
    printf("Space Complexity: O(m * n)\n");

    return 0;
}

/*
Algorithm Logic & Code Flow:
1. Accept input strings A and B from user dynamic inputs and measure lengths m and n.
2. Construct DP table dp[m+1][n+1] where dp[i][j] stores minimum operations to match prefixes.
3. Compute cost matrix using transitions for insert (left), delete (top), and substitute (diagonal).
4. Extract optimal minimum operations required from cell position dp[m][n].
5. Backtrack through dynamic table steps to trace and display exact substitution, insertion, or deletion operations.
6. Print comprehensive transformation trace alongside O(m*n) time and O(m*n) space consumption.
*/
