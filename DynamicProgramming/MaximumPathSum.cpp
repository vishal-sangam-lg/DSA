// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
// Approach: Try all 3 directions. return max

int solve(int x, int y, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp)
{
    if (x > n - 1 || y > n - 1 || x < 0 || y < 0)
    {
        return 0;
    }
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    if (x == n - 1)
    {
        return matrix[x][y];
    }

    return dp[x][y] = matrix[x][y] + max({solve(x + 1, y - 1, matrix, n, dp),
                                          solve(x + 1, y, matrix, n, dp), solve(x + 1, y + 1, matrix, n, dp)});
}
int maximumPath(int N, vector<vector<int>> Matrix)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    int ans = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, solve(0, i, Matrix, N, dp));
    }
    return ans;
}