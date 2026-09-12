/*
 * Q7: Matrix Chain Multiplication
 * Optimal matrix parenthesization and minimum scalar multiplications.
 */

#include <stdio.h>
#include <limits.h>

#define MAX_MATRICES 100

/*
 * Method Explanation:
 * Given chain of dimensions p[] of length n (defining n-1 matrices):
 * Matrix A_i has dimension p[i-1] x p[i].
 *
 * DP Table m[i][j]: minimum scalar multiplications for A_i...A_j.
 * Split Table s[i][j]: index k that achieves optimal split point.
 *
 * Recurrence:
 * m[i][j] = min_{i <= k < j} (m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j])
 *
 * Complexity:
 * - Time Complexity: O(N^3) standard MCM dynamic programming iteration.
 * - Space Complexity: O(N^2) to store cost and split tables.
 */

void print_optimal_parenthesis(int s[][MAX_MATRICES], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parenthesis(s, i, s[i][j]);
        print_optimal_parenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrix_chain_order(int p[], int n) {
    int m[MAX_MATRICES][MAX_MATRICES];
    int s[MAX_MATRICES][MAX_MATRICES];

    int num_matrices = n - 1;

    // Cost is 0 for multiplying single matrix
    for (int i = 1; i <= num_matrices; i++) {
        m[i][i] = 0;
    }

    // L is chain length
    for (int L = 2; L <= num_matrices; L++) {
        for (int i = 1; i <= num_matrices - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\n--- Matrix Chain Multiplication Result ---\n");
    printf("Minimum Scalar Multiplications: %d\n", m[1][num_matrices]);
    printf("Optimal Parenthesization Order: ");
    print_optimal_parenthesis(s, 1, num_matrices);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of dimension entries (Number of matrices + 1): ");
    if (scanf("%d", &n) != 1 || n < 2 || n > MAX_MATRICES) return 1;

    int p[MAX_MATRICES];
    printf("Enter %d dimensions sequence (e.g., 10 30 5 60): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    matrix_chain_order(p, n);

    return 0;
}