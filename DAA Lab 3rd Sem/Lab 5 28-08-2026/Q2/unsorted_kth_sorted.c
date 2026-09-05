#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

int findKthSmallest(int arr[], int low, int high, int k) {
    // k is converted to 0-based index (k - 1)
    if (k > 0 && k <= high - low + 1) {
        int pi = partition(arr, low, high);

        if (pi - low == k - 1)
            return arr[pi];
        if (pi - low > k - 1)
            return findKthSmallest(arr, low, pi - 1, k);
        return findKthSmallest(arr, pi + 1, high, k - (pi - low + 1));
    }
    return -1;
}

int main() {
    int n, k;
    printf("Enter number of elements (N): ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d space-separated integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of K (1 to %d): ", n);
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid value of K.\n");
    } else {
        int result = findKthSmallest(arr, 0, n - 1, k);
        printf("\nThe %d-th smallest element is: %d\n", k, result);
    }

    free(arr);
    return 0;
}