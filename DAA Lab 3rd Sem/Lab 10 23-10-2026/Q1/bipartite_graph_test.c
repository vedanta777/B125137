#include <stdio.h>
#include <stdlib.h>

// Structure for DSU with parity
typedef struct {
    int *parent;
    int *rank;
    int *parity; // 0 if same parity as parent, 1 if opposite parity
} DSUWithParity;

DSUWithParity* createDSU(int n) {
    DSUWithParity *dsu = (DSUWithParity*)malloc(sizeof(DSUWithParity));
    dsu->parent = (int*)malloc((n + 1) * sizeof(int));
    dsu->rank = (int*)malloc((n + 1) * sizeof(int));
    dsu->parity = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
        dsu->parity[i] = 0;
    }
    return dsu;
}

// Find root with path compression and parity update
int find(DSUWithParity *dsu, int i, int *p_out) {
    if (dsu->parent[i] == i) {
        *p_out = 0;
        return i;
    }
    int p_from_parent;
    int root = find(dsu, dsu->parent[i], &p_from_parent);
    dsu->parity[i] ^= p_from_parent;
    dsu->parent[i] = root;
    *p_out = dsu->parity[i];
    return root;
}

int unionSets(DSUWithParity *dsu, int u, int v) {
    int p_u, p_v;
    int root_u = find(dsu, u, &p_u);
    int root_v = find(dsu, v, &p_v);

    if (root_u == root_v) {
        // If same root, check if they have the same parity (which means odd cycle)
        if (p_u == p_v) {
            return 0; // Violation: violates bipartiteness
        }
        return 1; // Valid edge, already in same component with correct parity
    }

    if (dsu->rank[root_u] < dsu->rank[root_v]) {
        int temp = root_u; root_u = root_v; root_v = temp;
        temp = u; u = v; v = temp;
    }

    dsu->parent[root_v] = root_u;
    dsu->parity[root_v] = p_u ^ p_v ^ 1; // Make them have different parities
    if (dsu->rank[root_u] == dsu->rank[root_v]) {
        dsu->rank[root_u]++;
    }
    return 1;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &V, &E) != 2) return 0;

    DSUWithParity *dsu = createDSU(V);

    printf("Enter edges (u v) online:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (unionSets(dsu, u, v)) {
            printf("Edge (%d, %d) added. Graph remains bipartite.\n", u, v);
        } else {
            printf("Edge (%d, %d) skipped. Violates bipartiteness (odd cycle detected).\n", u, v);
        }
    }

    free(dsu->parent);
    free(dsu->rank);
    free(dsu->parity);
    free(dsu);
    return 0;
}

/*
 * ALGORITHM SUMMARY:
 * 1. Maintain vertex connectivity and distance parity from set representatives using an extended Disjoint Set Union (DSU) structure.
 * 2. For each incoming edge (u, v), find the roots of both vertices along with their cumulative parity relative to their roots.
 * 3. If both vertices share the same root and have identical parities, adding the edge creates an odd-length cycle; hence, reject it.
 * 4. If they share the same root with opposite parities, the edge is redundant but consistent with bipartiteness; accept it without merging.
 * 5. If they belong to different roots, union the two sets and adjust the relative parity of the new root to maintain 2-colorability.
 * 6. The time complexity is O(alpha(V)) per edge query using path compression, where alpha is the Inverse Ackermann function.
 */