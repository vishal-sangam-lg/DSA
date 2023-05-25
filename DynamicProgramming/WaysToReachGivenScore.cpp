// https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1
// Approach:
// If n - scores[i] >= 0 -> include = solve(i, n-scores[i])
// exclude -> solve(i-1, n)
// return include + exclude

int scores[] = {3, 5, 10};

long long int solve(int i, long long int n, vector<vector<long long int>> &dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0 || i < 0)
    {
        return 0;
    }
    if (dp[n][i] != -1)
    {
        return dp[n][i];
    }

    long long int include = 0, exclude = 0;
    if (n - scores[i] >= 0)
    {
        include = solve(i, n - scores[i], dp);
    }
    exclude = solve(i - 1, n, dp);

    return dp[n][i] = include + exclude;
}

long long solveTab(long long int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 3; i <= n; i++)
        dp[i] += dp[i - 3];
    for (int i = 5; i <= n; i++)
        dp[i] += dp[i - 5];
    for (int i = 10; i <= n; i++)
        dp[i] += dp[i - 10];

    return dp[n];
}

long long int count(long long int n)
{
    // 	vector<vector<long long int>> dp(n+1, vector<long long int>(3, -1));
    // 	return solve(2, n, dp);
    return solveTab(n);
}