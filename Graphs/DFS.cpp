// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Approach: Push current node to ans and mark as visited. dfs() for all adjacent non visited nodes
// TC: O(V+E)
// SC: O(V)

void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
{
    // Push current node and mark as visited
    ans.push_back(node);
    visited[node] = true;

    // dfs all non-visited neighbours
    for (auto x : adj[node])
    {
        if (visited[x] == false)
        {
            dfs(x, adj, visited, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<int> ans;
    dfs(0, adj, visited, ans);
    return ans;
}