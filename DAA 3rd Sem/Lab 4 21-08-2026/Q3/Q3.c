#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return true;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// Recursive helper achieving O(n^(k-1) log n)
bool kSumHelper(int S[], int n, int k, int target, int startIndex) {
    // Base Case: 2-Sum using Binary Search in O(n log n)
    if (k == 2) {
        for (int i = startIndex; i < n - 1; i++) {
            int needed = target - S[i];
            if (binarySearch(S, i + 1, n - 1, needed)) {
                return true;
            }
        }
        return false;
    }

    // Recursive Case: Fix element and solve (k-1)-Sum
    for (int i = startIndex; i <= n - k; i++) {
        if (kSumHelper(S, n, k - 1, target - S[i], i + 1)) {
            return true;
        }
    }

    return false;
}

bool kSum(int S[], int n, int k, int T) {
    qsort(S, n, sizeof(int), compare); // O(n log n) initial sort
    return kSumHelper(S, n, k, T, 0);
}

int main() {
    int S[] = {1, 4, 45, 6, 10, 8, 12};
    int n = sizeof(S) / sizeof(S[0]);
    int k = 4;
    int T = 29; // e.g., 1 + 4 + 6 + 18 (or 1 + 6 + 10 + 12 = 29)

    if (kSum(S, n, k, T)) {
        printf("Yes, there exist %d elements in S that sum up to %d.\n", k, T);
    } else {
        printf("No %d elements sum up to %d.\n", k, T);
    }

    return 0;
}