// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

// Recursive relation of Longest common subsequence
// If match  -> 1 + solve(n-1, m-1)
// Not match -> max(solve(n-1, m), solve(n, m-1))

// Copy paste optimal solution of Longest common subsequence
// Modification - for matching -> add condition that indices are not same

int solveSO(string s1, string s2, int len)
{
    vector<int> prev(len + 1, 0);
    vector<int> curr(len + 1, 0);
    vector<int> ans(len + 1, 0);

    for (int n = 1; n <= len; n++)
    {
        for (int m = 1; m <= len; m++)
        {
            if (s1[n - 1] == s2[m - 1] && n != m)
            {
                ans[m] = 1 + prev[m - 1];
            }
            else
            {
                ans[m] = max(prev[m], curr[m - 1]);
            }
            prev = curr;
            curr = ans;
        }
    }

    return ans[len];
}

int LongestRepeatingSubsequence(string str)
{
    return solveSO(str, str, str.length());
}