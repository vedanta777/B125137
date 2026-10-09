#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of children: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int ratings[n];
    printf("Enter rating values for each child: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ratings[i]);
    }

    int candies[n];
    // Base condition: Every child receives at least one candy
    for (int i = 0; i < n; i++) {
        candies[i] = 1;
    }

    // Left-to-Right pass: Higher rating than left neighbor gets more candies
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right-to-Left pass: Higher rating than right neighbor gets more candies
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            if (candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
            }
        }
    }

    // Accumulate total candies
    int total_candies = 0;
    printf("\nCandy Allocation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", candies[i]);
        total_candies += candies[i];
    }

    printf("\nMinimum Total Candies Required: %d\n", total_candies);
    return 0;
}

/*
================================================================================
ALGORITHM LOGIC:
1. Accept total child count and rating scores array from user input.
   Initialize candy allocation array with baseline value 1 for all children.
2. Scan line left-to-right starting from second child to evaluate left neighbor condition.
   If current rating exceeds left neighbor, set current candies to left neighbor candies + 1.
3. Scan line right-to-left starting from second-last child to evaluate right neighbor condition.
   If current rating exceeds right neighbor, update candies to max(current, right neighbor + 1).
4. Dual directional sweeps guarantee local greedy slope constraints are satisfied on both flanks.
   Simultaneously optimizes global minimum sum without breaking relative child rank rules.
5. Traverse candy array to calculate total sum across all allocated elements.
   Print individualized candy distribution along with total candy sum.
6. Complexity: Time O(N) dual linear passes, Space O(N) for array storage.
================================================================================
*/