// https://practice.geeksforgeeks.org/problems/queue-reversal/1
// Approach: Recursively reach last element. Then add back
// TC: O(n)
// SC: O(n)

void helper(queue<int> &q)
{
    if (q.empty())
        return;

    int x = q.front();
    q.pop();
    helper(q);
    q.push(x);
}
queue<int> rev(queue<int> q)
{
    helper(q);
    return q;
}