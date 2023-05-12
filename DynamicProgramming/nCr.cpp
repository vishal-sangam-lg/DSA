// https://practice.geeksforgeeks.org/problems/ncr1019/1
// nCr is pascal triange with 0 based indexing
// Recursive relation: n C r = (n-1) C (r-1) + (n-1) C (r)
//      1
//     1 1
//    1 2 1
//   1 3 3 1
//  1 4 6 4 1
// Examples:
// 3C1 = 2C0 + 2C1 = 1 + 2 = 3
// 3C2 = 2C1 + 2C2 = 2 + 1 = 3
// 4C1 = 3C0 + 3C1 = 1 + 3 = 4
// 4C2 = 3C1 + 3C2 = 3 + 3 = 6

// constants
int m = 1e9 + 7;

int solve(int n, int r, vector<vector<int>> &dp)
{
    if (r < 0)
    {
        return 0;
    }
    if (r == 0)
    {
        return dp[n][r] = 1;
    }
    if (n == 0)
    {
        return dp[n][r] = 0;
    }
    if (dp[n][r] != -1)
    {
        return dp[n][r];
    }

    return dp[n][r] = (solve(n - 1, r - 1, dp) % m + solve(n - 1, r, dp) % m) % m;
}

int solveTab(int N, int R)
{
    vector<vector<int>> dp(N + 1, vector<int>(R + 1, 0));
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }

    for (int n = 1; n <= N; n++)
    {
        for (int r = 1; r <= R; r++)
        {
            dp[n][r] = (dp[n - 1][r - 1] % m + dp[n - 1][r] % m) % m;
        }
    }

    return dp[N][R];
}

int solveSO(int N, int R)
{
    vector<int> prev(R + 1, 0);
    vector<int> curr(R + 1, 0);

    prev[0] = 1;
    curr[0] = 1;

    for (int n = 1; n <= N; n++)
    {
        for (int r = 1; r <= R; r++)
        {
            if (r > n)
                continue;
            curr[r] = (prev[r - 1] % m + prev[r] % m) % m;
        }
        prev = curr;
    }

    return curr[R];
}

int nCr(int n, int r)
{
    // vector<vector<int>> dp(n+1, vector<int> (r+1, -1));
    // return solve(n, r, dp);
    // return solveTab(n, r);
    return solveSO(n, r);
}