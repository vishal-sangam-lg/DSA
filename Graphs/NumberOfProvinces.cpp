// https://practice.geeksforgeeks.org/problems/number-of-provinces/1
// Approach: dfs with visited. Whenever you find a different component. provinces++

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int V)
{
    visited[node] = true;

    for (int i = 0; i < V; i++)
    {
        if (adj[node][i] == 1 && visited[i] == false)
        {
            dfs(i, adj, visited, V);
        }
    }
}
int numProvinces(vector<vector<int>> adj, int V)
{
    int provinces = 0;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            provinces++;
            dfs(i, adj, visited, V);
        }
    }

    return provinces;
}