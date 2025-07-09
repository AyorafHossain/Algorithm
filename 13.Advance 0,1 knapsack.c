#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int Wmax, int weight[], int profit[], int n, int knap[101][101]) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= Wmax; j++) {
            if (i == 0 || j == 0) {
                knap[i][j] = 0;
            } else if (weight[i - 1] <= j) {
                knap[i][j] = max(knap[i - 1][j], profit[i - 1] + knap[i - 1][j - weight[i - 1]]);
            } else {
                knap[i][j] = knap[i - 1][j];
            }
        }
    }
    return knap[n][Wmax];
}

void printSelectedItems(int n, int Wmax, int weight[], int knap[101][101]) {
    int i = n, j = Wmax;
    printf("Items included (0-based index): ");
    while (i > 0 && j > 0) {
        if (knap[i][j] != knap[i - 1][j]) {
            printf("%d ", i - 1);
            j = j - weight[i - 1];
        }
        i--;
    }
    printf("\n");
}

int main() {
    int i, n, Wmax;
    int weight[100], profit[100];
    int knap[101][101];  // DP table

    printf("Enter the no of items: ");
    scanf("%d", &n);

    printf("Enter maximum weight: ");
    scanf("%d", &Wmax);

    printf("Enter weights: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter profits: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    int max_profit = knapsack(Wmax, weight, profit, n, knap);
    printf("Maximum profit: %d\n", max_profit);
    printSelectedItems(n, Wmax, weight, knap);

    return 0;
}
