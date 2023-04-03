// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// Approach: Maintain minHeap of size k.
// Add all 0th elements of k arrays
// Everytime add pq.top() to answer and push its next element

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // creating a min heap
    priority_queue<node *, vector<node *>, compare> pq;
    for (int i = 0; i < K; i++)
    {
        node *temp = new node(arr[i][0], i, 0);
        pq.push(temp);
    }
    vector<int> ans;
    while (pq.size() > 0)
    {
        node *temp = pq.top();
        pq.pop();
        ans.push_back(temp->data);

        int row = temp->row;
        int col = temp->col;
        if (col + 1 < arr[row].size())
        {
            node *temp = new node(arr[row][col + 1], row, col + 1);
            pq.push(temp);
        }
    }
    return ans;
}