// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
// If I pick from front/back -> Opposite player will pick
// from front or back such that I get minimum
// pickFromFront = a[i] + min(solve(i + 2, j), solve(i + 1, j - 1));
// pickFromBack = a[j] + min(solve(i + 1, j - 1), solve(i, j - 2));

long long solve(int i, int j, int a[])
{
    if (i > j)
    {
        return 0;
    }

    // If I pick from front/back -> Opposite player will pick
    // from front or back such that I get minimum
    long long pickFromFront = a[i] + min(solve(i + 2, j, a), solve(i + 1, j - 1, a));
    long long pickFromBack = a[j] + min(solve(i + 1, j - 1, a), solve(i, j - 2, a));

    return max(pickFromFront, pickFromBack);
}

long long solveMem(int i, int j, int a[], vector<vector<long long>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    long long pickFromFront = a[i] + min(solveMem(i + 2, j, a, dp), solveMem(i + 1, j - 1, a, dp));
    long long pickFromBack = a[j] + min(solveMem(i + 1, j - 1, a, dp), solveMem(i, j - 2, a, dp));

    return dp[i][j] = max(pickFromFront, pickFromBack);
}

long long solveTab(int a[], int n)
{
    vector<vector<long long>> dp(n + 2, vector<long long>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            if (i <= j)
            {
                long long pickFromFront = a[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                long long pickFromBack = a[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

                dp[i][j] = max(pickFromFront, pickFromBack);
            }
        }
    }

    return dp[0][n - 1];
}

long long solveSO(int a[], int n)
{
    vector<long long> curr(n, 0);
    vector<long long> next1(n, 0);
    vector<long long> next2(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            if (i <= j)
            {
                long long pickFromFront = a[i] + min(next2[j], next1[j - 1]);
                long long pickFromBack = a[j] + min(next1[j - 1], curr[j - 2]);

                curr[j] = max(pickFromFront, pickFromBack);
            }
        }
        next2 = next1;
        next1 = curr;
    }

    return curr[n - 1];
}

long long maximumAmount(int arr[], int n)
{
    // return solve(0, n-1, arr);

    // vector<vector<long long>> dp(n, vector<long long>(n, -1));
    // return solveMem(0, n-1, arr, dp);

    // return solveTab(arr, n);

    return solveSO(arr, n);
}