#include <stdio.h>
#include <stdlib.h>

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

int minVal(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    MaxHeap hp = { .size = 0 };
    int current_min = 2147483647;

    printf("Enter positive array elements: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        // Pre-process: Double all odd numbers to reduce problem strictly to division operations
        if (val % 2 != 0) {
            val *= 2;
        }

        pushHeap(&hp, val);
        current_min = minVal(current_min, val);
    }

    int min_deviation = hp.data[0] - current_min;

    // Repeatedly halve the maximum even element
    while (hp.data[0] % 2 == 0) {
        int max_val = popHeap(&hp);
        int new_val = max_val / 2;

        pushHeap(&hp, new_val);
        current_min = minVal(current_min, new_val);

        int current_deviation = hp.data[0] - current_min;
        if (current_deviation < min_deviation) {
            min_deviation = current_deviation;
        }
    }

    printf("\nMinimum Possible Deviation: %d\n", min_deviation);
    return 0;
}

/*
================================================================================
ALGORITHM LOGIC:
1. Accept array size and element values from user input.
   Pre-process odd elements by multiplying by 2 to convert all elements into maximum possible values.
2. Insert modified elements into a max-heap while tracking global minimum value.
   Compute initial array deviation as max_heap_top minus global minimum.
3. Greedily target current maximum value sitting at max-heap top.
   Check if top element is even (can be divided by 2).
4. Pop top maximum element, halve its value, and re-insert back into max-heap.
   Update global minimum value if newly halved element becomes new minimum.
5. Re-calculate current deviation (heap_top - current_min) and update global minimum deviation.
   Repeat halving loop until top element becomes odd and cannot be halved further.
6. Output final minimum achieved deviation after exhausting allowable reductions.
   Complexity: Time O(N log N log M) where M is max element value, Space O(N).
================================================================================
*/