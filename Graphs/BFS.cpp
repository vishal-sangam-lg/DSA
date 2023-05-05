// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Approach: Maintain Queue, visited. Push a node and all its adj nodes to queue if they are not visited
// While poping add to ans
// TC: O(V+E)
// SC: O(V)

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> ans;
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        ans.push_back(a);

        for (auto x : adj[a])
        {
            if (visited[x] == 0)
            {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
    return ans;
}