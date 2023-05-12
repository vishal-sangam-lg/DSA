// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Recursive Relation:
// i-1 -> start
// k   -> partition
// j   -> end
// So we have to multiply i-1 * k * j + recursively solve whatever is in between
// i.e solve(i, k) + solve(k+1, j)

int solve(int i, int j, int arr[], vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
        ans = min(ans, steps);
    }

    return dp[i][j] = ans;
}

int solveTab(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int ans = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                ans = min(ans, steps);
            }
            dp[i][j] = ans;
        }
    }

    return dp[1][N - 1];
}

int matrixMultiplication(int N, int arr[])
{
    // vector<vector<int>> dp(N, vector<int> (N, -1));
    // return solve(1, N-1, arr, dp);
    return solveTab(N, arr);
}