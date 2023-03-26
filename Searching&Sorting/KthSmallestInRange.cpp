// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-given-n-ranges/1
// Approach: Add to set then to vector -> Sort
// TC: O(nlogn)
// SC: O(n)

vector<int> kthSmallestNum(vector<vector<int>> &range, vector<int> queries)
{
    vector<int> temp;
    vector<int> res;
    int n = range.size();
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int start = range[i][0];
        int end = range[i][1];
        while (start <= end)
        {
            s.insert(start);
            start++;
        }
    }
    for (auto it : s)
    {
        temp.push_back(it);
    }
    sort(temp.begin(), temp.end());

    for (int i = 0; i < queries.size(); i++)
    {
        if (queries[i] > temp.size())
            res.push_back(-1);
        else
            res.push_back(temp[queries[i] - 1]);
    }
    return res;
}