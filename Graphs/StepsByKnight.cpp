// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
// Approach: bfs in all 8 directions with queue<{x, y, distance}> and visited[][]

class coordinates
{
public:
    int x, y, distance;
    coordinates(int a, int b, int c)
    {
        x = a;
        y = b;
        distance = c;
    }
};

class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Initial config
        queue<coordinates> q;
        q.push({KnightPos[0], KnightPos[1], 0});
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        visited[KnightPos[0]][KnightPos[1]] = true;
        int dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
        int dy[8] = {-2, 2, -2, 2, -1, 1, -1, 1};

        // bfs in all 8 directions
        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int distance = q.front().distance;
            q.pop();

            if (x == TargetPos[0] && y == TargetPos[1])
            {
                return distance;
            }

            for (int i = 0; i < 8; i++)
            {
                int nx = x + dx[i]; // new x
                int ny = y + dy[i]; // new y
                if ((nx > 0 && nx <= N && ny > 0 && ny <= N) && visited[nx][ny] == false)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, distance + 1});
                }
            }
        }

        return -1;
    }
};