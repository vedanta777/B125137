#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter matrix dimension n (n x n): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);

    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &B[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Resultant Matrix Multiplication:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}