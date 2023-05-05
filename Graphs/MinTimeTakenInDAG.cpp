// https://practice.geeksforgeeks.org/problems/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/1
// Approach: Build graph with data with indegree
// Topological sort, if indegree becomes 0
// answer of current node = 1 + parent node ans

vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
{
    vector<int> ans(n, 0);
    vector<int> adj[n + 1];
    vector<int> indegree(n + 1, 0);

    // Build graph with given data, updata indegree
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }

    // Topological Sort
    queue<int> q;
    for (int i = 1; i < n + 1; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            ans[i - 1]++;
        }
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbour : adj[curr])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
                ans[neighbour - 1] = ans[curr - 1] + 1;
            }
        }
    }

    return ans;
}