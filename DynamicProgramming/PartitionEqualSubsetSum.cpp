// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

// Recursive relation
// If current element is <= sum. Try both including and excluding it
// i.e solve(n-1, sum-arr[n-1]) || solve(n-1, sum)
// If current element is > sum. Try excluding it
// i.e solve(n-1, sum)

int solve(int arr[], int n, int sum, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    // If current element is <= sum. Try both including and excluding it
    if (arr[n - 1] <= sum)
    {
        return dp[n][sum] = solve(arr, n - 1, sum - arr[n - 1], dp) || solve(arr, n - 1, sum, dp);
    }
    // If current element is > sum. Try excluding it
    else
    {
        return dp[n][sum] = solve(arr, n - 1, sum, dp);
    }
}

int solveTab(int arr[], int N, int Sum)
{
    vector<vector<int>> dp(N + 1, vector<int>(Sum + 1, 0));
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = 1;
    }

    for (int n = 1; n <= N; n++)
    {
        for (int sum = 1; sum <= Sum; sum++)
        {
            // If current element is <= sum. Try both including and excluding it
            if (arr[n - 1] <= sum)
            {
                dp[n][sum] = dp[n - 1][sum - arr[n - 1]] || dp[n - 1][sum];
            }
            // If current element is > sum. Try excluding it
            else
            {
                dp[n][sum] = dp[n - 1][sum];
            }
        }
    }

    return dp[N][Sum];
}

int equalPartition(int N, int arr[])
{
    int sum = accumulate(arr, arr + N, 0);
    if (sum & 1)
    {
        return 0;
    }
    else
    {
        // vector<vector<int>> dp(N+1, vector<int>(sum/2+1, -1));
        // return solve(arr, N, sum/2, dp);
        return solveTab(arr, N, sum / 2);
    }
}