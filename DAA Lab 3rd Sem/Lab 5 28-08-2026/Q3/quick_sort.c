#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter number of random elements (N) to generate: ");
    scanf("%d", &n);

    // Step 1: Write N random elements to input.txt
    FILE *fin = fopen("input.txt", "w");
    if (!fin) {
        printf("Error opening input file!\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < n; i++) {
        fprintf(fin, "%d ", rand() % 10000);
    }
    fclose(fin);
    printf("Successfully generated %d random numbers into 'input.txt'.\n", n);

    // Step 2: Read elements back into memory
    fin = fopen("input.txt", "r");
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);

    // Step 3: Sort using QuickSort
    quickSort(arr, 0, n - 1);

    // Step 4: Write sorted array to sorted_quicksort.txt
    FILE *fout = fopen("sorted_quicksort.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%d ", arr[i]);
    }
    fclose(fout);

    printf("Successfully written sorted elements to 'sorted_quicksort.txt'.\n");

    free(arr);
    return 0;
}