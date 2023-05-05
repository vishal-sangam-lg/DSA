// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Approach: minHeap pair<int,int> {weight,node}. Always choose the min weight from heap
// Add all adjacent nodes of it and mark visited

int spanningTree(int V, vector<vector<int>> adj[])
{
    // Prim's Algorithm
    // minHeap of {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<bool> visited(V, false);
    int ans = 0;
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int node = p.second;
        int weight = p.first;
        if (visited[node] == false)
        {
            visited[node] = true;
            ans += weight;
            for (auto x : adj[node])
            {
                if (visited[x[0]] == false)
                {
                    pq.push({x[1], x[0]});
                }
            }
        }
    }
    return ans;
}