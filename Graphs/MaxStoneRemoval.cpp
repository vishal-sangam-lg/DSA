// https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1
// Approach: count number of components with dfs. ans = n-components.
// Intuition: You can remove all stones in a component except the last one

int maxRemove(vector<vector<int>> &stones, int n)
{
    int components = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(stones, i, visited);
            components++;
        }
    }
    return n - components;
}

void dfs(vector<vector<int>> &stones, int i, vector<bool> &visited)
{
    visited[i] = true;

    for (int j = 0; j < stones.size(); j++)
    {
        if (check(stones[j], stones[i]) && visited[j] == false)
        {
            dfs(stones, j, visited);
        }
    }
}

bool check(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return true; // if same row
    if (a[1] == b[1])
        return true; // if same column

    return false;
}