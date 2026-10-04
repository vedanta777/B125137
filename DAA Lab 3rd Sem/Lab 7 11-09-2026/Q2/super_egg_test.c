/*
 * Q2: Super Egg Testing Experiment
 * Dynamic Programming solution for E eggs and F floors.
 */

#include <stdio.h>
#include <limits.h>

#define MAX_EGGS 100
#define MAX_FLOORS 1000

/*
 * Method Explanation:
 * We use Dynamic Programming where dp[i][j] represents the minimum attempts
 * needed for 'i' eggs and 'j' floors.
 * For a drop from floor 'x' (1 <= x <= j):
 *   1. If egg breaks: We check dp[i-1][x-1] (floors below x).
 *   2. If egg survives: We check dp[i][j-x] (floors above x).
 * We take the worst-case scenario: max(dp[i-1][x-1], dp[i][j-x]) + 1.
 * We then minimize this value across all choices of x (1 to j).
 *
 * Base Cases:
 * - dp[1][j] = j (1 egg requires checking sequentially floor by floor).
 * - dp[i][0] = 0 (0 floors require 0 attempts).
 * - dp[i][1] = 1 (1 floor requires 1 attempt).
 *
 * Complexity:
 * - Time Complexity: O(E * F^2) using standard 2D DP table.
 * - Space Complexity: O(E * F) to store the DP state table.
 */

int calculate_min_trials(int E, int F) {
    int dp[MAX_EGGS + 1][MAX_FLOORS + 1];

    // Base cases initialization
    for (int i = 1; i <= E; i++) {
        dp[i][0] = 0; // 0 floors
        dp[i][1] = 1; // 1 floor
    }

    // 1 egg needs F trials for F floors
    for (int j = 1; j <= F; j++) {
        dp[1][j] = j;
    }

    // Fill DP table iteratively
    for (int i = 2; i <= E; i++) {
        for (int j = 2; j <= F; j++) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) {
                int worst_case = 1 + (dp[i - 1][x - 1] > dp[i][j - x] ? dp[i - 1][x - 1] : dp[i][j - x]);
                if (worst_case < dp[i][j]) {
                    dp[i][j] = worst_case;
                }
            }
        }
    }

    return dp[E][F];
}

int main() {
    int E, F;

    // User inputs
    printf("Enter the number of eggs (E): ");
    if (scanf("%d", &E) != 1 || E <= 0 || E > MAX_EGGS) return 1;

    printf("Enter the number of floors (F): ");
    if (scanf("%d", &F) != 1 || F < 0 || F > MAX_FLOORS) return 1;

    int min_attempts = calculate_min_trials(E, F);

    printf("\n--- Egg Dropping Puzzle Results ---\n");
    printf("Eggs: %d, Floors: %d\n", E, F);
    printf("Minimum drops guaranteed in worst case: %d\n", min_attempts);

    return 0;
}