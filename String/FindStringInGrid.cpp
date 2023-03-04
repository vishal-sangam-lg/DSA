// https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1
// Approach: Store all 8 directions as const. Traverse grid.
// if first letter matches. dfs() in all 8 directions

bool check(int x, int y, int i, vector<vector<char>> &grid, string &word, vector<int> &direction)
{
    if (i == word.length())
        return true;
    if (x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] != word[i])
        return false;

    return check(x + direction[0], y + direction[1], i + 1, grid, word, direction);
}

vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
{
    vector<vector<int>> directions = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    vector<vector<int>> ans;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == word[0])
            {
                for (int k = 0; k < directions.size(); k++)
                {
                    if (check(i, j, 0, grid, word, directions[k]))
                    {
                        ans.push_back({i, j});
                        break;
                    }
                }
            }
        }
    }
    return ans;
}