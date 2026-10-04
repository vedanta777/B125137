#include <stdio.h>

long long countWays(int coins[], int n, int V) {
    long long dp[V + 1];
    for (int i = 0; i <= V; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= V; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[V];
}

int main() {
    int n, V;
    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter the coin values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter target amount V: ");
    scanf("%d", &V);

    printf("Total number of distinct ways: %lld\n", countWays(coins, n, V));

    printf("\n--- Complexity Analysis ---\n");
    printf("Time Complexity: O(n * V)\n");
    printf("Space Complexity: O(V)\n");

    return 0;
}

/*
Algorithm Logic & Code Flow:
1. Initialize a dynamic programming table dp of size V + 1 filled with zeros.
2. Set base case dp[0] = 1 representing one valid way to make amount 0 using zero coins.
3. Read the array of coin values and target sum V dynamically from user input.
4. Loop through each available coin denomination to ensure combinations are counted without permutation duplicate ordering.
5. Update dp[j] by adding dp[j - coin] for every sub-amount from coin value up to target V.
6. Print the calculated distinct coin combination total along with O(n*V) time and O(V) space analysis.
*/
