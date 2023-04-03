// Approach: Add freq to map. traverse map and add to pq.
// Traverse pq and push to ans

// https://leetcode.com/problems/top-k-frequent-elements/

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    for (auto num : nums)
    {
        freq[num]++;
    }
    // MaxHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {freq, num}
    for (auto f : freq)
    {
        pq.push({f.second, f.first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> res;
    while (!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

// https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

vector<int> topK(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    for (auto num : nums)
    {
        freq[num]++;
    }
    // MaxHeap
    priority_queue<pair<int, int>> pq; // {freq, num}
    for (auto f : freq)
    {
        pq.push({f.second, f.first});
    }
    vector<int> res;
    while (k--)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}