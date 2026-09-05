#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l;
    int r;
} Interval;

typedef struct {
    int coord;
    int type; // +1 for Left endpoint, -1 for Right endpoint
} EventPoint;

int compareEventPoints(const void* a, const void* b) {
    EventPoint* e1 = (EventPoint*)a;
    EventPoint* e2 = (EventPoint*)b;
    if (e1->coord != e2->coord) {
        return e1->coord - e2->coord;
    }
    // Left endpoint (+1) processed before Right endpoint (-1) since endpoints are inclusive[cite: 1]
    return e2->type - e1->type; 
}

void findPointWithMaxOverlap(Interval intervals[], int n) {
    EventPoint* events = (EventPoint*)malloc(2 * n * sizeof(EventPoint));

    for (int i = 0; i < n; i++) {
        events[2 * i]     = (EventPoint){intervals[i].l, 1};
        events[2 * i + 1] = (EventPoint){intervals[i].r, -1};
    }

    // Sort endpoints in O(n log n)
    qsort(events, 2 * n, sizeof(EventPoint), compareEventPoints);

    int maxOverlap = 0, currentOverlap = 0;
    int bestPoint = -1;

    for (int i = 0; i < 2 * n; i++) {
        currentOverlap += events[i].type;
        if (currentOverlap > maxOverlap) {
            maxOverlap = currentOverlap;
            bestPoint = events[i].coord;
        }
    }

    printf("Point p = %d lies in the maximum number of intervals (%d intervals).\n", bestPoint, maxOverlap);

    free(events);
}

int main() {
    // Example from lab sheet: S = {(10,40), (20,60), (50,90), (15,70)}[cite: 1]
    Interval intervals[] = {{10, 40}, {20, 60}, {50, 90}, {15, 70}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    findPointWithMaxOverlap(intervals, n);

    return 0;
}