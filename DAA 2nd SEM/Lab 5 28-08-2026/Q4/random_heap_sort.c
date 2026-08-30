#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintains Max-Heap property
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter number of random elements (N) to generate: ");
    scanf("%d", &n);

    // Step 1: Write N random numbers to file
    FILE *fin = fopen("input.txt", "w");
    if (!fin) {
        printf("Error creating file!\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < n; i++) {
        fprintf(fin, "%d ", rand() % 10000);
    }
    fclose(fin);
    printf("Generated %d random numbers into 'input.txt'.\n", n);

    // Step 2: Read data from file
    fin = fopen("input.txt", "r");
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);

    // Step 3: Run HeapSort
    heapSort(arr, n);

    // Step 4: Save output
    FILE *fout = fopen("sorted_heapsort.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%d ", arr[i]);
    }
    fclose(fout);

    printf("Sorted array written to 'sorted_heapsort.txt'.\n");

    free(arr);
    return 0;
}