// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// pick = val[n - 1] + solve(W - wt[n - 1], wt, val, n - 1);
// notpick = solve(W, wt, val, n - 1);
// if wt[n-1] <= W => max(pick, notpick)
// else not pick

// Recursion
int solve(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    // If it is possible to include current item in bag
    // Consider both include and exlude cases
    if (wt[n - 1] <= W)
    {
        int pick = val[n - 1] + solve(W - wt[n - 1], wt, val, n - 1);
        int notpick = solve(W, wt, val, n - 1);
        return max(pick, notpick);
    }

    // Else just exclude and move forward
    return solve(W, wt, val, n - 1);
}

// Recursion + Memoization
int solveMem(int w, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (dp[w][n] != -1)
    {
        return dp[w][n];
    }

    if (wt[n - 1] <= w)
    {
        int pick = val[n - 1] + solveMem(w - wt[n - 1], wt, val, n - 1, dp);
        int notpick = solveMem(w, wt, val, n - 1, dp);
        return dp[w][n] = max(pick, notpick);
    }

    return dp[w][n] = solveMem(w, wt, val, n - 1, dp);
}

// Tabulation
int solveTab(int W, int wt[], int val[], int N)
{
    vector<vector<int>> dp(W + 1, vector<int>(N + 1, 0));

    for (int w = 1; w <= W; w++)
    {
        for (int n = 1; n <= N; n++)
        {
            if (wt[n - 1] <= w)
            {
                int pick = val[n - 1] + dp[w - wt[n - 1]][n - 1];
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

int knapSack(int W, int wt[], int val[], int n)
{
    // return solve(W, wt, val, n);
    // vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
    // return solveMem(W, wt, val, n, dp);
    return solveTab(W, wt, val, n);
}