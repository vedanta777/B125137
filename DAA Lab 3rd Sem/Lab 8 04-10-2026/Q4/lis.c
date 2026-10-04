#include <stdio.h>

int LIS(int arr[], int n) {
    int lis[n];
    for (int i = 0; i < n; i++) lis[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (lis[i] > max) max = lis[i];
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

    printf("Length of LIS: %d\n", LIS(arr, n));

    printf("\n--- Complexity Analysis ---\n");
    printf("Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(n)\n");

    return 0;
}

/*
Algorithm Logic & Code Flow:
1. Accept dynamic size input n and read integer array elements into array A.
2. Initialize temporary LIS tracking array filling base values of 1 for all array indices.
3. Compare each current element i against prior elements j from index 0 up to i-1.
4. Increment subproblem sequence lengths whenever strictly increasing condition A[i] > A[j] is verified.
5. Compute global maximum element among calculated LIS subproblem values.
6. Print longest sequence length alongside its quadratic O(n^2) runtime and linear O(n) space complexity.
*/
