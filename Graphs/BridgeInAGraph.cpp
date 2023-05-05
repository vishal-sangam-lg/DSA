// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
// Approach: dfs starting from c.
// Don't go to visited nodes && Don't go from c to d
// If d remains unvisited after dfs, there is no other way to reach d except c-d

void dfs(int node, vector<int> adj[], vector<bool> &visited, int c, int d)
{
    visited[node] = true;
    for (auto x : adj[node])
    {
        // Don't go to visited nodes && Don't go from c to d
        if (visited[x] == false && !(node == c && x == d))
        {
            dfs(x, adj, visited, c, d);
        }
    }
}
int isBridge(int V, vector<int> adj[], int c, int d)
{
    vector<bool> visited(V, false);
    dfs(c, adj, visited, c, d);
    // If d remains unvisited -> It is a bridge
    // There is no other way to reach d except c-d
    return visited[d] == false;
}