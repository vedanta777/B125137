#include <stdio.h>
#include <stdbool.h>

bool is_symmetric(int n, int A[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i][j] != A[j][i]) return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter matrix dimension n (n x n): ");
    scanf("%d", &n);

    int A[n][n];
    printf("Enter elements of Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);

    if (is_symmetric(n, A)) printf("The matrix is SYMMETRIC.\n");
    else printf("The matrix is NOT symmetric.\n");

    return 0;
}