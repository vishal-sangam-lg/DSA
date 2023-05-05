// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1
// Approach: Apply Bellman ford algo. If the distance changes in nth iteration.
// Negative weight cycle is present

int isNegativeWeightCycle(int V, vector<vector<int>> edges)
{
    vector<int> dist(V, 1e8);
    dist[0] = 0;
    bool flag = false;
    // Apply formula for V-1 times
    for (int i = 0; i < V; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                if (i == V - 1)
                {
                    flag = true;
                }
            }
        }
    }

    return flag;
}