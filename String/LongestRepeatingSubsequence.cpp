// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// Approach: variant of LCS
// We take both strings as same. we try to find LCS with characters not having same index
// TC: o(n^2)
// SC: O(n)

// 	int solve(string str1, string str2, int i, int j, vector<vector<int>> &dp) {
// 	    if(i == str1.length()) {
// 	        return 0;
// 	    }
// 	    if(j == str2.length()) {
// 	        return 0;
// 	    }
// 	    if(dp[i][j] != -1) {
// 	        return dp[i][j];
// 	    }
// 	    int ans = 0;
// 	    if(str1[i] == str2[j] && i != j) {
// 	        ans = 1 + solve(str1, str2, i+1, j+1, dp);
// 	    } else {
// 	        ans = max(solve(str1, str2, i+1, j, dp), solve(str1, str2, i, j+1, dp));
// 	    }
// 	    return dp[i][j] = ans;
// 	}
// int solveTab(string str1, string str2) {
//     vector<vector<int>>dp(str1.length()+1, vector<int>(str2.length()+1, 0));

//     for(int i = str1.length()-1; i >= 0; i--) {
//         for(int j = str2.length()-1; j >= 0; j--) {
//             int ans = 0;
//     	    if(str1[i] == str2[j] && i != j) {
//     	        ans = 1 + dp[i+1][j+1];
//     	    } else {
//     	        ans = max(dp[i+1][j], dp[i][j+1]);
//     	    }
//     	    dp[i][j] = ans;
//         }
//     }
//     return dp[0][0];
// }
int solveSO(string str1, string str2)
{
    vector<int> curr(str2.length() + 1, 0);
    vector<int> next(str2.length() + 1, 0);

    for (int i = str1.length() - 1; i >= 0; i--)
    {
        for (int j = str2.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (str1[i] == str2[j] && i != j)
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                ans = max(next[j], curr[j + 1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
int LongestRepeatingSubsequence(string str)
{
    // vector<vector<int>> dp(str.length(), vector<int>(str.length(), -1));
    // int ans = solve(str, str, 0, 0, dp);
    // return solveTab(str, str);
    return solveSO(str, str);
}
