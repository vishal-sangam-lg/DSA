// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1
// Approach: for every row first column, call solve and store max ans
// recursive relation: max({solve(i-1,j+1), solve(i+1,j+1), solve(i, j+1)})

int solve(int i, int j, int n, int m, vector<vector<int>> &M, vector<vector<int>> &dp)
{
    if (i < 0 || i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int diagonallyUp = M[i][j] + solve(i - 1, j + 1, n, m, M, dp);
    int diagonallyDown = M[i][j] + solve(i + 1, j + 1, n, m, M, dp);
    int right = M[i][j] + solve(i, j + 1, n, m, M, dp);

    return dp[i][j] = max({diagonallyUp, diagonallyDown, right});
}

int maxGold(int n, int m, vector<vector<int>> M)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int currAns = solve(i, 0, n, m, M, dp);
        ans = max(ans, currAns);
    }
    return ans;
}