// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Approach I - dfs
// dfs with parent. if current node is already visited, its parent should be itself
// If it has some other parent, it has cycle

bool dfs(vector<int> adj[], vector<bool> &visited, int node, int parent)
{
    // Current node is visited
    visited[node] = true;

    // dfs adj list
    for (auto x : adj[node])
    {
        if (visited[x] == false)
        {
            if (dfs(adj, visited, x, node))
            {
                return true;
            }
        }
        else if (x != parent)
        {
            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    // From every node, dfs if it is not visited
    // So that all disjoint graphs are also computed
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (dfs(adj, visited, i, -1))
            {
                return true;
            }
        }
    }
    return false;
}

// Approach II - bfs
// bfs with queue<pair<int,int>> {node, parent}
// if node is visited and its parent is not equal to itself. cycle present
bool bfs(vector<int> adj[], vector<bool> &visited, int node)
{
    // Current node is visited
    queue<pair<int, int>> q;
    visited[node] = true;
    q.push({node, -1});

    // bfs adj list
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto x : adj[node])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push({x, node});
            }
            else if (x != parent)
            {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    // From every node, bfs if it is not visited
    // So that all disjoint graphs are also computed
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (bfs(adj, visited, i))
            {
                return true;
            }
        }
    }
    return false;
}