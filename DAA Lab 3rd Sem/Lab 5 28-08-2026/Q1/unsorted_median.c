#include <stdio.h>
#include <stdlib.h>

// Utility function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function similar to QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSelect implementation to find the k-th smallest element (0-indexed)
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi == k)
            return arr[pi];
        else if (pi > k)
            return quickSelect(arr, low, pi - 1, k);
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    return -1;
}

int main() {
    int n;
    printf("Enter number of elements (N): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d space-separated integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    double median;
    if (n % 2 != 0) {
        // Odd length: middle element
        median = quickSelect(arr, 0, n - 1, n / 2);
    } else {
        // Even length: average of two middle elements
        int mid1 = quickSelect(arr, 0, n - 1, n / 2 - 1);
        int mid2 = quickSelect(arr, 0, n - 1, n / 2);
        median = (double)(mid1 + mid2) / 2.0;
    }

    printf("\nMedian of the list: %.2f\n", median);
    free(arr);
    return 0;
}