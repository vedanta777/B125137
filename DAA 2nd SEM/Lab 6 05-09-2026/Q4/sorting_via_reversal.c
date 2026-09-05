#include <stdio.h>
#include <stdlib.h>

long long total_cost = 0;

// Reverses elements in range [i, j] and adds range length to cost
void reverse(int p[], int i, int j) {
    if (i >= j) return;
    int len = j - i + 1;
    total_cost += len; // Cost is equal to range length

    while (i < j) {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++;
        j--;
    }
}

// Custom Merge step using block reversals to keep cost within O(n log^2 n)
void divide_and_conquer_sort(int p[], int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;

    divide_and_conquer_sort(p, low, mid);
    divide_and_conquer_sort(p, mid + 1, high);

    // Merge step via reversals
    int l = low, r = mid + 1;
    while (l <= mid && r <= high) {
        if (p[l] <= p[r]) {
            l++;
        } else {
            int val = p[r];
            int index = r;

            // Shift element using sub-segment reversal
            reverse(p, l, index);
            reverse(p, l + 1, index);

            l++;
            mid++;
            r++;
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements in permutation (1 to n): ");
    scanf("%d", &n);

    int *p = (int *)malloc(n * sizeof(int));
    printf("Enter permutation of numbers 1 to %d: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    total_cost = 0;
    divide_and_conquer_sort(p, 0, n - 1);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\nTotal Accumulated Reversal Cost: %lld\n", total_cost);

    free(p);
    return 0;
}