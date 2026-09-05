#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Interval;

int compareIntervals(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    return i1->x - i2->x;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// O(n log n) time complexity
void mergeIntervals(Interval intervals[], int n) {
    if (n <= 0) return;

    // Step 1: Sort by start time x_i
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    Interval* merged = (Interval*)malloc(n * sizeof(Interval));
    int count = 0;

    int curX = intervals[0].x;
    int curY = intervals[0].y;

    // Step 2: Merge overlapping intervals
    for (int i = 1; i < n; i++) {
        if (intervals[i].x <= curY) {
            curY = max(curY, intervals[i].y);
        } else {
            merged[count++] = (Interval){curX, curY};
            curX = intervals[i].x;
            curY = intervals[i].y;
        }
    }
    merged[count++] = (Interval){curX, curY};

    printf("Merged Intervals: { ");
    for (int i = 0; i < count; i++) {
        printf("(%d, %d) ", merged[i].x, merged[i].y);
    }
    printf("}\n");

    free(merged);
}

int main() {
    // Example from lab sheet: {(1,3), (2,6), (8,10), (7,18)}[cite: 1]
    Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {7, 18}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    mergeIntervals(intervals, n);

    return 0;
}