// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Approach: Return for base cases. mark curr as 0. Explore path in all direction. Mark curr back to 1

vector<string> paths;
void solve(int i, int j, string path, vector<vector<int>> &m, int n)
{
    if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] == 0)
    {
        return;
    }
    if (i == n - 1 && j == n - 1)
    {
        paths.push_back(path);
        path = "";
        return;
    }

    m[i][j] = 0; // Mark as zero so that you don't come back
    solve(i + 1, j, path + "D", m, n);
    solve(i - 1, j, path + "U", m, n);
    solve(i, j + 1, path + "R", m, n);
    solve(i, j - 1, path + "L", m, n);
    m[i][j] = 1; // Backtrack, remove block
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
    {
        return {};
    }
    solve(0, 0, "", m, n);
    return paths;
}