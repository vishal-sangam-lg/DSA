// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
// Approach: Add connection a->b and b->a to map
// Find head. dfs(map, visited, head, ans)

void dfs(map<int, vector<int>> &m, set<int> &visited, int head, vector<int> &ans)
{
    if (visited.find(head) != visited.end())
    {
        return;
    }

    ans.push_back(head);
    visited.insert(head);
    for (auto x : m[head])
    {
        dfs(m, visited, x, ans);
    }
}
vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
{
    // Storing the connections in map
    map<int, vector<int>> m;
    for (auto it : adjacentPairs)
    {
        m[it[0]].push_back(it[1]);
        m[it[1]].push_back(it[0]);
    }
    // Finding the head of array
    int head;
    for (auto it : m)
    {
        if (it.second.size() == 1)
        {
            head = it.first;
        }
    }
    set<int> visited;
    vector<int> ans;
    dfs(m, visited, head, ans);
    return ans;
}