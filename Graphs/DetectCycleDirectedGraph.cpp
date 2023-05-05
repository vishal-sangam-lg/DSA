// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Approach I - dfs:
// Maintain visited, recStack. If node is visted and also present in recStack
// Cycle present.

bool dfs(int V, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack, int i)
{
    visited[i] = true;
    recStack[i] = true;

    for (auto x : adj[i])
    {
        if (visited[x] == false && dfs(V, adj, visited, recStack, x))
        {
            return true;
        }
        else if (visited[x] == true && recStack[x] == true)
        {
            return true;
        }
    }

    recStack[i] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (dfs(V, adj, visited, recStack, i))
            {
                return true;
            }
        }
    }
    return false;
}

// Approach II - bfs(Kahn algorithm):
// Indegree for all vertices
// Push when indegree == 0. indgree-- was you bfs
// If count == V. You covered all vertices. If count < V -> Cycle present
bool isCyclic(int V, vector<int> adj[])
{
    // Find indegree of every vertex.
    vector<int> indeg(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            indeg[x]++;
        }
    }

    // Add vertices with indegree 0 to queue
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    // Count number of vertices covered in Kahn's algorithm
    int count = 0;
    while (!q.empty())
    {
        int curr = q.front();
        count++;
        q.pop();

        for (auto x : adj[curr])
        {
            indeg[x]--;
            if (indeg[x] == 0)
            {
                q.push(x);
            }
        }
    }

    // if all the vertices are covered
    // then count should be equal to total number of vertices
    // else there should be a cycle in graph
    // Reason: There was extra dependency(indgree) left
    return count < V;
}
