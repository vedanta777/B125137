#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 100      // Number of sorted arrays
#define N 10000    // Elements per array (1,000,000 total elements)

void merge(int a[], int n1, int b[], int n2, int result[])
{
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2)
    {
        if(a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while(i < n1)
        result[k++] = a[i++];

    while(j < n2)
        result[k++] = b[j++];
}

int main()
{
    // Allocate 2D array dynamically to prevent stack overflow
    int **arrays = (int **)malloc(K * sizeof(int *));
    for(int i = 0; i < K; i++)
    {
        arrays[i] = (int *)malloc(N * sizeof(int));
    }

    // Populate all K sorted arrays in a sorted pattern using 2 nested loops
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < N; j++)
        {
            arrays[i][j] = (j * K) + (i + 1);
        }
    }

    printf("=== Method 1: Sequential Merge ===\n");
    printf("Merging %d sorted arrays of %d elements each (Total %d elements)...\n", K, N, K * N);

    clock_t start = clock();

    int current_size = N;
    int *current_result = (int *)malloc(current_size * sizeof(int));

    for(int j = 0; j < N; j++)
        current_result[j] = arrays[0][j];

    // Sequentially merge array by array into the accumulating result buffer
    for(int i = 1; i < K; i++)
    {
        int next_size = current_size + N;
        int *temp_result = (int *)malloc(next_size * sizeof(int));

        merge(current_result, current_size, arrays[i], N, temp_result);

        free(current_result);
        current_result = temp_result;
        current_size = next_size;
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMerged Result (First 10 elements):\n");
    for(int i = 0; i < 10; i++)
        printf("%d ", current_result[i]);

    printf("\n...\nTime taken: %f seconds (%f ms)\n", time_taken, time_taken * 1000);

    // Free allocated memory
    free(current_result);
    for(int i = 0; i < K; i++)
        free(arrays[i]);
    free(arrays);

    return 0;
}