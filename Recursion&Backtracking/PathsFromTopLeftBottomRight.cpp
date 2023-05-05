// https://practice.geeksforgeeks.org/problems/find-all-possible-paths-from-top-to-bottom/1
// Approach: solve(i+1, j) and solve(i, j+1). Push path to ans when you reach bottom right
// pop_back path to backtrack

void pathfind(int i, int j, int n, int m, vector<vector<int>> grid, vector<int> &curr, vector<vector<int>> &ans)
{
    if (i == n - 1 && j == m - 1)
    {
        curr.push_back(grid[i][j]); // push curr cell to path
        ans.push_back(curr);
        curr.pop_back(); // backtrack
        return;
    }
    curr.push_back(grid[i][j]); // push curr cell to path
    if (i < n - 1)
        pathfind(i + 1, j, n, m, grid, curr, ans);
    if (j < m - 1)
        pathfind(i, j + 1, n, m, grid, curr, ans);
    curr.pop_back(); // backtrack
}
vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
{
    vector<int> curr;
    vector<vector<int>> ans;
    pathfind(0, 0, n, m, grid, curr, ans);
    return ans;
}