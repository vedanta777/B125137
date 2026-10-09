#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure representing nodes in ordered sequence merge tree
typedef struct Node {
    int weight;
    int is_leaf;
    int index;
    struct Node *left, *right;
} Node;

Node* createLeafNode(int weight, int idx) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->weight = weight;
    node->is_leaf = 1;
    node->index = idx;
    node->left = node->right = NULL;
    return node;
}

Node* createInternalNode(Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->weight = left->weight + right->weight;
    node->is_leaf = 0;
    node->index = -1;
    node->left = left;
    node->right = right;
    return node;
}

// Compute total weighted depth sum: sum(w_i * depth_i)
int calculateWeightedPathLength(Node* root, int depth) {
    if (!root) return 0;
    if (root->is_leaf) {
        return root->weight * depth;
    }
    return calculateWeightedPathLength(root->left, depth + 1) + 
           calculateWeightedPathLength(root->right, depth + 1);
}

int main() {
    int n;
    printf("Enter number of ordered sequence weights: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    Node* nodes[200];
    printf("Enter ordered sequence weights (w1, w2, ..., wn): ");
    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        nodes[i] = createLeafNode(w, i);
    }

    int current_size = n;

    // Simulation of Hu-Tucker Combination Phase (Min-Cost Adjacent/Compatible Merges)
    while (current_size > 1) {
        int min_sum = INT_MAX;
        int merge_i = -1, merge_j = -1;

        // Search for minimum weight sum compatible pair (strictly adjacent pairs maintain alphabetic order)
        for (int i = 0; i < current_size - 1; i++) {
            int sum = nodes[i]->weight + nodes[i + 1]->weight;
            if (sum < min_sum) {
                min_sum = sum;
                merge_i = i;
                merge_j = i + 1;
            }
        }

        // Merge chosen optimal adjacent pair
        Node* parent = createInternalNode(nodes[merge_i], nodes[merge_j]);
        nodes[merge_i] = parent;

        // Shift remaining nodes left to consolidate working list
        for (int k = merge_j; k < current_size - 1; k++) {
            nodes[k] = nodes[k + 1];
        }
        current_size--;
    }

    int total_cost = calculateWeightedPathLength(nodes[0], 0);

    printf("\n--- Hu-Tucker Simulation Complete ---\n");
    printf("Minimum Weighted Path Length sum(w_i * depth_i): %d\n", total_cost);

    return 0;
}

/*
================================================================================
ALGORITHM LOGIC:
1. Accept ordered sequence weights w1, w2, ..., wn maintaining strict in-order indices.
   Create leaf nodes for each weight and store them in an ordered working array.
2. Search through current working sequence for adjacent node pairs yielding minimum combined weight sum.
   Strict adjacency guarantees preservation of alphabetic sequence order constraints.
3. Merge identified optimal adjacent pair into a single internal parent node with combined weight sum.
   Assign left and right child pointers to preserve spatial structure.
4. Shift remaining working array elements leftward to overwrite merged slot and decrement active node count.
   Repeat scanning and merging steps until only one root node remains in working list.
5. Recursively traverse generated binary tree structure from root node down to leaf nodes.
   Accumulate product sum of leaf weight multiplied by leaf depth level.
6. Print total weighted path length sum representing minimum alphabetic binary search cost.
   Complexity: Time O(N^2) for array simulation, Space O(N).
================================================================================
*/