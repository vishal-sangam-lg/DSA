// https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1
// Approach: Maintain priority_queue<pair<int,int>> {number, index} of size k

vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    priority_queue<pair<int, int>> pq; // {number, index}
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i], i});
    }
    vector<int> ans;
    ans.push_back(pq.top().first);
    for (int i = k; i < arr.size(); i++)
    {
        pq.push({arr[i], i});
        while (pq.top().second <= (i - k))
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}