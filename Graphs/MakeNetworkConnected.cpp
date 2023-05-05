// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// https://practice.geeksforgeeks.org/problems/minimize-connections/1
// Approach: dfs with visited. Count disjoint graphs. return count - 1

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
{
    visited[src] = true;
    for (int i : adj[src])
        if (visited[i] == false)
            dfs(adj, visited, i);
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
        return -1;
    vector<vector<int>> adj(n);
    for (auto v : connections)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }

    vector<bool> visited(n, false);
    int components = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            components++;
            dfs(adj, visited, i);
        }
    }
    // If there are n components, you need to make n-1 connections
    // to make all computers connected
    return components - 1;
}