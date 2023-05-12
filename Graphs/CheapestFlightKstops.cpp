// https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1
// Approach: Construct graph. queue<pair<pair<int, int>, int>> q; // {{cost, node}, stopCount}
// bfs. update distance when stop <= k

int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto x : flights)
    {
        adj[x[0]].push_back({x[1], x[2]});
    }

    queue<pair<pair<int, int>, int>> q; // {{cost, node}, stopCount}

    q.push({{0, src}, 0});
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while (!q.empty())
    {
        int cost = q.front().first.first;
        int node = q.front().first.second;
        int stop = q.front().second;
        q.pop();

        // With <= k stops, update all distance to their lowest cost
        if (stop <= k)
        {
            for (auto x : adj[node])
            {
                int adjNode = x.first;
                int adjCost = x.second;
                if (cost + adjCost < dist[adjNode])
                {
                    dist[adjNode] = cost + adjCost;
                    q.push({{dist[adjNode], adjNode}, stop + 1});
                }
            }
        }
    }
    if (dist[dst] == INT_MAX)
        return -1;
    return dist[dst];
}