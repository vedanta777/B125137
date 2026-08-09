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

    printf("=== Method 2: Pairwise Tree Merge ===\n");
    printf("Merging %d sorted arrays of %d elements each (Total %d elements)...\n", K, N, K * N);

    clock_t start = clock();

    int **current_level = (int **)malloc(K * sizeof(int *));
    int *current_sizes = (int *)malloc(K * sizeof(int));

    for(int i = 0; i < K; i++)
    {
        current_level[i] = (int *)malloc(N * sizeof(int));
        for(int j = 0; j < N; j++)
            current_level[i][j] = arrays[i][j];
        current_sizes[i] = N;
    }

    int active_arrays = K;

    // Merge adjacent pairs level-by-level until 1 final array remains
    while(active_arrays > 1)
    {
        int next_active = 0;

        for(int i = 0; i < active_arrays; i += 2)
        {
            if(i + 1 < active_arrays)
            {
                int new_size = current_sizes[i] + current_sizes[i + 1];
                int *merged = (int *)malloc(new_size * sizeof(int));

                merge(current_level[i], current_sizes[i], current_level[i + 1], current_sizes[i + 1], merged);

                free(current_level[i]);
                free(current_level[i + 1]);

                current_level[next_active] = merged;
                current_sizes[next_active] = new_size;
                next_active++;
            }
            else
            {
                current_level[next_active] = current_level[i];
                current_sizes[next_active] = current_sizes[i];
                next_active++;
            }
        }
        active_arrays = next_active;
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMerged Result (First 10 elements):\n");
    for(int i = 0; i < 10; i++)
        printf("%d ", current_level[0][i]);

    printf("\n...\nTime taken: %f seconds (%f ms)\n", time_taken, time_taken * 1000);

    // Free allocated memory
    free(current_level[0]);
    free(current_level);
    free(current_sizes);
    for(int i = 0; i < K; i++)
        free(arrays[i]);
    free(arrays);

    return 0;
}