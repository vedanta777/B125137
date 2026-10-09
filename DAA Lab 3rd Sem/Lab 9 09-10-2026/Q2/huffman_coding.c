#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman Tree
typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

// Structure to store canonical code entries
typedef struct {
    char ch;
    int length;
    char code[64];
} CanonicalCode;

// Min-Heap structure for building Huffman tree
typedef struct {
    int size;
    Node *array[256];
} MinHeap;

Node* createNode(char ch, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

Node* extractMin(MinHeap* heap) {
    Node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

void insertMinHeap(MinHeap* heap, Node* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Extract bit lengths of standard Huffman codes
void getCodeLengths(Node* root, int depth, int lengths[]) {
    if (!root) return;
    if (!root->left && !root->right) {
        lengths[(unsigned char)root->ch] = depth;
        return;
    }
    getCodeLengths(root->left, depth + 1, lengths);
    getCodeLengths(root->right, depth + 1, lengths);
}

// Sorting comparator for Canonical Codebook:
// Order primary by code length ascending, secondary by character value ascending
int compareCanonical(const void* a, const void* b) {
    CanonicalCode* c1 = (CanonicalCode*)a;
    CanonicalCode* c2 = (CanonicalCode*)b;
    if (c1->length != c2->length)
        return c1->length - c2->length;
    return c1->ch - c2->ch;
}

int main() {
    int n;
    printf("Enter number of distinct symbols: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    MinHeap heap = {0};
    char symbols[n];
    int frequencies[n];

    for (int i = 0; i < n; i++) {
        printf("Enter symbol %d (char) and frequency: ", i + 1);
        scanf(" %c %d", &symbols[i], &frequencies[i]);
        insertMinHeap(&heap, createNode(symbols[i], frequencies[i]));
    }

    // Build standard Huffman Tree using greedy choice
    while (heap.size > 1) {
        Node* left = extractMin(&heap);
        Node* right = extractMin(&heap);
        Node* parent = createNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        insertMinHeap(&heap, parent);
    }

    int lengths[256] = {0};
    getCodeLengths(heap.array[0], 0, lengths);

    // Prepare entries for canonical conversion
    CanonicalCode canonical[n];
    for (int i = 0; i < n; i++) {
        canonical[i].ch = symbols[i];
        canonical[i].length = lengths[(unsigned char)symbols[i]];
    }

    // Sort entries by length and character order
    qsort(canonical, n, sizeof(CanonicalCode), compareCanonical);

    // Construct Canonical Codes
    int current_code = 0;
    int current_len = canonical[0].length;

    for (int i = 0; i < n; i++) {
        if (canonical[i].length > current_len) {
            current_code <<= (canonical[i].length - current_len);
            current_len = canonical[i].length;
        }

        // Convert integer code to binary string
        for (int bit = current_len - 1; bit >= 0; bit--) {
            canonical[i].code[current_len - 1 - bit] = ((current_code >> bit) & 1) ? '1' : '0';
        }
        canonical[i].code[current_len] = '\0';
        current_code++;
    }

    // Print final Canonical Huffman Codebook
    printf("\n--- Canonical Huffman Codebook ---\n");
    printf("Symbol\tLength\tCode\n");
    for (int i = 0; i < n; i++) {
        printf("  %c\t  %d\t%s\n", canonical[i].ch, canonical[i].length, canonical[i].code);
    }

    return 0;
}

/*
================================================================================
ALGORITHM LOGIC:
1. Accept distinct symbol characters and frequency counts from the user.
   Insert each symbol as an individual tree node into a priority min-heap.
2. Repeatedly extract two smallest frequency nodes from the min-heap to form a parent node.
   Reinsert merged parent nodes until only one root node remains.
3. Perform DFS on the Huffman tree to extract optimal code bit-lengths for every symbol.
   Store these code lengths alongside their corresponding characters.
4. Sort symbols primary by code length ascending and secondary by alphabetical character order.
   This establishes canonical ordering rules.
5. Compute canonical binary strings by bit-shifting integer values when lengths increase.
   Increment numeric codes sequentially for items sharing identical lengths.
6. Print the formatted canonical codebook showing symbols, bit-lengths, and binary codes.
   Complexity: Time O(N log N), Space O(N).
================================================================================
*/