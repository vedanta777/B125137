#include <stdio.h>

void rodCutting(int price[], int n) {
    int val[n + 1];
    int pos[n + 1];
    val[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = -1;
        int best_cut = -1;
        for (int j = 1; j <= i; j++) {
            if (price[j - 1] + val[i - j] > max_val) {
                max_val = price[j - 1] + val[i - j];
                best_cut = j;
            }
        }
        val[i] = max_val;
        pos[i] = best_cut;
    }

    printf("\n(i) Maximum Revenue: %d\n", val[n]);
    printf("(ii) Optimal Piece Lengths: ");
    int temp = n;
    while (temp > 0) {
        printf("%d ", pos[temp]);
        temp = temp - pos[temp];
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter rod length n: ");
    scanf("%d", &n);

    int price[n];
    printf("Enter prices for length 1 to %d: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    rodCutting(price, n);

    printf("\n--- Complexity Analysis ---\n");
    printf("Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(n)\n");

    return 0;
}

/*
Algorithm Logic & Code Flow:
1. Read user input for target rod total length n and prices array for piece sizes 1 to n.
2. Initialize dynamic arrays val (stores max profit) and pos (stores optimal cut lengths).
3. Compute maximum revenue recursively for every sub-length i using bottom-up tabulating loops.
4. Save selected best first-cut sizes at index pos[i] during profit evaluations.
5. Reconstruct cut sequence by traversing pos tracking decisions iteratively from total length n down to 0.
6. Output total maximum revenue and exact piece combination along with O(n^2) time and O(n) space metrics.
*/
