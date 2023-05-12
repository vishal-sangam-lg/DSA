// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// Approach:
// If match  -> 1 + solve(n-1, m-1)
// Not match -> max(solve(n-1, m), solve(n, m-1))

int solve(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = 1 + solve(s1, s2, n - 1, m - 1, dp);
    }
    else
    {
        return dp[n][m] = max(solve(s1, s2, n - 1, m, dp), solve(s1, s2, n, m - 1, dp));
    }
}

int solveTab(string s1, string s2, int N, int M)
{
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int n = 1; n <= N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            if (s1[n - 1] == s2[m - 1])
            {
                dp[n][m] = 1 + dp[n - 1][m - 1];
            }
            else
            {
                dp[n][m] = max(dp[n - 1][m], dp[n][m - 1]);
            }
        }
    }

    return dp[N][M];
}

int solveSO(string s1, string s2, int N, int M)
{
    if (N < M)
    {
        swap(N, M);
        swap(s1, s2);
    }

    vector<int> prev(M + 1, 0);
    vector<int> curr(M + 1, 0);
    vector<int> ans(M + 1, 0);

    for (int n = 1; n <= N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            if (s1[n - 1] == s2[m - 1])
            {
                ans[m] = 1 + prev[m - 1];
            }
            else
            {
                ans[m] = max(prev[m], curr[m - 1]);
            }
            prev = curr;
            curr = ans;
        }
    }

    return ans[M];
}

int lcs(int x, int y, string s1, string s2)
{
    // vector<vector<int>> dp(x+1, vector<int> (y+1, -1));
    // return solve(s1, s2, x, y, dp);
    // return solveTab(s1, s2, x, y);
    return solveSO(s1, s2, x, y);
}