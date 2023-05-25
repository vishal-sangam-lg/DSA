// https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1
// Approach: Greedy yields better results
// sort arr, traverse RTL
// if(arr[i] - arr[i-1] < k)
// Include them in maxsum

// Greedy solution
// TC: O(nlogn)
// SC: O(1)

int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int maxsum = 0;
    for (int i = n - 1; i > 0; i--)
        if (arr[i] - arr[i - 1] < k)
        {
            maxsum += arr[i] + arr[i - 1];
            i--;
        }
    return maxsum;
}

// DP solution
// TC: O(2^n) with just recursion
// SC: O(n^2)

int solve(int i, int j, int arr[], int N, int K, vector<vector<int>> &dp)
{
    if (j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int include = 0, exclude = 0;
    if (arr[i] - arr[j] < K)
    {
        include = arr[i] + arr[j] + solve(j - 1, j - 2, arr, N, K, dp);
    }
    exclude = solve(i - 1, j - 1, arr, N, K, dp);
    return dp[i][j] = max(include, exclude);
}

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    sort(arr, arr + N);
    return solve(N - 1, N - 2, arr, N, K, dp);
}