#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double determinant(int n, double A[n][n]) {
    double det = 1.0;
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(A[j][i]) > fabs(A[pivot][i])) pivot = j;
        }
        if (pivot != i) {
            for (int k = 0; k < n; k++) {
                double temp = A[i][k];
                A[i][k] = A[pivot][k];
                A[pivot][k] = temp;
            }
            det *= -1;
        }
        if (A[i][i] == 0) return 0;
        det *= A[i][i];
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i + 1; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }
    return det;
}

int main() {
    int n;
    printf("Enter matrix dimension n (n x n): ");
    scanf("%d", &n);

    double A[n][n];
    printf("Enter elements of Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%lf", &A[i][j]);

    printf("Determinant: %.2f\n", determinant(n, A));
    return 0;
}