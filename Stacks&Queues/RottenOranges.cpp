// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
// Approach: bfs using queue<pair<int,int> {x,y}.
// process queue -> mark all 4 direction neighbours their ans

int orangesRotting(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    int Time = 0, fresh = 0;
    queue<pair<int, int>> q; // Store co-ordinates of rotten oranges {x,y}

    // Push initially rotten oranges to queue
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }

    // Directions (x, y)
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // BFS
    while (!q.empty())
    {
        Time++;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Rotting all neighbouring oranges (4 directions)
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k]; // neighbour x
                int ny = y + dy[k]; // neighbour y

                if (nx < 0 || ny < 0 || nx >= row || ny >= col || grid[nx][ny] == 2 || grid[nx][ny] == 0)
                {
                    continue;
                }

                grid[nx][ny] = 2;
                fresh--;
                q.push({nx, ny});
            }
        }
        // If there are no more fresh oranges, return time
        if (fresh == 0)
        {
            return Time;
        }
    }

    return -1;
}