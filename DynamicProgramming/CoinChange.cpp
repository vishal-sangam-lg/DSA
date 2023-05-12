// https://practice.geeksforgeeks.org/problems/coin-change2448/1

// Recursive relation: solve(i, sum - coins[i]) + solve(i + 1, sum)
// i.e pick current coin or not pick current coin

// Recursive solution
long long int solve(int coins[], int n, int i, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (i == n || sum < 0)
    {
        return 0;
    }
    return solve(coins, n, i, sum - coins[i]) + solve(coins, n, i + 1, sum);
}
// Recursion + memoisation (Bottom Up)
long long int solveMemo(int coins[], int n, int i, int sum, vector<vector<long long int>> &dp)
{
    if (sum == 0)
    {
        return 1;
    }
    if (i == n || sum < 0)
    {
        return 0;
    }
    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    return dp[i][sum] = solve(coins, n, i, sum - coins[i]) + solve(coins, n, i + 1, sum);
}
// Tabulation (Top Down)
long long int solveTab(int coins[], int n, int i, int sum)
{
    vector<vector<long long int>> dp(n + 1, vector<long long int>(sum + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                long long int a = 0;
                if (j - coins[i] >= 0)
                {
                    a = dp[i][j - coins[i]];
                }
                long long int b = dp[i + 1][j];
                dp[i][j] = a + b;
            }
        }
    }
    return dp[0][sum];
}
long long int count(int coins[], int N, int sum)
{
    // return solve(coins, N, 0, sum);
    // vector<vector<long long int>> dp(N, vector<long long int>(sum+1, -1));
    // return solveMemo(coins, N, 0, sum, dp);
    return solveTab(coins, N, 0, sum);
}