// https://practice.geeksforgeeks.org/problems/edit-distance3702/1

// Recursive relation:
// If match - solve(n-1, m-1)
// Not match - min({insert, delete, replace})
// i.e min({solve(n, m-1), solve(n-1, m), solve(n-1, m-1)})

int solve(string s, string t, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return m;
    }
    if (m == 0)
    {
        return n;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    int ans = 0;
    if (s[n - 1] == t[m - 1])
    {
        return dp[n][m] = solve(s, t, n - 1, m - 1, dp);
    }
    else
    {
        // Insert -> one character less to match.
        int insertAns = 1 + solve(s, t, n, m - 1, dp);
        // Delete -> One character less in original string
        int deleteAns = 1 + solve(s, t, n - 1, m, dp);
        // Replace -> One char less in both since we replaced
        int replaceAns = 1 + solve(s, t, n - 1, m - 1, dp);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return dp[n][m] = ans;
}

int solveTab(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int insertAns = 1 + dp[i][j - 1];
                int deleteAns = 1 + dp[i - 1][j];
                int replaceAns = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(insertAns, min(deleteAns, replaceAns));
            }
        }
    }

    return dp[n][m];
}

int solveSO(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<int> curr(m + 1, 0);
    vector<int> prev(m + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                curr[j] = j;
            }
            else if (j == 0)
            {
                curr[j] = i;
            }
            else if (s[i - 1] == t[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                int insertAns = 1 + curr[j - 1];
                int deleteAns = 1 + prev[j];
                int replaceAns = 1 + prev[j - 1];
                curr[j] = min(insertAns, min(deleteAns, replaceAns));
            }
        }
        prev = curr;
    }

    return curr[m];
}

int editDistance(string s, string t)
{
    // int n = s.length();
    // int m = t.length();

    // if(n == 0) return m;

    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    // return solve(s, t, n, m, dp);

    // return solveTab(s, t);

    return solveSO(s, t);
}