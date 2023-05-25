// https://practice.geeksforgeeks.org/problems/array-removals/1
// Approach:
// Sort the array
// Try removing from front and back. return min
// Recursive relation:
// return min(removeFront, removeBack)
// return min(1 + solve(i+1, j), 1 + solve(i, j-1))

int solve(int i, int j, vector<int> &a, int k, vector<vector<int>> &dp)
{
    if (i >= a.size() || j < 0 || a[j] - a[i] <= k)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int removeFront = 1 + solve(i + 1, j, a, k, dp);
    int removeBack = 1 + solve(i, j - 1, a, k, dp);

    return dp[i][j] = min(removeFront, removeBack);
}

int solveTab(vector<int> &a, int k, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[j] - a[i] <= k)
            {
                dp[i][j] = 0;
                continue;
            }

            int removeFront = 1 + dp[i + 1][j];
            int removeBack = 1 + dp[i][j - 1];

            dp[i][j] = min(removeFront, removeBack);
        }
    }

    return dp[0][n - 1];
}

int solveSO(vector<int> &a, int k, int n)
{
    vector<int> curr(n, 0);
    vector<int> next(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[j] - a[i] <= k)
            {
                curr[j] = 0;
                continue;
            }

            int removeFront = 1 + next[j];
            int removeBack = 1 + curr[j - 1];

            curr[j] = min(removeFront, removeBack);
        }
        next = curr;
    }

    return curr[n - 1];
}

int removals(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    // vector<vector<int>> dp(n, vector<int> (n, -1));
    // return solve(0, n-1, arr, k, dp);
    // return solveTab(arr, k, n);
    return solveSO(arr, k, n);
}