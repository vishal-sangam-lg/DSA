// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
// Approach:
// If mat[i][j] == 1
// then 1 + min({right, diagonal, down})
// else 0

int solve(vector<vector<int>> &mat, int i, int j, int &ans, vector<vector<int>> &dp)
{
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solve(mat, i, j + 1, ans, dp);
    int digonal = solve(mat, i + 1, j + 1, ans, dp);
    int down = solve(mat, i + 1, j, ans, dp);

    if (mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(digonal, down));
        ans = max(ans, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}

void solveTab(vector<vector<int>> &mat, int &ans, int n, int m)
{
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1];
            int diagonal = dp[i + 1][j + 1];
            int down = dp[i + 1][j];

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min({right, diagonal, down});
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return;
}

void solveSO(vector<vector<int>> &mat, int &ans, int n, int m)
{
    vector<int> finalAns(m + 2, 0);
    vector<int> curr(m + 2, 0);
    vector<int> next(m + 2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int right = curr[j + 1];
            int diagonal = next[j + 1];
            int down = next[j];

            if (mat[i][j] == 1)
            {
                finalAns[j] = 1 + min({right, diagonal, down});
                ans = max(ans, finalAns[j]);
            }
            else
            {
                finalAns[j] = 0;
            }
            next = curr;
            curr = finalAns;
        }
    }

    return;
}

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int ans = 0;
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // solve(mat, 0, 0, ans, dp);
    // solveTab(mat, ans, n, m);
    solveSO(mat, ans, n, m);
    return ans;
}