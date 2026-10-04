/*
 * Q1: Invert Coin Triangle
 * Find minimum moves to flip an n-row coin triangle.
 */

#include <stdio.h>

/*
 * Method Explanation:
 * For an equilateral triangle of side/height n:
 * The total number of coins is N = n * (n + 1) / 2.
 * To invert the triangle in minimum moves, we move the coins from the 
 * corners/tips into missing positions of the inverted orientation.
 * Mathematically, the minimum number of moves required is floor(n * (n + 1) / 6).
 *
 * Complexity:
 * - Time Complexity: O(1) direct mathematical formula evaluation.
 * - Space Complexity: O(1) auxilliary space.
 */

int main() {
    int n;

    // Take user input for the number of rows in the coin triangle
    printf("Enter the number of rows (n) in the coin triangle: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Formula: floor(n * (n + 1) / 6)
    int min_moves = (n * (n + 1)) / 6;

    // Output the result
    printf("\n--- Coin Triangle Inversion Results ---\n");
    printf("Number of rows (n): %d\n", n);
    printf("Total coins: %d\n", (n * (n + 1)) / 2);
    printf("Minimum moves required: %d\n", min_moves);

    return 0;
}