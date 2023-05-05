// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
// Bipartite graph - Try to color every node such that no two adjacent nodes have same color, you have only two colors
// Approach I : bfs and color every node opposite color of its parent. If the condition breaks at any point, return false

bool bfs(int node, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int currColor = color[x];
        for (auto neighbour : adj[x])
        {
            if (color[neighbour] != -1)
            {
                if (color[neighbour] == currColor)
                    return false;
            }
            else
            {
                // Assign currColor opposite color to neighbour
                color[neighbour] = currColor == 0 ? 1 : 0;
                q.push(neighbour);
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    // -1 -> no color, 0/1 are available two colors
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (bfs(i, adj, color) == false)
            {
                return false;
            }
        }
    }
    return true;
}

// Approach II - dfs -> same logic

bool dfs(int node, vector<int> adj[], vector<int> &color, bool &flag)
{
    int currColor = color[node];

    for (auto x : adj[node])
    {
        if (color[x] != -1)
        {
            if (color[x] == currColor)
            {
                flag = false;
                return false;
            }
        }
        else
        {
            color[x] = currColor == 0 ? 1 : 0;
            dfs(x, adj, color, flag);
        }
    }
    return flag;
}
bool isBipartite(int V, vector<int> adj[])
{
    // -1 -> no color, 0/1 are available two colors
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            bool flag = true;
            if (dfs(i, adj, color, flag) == false)
            {
                return false;
            }
        }
    }
    return true;
}