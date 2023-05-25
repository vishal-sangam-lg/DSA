// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
// Approach: LongestCommonSubsequence(string, reverse of string)

int lcs(string s1, string s2, int N, int M)
{
    if (N < M)
    {
        swap(N, M);
        swap(s1, s2);
    }

    vector<int> prev(M + 1, 0);
    vector<int> curr(M + 1, 0);
    vector<int> ans(M + 1, 0);

    for (int n = 1; n <= N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            if (s1[n - 1] == s2[m - 1])
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

    return ans[M];
}

int longestPalinSubseq(string A)
{
    string s1 = A;
    reverse(A.begin(), A.end());
    string s2 = A;
    int n = A.size();

    return lcs(s1, s2, n, n);
}