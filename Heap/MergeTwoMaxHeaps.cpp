// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
// Approach: Push all element of heap A and B to maxHeap pq. pop and store ans

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        pq.push(a[i]);
    for (int i = 0; i < m; i++)
        pq.push(b[i]);
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}