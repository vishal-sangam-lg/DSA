// https://practice.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1
// Approach: dfs in all 4 directions with length. If you reach destination, update ans with length

// Constants
int n, m;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
void dfs(int x, int y, int destX, int destY, int len, vector<vector<int>> &mat, int &ans)
{
    if (isValid(x, y) == false)
    {
        return;
    }
    if (x == destX && y == destY)
    {
        ans = max(ans, len);
        return;
    }

    mat[x][y] = 0; // marking current position as visited
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (isValid(nx, ny))
        {
            if (mat[nx][ny] == 1)
            {
                dfs(nx, ny, destX, destY, len + 1, mat, ans);
            }
        }
    }
    mat[x][y] = 1; // Backtrack - mark as un-visited
}

int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
{
    n = matrix.size();
    m = matrix[0].size();
    int ans = -1;
    if (matrix[xs][ys] == 1)
    {
        dfs(xs, ys, xd, yd, 0, matrix, ans);
    }
    return ans;
}