#include <stdio.h>

void transpose_in_situ(int n, int A[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter matrix dimension n (n x n): ");
    scanf("%d", &n);

    int A[n][n];
    printf("Enter elements of Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);

    transpose_in_situ(n, A);

    printf("Transposed Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", A[i][j]);
        printf("\n");
    }
    return 0;
}