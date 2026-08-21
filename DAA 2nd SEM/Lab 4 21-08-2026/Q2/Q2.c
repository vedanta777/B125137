#include <stdio.h>
#include <stdbool.h>

// Utility function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort (Lomuto Partition Scheme)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Explicit Quick Sort implementation: O(n log n) average time complexity
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Binary search to find ANY matching index of target in array
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Function to find and print ALL pairs from S1 and S2 that sum to x
int findAllTwoSumPairs(int S1[], int S2[], int n1, int n2, int x) {
    // Step 1: Sort S2 using Quick Sort in O(n2 log n2)
    quickSort(S2, 0, n2 - 1);

    int pairCount = 0;

    // Step 2: Search for matches for each element in S1
    for (int i = 0; i < n1; i++) {
        int target = x - S1[i];
        int matchIdx = binarySearch(S2, n2, target);

        if (matchIdx != -1) {
            // Scan LEFT to find all duplicate occurrences of target in sorted S2
            int left = matchIdx;
            while (left >= 0 && S2[left] == target) {
                printf("Pair %d: %d (from S1[%d]) + %d (from S2[%d]) = %d\n", 
                       ++pairCount, S1[i], i, S2[left], left, x);
                left--;
            }

            // Scan RIGHT to find all duplicate occurrences of target in sorted S2
            int right = matchIdx + 1;
            while (right < n2 && S2[right] == target) {
                printf("Pair %d: %d (from S1[%d]) + %d (from S2[%d]) = %d\n", 
                       ++pairCount, S1[i], i, S2[right], right, x);
                right++;
            }
        }
    }

    return pairCount;
}

int main() {
    int S1[] = {12, 3, 7, 3, 19};
    int S2[] = {4, 14, 14, 2, 10};
    int n1 = sizeof(S1) / sizeof(S1[0]);
    int n2 = sizeof(S2) / sizeof(S2[0]);
    int x = 17;

    printf("Searching for all pairs from S1 and S2 that add up to %d:\n\n", x);
    int totalPairs = findAllTwoSumPairs(S1, S2, n1, n2, x);

    if (totalPairs == 0) {
        printf("No satisfying pairs found.\n");
    } else {
        printf("\nTotal matching pairs found: %d\n", totalPairs);
    }

    return 0;
}