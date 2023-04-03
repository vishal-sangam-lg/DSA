// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1
// Approach: maintain MinHeap of size k

int kthLargest(vector<int> &arr, int N, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // minHeap
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += arr[j];
            pq.push(sum);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
}