// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Approach I - Priority Queue:
// Use pq<pair<int,int>> minheap to store smallest node.
// Move to smallest node available, update distance of its neighbours, repeat

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> distance(V, INT_MAX);
    // min-heap of pair<int,int> {cost, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S}); // Source node
    distance[S] = 0;

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        int parentCost = top.first;
        int node = top.second;
        pq.pop();

        for (auto x : adj[node])
        {
            int nextNode = x[0];
            int edgeCost = x[1];
            // Update smallest distance to next node
            if (distance[node] + edgeCost < distance[nextNode])
            {
                distance[nextNode] = distance[node] + edgeCost;

                pq.push({distance[nextNode], nextNode});
            }
        }
    }

    return distance;
}

// Approach II - Sets
// Same logic: instead of pq.top(). use auto p = *(s.begin())

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int, int>> s; // {distance, node}
    vector<int> distance(V, INT_MAX);
    s.insert({0, S});
    distance[S] = 0;

    while (!s.empty())
    {
        auto p = *(s.begin());
        int parentCost = p.first;
        int node = p.second;
        s.erase(p);

        for (auto x : adj[node])
        {
            int nextNode = x[0];
            int edgeCost = x[1];
            if (parentCost + edgeCost < distance[nextNode])
            {
                // Delete node if it already exist in set. Insert with new values
                if (distance[nextNode] != INT_MAX)
                {
                    s.erase({distance[nextNode], nextNode});
                }
                distance[nextNode] = parentCost + edgeCost;
                s.insert({distance[nextNode], nextNode});
            }
        }
    }

    return distance;
}