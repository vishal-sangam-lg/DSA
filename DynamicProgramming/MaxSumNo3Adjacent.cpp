// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents-2/1
// Approach:
// Return max({pickCurrAndNext, notPickCurr, pickCurrAndNextNext});

// Nomenclature:
// when we have 3 consecutive elements 1 2 3
// We can pick 1 2 -> pickCurrAndNext
// We can pick 2 3 -> notPickCurr
// We can pick 1 3 -> pickCurrAndNextNext

int solve(vector<int> &a, int n, int i, vector<int> &dp)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int pickCurrAndNext = 0;
    if (i + 1 < n)
    {
        pickCurrAndNext = a[i] + a[i + 1] + solve(a, n, i + 3, dp);
    }
    else
    {
        pickCurrAndNext = a[i] + solve(a, n, i + 3, dp);
    }

    int notPickCurr = solve(a, n, i + 1, dp);
    int pickCurrAndNextNext = a[i] + solve(a, n, i + 2, dp);

    return dp[i] = max({pickCurrAndNext, notPickCurr, pickCurrAndNextNext});
}

int solveTab(vector<int> &a, int n)
{
    vector<int> dp(n + 3, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        int pickCurrAndNext = 0;
        if (i + 1 < n)
        {
            pickCurrAndNext = a[i] + a[i + 1] + dp[i + 3];
        }
        else
        {
            pickCurrAndNext = a[i] + dp[i + 3];
        }

        int notPickCurr = dp[i + 1];
        int pickCurrAndNextNext = a[i] + dp[i + 2];

        dp[i] = max({pickCurrAndNext, notPickCurr, pickCurrAndNextNext});
    }

    return dp[0];
}

int solveSO(vector<int> &a, int n)
{
    int curr = 0, next1 = 0, next2 = 0, next3 = 0;
    // Represents dp[i], dp[i+1], dp[i+2], dp[i+3]

    for (int i = n - 1; i >= 0; i--)
    {
        int pickCurrAndNext = 0;
        if (i + 1 < n)
        {
            pickCurrAndNext = a[i] + a[i + 1] + next3;
        }
        else
        {
            pickCurrAndNext = a[i] + next3;
        }

        int notPickCurr = next1;
        int pickCurrAndNextNext = a[i] + next2;

        curr = max({pickCurrAndNext, notPickCurr, pickCurrAndNextNext});
        next3 = next2;
        next2 = next1;
        next1 = curr;
    }

    return curr;
}

int findMaxSum(vector<int> &a)
{
    // vector<int> dp(a.size(), -1);
    // return solve(a, a.size(), 0, dp);
    // return solveTab(a, a.size());
    return solveSO(a, a.size());
}