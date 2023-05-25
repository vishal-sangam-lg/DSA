// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
// If lengthLeft >= index. return max(include, exclude)
// Else return exclude
// include = price[index-1] + solve(index, lengthLeft - index)
// exclude = solve(index-1, lengthLeft)

int solve(int index, int lengthLeft, int price[], vector<vector<int>> &dp)
{
    if (lengthLeft == 0 || index <= 0)
    {
        return 0;
    }
    if (dp[index][lengthLeft] != -1)
    {
        return dp[index][lengthLeft];
    }

    if (lengthLeft >= index)
    {
        int include = price[index - 1] + solve(index, lengthLeft - index, price, dp);
        int exclude = solve(index - 1, lengthLeft, price, dp);
        return dp[index][lengthLeft] = max(include, exclude);
    }
    else
    {
        int exclude = solve(index - 1, lengthLeft, price, dp);
        return dp[index][lengthLeft] = exclude;
    }
}

int solveTab(int n, int price[])
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int index = 1; index <= n; index++)
    {
        for (int lengthLeft = 1; lengthLeft <= n; lengthLeft++)
        {
            if (lengthLeft >= index)
            {
                int include = price[index - 1] + dp[index][lengthLeft - index];
                int exclude = dp[index - 1][lengthLeft];
                dp[index][lengthLeft] = max(include, exclude);
            }
            else
            {
                int exclude = dp[index - 1][lengthLeft];
                dp[index][lengthLeft] = exclude;
            }
        }
    }
    return dp[n][n];
}

int solveSO(int n, int price[])
{
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int index = 1; index <= n; index++)
    {
        for (int lengthLeft = 1; lengthLeft <= n; lengthLeft++)
        {
            if (lengthLeft >= index)
            {
                int include = price[index - 1] + curr[lengthLeft - index];
                int exclude = prev[lengthLeft];
                curr[lengthLeft] = max(include, exclude);
            }
            else
            {
                int exclude = prev[lengthLeft];
                curr[lengthLeft] = exclude;
            }
        }
        prev = curr;
    }
    return curr[n];
}

int cutRod(int price[], int n)
{
    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // return solve(n, n, price, dp);
    // return solveTab(n, price);
    return solveSO(n, price);
}