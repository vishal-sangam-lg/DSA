// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// Approach:
// Traverse RTL
// if matches, return 1 + solve(n-1, m-1)
// else return max(solve(n-1,m), solve(n,m-1))

// int solve(string s1, string s2, int n, int m, vector<vector<int>> &dp) {
//     if(n == 0 || m == 0) {
//         return 0;
//     }
//     if(dp[n][m] != -1) {
//         return dp[n][m];
//     }

//     if(s1[n-1] == s2[m-1]) {
//         return dp[n][m] = 1 + solve(s1, s2, n-1, m-1, dp);
//     } else {
//         return dp[n][m] = max(solve(s1, s2, n-1, m, dp), solve(s1, s2, n, m-1, dp));
//     }
// }

int solveTab(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int lcs(int x, int y, string s1, string s2)
{
    // vector<vector<int>> dp(x+1, vector<int> (y+1, -1));
    // int ans = solve(s1, s2, x, y, dp);
    int ans = solveTab(s1, s2, x, y);
    return ans;
}