// https://practice.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1
// Approach: Mark all 4 adjacent cells of landmine as -1.
// Multi-source bfs in all 4 directions starting from all valid points in first column
// Update distance for every bfs iteration
// queue<pair<pair<int, int>, int>> q; // {{x,y}, distance}

bool isSafe(int &x, int &y, int &n, int &m)
{
    if (x < 0 or y < 0 or x >= n or y >= m)
        return false;
    return true;
}

int findShortestPath(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    // Mark all 4 adjacent cells of landmine as -1
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (mat[x][y] == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (isSafe(nx, ny, n, m) && mat[nx][ny] != 0)
                    {
                        mat[nx][ny] = -1;
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q; // {{x,y}, distance}
    // Push all valid cells in first column into queue
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 1)
        {
            q.push({{i, 0}, 1});
            visited[i][0] = true;
        }
    }

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int distance = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k]; // new x
            int ny = y + dy[k]; // new y
            if (isSafe(nx, ny, n, m) && mat[nx][ny] == 1 && visited[nx][ny] == false)
            {
                visited[nx][ny] = true;
                q.push({{nx, ny}, distance + 1});
                if (ny == m - 1)
                {
                    ans = min(ans, distance + 1);
                }
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}
