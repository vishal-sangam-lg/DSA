// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

// Description
// A node is a terminal node if there are no outgoing edges.
// A node is a safe node if every possible path starting from that node leads to a terminal node.

// Approach:
// Transpose graph
// Topological sort with indegree same as kahn algo

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> adjRev[V];
    int indegree[V] = {0};
    // Step1: Transpose
    for (int i = 0; i < V; i++)
    {
        // i -> it
        // it -> i
        for (auto it : adj[i])
        {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> safeNodes;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Step2: Topological sort
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for (auto it : adjRev[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}