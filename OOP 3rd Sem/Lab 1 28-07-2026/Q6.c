#include <stdio.h>

struct Distance {
    float inches;
    float feet;
    float total_feet;
};

int main() {
    struct Distance dist;

    // User Inputs
    printf("Enter Feet: ");
    scanf("%f", &dist.feet);

    printf("Enter Inches: ");
    scanf("%f", &dist.inches);

    // Calculation (12 inches = 1 foot)
    dist.total_feet = dist.feet + (dist.inches / 12.0f);

    // Output display
    printf("\n--- Distance Summary ---\n");
    printf("Input        : %.2f ft, %.2f in\n", dist.feet, dist.inches);
    printf("Total Feet   : %.2f ft\n", dist.total_feet);

    return 0;
}
