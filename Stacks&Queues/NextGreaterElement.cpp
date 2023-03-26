// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// Approach: Traverse RTL. Maintain stack in sorted order top to bottom.
// while arr[i] >= stk.top(), pop. push(arr[i])

stack<long long> stk;
// Function to find the next greater element for each element of the array.
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> nextGreater(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[i] >= stk.top())
        {
            stk.pop();
        }
        if (stk.empty())
        {
            nextGreater[i] = -1;
        }
        else
        {
            nextGreater[i] = stk.top();
        }
        stk.push(arr[i]);
    }
    return nextGreater;
}