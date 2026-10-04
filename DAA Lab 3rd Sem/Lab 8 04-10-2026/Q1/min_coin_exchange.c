#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int V) {
    int dp[V + 1];
    dp[0] = 0;

    for (int i = 1; i <= V; i++) {
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }
    return (dp[V] == INT_MAX) ? -1 : dp[V];
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

    int ans = minCoins(coins, n, V);
    if (ans == -1) {
        printf("It is not possible to make amount %d with given coins.\n", V);
    } else {
        printf("Minimum coins required: %d\n", ans);
    }

    printf("\n--- Complexity Analysis ---\n");
    printf("Time Complexity: O(n * V)\n");
    printf("Space Complexity: O(V)\n");

    return 0;
}

/*
Algorithm Logic & Code Flow:
1. Initialize a 1D DP array of size V + 1 with base case dp[0] = 0 and infinity for all other elements.
2. Read user inputs for the total number of coin types, coin array elements, and target value V.
3. Iterate from amount 1 to V, building optimal minimum coin combinations bottom-up.
4. For each amount, check all coin denominations and select the minimum coin transition possible.
5. Store the final minimum result at dp[V] or return -1 if target amount cannot be formed.
6. Print the minimum coin count alongside time O(n*V) and space O(V) dynamic programming complexities.
*/
