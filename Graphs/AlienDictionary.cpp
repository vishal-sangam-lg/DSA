// https://practice.geeksforgeeks.org/problems/alien-dictionary/1
// Approach: Build a graph comparing every s[i] & s[i+1].
// The point of difference are two vertices to be joined in graph
// Topo sort graph to get alien dict

string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];
    vector<int> indegree(26, 0);
    // Building a graph with given data
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        for (int j = 0; j < min(s1.size(), s2.size()); j++)
        {
            if (s1[j] != s2[j])
            {
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';
                adj[u].push_back(v);
                indegree[v]++;
                break;
            }
        }
    }

    // Topological sort
    queue<int> q;
    for (int i = 0; i < K; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    string ans = "";
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto x : adj[curr])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
        char ch = 'a' + curr;
        ans += ch;
    }

    return ans;
}