#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int parent;
    int size;
    long long weight;
} Element;

typedef struct {
    Element *elems;
    int *head;
    int *next;
    int max_k;
    long long global_max_weight;
} ConstrainedDSU;

// Global tracking of valid component weights could be complex, 
// so we can maintain max weight among components of size <= K by scanning or maintaining a simple structure.

int main() {
    int V, E, K;
    printf("Enter number of vertices (V), edges (E), and size constraint (K): ");
    if (scanf("%d %d %d", &V, &E, &K) != 3) return 0;

    long long *w = (long long*)malloc((V + 1) * sizeof(long long));
    printf("Enter weights for vertices 1 to %d:\n", V);
    for (int i = 1; i <= V; i++) {
        scanf("%lld", &w[i]);
    }

    int *parent = (int*)malloc((V + 1) * sizeof(int));
    int *size = (int*)malloc((V + 1) * sizeof(int));
    long long *comp_weight = (long long*)malloc((V + 1) * sizeof(long long));

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
        size[i] = 1;
        comp_weight[i] = w[i];
    }

    // Function to find root with path compression
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    long long current_max = 0;
    for (int i = 1; i <= V; i++) {
        if (size[i] <= K && comp_weight[i] > current_max) {
            current_max = comp_weight[i];
        }
    }

    printf("Enter edges (u v) sequentially:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            if (size[root_u] + size[root_v] <= K) {
                parent[root_v] = root_u;
                size[root_u] += size[root_v];
                comp_weight[root_u] += comp_weight[root_v];
                if (comp_weight[root_u] > current_max) {
                    current_max = comp_weight[root_u];
                }
            } else {
                // If combined size exceeds K, we can still union them for connectivity, 
                // but the new component won't contribute to valid components <= K.
                parent[root_v] = root_u;
                size[root_u] += size[root_v];
                comp_weight[root_u] += comp_weight[root_v];
            }
        }
        printf("After edge %d-%d, max weight of component with size <= %d is: %lld\n", u, v, K, current_max);
    }

    free(w); free(parent); free(size); free(comp_weight);
    return 0;
}

/*
 * ALGORITHM SUMMARY:
 * 1. Initialize each vertex as an independent component with its individual weight and a size of 1.
 * 2. Track a global maximum weight variable for all connected components whose size is less than or equal to K.
 * 3. As edges arrive sequentially, locate the roots of the endpoints using DSU with path compression.
 * 4. When merging two components, update the combined component's total vertex weight and size.
 * 5. If the merged component's size does not exceed K, compare its total weight with the current global maximum and update if larger.
 * 6. Report the maximum valid component weight efficiently after each edge addition step.
 */