#include <stdio.h>

void prim(int graph[10][10], int vertices) {
    int selected[10] = {0};  // Track selected vertices
    int edge_count = 0;
    int INF = 9999;          // A large number representing infinity

    selected[0] = 1;         // Start from vertex 0

    printf("Edge \tWeight\n");

    while (edge_count < vertices - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < vertices; i++) {
            if (selected[i]) {
                for (int j = 0; j < vertices; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d \t%d\n", x, y, graph[x][y]);
        selected[y] = 1;
        edge_count++;
    }
}

int main() {
    int vertices;
    int graph[10][10];

    printf("Enter number of vertices (max 10): ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, vertices);

    return 0;
}

