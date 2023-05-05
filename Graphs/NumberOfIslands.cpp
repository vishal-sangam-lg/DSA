// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
// Approach: dfs all nodes which have 1. Store 2 in it (marking visited)
// dfs in all 8 directions from there

void dfs(vector<vector<char>> &grid, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1')
        return;
    grid[i][j] = '2';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
    dfs(grid, i + 1, j + 1);
    dfs(grid, i - 1, j + 1);
    dfs(grid, i + 1, j - 1);
    dfs(grid, i - 1, j - 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}