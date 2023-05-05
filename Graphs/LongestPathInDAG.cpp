// https://practice.geeksforgeeks.org/problems/longest-path-in-a-directed-acyclic-graph/1
// Approach: Topo sort and store in vector. Traverse topologically and maximise distance

vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src)
{
    queue<int> q;
    vector<int> topo;
    vector<int> indegree(v, 0);
    vector<vector<int>> adj[v]; // source -> {node,weight}

    vector<int> distance(v, INT_MIN);
    distance[src] = 0;

    // Build graph and indegree
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        indegree[edges[i][1]]++;
    }

    // Push all source nodes to queue
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // bfs
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        for (auto x : adj[curr])
        {
            indegree[x[0]]--;
            if (indegree[x[0]] == 0)
            {
                q.push(x[0]);
            }
        }
    }

    // Traverse topologically and update distance to max
    for (auto i : topo)
    {
        for (auto x : adj[i])
        {
            int u = i;
            int v = x[0];
            int weight = x[1];
            if (distance[u] == INT_MIN)
            {
                continue;
            }
            if (distance[u] + weight > distance[v])
            {
                distance[v] = distance[u] + weight;
            }
        }
    }

    return distance;
}