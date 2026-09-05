#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double real;
    double imag;
} Complex;

Complex add(Complex a, Complex b) {
    return (Complex){a.real + b.real, a.imag + b.imag};
}

Complex sub(Complex a, Complex b) {
    return (Complex){a.real - b.real, a.imag - b.imag};
}

Complex mul(Complex a, Complex b) {
    return (Complex){a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

// Cooley-Tukey FFT Algorithm
void fft(Complex *x, int n, int invert) {
    if (n <= 1) return;

    Complex *even = (Complex *)malloc((n / 2) * sizeof(Complex));
    Complex *odd  = (Complex *)malloc((n / 2) * sizeof(Complex));

    for (int i = 0; i < n / 2; i++) {
        even[i] = x[2 * i];
        odd[i]  = x[2 * i + 1];
    }

    fft(even, n / 2, invert);
    fft(odd, n / 2, invert);

    double angle = 2 * PI / n * (invert ? -1 : 1);
    Complex w = {1, 0};
    Complex wn = {cos(angle), sin(angle)};

    for (int i = 0; i < n / 2; i++) {
        Complex t = mul(w, odd[i]);
        x[i] = add(even[i], t);
        x[i + n / 2] = sub(even[i], t);
        if (invert) {
            x[i].real /= 2;
            x[i].imag /= 2;
            x[i + n / 2].real /= 2;
            x[i + n / 2].imag /= 2;
        }
        w = mul(w, wn);
    }

    free(even);
    free(odd);
}

int main() {
    int m, n;
    printf("Enter length of Vector A (m): ");
    scanf("%d", &m);
    printf("Enter length of Vector B (n, where n >= m): ");
    scanf("%d", &n);

    if (m > n) {
        printf("Condition n >= m violated. Swapping inputs logically.\n");
    }

    int result_len = m + n - 1;
    int N = 1;
    while (N < result_len) N <<= 1;

    Complex *A = (Complex *)calloc(N, sizeof(Complex));
    Complex *B = (Complex *)calloc(N, sizeof(Complex));

    printf("Enter %d elements of Vector A: ", m);
    for (int i = 0; i < m; i++) scanf("%lf", &A[i].real);

    printf("Enter %d elements of Vector B: ", n);
    for (int i = 0; i < n; i++) scanf("%lf", &B[i].real);

    // Compute FFT of both vectors
    fft(A, N, 0);
    fft(B, N, 0);

    // Pointwise multiplication in frequency domain
    Complex *C = (Complex *)malloc(N * sizeof(Complex));
    for (int i = 0; i < N; i++) {
        C[i] = mul(A[i], B[i]);
    }

    // Inverse FFT to get convolution result
    fft(C, N, 1);

    printf("\nConvolved Vector C (Size %d):\n", result_len);
    for (int i = 0; i < result_len; i++) {
        printf("%.2f ", C[i].real);
    }
    printf("\n");

    free(A); free(B); free(C);
    return 0;
}