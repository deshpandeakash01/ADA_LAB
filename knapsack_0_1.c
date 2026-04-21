#include <stdio.h>

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = (val[i-1] + dp[i-1][w-wt[i-1]] > dp[i-1][w]) 
                           ? val[i-1] + dp[i-1][w-wt[i-1]] 
                           : dp[i-1][w];
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    int res = dp[n][W];
    printf("Maximum value in knapsack = %d\n", res);

    int w = W;
    printf("Items selected (index, value, weight):\n");
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i-1][w]) {
            continue;
        } else {
            printf("Item %d -> Value: %d, Weight: %d\n", i-1, val[i-1], wt[i-1]);
            res -= val[i-1];
            w -= wt[i-1];
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &wt[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    knapsack(W, wt, val, n);

    return 0;
}
