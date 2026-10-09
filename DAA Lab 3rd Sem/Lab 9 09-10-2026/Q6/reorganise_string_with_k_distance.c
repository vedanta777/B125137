#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

typedef struct {
    CharFreq data[256];
    int size;
} MaxHeap;

void pushHeap(MaxHeap *hp, CharFreq val) {
    hp->data[hp->size] = val;
    int i = hp->size++;
    while (i > 0 && hp->data[(i - 1) / 2].freq < hp->data[i].freq) {
        CharFreq temp = hp->data[i];
        hp->data[i] = hp->data[(i - 1) / 2];
        hp->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

CharFreq popHeap(MaxHeap *hp) {
    CharFreq top = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1, right = 2 * i + 2, max_idx = left;
        if (right < hp->size && hp->data[right].freq > hp->data[left].freq)
            max_idx = right;
        if (hp->data[i].freq >= hp->data[max_idx].freq) break;
        CharFreq temp = hp->data[i];
        hp->data[i] = hp->data[max_idx];
        hp->data[max_idx] = temp;
        i = max_idx;
    }
    return top;
}

int main() {
    char str[1000];
    int k;

    printf("Enter input string S: ");
    if (scanf("%s", str) != 1) return 0;

    printf("Enter distance separation K: ");
    if (scanf("%d", &k) != 1) return 0;

    int len = strlen(str);
    if (k <= 1) {
        printf("Reorganized String: %s\n", str);
        return 0;
    }

    int freq[256] = {0};
    for (int i = 0; i < len; i++) {
        freq[(unsigned char)str[i]]++;
    }

    MaxHeap hp = { .size = 0 };
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            CharFreq cf = { .ch = (char)i, .freq = freq[i] };
            pushHeap(&hp, cf);
        }
    }

    char result[len + 1];
    result[len] = '\0';
    int write_idx = 0;

    // Queue structure for cooling down elements until K distance requirement met
    CharFreq waitQueue[len];
    int qFront = 0, qRear = 0;

    while (hp.size > 0) {
        CharFreq current = popHeap(&hp);
        result[write_idx++] = current.ch;
        current.freq--;

        // Place character into cooling queue
        waitQueue[qRear++] = current;

        // Release character back to Max-Heap if distance K is reached
        if (qRear - qFront >= k) {
            CharFreq frontChar = waitQueue[qFront++];
            if (frontChar.freq > 0) {
                pushHeap(&hp, frontChar);
            }
        }
    }

    // Validation: If result length equals input string length, valid string formed
    if (write_idx == len) {
        printf("\nReorganized String: %s\n", result);
    } else {
        printf("\nImpossible to reorganize string with distance K=%d (Result: \"\")\n", k);
    }

    return 0;
}

/*
================================================================================
ALGORITHM LOGIC:
1. Accept input string S and separation integer K from user input.
   Count character frequencies and populate non-zero frequencies into a max-heap.
2. Initialize cooling queue buffer to temporarily hold characters until K distance constraint expires.
   Initialize result writing pointer to build output string sequentially.
3. Extract character with highest remaining frequency from max-heap and append to result string.
   Decrement frequency count and enqueue extracted element into wait queue.
4. Check if wait queue length reaches separation distance K.
   If distance condition met, dequeue oldest element and re-insert into max-heap if frequency remains positive.
5. Repeat extraction, queueing, and re-insertion steps until max-heap contains no further characters.
   Loop terminates when heap empties or valid placements exhaust.
6. Verify output string length matches original input string length.
   Output reorganized string if valid; otherwise return empty string signaling impossibility.
   Complexity: Time O(N log A) where A is alphabet size, Space O(N + A).
================================================================================
*/