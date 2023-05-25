// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// Approach: Same as knapsack, but when you pick, again consider nth item

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(W + 1, vector<int>(N + 1, 0));

    for (int w = 1; w <= W; w++)
    {
        for (int n = 1; n <= N; n++)
        {
            if (wt[n - 1] <= w)
            {
                // int pick = val[n - 1] + dp[w - wt[n - 1]][n-1];
                // is for knapsack with limited items
                // If it is unlimited, we can consider
                // nth item again after picking nth item
                int pick = val[n - 1] + dp[w - wt[n - 1]][n];
                int notpick = dp[w][n - 1];
                dp[w][n] = max(pick, notpick);
            }
            else
            {
                dp[w][n] = dp[w][n - 1];
            }
        }
    }

    return dp[W][N];
}