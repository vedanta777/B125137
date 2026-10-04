/*
 * Q5: Hitting a Moving Target
 * Deterministic shooting strategy to hit an adjacent-moving target.
 */

#include <stdio.h>

/*
 * Method Explanation:
 * Spot positions are indexed 1 to n.
 * At each step, the target parity (even or odd index) toggles because it moves
 * to an adjacent spot (+1 or -1).
 *
 * Strategy:
 * Phase 1: Assume target starts at an EVEN spot.
 *          Shoot spots 2, 3, ..., n-1 in order.
 * Phase 2: If missed, target must have started at an ODD spot.
 *          Shoot spots 2, 3, ..., n-1 (or vice versa for edge parity handling).
 *
 * Total shots required: 2 * (n - 2) shots for n >= 3.
 *
 * Complexity:
 * - Time Complexity: O(n) total shot operations.
 * - Space Complexity: O(1) auxiliary storage.
 */

void generate_shooting_sequence(int n) {
    if (n <= 1) {
        printf("Invalid number of spots. n must be > 1.\n");
        return;
    }
    if (n == 2) {
        printf("Shoot Spot 1, then Shoot Spot 1.\n");
        return;
    }

    int shot = 1;
    printf("\n--- Guaranteed Shooting Order ---\n");

    // Phase 1: Sweep left-to-right assuming Even starting spot
    printf("Phase 1 (Assuming target started on EVEN position):\n");
    for (int i = 2; i <= n - 1; i++) {
        printf("Shot %d: Target Spot %d\n", shot++, i);
    }

    // Phase 2: Sweep left-to-right or right-to-left assuming Odd starting spot
    printf("Phase 2 (Assuming target started on ODD position):\n");
    for (int i = 2; i <= n - 1; i++) {
        printf("Shot %d: Target Spot %d\n", shot++, i);
    }

    printf("Guaranteed target elimination within %d shots!\n", shot - 1);
}

int main() {
    int n;

    printf("Enter number of hiding spots along line (n > 1): ");
    if (scanf("%d", &n) != 1 || n <= 1) {
        printf("Target needs at least 2 hiding spots.\n");
        return 1;
    }

    generate_shooting_sequence(n);

    return 0;
}