// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
// Recursive relation:
// 1 + max({solve(n-x), solve(n-y), solve(n-z)})

int solve(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }

    int cutX = INT_MIN, cutY = INT_MIN, cutZ = INT_MIN;
    if (n - x >= 0)
        cutX = solve(n - x, x, y, z);
    if (n - y >= 0)
        cutY = solve(n - y, x, y, z);
    if (n - z >= 0)
        cutZ = solve(n - z, x, y, z);

    return 1 + max({cutX, cutY, cutZ});
}

int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int cutX = INT_MIN, cutY = INT_MIN, cutZ = INT_MIN;
    if (n - x >= 0)
        cutX = solve(n - x, x, y, z);
    if (n - y >= 0)
        cutY = solve(n - y, x, y, z);
    if (n - z >= 0)
        cutZ = solve(n - z, x, y, z);

    return dp[n] = 1 + max({cutX, cutY, cutZ});
}

int solveTab(int N, int x, int y, int z)
{
    vector<int> dp(N + 1, 0);

    for (int n = 1; n <= N; n++)
    {
        int cutX = INT_MIN, cutY = INT_MIN, cutZ = INT_MIN;
        if (n - x >= 0)
            cutX = dp[n - x];
        if (n - y >= 0)
            cutY = dp[n - y];
        if (n - z >= 0)
            cutZ = dp[n - z];

        dp[n] = 1 + max({cutX, cutY, cutZ});
    }

    return dp[N] < 0 ? 0 : dp[N];
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    // vector<int> dp(n+1, -1);
    // int ans = solve(n, x, y, z);
    // int ans = solveMem(n, x, y, z, dp);
    return solveTab(n, x, y, z);
}