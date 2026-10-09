#include <stdio.h>
#include <stdlib.h>

// Structure representing a fuel station
typedef struct {
    int distance;
    int fuel;
} Station;

// Max-Heap implementation to dynamically select reachable station offering maximum fuel
typedef struct {
    int data[1000];
    int size;
} MaxHeap;

void pushHeap(MaxHeap *hp, int val) {
    hp->data[hp->size] = val;
    int i = hp->size++;
    while (i > 0 && hp->data[(i - 1) / 2] < hp->data[i]) {
        int temp = hp->data[i];
        hp->data[i] = hp->data[(i - 1) / 2];
        hp->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int popHeap(MaxHeap *hp) {
    if (hp->size <= 0) return 0;
    int top = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, max_idx = left;
        if (right < hp->size && hp->data[right] > hp->data[left])
            max_idx = right;
        if (hp->data[i] >= hp->data[max_idx]) break;
        int temp = hp->data[i];
        hp->data[i] = hp->data[max_idx];
        hp->data[max_idx] = temp;
        i = max_idx;
    }
    return top;
}

// Sort fuel stations by distance from origin
int compareStations(const void *a, const void *b) {
    return ((Station*)a)->distance - ((Station*)b)->distance;
}

int main() {
    int target, initial_fuel, n;

    printf("Enter Target Distance (D): ");
    if (scanf("%d", &target) != 1) return 0;

    printf("Enter Starting Fuel (F): ");
    if (scanf("%d", &initial_fuel) != 1) return 0;

    printf("Enter number of refueling stations: ");
    if (scanf("%d", &n) != 1) return 0;

    Station stations[n];
    for (int i = 0; i < n; i++) {
        printf("Enter station %d distance and available fuel: ", i + 1);
        scanf("%d %d", &stations[i].distance, &stations[i].fuel);
    }

    // Sort stations by position along the path
    qsort(stations, n, sizeof(Station), compareStations);

    MaxHeap hp = { .size = 0 };
    int stops = 0;
    int curr_fuel = initial_fuel;
    int idx = 0;

    // Simulate journey to destination
    while (curr_fuel < target) {
        // Push all reachable stations into Max-Heap
        while (idx < n && stations[idx].distance <= curr_fuel) {
            pushHeap(&hp, stations[idx].fuel);
            idx++;
        }

        // If heap is empty, vehicle cannot move further
        if (hp.size == 0) {
            printf("\nTarget unreachable! Maximum distance reached: %d\n", curr_fuel);
            return 0;
        }

        // Reverse Greedy choice: Pop station offering max fuel
        curr_fuel += popHeap(&hp);
        stops++;
    }

    printf("\nMinimum Refueling Stops Required: %d\n", stops);
    return 0;
}

/*
================================================================================
ALGORITHM LOGIC:
1. Accept target distance D, initial fuel capacity F, station count, and station distances/fuel amounts.
   Sort stations in ascending order based on distance from origin.
2. Maintain a max-heap to store available fuel from reachable stations passed so far.
   Initialize current reachable distance to starting fuel F and stop count to zero.
3. Push fuel amounts of all stations within current reachable distance into the max-heap.
   Advance station index accordingly as vehicle range expands.
4. If current range falls short of target and heap is empty, terminate as target is unreachable.
   Otherwise, greedily extract maximum fuel from reachable stations in max-heap.
5. Add extracted fuel to current distance range and increment total stop counter by one.
   Repeat process until target distance is reached or path becomes blocked.
6. Output the minimum refueling stops required to reach target distance safely.
   Complexity: Time O(N log N), Space O(N).
================================================================================
*/