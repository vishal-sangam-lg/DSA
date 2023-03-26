// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
// Approach: bfs using queue<pair<int,int> {x,y}.
// process queue -> mark all 4 direction neighbours their ans
// TC: O(n^2)
// SC: O(n)

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int row = grid.size();
    int col = grid[0].size();

    queue<pair<int, int>> q; // To store co-ordinates {x,y}
    vector<vector<int>> ans(row, vector<int>(col, -1));

    // Push all initial 1s to queue and mark its ans = 0
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                ans[i][j] = 0;
            }
        }
    }

    // Directions (x, y)
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    // BFS
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Marking all neighbouring answer (4 directions)
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k]; // neighbour x
                int ny = y + dy[k]; // neighbour y

                if (nx < 0 || ny < 0 || nx >= row || ny >= col || ans[nx][ny] != -1)
                {
                    continue;
                }
                q.push({nx, ny});
                ans[nx][ny] = ans[x][y] + 1;
            }
        }
    }

    return ans;
}