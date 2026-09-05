#include <stdio.h>
#include <stdlib.h>

int remove_duplicates(int arr[], int n) {
    int new_size = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < new_size; j++) {
            if (arr[i] == arr[j]) break;
        }
        if (j == new_size) {
            arr[new_size++] = arr[i];
        }
    }
    return new_size;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int new_n = remove_duplicates(arr, n);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < new_n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}