/*
 * Q3: Reve's Puzzle
 * Frame-Stewart algorithm to solve 4-peg Tower of Hanoi.
 */

#include <stdio.h>
#include <math.h>

static int move_count = 0;

/*
 * Method Explanation:
 * Reve's puzzle solves 4-peg Hanoi via the Frame-Stewart recursive algorithm:
 * 1. Calculate optimal partition k = n - round(sqrt(2*n + 1)) + 1.
 * 2. Move top k disks from source to aux1 using 4 pegs.
 * 3. Move bottom (n - k) disks from source to target using 3 pegs (standard Hanoi).
 * 4. Move top k disks from aux1 to target using 4 pegs.
 *
 * Complexity:
 * - Time Complexity: O(2^(sqrt(2n))) move operations.
 * - Space Complexity: O(n) auxiliary recursion stack depth.
 */

// Standard 3-peg Hanoi subroutine
void hanoi_3peg(int count, char source, char target, char aux) {
    if (count <= 0) return;
    
    hanoi_3peg(count - 1, source, aux, target);
    
    move_count++;
    printf("Move %2d: Move top disk from Peg %c to Peg %c\n", move_count, source, target);
    fflush(stdout);
    
    hanoi_3peg(count - 1, aux, target, source);
}

// 4-peg Reve's puzzle solver
void reves_puzzle(int n, char source, char target, char aux1, char aux2) {
    // Base case 0 disks
    if (n <= 0) return;

    // Base case 1 disk
    if (n == 1) {
        move_count++;
        printf("Move %2d: Move top disk from Peg %c to Peg %c\n", move_count, source, target);
        fflush(stdout);
        return;
    }

    // Frame-Stewart optimal choice of k
    int k = (int)round(n - sqrt(2.0 * n + 1.0) + 1.0);

    // Enforce strict bounds: k MUST be strictly between 1 and n-1
    if (k >= n || k <= 0) {
        k = n - 1;
    }

    // Step 1: Transfer top k disks to aux1 using 4 pegs
    reves_puzzle(k, source, aux1, target, aux2);

    // Step 2: Transfer remaining (n - k) disks to target using 3 pegs
    hanoi_3peg(n - k, source, target, aux2);

    // Step 3: Transfer top k disks from aux1 to target using 4 pegs
    reves_puzzle(k, aux1, target, source, aux2);
}

int main() {
    int n;

    // Flush prompt output explicitly
    printf("Enter total number of disks (n): ");
    fflush(stdout);

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    move_count = 0;
    printf("\n--- Sequence of Moves for %d Disks (4 Pegs) ---\n", n);
    fflush(stdout);

    reves_puzzle(n, 'A', 'B', 'C', 'D');

    printf("\nTotal moves executed: %d\n", move_count);
    fflush(stdout);

    return 0;
}