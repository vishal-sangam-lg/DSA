// https://leetcode.com/problems/k-closest-points-to-origin/
// Approach: Traverse and push all points to minHeap. store first k points in minHeap to ans
// Custom comparator

struct compare
{
    bool operator()(vector<int> &p, vector<int> &q)
    {
        return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
    }
};
vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
{
    priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
    vector<vector<int>> ans;
    for (int i = 0; i < K; i++)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}