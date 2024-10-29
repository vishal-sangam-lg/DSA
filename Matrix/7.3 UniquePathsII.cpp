// Leetcode 63 - https://leetcode.com/problems/unique-paths-ii/description/
// Approach - Same as UniquePath I. Add conditions for obstacles

int solve(int m, int n, vector<vector<int>> &obstacleGrid)
{
    if (m == 0 && n == 0 && !obstacleGrid[m][n])
    {
        return 1;
    }
    if (m < 0 || n < 0 || obstacleGrid[m][n])
    {
        return 0;
    }
    return solve(m - 1, n, obstacleGrid) + solve(m, n - 1, obstacleGrid);
}
int solveMem(int m, int n, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
{
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (m == 0 && n == 0 && !obstacleGrid[m][n])
    {
        return 1;
    }
    if (obstacleGrid[m][n])
    {
        return 0;
    }
    int ans = 0;
    if (m - 1 >= 0)
    {
        ans += solveMem(m - 1, n, dp, obstacleGrid);
    }
    if (n - 1 >= 0)
    {
        ans += solveMem(m, n - 1, dp, obstacleGrid);
    }
    return dp[m][n] = ans;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    // return solve(m - 1, n - 1, obstacleGrid);

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solveMem(m - 1, n - 1, dp, obstacleGrid);
}