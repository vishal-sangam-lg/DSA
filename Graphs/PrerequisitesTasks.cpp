// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1
// Approach: Topological sort - Kahn's algorithm with indegree vector.
// Analogy - indegree == 0 => 0 dependencies

bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    vector<int> indegree(N, 0);
    vector<vector<int>> graph(N);
    for (auto x : prerequisites)
    {
        graph[x.second].push_back(x.first);
        indegree[x.first]++;
    }

    queue<int> q;
    int taskCompleted = 0;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        taskCompleted++;
        q.pop();

        for (auto x : graph[node])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }

    return taskCompleted == N;
}