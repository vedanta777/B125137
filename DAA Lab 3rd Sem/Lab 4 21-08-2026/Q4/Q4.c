#include <stdio.h>
#include <stdlib.h>

#define MAX_PERSONS 100
#define MAX_EVENTS (2 * MAX_PERSONS)

typedef struct {
    int time;
    int type; // +1 for Entry, -1 for Exit
} Event;

// Comparator function for qsort
int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    
    // Sort primarily by time in ascending order
    if (e1->time != e2->time) {
        return e1->time - e2->time;
    }
    
    // If times are equal, process Exits (-1) before Entries (+1)
    return e1->type - e2->type; 
}

void findPeakAttendance(int entry[], int exit[], int n) {
    // Static event array with maximum capacity (no dynamic allocation)
    Event events[MAX_EVENTS];

    // Populate events array
    for (int i = 0; i < n; i++) {
        events[2 * i].time = entry[i];
        events[2 * i].type = 1;  // Arrival

        events[2 * i + 1].time = exit[i];
        events[2 * i + 1].type = -1; // Departure
    }

    int totalEvents = 2 * n;

    // Sort all events chronologically in O(n log n)
    qsort(events, totalEvents, sizeof(Event), compareEvents);

    int maxGuests = 0;
    int currentGuests = 0;
    int peakTime = -1;

    // Linear sweep through sorted events
    for (int i = 0; i < totalEvents; i++) {
        currentGuests += events[i].type;

        if (currentGuests > maxGuests) {
            maxGuests = currentGuests;
            peakTime = events[i].time;
        }
    }

    printf("Peak Attendance: %d people simultaneously present at time = %d\n", maxGuests, peakTime);
}

int main() {
    int entry[] = {1, 2, 10, 5, 8};
    int exit[]  = {4, 5, 12, 9, 11};
    int n = sizeof(entry) / sizeof(entry[0]);

    if (n > MAX_PERSONS) {
        printf("Error: Number of persons exceeds static array capacity.\n");
        return 1;
    }

    findPeakAttendance(entry, exit, n);

    return 0;
}