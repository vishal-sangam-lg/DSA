// https://leetcode.com/problems/flood-fill/
// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

// Approach I : dfs
// dfs in all 4 directions, if image[i][j] == val, color it. (val = image[sr][sc])

void dfs(vector<vector<int>> &image, int i, int j, int val, int color)
{
    if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != val || image[i][j] == color)
    {
        return;
    }

    image[i][j] = color;
    dfs(image, i + 1, j, val, color);
    dfs(image, i, j + 1, val, color);
    dfs(image, i - 1, j, val, color);
    dfs(image, i, j - 1, val, color);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int val = image[sr][sc];
    dfs(image, sr, sc, val, color);
    return image;
}

// Approach II : bfs
// bfs in all 4 directions, if image[i][j] == val, color it. (val = image[sr][sc])
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int value = image[sr][sc];
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int val = image[x][y];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= image.size() || ny < 0 || ny >= image[0].size() || image[nx][ny] != value || image[nx][ny] == color)
            {
                continue;
            }

            image[nx][ny] = color; // also marks as visited
            q.push({nx, ny});
        }
    }

    return image;
}