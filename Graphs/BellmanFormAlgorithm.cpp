// Bellman Ford Algorithm

// Step 1
// n-1 times update (n -> no. of vertices)
// if(dist[u] + edgeCost < dist[v]) {
//     dist[v] = dist[u] + edgeCost
// }

// Step 2
// Apply the same formula again to all nodes
// If any one distance updates -> Negative cycle is present
// You cannot find shortest path

// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// Update distance n-1 times in whole graph, If it updates nth time, -ve cycle else return dist[]

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    // Apply formula for V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // checking cycle Nth time
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                return {-1}; // Negative cycle detected
            }
        }
    }
    // no negative cycle
    return dist;
}