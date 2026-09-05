#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double find_std_dev(int arr[], int n) {
    double sum = 0, mean, sq_sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    mean = sum / n;

    for (int i = 0; i < n; i++) {
        sq_sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return sqrt(sq_sum / n);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Standard Deviation: %.4f\n", find_std_dev(arr, n));
    free(arr);
    return 0;
}