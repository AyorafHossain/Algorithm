#include <stdio.h>
#include <stdlib.h>

#define MAX 30

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

int parent[MAX];

// Find parent of a node
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Union of two sets
int union_set(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    struct Edge edge_list[MAX], result[MAX];
    int n, e, i, j, u, v, total_cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edge_list[i].u, &edge_list[i].v, &edge_list[i].weight);
    }

    // Sort edges by weight (Bubble sort for simplicity)
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edge_list[j].weight > edge_list[j + 1].weight) {
                struct Edge temp = edge_list[j];
                edge_list[j] = edge_list[j + 1];
                edge_list[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0, j = 0; i < e && j < n - 1; i++) {
        u = find(edge_list[i].u);
        v = find(edge_list[i].v);

        if (union_set(u, v)) {
            result[j++] = edge_list[i];
            total_cost += edge_list[i].weight;
        }
    }

    for (i = 0; i < n - 1; i++) {
        printf("%d - %d \t%d\n", result[i].u, result[i].v, result[i].weight);
    }

    printf("Total cost of MST = %d\n", total_cost);

    return 0;
}

