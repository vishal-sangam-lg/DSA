// https://practice.geeksforgeeks.org/problems/interleaved-strings/1
// Approach:
// matchA -> if a[i-1] == c[i+j-1] -> solve(i-1, j)
// matchB -> if b[j-1] == c[i+j-1] -> solve(i, j-1)
// return matchA | matchB

bool solve(int i, int j, string &a, string &b, string &c, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        return true;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    bool matchA = false;
    bool matchB = false;

    if (i != 0 && a[i - 1] == c[i + j - 1])
    {
        matchA = solve(i - 1, j, a, b, c, dp);
    }
    if (j != 0 && b[j - 1] == c[i + j - 1])
    {
        matchB = solve(i, j - 1, a, b, c, dp);
    }

    return dp[i][j] = matchA | matchB;
}

bool solveTab(int I, int J, string &a, string &b, string &c)
{
    vector<vector<bool>> dp(I + 1, vector<bool>(J + 1, true));

    for (int i = 1; i <= I; i++)
    {
        for (int j = 1; j <= J; j++)
        {
            bool matchA = false;
            bool matchB = false;

            if (i != 0 && a[i - 1] == c[i + j - 1])
            {
                matchA = dp[i - 1][j];
            }
            if (j != 0 && b[j - 1] == c[i + j - 1])
            {
                matchB = dp[i][j - 1];
            }

            dp[i][j] = matchA | matchB;
        }
    }
    return dp[I][J];
}

bool solveSO(int I, int J, string &a, string &b, string &c)
{
    vector<bool> prev(J + 1, true);
    vector<bool> curr(J + 1, true);

    for (int i = 1; i <= I; i++)
    {
        for (int j = 1; j <= J; j++)
        {
            bool matchA = false;
            bool matchB = false;

            if (i != 0 && a[i - 1] == c[i + j - 1])
            {
                matchA = prev[j];
            }
            if (j != 0 && b[j - 1] == c[i + j - 1])
            {
                matchB = curr[j - 1];
            }

            curr[j] = matchA | matchB;
        }
        prev = curr;
    }
    return curr[J];
}

bool isInterleave(string A, string B, string C)
{
    int i = A.size(), j = B.size();
    // vector<vector<int>> dp(i+1, vector<int>(j+1, -1));
    // return solve(i, j, A, B, C, dp);
    // return solveTab(i, j, A, B, C);
    return solveSO(i, j, A, B, C);
}