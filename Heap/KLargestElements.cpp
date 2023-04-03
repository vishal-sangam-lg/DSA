// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1
// Approach: Add all elements to maxHeap. Pop and store k elements

vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int> pq;
    vector<int> ans;
    for (int i = 0; i < n; i++) // O(n)
    {
        pq.push(arr[i]);
    }
    for (int i = 0; i < k; i++) // O(klogk)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}