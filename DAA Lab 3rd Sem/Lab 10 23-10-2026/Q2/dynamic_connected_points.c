#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *parent;
    int *rank;
    int count;
} DSUGrid;

DSUGrid* createGridDSU(int size) {
    DSUGrid *dsu = (DSUGrid*)malloc(sizeof(DSUGrid));
    dsu->parent = (int*)malloc(size * sizeof(int));
    dsu->rank = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        dsu->parent[i] = -1; // -1 indicates water
        dsu->rank[i] = 0;
    }
    dsu->count = 0;
    return dsu;
}

int find(DSUGrid *dsu, int i) {
    if (dsu->parent[i] == i)
        return i;
    return dsu->parent[i] = find(dsu, dsu->parent[i]);
}

void unionSets(DSUGrid *dsu, int i, int j) {
    int root_i = find(dsu, i);
    int root_j = find(dsu, j);
    if (root_i != root_j) {
        if (dsu->rank[root_i] < dsu->rank[root_j]) {
            dsu->parent[root_i] = root_j;
        } else if (dsu->rank[root_i] > dsu->rank[root_j]) {
            dsu->parent[root_j] = root_i;
        } else {
            dsu->parent[root_j] = root_i;
            dsu->rank[root_i]++;
        }
        dsu->count--;
    }
}

int main() {
    int R, C, K;
    printf("Enter grid rows (R), columns (C), and number of land operations (K): ");
    if (scanf("%d %d %d", &R, &C, &K) != 3) return 0;

    DSUGrid *dsu = createGridDSU(R * C);
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    printf("Enter the land cell coordinates (r c) 0-indexed:\n");
    for (int op = 0; op < K; op++) {
        int r, c;
        scanf("%d %d", &r, &c);
        int idx = r * C + c;

        if (dsu->parent[idx] != -1) {
            printf("Operation %d: Cell (%d, %d) is already land. Total islands: %d\n", op + 1, r, c, dsu->count);
            continue;
        }

        dsu->parent[idx] = idx;
        dsu->count++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                int n_idx = nr * C + nc;
                if (dsu->parent[n_idx] != -1) {
                    unionSets(dsu, idx, n_idx);
                }
            }
        }
        printf("Operation %d: Added land at (%d, %d). Current islands: %d\n", op + 1, r, c, dsu->count);
    }

    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
    return 0;
}

/*
 * ALGORITHM SUMMARY:
 * 1. Initialize an R x C grid representation using a Disjoint Set Union structure where all cells start marked as water (-1).
 * 2. For each land addition query at (r, c), map 2D coordinates to 1D index using coordinate flattening (r * C + c).
 * 3. If the cell is already land, skip merging and output the current island count; otherwise, activate the cell and increment island count.
 * 4. Check all four 4-directional adjacent neighbors to see if they are active land cells.
 * 5. If a neighbor is active, union its set with the current cell's set and decrement the total island count by one.
 * 6. Output the updated island count after each operation with near-constant amortized time complexity per query.
 */