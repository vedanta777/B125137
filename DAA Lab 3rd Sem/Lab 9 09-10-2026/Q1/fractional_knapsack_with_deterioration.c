#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item with decay rate
typedef struct {
    int id;
    double v;        // Base value
    double w;        // Weight
    double lambda;   // Decay rate
    double density;  // Initial value density (v / w)
} Item;

// Comparator to sort items in descending order of decay rate (lambda)
// Greedy Choice: Consume items with higher decay rates first to minimize lost value over time
int compareLambda(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item2->lambda > item1->lambda) return 1;
    if (item2->lambda < item1->lambda) return -1;
    return 0;
}

int main() {
    int n;
    double W;

    // Prompt user for input
    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    printf("Enter knapsack capacity (W): ");
    if (scanf("%lf", &W) != 1 || W <= 0) return 0;

    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Enter base value (v), weight (w), and decay rate (lambda) for item %d: ", i + 1);
        scanf("%lf %lf %lf", &items[i].v, &items[i].w, &items[i].lambda);
        items[i].density = items[i].v / items[i].w;
    }

    // Sort items by decay rate in descending order
    qsort(items, n, sizeof(Item), compareLambda);

    double total_value = 0.0;
    double current_time = 0.0;
    double current_weight = 0.0;

    printf("\n--- Optimal Scheduling & Selection Order ---\n");
    for (int i = 0; i < n; i++) {
        if (current_weight >= W) break;

        // Determine fraction of current item to take
        double remaining_capacity = W - current_weight;
        double fraction = (items[i].w <= remaining_capacity) ? 1.0 : (remaining_capacity / items[i].w);

        // Effective value density decays as: (v_i / w_i) - lambda_i * t
        double effective_density = items[i].density - (items[i].lambda * current_time);
        if (effective_density < 0) effective_density = 0; // Density cannot be negative

        double weight_taken = fraction * items[i].w;
        double value_gained = weight_taken * effective_density;

        total_value += value_gained;
        current_weight += weight_taken;

        printf("Item %d: Took %.2f%% | Effective Density: %.4f | Value Added: %.2f\n", 
               items[i].id, fraction * 100.0, effective_density, value_gained);

        // Advance time proportional to the weight taken
        current_time += weight_taken;
    }

    printf("\nMaximum Total Effective Value: %.4f\n", total_value);
    return 0;
}

/*
================================================================================
ALGORITHM LOGIC:
1. Read total item count, total knapsack capacity, and each item's base value, weight, and decay rate.
   Compute initial value density (v/w) for all items.
2. Sort all items in descending order based on their decay rates (lambda) using quicksort.
   This prioritizes items that degrade fastest to mitigate value loss over time.
3. Track current elapsed time and remaining knapsack capacity initialized to zero and W respectively.
   Iterate sequentially through the sorted item list.
4. Calculate the effective value density for the current item adjusted for elapsed time.
   Clamp negative density values to zero if decay drops below zero.
5. Determine the allowable fraction to fill remaining capacity and compute accumulated value.
   Advance total elapsed time by the amount of weight selected.
6. Output individual item fractions, effective densities, and total maximum effective value.
   Complexity: Time O(N log N) due to sorting, Space O(N) for item storage.
================================================================================
*/