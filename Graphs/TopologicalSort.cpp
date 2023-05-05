// https://practice.geeksforgeeks.org/problems/topological-sort/1
// Approach I - Kahn's algorithm - bfs
// Indegree vector. Push those nodes with 0 indegree. Traverse bfs, and indegree--
// if indegree == 0. push to queue

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> indegree(V, 0);
    queue<int> q;

    // Update indegree of all nodes
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }

    // Push those nodes with 0 indegree to queue
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // bfs
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();

        // Push those nodes to queue which has indegree 0
        for (auto x : adj[node])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }

    return ans;
}

// Approach II - dfs with stack
// Traverse dfs, push to stack while returning after dfsing a particular node
// store the stack back to ans

stack<int> stk;
void dfs(vector<int> adj[], int i, vector<bool> &visited)
{
    visited[i] = true;
    for (auto x : adj[i])
    {
        if (visited[x] == false)
        {
            dfs(adj, x, visited);
        }
    }
    // Push to stack while returning from dfs
    // Basically you get the reverse order of dfs
    stk.push(i);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            dfs(adj, i, visited);
        }
    }

    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}