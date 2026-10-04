/*
 * Q4: Security Switches
 * Minimum operations to turn off n security switches.
 */

#include <stdio.h>

static int move_count = 0;

/*
 * Method Explanation:
 * The rules given correspond directly to Gray Code / Chinese Ring Puzzle mechanisms.
 * To turn off n switches (initially all 1s):
 * - turning_off(n):
 *    1. Recursively turn off switches 1 to n-2 (if n > 2).
 *    2. Toggle switch n (turn off).
 *    3. Recursively turn on switches 1 to n-2 (if n > 2).
 *    4. Recursively turn off switches 1 to n-1.
 *
 * Formula for minimum moves:
 * - If n is even: (2^(n+1) - 2) / 3
 * - If n is odd:  (2^(n+1) - 1) / 3
 *
 * Complexity:
 * - Time Complexity: O(2^n) switch toggles.
 * - Space Complexity: O(n) stack depth.
 */

void turn_on(int n, int state[]);

void turn_off(int n, int state[]) {
    if (n <= 0) return;
    if (n == 1) {
        state[1] = 0;
        move_count++;
        printf("Move %2d: Toggle switch 1 OFF\n", move_count);
        return;
    }

    // Step 1: Turn off switches 1 to n-2
    turn_off(n - 2, state);

    // Step 2: Toggle switch n OFF
    state[n] = 0;
    move_count++;
    printf("Move %2d: Toggle switch %d OFF\n", move_count, n);

    // Step 3: Turn on switches 1 to n-2
    turn_on(n - 2, state);

    // Step 4: Turn off switches 1 to n-1
    turn_off(n - 1, state);
}

void turn_on(int n, int state[]) {
    if (n <= 0) return;
    if (n == 1) {
        state[1] = 1;
        move_count++;
        printf("Move %2d: Toggle switch 1 ON\n", move_count);
        return;
    }

    turn_on(n - 1, state);
    turn_off(n - 2, state);
    state[n] = 1;
    move_count++;
    printf("Move %2d: Toggle switch %d ON\n", move_count, n);
    turn_on(n - 2, state);
}

int main() {
    int n;

    printf("Enter number of security switches (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int state[100];
    for (int i = 1; i <= n; i++) state[i] = 1; // Initially all ON

    move_count = 0;
    printf("\n--- Step-by-Step Toggle Sequence ---\n");
    turn_off(n, state);

    printf("\nTotal moves executed: %d\n", move_count);

    // Calculate theoretical minimum using mathematical formula
    long long expected_moves = (n % 2 == 0) ? ((1LL << (n + 1)) - 2) / 3 : ((1LL << (n + 1)) - 1) / 3;
    printf("Theoretical Minimum Moves: %lld\n", expected_moves);

    return 0;
}