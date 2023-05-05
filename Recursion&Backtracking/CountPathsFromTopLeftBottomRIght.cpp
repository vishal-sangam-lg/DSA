// https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1
// Approach: Recursive relation - solve(m-1,n) + solve(m, n-1). Apply dp

// constants
long long int mod = 1e9 + 7;

long long int solve(int m, int n, vector<vector<long long int>> &dp)
{
    if (m < 0 || n < 0)
        return 0;
    if (m == 0 && n == 0)
        return 1;
    if (dp[m][n] != 0)
    {
        return dp[m][n];
    }

    return dp[m][n] = (solve(m - 1, n, dp) % mod + solve(m, n - 1, dp) % mod) % mod;
}

long long int solveTab(int m, int n)
{
    vector<vector<long long int>> dp(m, vector<long long int>(n, 1));
    dp[0][0] = 1;

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    return dp[m - 1][n - 1] % mod;
}

long long int solveSO(int m, int n)
{
    vector<long long int> curr(n, 1);
    vector<long long int> prev(n, 1);

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            curr[j] = (prev[j] + curr[j - 1]) % mod;
            prev.assign(curr.begin(), curr.end());
        }
    }
    return prev[n - 1] % mod;
}

long long int numberOfPaths(int m, int n)
{
    // vector<vector<long long int>> dp(m+1, vector<long long int>(n+1, 0));
    // return solve(m-1, n-1, dp);
    // return solveTab(m, n);
    return solveSO(m, n);
}