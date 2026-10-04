#include <stdio.h>
#include <float.h>

double sumProb(double p[], double q[], int i, int j) {
    double sum = 0;
    for (int k = i; k <= j; k++) sum += p[k];
    for (int k = i - 1; k <= j; k++) sum += q[k];
    return sum;
}

void OBST(double p[], double q[], int n) {
    double e[n + 2][n + 1];
    double w[n + 2][n + 1];

    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = DBL_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (int r = i; r <= j; r++) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                }
            }
        }
    }

    printf("\nMinimum Expected Search Cost: %lf\n", e[1][n]);
}

int main() {
    int n;
    printf("Enter number of keys: ");
    scanf("%d", &n);

    double p[n + 1], q[n + 1];
    printf("Enter %d probabilities for successful searches (p1 to p%d): ", n, n);
    for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);

    printf("Enter %d probabilities for unsuccessful searches (q0 to q%d): ", n + 1, n);
    for (int i = 0; i <= n; i++) scanf("%lf", &q[i]);

    OBST(p, q, n);

    printf("\n--- Complexity Analysis ---\n");
    printf("Time Complexity: O(n^3)\n");
    printf("Space Complexity: O(n^2)\n");

    return 0;
}

/*
Algorithm Logic & Code Flow:
1. Accept dynamic system input n, key search probabilities p, and dummy key search probabilities q.
2. Initialize expected search cost table e and sub-tree probability sum table w.
3. Compute base cases representing empty subtree nodes initialized with dummy search probabilities.
4. Iterate over increasing subtree length l to solve dynamic matrix subproblems systematically.
5. Select optimal key root r minimizing expected cost function transition e[i][j].
6. Output final global minimum search tree cost alongside O(n^3) time and O(n^2) space complexities.
*/
