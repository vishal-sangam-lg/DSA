// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
// Approach: Store first k elements in stack. add them to result then rest of queue to result. return result
// TC: O(n)
// SC: O(n)

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    queue<int> res;
    while (!st.empty())
    {
        res.push(st.top());
        st.pop();
    }
    while (!q.empty())
    {
        res.push(q.front());
        q.pop();
    }
    return res;
}