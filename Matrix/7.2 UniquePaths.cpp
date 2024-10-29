// https://practice.geeksforgeeks.org/problems/number-of-paths0926/1
// Leetcode 62 - https://leetcode.com/problems/unique-paths/description/
// Space Optimised -> TC - O(n*m) : SC - O(N)

int solve(int m, int n)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (m < 0 || n < 0)
    {
        return 0;
    }
    return solve(m - 1, n) + solve(m, n - 1);
}
int solveMem(int m, int n, vector<vector<int>> &dp)
{
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (m == 0 && n == 0)
    {
        return 1;
    }
    int ans = 0;
    if (m - 1 >= 0)
    {
        ans += solveMem(m - 1, n, dp);
    }
    if (n - 1 >= 0)
    {
        ans += solveMem(m, n - 1, dp);
    }
    return dp[m][n] = ans;
}
int solveTab(int M, int N)
{
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 0; i <= M; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= N; i++)
    {
        dp[0][i] = 1;
    }
    for (int m = 1; m <= M; ++m)
    {
        for (int n = 1; n <= N; ++n)
        {
            dp[m][n] = dp[m - 1][n] + dp[m][n - 1];
        }
    }
    return dp[M][N];
}
int solveSO(int M, int N)
{
    vector<int> prev(N + 1, 1);
    vector<int> curr(N + 1, 0);
    curr[0] = 1;
    for (int m = 1; m <= M; ++m)
    {
        for (int n = 1; n <= N; ++n)
        {
            curr[n] = prev[n] + curr[n - 1];
        }
        prev = curr;
    }
    return prev[N];
}
int uniquePaths(int m, int n)
{
    // return solve(m - 1, n - 1);

    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    // return solveMem(m - 1, n - 1, dp);

    // return solveTab(m - 1, n - 1);

    return solveSO(m - 1, n - 1);
}