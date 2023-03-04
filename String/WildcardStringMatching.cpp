// https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1
// Approach: Read the solution
// TC: O(n^2)
// SC: O(n^2)

bool solve(string &wild, string &pattern, int i, int j, vector<vector<int>> &dp)
{
    // Base Cases
    // Case 1: Both wild and pattern ends -> True
    if (i < 0 && j < 0)
        return true;
    // Case 2: Wild ends but pattern is left -> False
    if (i < 0 && j >= 0)
        return false;
    // Case 3: Wild is left, pattern has ended -> True only if * is left in wild
    if (i >= 0 && j < 0)
    {
        for (int k = 0; k <= i; k++)
        {
            if (wild[k] != '*')
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    // wild and pattern character match or its ? in wild
    if (wild[i] == pattern[j] || wild[i] == '?')
    {
        return dp[i][j] = solve(wild, pattern, i - 1, j - 1, dp);
    }
    // wild is *
    // case 1: consider * as empty string
    // case 2: consider * to consume current character in pattern
    else if (wild[i] == '*')
    {
        return dp[i][j] = (solve(wild, pattern, i - 1, j, dp) || solve(wild, pattern, i, j - 1, dp));
    }
    // when pattern wild doesn't match and its not even * or ? -> return False
    else
    {
        return false;
    }
}
bool match(string wild, string pattern)
{
    int n = wild.size();
    int m = pattern.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve(wild, pattern, n - 1, m - 1, dp);
}