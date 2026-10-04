#include <stdio.h>

int MSIS(int arr[], int n) {
    int msis[n];
    for (int i = 0; i < n; i++) {
        msis[i] = arr[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                msis[i] = msis[j] + arr[i];
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (msis[i] > max) max = msis[i];
    }
    return max;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Maximum Sum Increasing Subsequence: %d\n", MSIS(arr, n));

    printf("\n--- Complexity Analysis ---\n");
    printf("Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(n)\n");

    return 0;
}

/*
Algorithm Logic & Code Flow:
1. Prompt user for sequence size n and read input array values into memory.
2. Initialize dynamic programming array initialized with values of each corresponding original array index.
3. Compare current element i with every preceding index j to check strictly increasing progression.
4. Update subproblem sums dynamically when including element i yields higher total sequence sum.
5. Search maximum value stored across all entries in the computed MSIS table.
6. Print ultimate maximum sum obtained with O(n^2) time complexity and O(n) auxiliary space.
*/
