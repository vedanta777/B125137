#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void merge(int arr[], int left, int mid1, int mid2, int right)
{
    int n1 = mid1 - left + 1;
    int n2 = mid2 - mid1;
    int n3 = right - mid2;

    int *A = (int *)malloc(n1 * sizeof(int));
    int *B = (int *)malloc(n2 * sizeof(int));
    int *C = (int *)malloc(n3 * sizeof(int));

    for(int i = 0; i < n1; i++)
        A[i] = arr[left + i];

    for(int i = 0; i < n2; i++)
        B[i] = arr[mid1 + 1 + i];

    for(int i = 0; i < n3; i++)
        C[i] = arr[mid2 + 1 + i];

    int i = 0;
    int j = 0;
    int k = 0;
    int index = left;

    while(i < n1 && j < n2 && k < n3)
    {
        if(A[i] <= B[j] && A[i] <= C[k])
            arr[index++] = A[i++];
        else if(B[j] <= A[i] && B[j] <= C[k])
            arr[index++] = B[j++];
        else
            arr[index++] = C[k++];
    }

    while(i < n1 && j < n2)
    {
        if(A[i] <= B[j])
            arr[index++] = A[i++];
        else
            arr[index++] = B[j++];
    }

    while(j < n2 && k < n3)
    {
        if(B[j] <= C[k])
            arr[index++] = B[j++];
        else
            arr[index++] = C[k++];
    }

    while(i < n1 && k < n3)
    {
        if(A[i] <= C[k])
            arr[index++] = A[i++];
        else
            arr[index++] = C[k++];
    }

    while(i < n1)
        arr[index++] = A[i++];

    while(j < n2)
        arr[index++] = B[j++];

    while(k < n3)
        arr[index++] = C[k++];

    free(A);
    free(B);
    free(C);
}

void mergeSort3Way(int arr[], int left, int right)
{
    if(left >= right)
        return;

    int third = (right - left) / 3;

    int mid1 = left + third;
    int mid2 = left + 2 * third + 1;

    if(mid2 > right)
        mid2 = right;

    mergeSort3Way(arr, left, mid1);
    mergeSort3Way(arr, mid1 + 1, mid2);
    mergeSort3Way(arr, mid2 + 1, right);

    merge(arr, left, mid1, mid2, right);
}

int main()
{
    int *arr = (int *)malloc(SIZE * sizeof(int));
    srand(time(NULL));

    for(int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000000;

    printf("Sorting array of size %d using 3-Way Merge Sort...\n", SIZE);

    clock_t start = clock();
    mergeSort3Way(arr, 0, SIZE - 1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds (%f ms)\n", time_taken, time_taken * 1000);

    free(arr);
    return 0;
}