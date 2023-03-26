// https://practice.geeksforgeeks.org/problems/knight-walk4521/1
// Approach: bfs using queue<pair<int,int> {x,y}.
// process queue -> move all 8 direction, then thier children

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
{
    // Directions (x, y) -> 8 possibilities
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int steps = 0;
    queue<pair<int, int>> q; // Store co-ordinates of rotten oranges {x,y}
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

    // Marking initial position
    q.push({KnightPos[0], KnightPos[1]});
    visited[KnightPos[0]][KnightPos[1]] = true;

    // BFS -> Try out all 8 possibilities then cascade their 8 children
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == TargetPos[0] && y == TargetPos[1])
                return steps;

            for (int k = 0; k < 8; k++)
            {
                int nx = x + dx[k]; // new x
                int ny = y + dy[k]; // new y
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        steps++;
    }
    return steps;
}