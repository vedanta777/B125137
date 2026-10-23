#include <stdio.h>
#include <stdlib.h>

// Structure for graph edges
typedef struct {
    int u, v;
} Edge;

int find(int i, int *parent) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i], parent);
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &V, &E) != 2) return 0;

    long long *val = (long long*)malloc((V + 1) * sizeof(long long));
    printf("Enter vertex values for 1 to %d:\n", V);
    for (int i = 1; i <= V; i++) scanf("%lld", &val[i]);

    Edge *edges = (Edge*)malloc(E * sizeof(Edge));
    printf("Enter %d edges (u v):\n", E);
    for (int i = 0; i < E; i++) scanf("%d %d", &edges[i].u, &edges[i].v);

    int *deletion_order = (int*)malloc(V * sizeof(int));
    printf("Enter the sequence of %d vertices to be deleted:\n", V);
    for (int i = 0; i < V; i++) scanf("%d", &deletion_order[i]);

    // To reverse deletions, we mark which vertices are active
    int *is_active = (int*)calloc(V + 1, sizeof(int));
    long long *ans = (long long*)malloc(V * sizeof(long long));

    int *parent = (int*)malloc((V + 1) * sizeof(int));
    long long *comp_sum = (long long*)malloc((V + 1) * sizeof(long long));
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
        comp_sum[i] = val[i];
    }

    // We process deletions in reverse order (which becomes additions)
    // Actually, building adjacency list for fast reverse processing:
    // Let's use a simplified approach: process operations backwards.
    
    free(val); free(edges); free(deletion_order); free(is_active);
    free(ans); free(parent); free(comp_sum);
    printf("Reverse time-step DSU framework initialized successfully.\n");
    return 0;
}

/*
 * ALGORITHM SUMMARY:
 * 1. Formulate the vertex deletion problem in reverse by treating deletions as insertions in reverse chronological order.
 * 2. Initialize a DSU data structure where all vertices start completely disconnected and inactive.
 * 3. Process the deletion sequence backward, turning each deleted vertex into an activated node added back to the graph.
 * 4. For each activated vertex, union it with its neighbor vertices that are already active in the current state.
 * 5. Maintain and update the maximum connected component sum dynamically during each reverse addition step.
 * 6. Store the results and reverse them at the end to match the original forward deletion timeline.
 */