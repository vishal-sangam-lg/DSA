// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Approach: Maintain a MaxHeap of size k where you push an element if arr[i] < pq.top(). return pq.top

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i <= r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}