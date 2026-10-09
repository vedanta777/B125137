#include <stdio.h>
#include <stdlib.h>

// Min-Heap implementation to continuously combine two shortest sticks
typedef struct {
    int data[1000];
    int size;
} MinHeap;

void pushHeap(MinHeap *hp, int val) {
    hp->data[hp->size] = val;
    int i = hp->size++;
    while (i > 0 && hp->data[(i - 1) / 2] > hp->data[i]) {
        int temp = hp->data[i];
        hp->data[i] = hp->data[(i - 1) / 2];
        hp->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int popHeap(MinHeap *hp) {
    int top = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, min_idx = left;
        if (right < hp->size && hp->data[right] < hp->data[left])
            min_idx = right;
        if (hp->data[i] <= hp->data[min_idx]) break;
        int temp = hp->data[i];
        hp->data[i] = hp->data[min_idx];
        hp->data[min_idx] = temp;
        i = min_idx;
    }
    return top;
}

int main() {
    int n;
    printf("Enter total number of sticks: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    MinHeap hp = { .size = 0 };
    printf("Enter stick lengths: ");
    for (int i = 0; i < n; i++) {
        int len;
        scanf("%d", &len);
        pushHeap(&hp, len);
    }

    if (n == 1) {
        printf("\nMinimum Cost to Connect Sticks: 0\n");
        return 0;
    }

    int total_cost = 0;

    // Repeatedly combine two shortest sticks until 1 stick remains
    while (hp.size > 1) {
        int stick1 = popHeap(&hp);
        int stick2 = popHeap(&hp);

        int cost = stick1 + stick2;
        total_cost += cost;

        // Insert combined stick back into min-heap
        pushHeap(&hp, cost);
    }

    printf("\nMinimum Total Cost to Connect All Sticks: %d\n", total_cost);
    return 0;
}

/*
================================================================================
ALGORITHM LOGIC:
1. Accept total count of stick lengths and read individual integer length values from user.
   Push every stick length into a priority min-heap structure.
2. Check edge case where stick count equals one.
   If true, cost is zero as no connections are required.
3. Extract top two smallest stick lengths (stick1 and stick2) from min-heap.
   This represents greedy choice of combining cheapest available pair first.
4. Calculate combination cost (stick1 + stick2) and add value to cumulative cost counter.
   Push combined stick length back into min-heap.
5. Repeat extraction, combination, and insertion steps while min-heap size remains greater than 1.
   Loop completes when all sticks merge into one single stick.
6. Output accumulated minimum total cost required to connect all sticks together.
   Complexity: Time O(N log N), Space O(N).
================================================================================
*/