#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 100000;
    int fair = 0, biased = 0;

    srand(time(NULL));

    for(int i = 0; i < n; i++) {

        // Fair coin
        if(rand() % 2 == 0)
            fair++;

        // Biased coin (70% heads)
        double r = (double)rand() / RAND_MAX;

        if(r < 0.7)
            biased++;
    }

    printf("Fair Coin Probability = %.5f\n", (double)fair/n);
    printf("Biased Coin Probability = %.5f\n", (double)biased/n);

    return 0;
}

/*
-> rand is not used because it always generates the same sequence of random numbers for every execution.
-> srand changes the seed value, so every execution of rand generates a unique sequence of random numbers
-> time(NULL) returns the current sytem time in seconds and srand generates a random seed, and then rand is used to generate a random sequence of numbers based on return value from time(NULL).
-> for unbiased coin simulation, we just divide the random number by 2, where, a remainder of 0 means heads and 1 means tails.
-> for biased coin simulation, we take a random decimal which indicates the max rate of occurence of heads in the coin (in this case 0.7 or 70 percent).
-> after the random sequence is generated, division by the greatest generable number follows, but this time a decimal score below 0.7 indicates head and above tails.
*/