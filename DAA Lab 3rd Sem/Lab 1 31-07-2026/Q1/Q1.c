#include <stdio.h>

int main()
{
    char *functions[] = {
        "1/n",
        "log2(n)",
        "12*sqrt(n)",
        "50*sqrt(n)",
        "n^0.51",
        "2^32*n",
        "n*log2(n)",
        "n^2 - 324",
        "100*n^2 + 6*n",
        "2*n^3",
        "n^(log2(n))",
        "3^n"
    };

    int n = sizeof(functions) / sizeof(functions[0]);

    printf("Functions in increasing order of growth:\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("%2d. %s\n", i + 1, functions[i]);
    }

    return 0;
}

/*
-> the general order of increasing rate of growth is decreasing functions, logarithm, root, fractional power, linear, quadratic, cubic, super-polynomial, exponential, factorial and x raised to x.
-> the up and down in rate between two functions of same category is due to their coefficients of dominant terms (compared first) and terms other than the dominant term in the polynomial.
*/