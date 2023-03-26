// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// Maintain a deque in descending order. pop if arr[i] > dq.back or dq.front == arr[i-k]
// ans.push(dq.front)

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] > dq.back())
        {
            dq.pop_back();
        }
        dq.push_back(arr[i]);
    }

    ans.push_back(dq.front());

    for (int i = k; i < n; i++)
    {
        if (dq.front() == arr[i - k])
            dq.pop_front();

        while (!dq.empty() && arr[i] > dq.back())
        {
            dq.pop_back();
        }
        dq.push_back(arr[i]);
        ans.push_back(dq.front());
    }
    return ans;
}