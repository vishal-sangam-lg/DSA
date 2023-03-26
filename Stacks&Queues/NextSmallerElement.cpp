// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1
// Approach: Traverse RTL. Maintain stack in sorted order top to bottom.
// while stk.top() >= arr[i], pop. push(arr[i])

vector<int> help_classmate(vector<int> arr, int n)
{
    stack<int> stk;
    vector<int> nextSmaller(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() >= arr[i])
        {
            stk.pop();
        }
        if (stk.empty())
        {
            nextSmaller[i] = -1;
        }
        else
        {
            nextSmaller[i] = stk.top();
        }
        stk.push(arr[i]);
    }
    return nextSmaller;
}