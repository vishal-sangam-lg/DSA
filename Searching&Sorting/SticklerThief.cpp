// maximum sum such that no 2 elements are adjacent
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
// Approach: Recursion -> include exclude -> dp -> tab -> SO
// TC: O(n)
// SC: O(1)

// int solve(int arr[], int i, int n, vector<int> &dp) {
//     if(i >= n) {
//         return 0;
//     }
//     if(dp[i] != -1) {
//         return dp[i];
//     }

//     int includeSum = arr[i] + solve(arr, i+2, n, dp);
//     int excludeSum = solve(arr, i+1, n, dp);
//     return dp[i] = max(includeSum, excludeSum);
// }

int FindMaxSum(int arr[], int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    // vector<int> dp(n, -1);

    // return solve(arr, 0, n, dp);

    // // solveTab
    // vector<int> dp(n+2);
    // dp[n] = 0;
    // dp[n+1] = 0;
    // for(int i = n-1; i >= 0; i--) {
    //     dp[i] = max(dp[i+1], arr[i] + dp[i+2]);
    // }
    // return dp[0];

    // SolveSO
    int v1 = arr[0];
    int v2 = max(v1, arr[1]);

    for (int i = 2; i < n; i++)
    {
        int temp = v2;
        v2 = max(v2, v1 + arr[i]);
        v1 = temp;
    }

    return v2;
}