// https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1
// Include Exclude type
// Recursive relation:
// If n <= w -> min(cost[n-1] + solve(n, w-n), solve(n-1, w))
// Else -> solve(n-1, w)

long long int solve(int cost[], int n, int w, vector<vector<long long int>> &dp)
{
    if (w == 0)
    {
        return 0;
    }
    if (n == 0 || w < 0)
    {
        return INT_MAX;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }

    if (n <= w && cost[n - 1] != -1)
    {
        return dp[n][w] = min(cost[n - 1] + solve(cost, n, w - n, dp), solve(cost, n - 1, w, dp));
    }

    return dp[n][w] = solve(cost, n - 1, w, dp);
}

int solveTab(int cost[], int N, int W)
{
    vector<vector<long long int>> dp(N + 1, vector<long long int>(W + 1, 0));
    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = INT_MAX;
    }

    for (int n = 1; n <= N; n++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (n <= w && cost[n - 1] != -1)
            {
                dp[n][w] = min(cost[n - 1] + dp[n][w - n], dp[n - 1][w]);
            }
            else
            {
                dp[n][w] = dp[n - 1][w];
            }
        }
    }

    return dp[N][W];
}

int solveSO(int cost[], int N, int W)
{
    vector<long long int> curr(W + 1, 0);
    vector<long long int> prev(W + 1, 0);

    for (int i = 0; i <= W; i++)
    {
        prev[i] = INT_MAX;
    }

    for (int n = 1; n <= N; n++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (n <= w && cost[n - 1] != -1)
            {
                curr[w] = min(cost[n - 1] + curr[w - n], prev[w]);
            }
            else
            {
                curr[w] = prev[w];
            }
        }
        prev = curr;
    }

    return curr[W];
}

int minimumCost(int cost[], int N, int W)
{
    // vector<vector<long long int>> dp(N+1, vector<long long int> (W+1, -1));
    // int res = solve(cost, N, W, dp);
    // int res = solveTab(cost, N, W);
    int res = solveSO(cost, N, W);
    return res >= INT_MAX ? -1 : (int)res;
}