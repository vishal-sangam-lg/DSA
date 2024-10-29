// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/
// Leetcode - 1886. Determine Whether Matrix Can Be Obtained By Rotation
// Approach - count c90, c180, c270, c0. Return If any of count == n * n
// TC - O(n*n) : SC - O(1)

bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
{
    int n = mat.size();
    int c90 = 0, c180 = 0, c270 = 0, c0 = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // Considering clockwise rotation
            if (target[i][j] == mat[j][n - i - 1])
            {
                c90++;
            }
            if (target[i][j] == mat[n - i - 1][n - j - 1])
            {
                c180++;
            }
            if (target[i][j] == mat[n - j - 1][i])
            {
                c270++;
            }
            if (target[i][j] == mat[i][j])
            {
                c0++;
            }
        }
    }

    int N = n * n;
    return c90 == N || c180 == N || c270 == N || c0 == N;
}