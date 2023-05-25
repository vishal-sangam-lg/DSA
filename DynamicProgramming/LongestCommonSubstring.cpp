// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
// Approach:
// if match -> 1 + solve(n-1, m-1). update ans
// Else -> dp[n][m] = 0
// At the end, call solve(n-1, m) and solve(n, m-1)
// To cover all cases

int solve(string s1, string s2, int n, int m, vector<vector<int>> &dp, int &ans)
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
        dp[n][m] = 1 + solve(s1, s2, n - 1, m - 1, dp, ans);
        ans = max(ans, dp[n][m]);
    }
    else
    {
        dp[n][m] = 0;
    }

    solve(s1, s2, n - 1, m, dp, ans);
    solve(s1, s2, n, m - 1, dp, ans);

    return dp[n][m];
}

int solveTab(string s1, string s2, int N, int M)
{
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    int ans = 0;

    for (int n = 1; n <= N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            if (s1[n - 1] == s2[m - 1])
            {
                dp[n][m] = 1 + dp[n - 1][m - 1];
                ans = max(ans, dp[n][m]);
            }
            else
            {
                dp[n][m] = 0;
            }
        }
    }

    return ans;
}

int solveSO(string s1, string s2, int N, int M)
{
    vector<int> curr(M + 1, 0);
    vector<int> prev(M + 1, 0);
    int ans = 0;

    for (int n = 1; n <= N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            if (s1[n - 1] == s2[m - 1])
            {
                curr[m] = 1 + prev[m - 1];
                ans = max(ans, curr[m]);
            }
            else
            {
                curr[m] = 0;
            }
        }
        prev = curr;
    }

    return ans;
}

int longestCommonSubstr(string s1, string s2, int n, int m)
{
    // int ans = 0;
    // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    // int dummy = solve(s1, s2, n, m, dp, ans);
    // return ans;
    // return solveTab(s1, s2, n, m);
    return solveSO(s1, s2, n, m);
}