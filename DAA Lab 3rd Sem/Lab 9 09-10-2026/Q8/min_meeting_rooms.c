#include <stdio.h>
#include <stdlib.h>

// Sort start times ascending
int compareInts(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("Enter total number of meetings: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int start_times[n];
    int end_times[n];

    for (int i = 0; i < n; i++) {
        printf("Enter start and end time for meeting %d: ", i + 1);
        scanf("%d %d", &start_times[i], &end_times[i]);
    }

    // Separate and sort start and end time arrays independently
    qsort(start_times, n, sizeof(int), compareInts);
    qsort(end_times, n, sizeof(int), compareInts);

    int rooms_needed = 0;
    int max_rooms = 0;
    int start_ptr = 0;
    int end_ptr = 0;

    // Two-pointer chronological timeline sweep
    while (start_ptr < n) {
        if (start_times[start_ptr] < end_times[end_ptr]) {
            // Meeting started before earliest end time -> allocate new room
            rooms_needed++;
            if (rooms_needed > max_rooms) {
                max_rooms = rooms_needed;
            }
            start_ptr++;
        } else {
            // Meeting ended -> free up a room
            rooms_needed--;
            end_ptr++;
        }
    }

    printf("\nMinimum Conference Rooms Required: %d\n", max_rooms);
    return 0;
}

/*
================================================================================
ALGORITHM LOGIC:
1. Accept total meeting count and paired start/end interval times from user input.
   Extract start times and end times into two separate integer arrays.
2. Sort start time array and end time array independently in ascending order.
   Sorting enables chronological timeline simulation without tracking individual pairs.
3. Initialize two pointers (start_ptr, end_ptr) and track active meeting room counts.
   Set max_rooms to track peak concurrent room requirements.
4. Compare current start time against current end time at pointers.
   If start time is earlier, increment required room count and advance start_ptr.
5. If end time is less than or equal to start time, decrement room count and advance end_ptr.
   Update maximum room count variable whenever active room count exceeds historical maximum.
6. Print peak room count representing minimum conference rooms required.
   Complexity: Time O(N log N) due to sorting, Space O(N).
================================================================================
*/