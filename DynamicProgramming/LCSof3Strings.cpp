// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

// Approach:
// if match  -> solve(i-1, j-1, k-1)
// not match -> max({solve(i - 1, j, k), solve(i, j - 1, k), solve(i, j, k - 1)})

int dp[21][21][21];

int solve(string &a, string &b, string &c, int i, int j, int k)
{
    if (i == 0 || j == 0 || k == 0)
    {
        return 0;
    }
    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }

    if ((a[i - 1] == b[j - 1]) && (a[i - 1] == c[k - 1]))
    {
        return dp[i][j][k] = 1 + solve(a, b, c, i - 1, j - 1, k - 1);
    }
    else
    {
        return dp[i][j][k] = max({solve(a, b, c, i - 1, j, k), solve(a, b, c, i, j - 1, k), solve(a, b, c, i, j, k - 1)});
    }
}

int solveTab(string &a, string &b, string &c, int n1, int n2, int n3)
{
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            for (int k = 0; k <= n3; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    dp[i][j][k] = 0;
                }
                else if ((a[i - 1] == b[j - 1]) && (a[i - 1] == c[k - 1]))
                {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                }
                else
                {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }
    return dp[n1][n2][n3];
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    // initialising dp
    memset(dp, -1, sizeof(dp));
    // return solve(A, B, C, n1, n2, n3);
    return solveTab(A, B, C, n1, n2, n3);
}