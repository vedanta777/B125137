#include <stdio.h>
#include <stdlib.h>

long long getCollatzSteps(long long n) {
    long long steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }
    return steps;
}

void analyzeInterval(long long a, long long b) {
    long long max_steps = 0;
    long long max_val = a;

    for (long long i = a; i <= b; i++) {
        long long steps = getCollatzSteps(i);
        if (steps > max_steps) {
            max_steps = steps;
            max_val = i;
        }
    }

    printf("\n--- Interval Analysis [%lld, %lld] ---\n", a, b);
    printf("Value with longest trajectory: %lld\n", max_val);
    printf("Maximum stopping time (steps to reach 1): %lld\n", max_steps);
}

int main() {
    long long single_n, a, b;
    
    printf("Enter a single starting value n (>= 1): ");
    scanf("%lld", &single_n);
    if (single_n < 1) {
        printf("Invalid input! n must be >= 1.\n");
        return 1;
    }

    printf("Trajectory steps for %lld: %lld\n", single_n, getCollatzSteps(single_n));

    printf("\nEnter interval bounds [a, b]: ");
    scanf("%lld %lld", &a, &b);
    if (a < 1 || b < a) {
        printf("Invalid interval bounds!\n");
        return 1;
    }

    analyzeInterval(a, b);

    printf("\n--- Complexity Analysis ---\n");
    printf("Time Complexity: O((b - a + 1) * T(n)) [Unbounded per value, empirically small]\n");
    printf("Space Complexity: O(1)\n");

    return 0;
}

/*
Algorithm Logic & Code Flow:
1. Accept user inputs for single test value n and interval bounds [a, b].
2. Evaluate single number trajectory applying rules n/2 for even numbers and 3n+1 for odd numbers.
3. Count total iteration steps taken until integer value successfully converges down to 1.
4. Loop sequentially through closed interval bounds [a, b] computing trajectory lengths dynamically.
5. Track maximum stopping step count and pinpoint exact value producing peak trajectory sequence.
6. Display detailed evaluation report alongside O(1) space and open-problem empirical time bounds.
*/
