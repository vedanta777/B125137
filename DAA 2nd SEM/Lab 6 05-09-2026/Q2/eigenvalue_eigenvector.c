#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void power_method(int n, double A[n][n], int max_iter, double tol) {
    double X[n], X_new[n];
    for (int i = 0; i < n; i++) X[i] = 1.0; 

    double lambda_old = 0, lambda_new = 0;

    for (int iter = 0; iter < max_iter; iter++) {
        for (int i = 0; i < n; i++) {
            X_new[i] = 0;
            for (int j = 0; j < n; j++) {
                X_new[i] += A[i][j] * X[j];
            }
        }

        lambda_new = fabs(X_new[0]);
        for (int i = 1; i < n; i++) {
            if (fabs(X_new[i]) > lambda_new) lambda_new = fabs(X_new[i]);
        }

        for (int i = 0; i < n; i++) X_new[i] /= lambda_new;

        if (fabs(lambda_new - lambda_old) < tol) break;
        
        lambda_old = lambda_new;
        for (int i = 0; i < n; i++) X[i] = X_new[i];
    }

    printf("Dominant Eigenvalue: %.4f\n", lambda_new);
    printf("Corresponding Eigenvector: ");
    for (int i = 0; i < n; i++) printf("%.4f ", X_new[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter matrix dimension n (n x n): ");
    scanf("%d", &n);

    double A[n][n];
    printf("Enter elements of Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%lf", &A[i][j]);

    power_method(n, A, 1000, 0.0001);
    return 0;
}