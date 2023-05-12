// https://practice.geeksforgeeks.org/problems/path-of-greater-than-equal-to-k-length1034/1
// Approach: Construct graph. dfs with backtrack visited.
// Maintain cost, if cost >= k. return true

bool dfs(int node, vector<pair<int, int>> adj[], vector<bool> &visited, int k, int cost)
{
    visited[node] = true;
    if (cost >= k)
    {
        return true;
    }

    for (auto x : adj[node])
    {
        int v = x.first;
        int wt = x.second;
        if (visited[v] == false)
        {
            if (dfs(v, adj, visited, k, cost + wt))
            {
                return true;
            }
        }
    }

    visited[node] = false; // backtrack
    return false;
}

bool pathMoreThanK(int V, int E, int k, int *a)
{
    vector<pair<int, int>> adj[V]; // graph
    // Formatting data and constructing graph
    // Every three consequetive elements are u,v,wt where (u->v)
    for (int i = 0; i < 3 * E; i = i + 3)
    {
        int u = a[i];
        int v = a[i + 1];
        int wt = a[i + 2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<bool> visited(V, 0);
    return dfs(0, adj, visited, k, 0);
}