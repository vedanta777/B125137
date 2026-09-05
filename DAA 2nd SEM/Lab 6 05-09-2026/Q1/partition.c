#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void custom_partition(int arr[], int n) {
    srand(time(0));
    int pivot_idx = rand() % n;
    int pivot = arr[pivot_idx];
    printf("Chosen Pivot Element: %d\n", pivot);

    int left = 0, right = n - 1;
    while (left <= right) {
        while (left <= right && arr[left] >= pivot) left++;
        while (left <= right && arr[right] < pivot) right--;
        if (left < right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    custom_partition(arr, n);
    printf("Partitioned Array (>= Pivot first, < Pivot after): ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}