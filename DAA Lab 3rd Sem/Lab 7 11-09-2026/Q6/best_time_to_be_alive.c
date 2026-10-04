/*
 * Q6: Best Time to be Alive
 * Finding peak overlapping life intervals using Event Sorting.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a single point event in time
typedef struct {
    int year;
    int type; // +1 indicates a birth, -1 indicates a death
} Event;

/*
 * Comparator function for qsort to order events chronologically.
 * 
 * Logic:
 * 1. Primary Sort: Sort events by year in ascending order.
 * 2. Tie-Breaking: If a birth and death occur in the same year, the problem statement 
 *    specifies that the death happened BEFORE the birth. Thus, Death (-1) must 
 *    precede Birth (+1) when years are equal.
 */
int compare_events(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    // Primary sort by year
    if (e1->year != e2->year) {
        return e1->year - e2->year;
    }
    
    // Secondary sort: -1 (death) comes before +1 (birth)
    return e1->type - e2->type;
}

int main() {
    int N;

    // Step 1: Read user input for the number of scientists
    printf("Enter number of prominent scientists (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    /*
     * Dynamic Memory Allocation:
     * Each scientist generates 2 point-events (Birth and Death), yielding 2 * N total events.
     * We use malloc instead of a variable-length array (VLA) to maintain standard C compatibility
     * and avoid stack size limits or compiler warnings ("expression must have a constant value").
     */
    Event *events = (Event *)malloc(2 * N * sizeof(Event));
    if (events == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 2: Populate the event array from user inputs
    printf("Enter birth and death year for each scientist (Birth Death):\n");
    for (int i = 0; i < N; i++) {
        int birth, death;
        printf("Scientist %d: ", i + 1);
        scanf("%d %d", &birth, &death);

        // Record Birth Event (+1 to running count of living scientists)
        events[2 * i].year = birth;
        events[2 * i].type = 1;

        // Record Death Event (-1 to running count of living scientists)
        events[2 * i + 1].year = death;
        events[2 * i + 1].type = -1;
    }

    // Step 3: Sort all events chronologically using qsort
    qsort(events, 2 * N, sizeof(Event), compare_events);

    /*
     * Step 4: Sweep-Line Algorithm Execution
     * Iterate through sorted time events to maintain a running tally of currently 
     * living scientists. Track the maximum count achieved and the starting year.
     */
    int max_scientists = 0;
    int current_scientists = 0;
    int best_year = -1;

    for (int i = 0; i < 2 * N; i++) {
        current_scientists += events[i].type;

        // Update peak population and record the year if a new maximum is found
        if (current_scientists > max_scientists) {
            max_scientists = current_scientists;
            best_year = events[i].year;
        }
    }

    // Step 5: Output the result
    printf("\n--- Analysis Result ---\n");
    printf("Max scientists alive simultaneously: %d\n", max_scientists);
    printf("Peak year / period start: Year %d\n", best_year);

    // Step 6: Free dynamically allocated heap memory to prevent memory leaks
    free(events);

    return 0;
}