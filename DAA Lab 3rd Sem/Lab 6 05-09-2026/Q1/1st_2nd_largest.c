#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void find_two_largest(int arr[], int n) {
    if (n < 2) {
        printf("Array needs at least 2 elements.\n");
        return;
    }
    int first = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    if (second == INT_MIN)
        printf("No distinct second largest element found.\n");
    else
        printf("First Largest: %d, Second Largest: %d\n", first, second);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    find_two_largest(arr, n);
    free(arr);
    return 0;
}