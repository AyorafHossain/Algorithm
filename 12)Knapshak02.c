#include <stdio.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack using Dynamic Programming
void knapsack(int W, int wt[], int val[], int n) {
    int i, j;
    int knap[n + 1][W + 1];

    // Build the DP table using bottom-up approach
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                knap[i][j] = 0;  // Base case: No items or weight is 0
            else if (wt[i - 1] <= j)
                knap[i][j] = max(val[i - 1] + knap[i - 1][j - wt[i - 1]], knap[i - 1][j]);
            else
                knap[i][j] = knap[i - 1][j];
        }
    }

    // Maximum profit stored in knap[n][W]
    int maxProfit = knap[n][W];
    printf("Maximum Profit: %d\n", maxProfit);

    // Finding which items are included
    printf("Selected Items (weight, value):\n");
    i = n;
    j = W;
    while (i > 0 && j > 0) {
        if (knap[i][j] != knap[i - 1][j]) { // Item was included
            printf("Item %d -> Weight: %d, Value: %d\n", i, wt[i - 1], val[i - 1]);
            j -= wt[i - 1];  // Reduce knapsack weight
        }
        i--; // Move to the previous item
    }
}

int main() {
    int val[] = {20, 25, 40};
    int wt[] = {25, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    knapsack(W, wt, val, n);

    return 0;
}

