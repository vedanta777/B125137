#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);
        if (pi == k) return arr[pi];
        else if (pi > k) return quickselect(arr, low, pi - 1, k);
        else return quickselect(arr, pi + 1, high, k);
    }
    return -1;
}

double find_median(int arr[], int n) {
    if (n % 2 != 0) {
        return quickselect(arr, 0, n - 1, n / 2);
    } else {
        int m1 = quickselect(arr, 0, n - 1, n / 2 - 1);
        int m2 = quickselect(arr, 0, n - 1, n / 2);
        return (m1 + m2) / 2.0;
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Median: %.2f\n", find_median(arr, n));
    free(arr);
    return 0;
}