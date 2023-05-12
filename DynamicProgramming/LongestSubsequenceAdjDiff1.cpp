// https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1
// Approach:
// Include if its first element or if its difference = 1 -> 1 + solve(curr+1, curr)
// Exclude in any case -> solve(curr+1, prev)
// return max(include, exclude)

int solve(int curr, int prev, int a[], int n)
{
    if (curr >= n)
    {
        return 0;
    }

    // Include if its first element or if its difference = 1
    int include = 0;
    if (prev == -1 || abs(a[curr] - a[prev]) == 1)
    {
        include = 1 + solve(curr + 1, curr, a, n);
    }
    int exclude = solve(curr + 1, prev, a, n);
    return max(include, exclude);
}
// Catch -> since prev starts from -1, use dp[curr][prev+1]
int solveMem(int curr, int prev, int a[], int n, vector<vector<int>> &dp)
{
    if (curr >= n)
    {
        return 0;
    }
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }

    // Include if its first element or if its difference = 1
    int include = 0;
    if (prev == -1 || abs(a[curr] - a[prev]) == 1)
    {
        include = 1 + solveMem(curr + 1, curr, a, n, dp);
    }
    int exclude = solveMem(curr + 1, prev, a, n, dp);
    return dp[curr][prev + 1] = max(include, exclude);
}

int longestSubsequence(int N, int A[])
{
    // return solve(0, -1, A, N);
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return solveMem(0, -1, A, N, dp);
}