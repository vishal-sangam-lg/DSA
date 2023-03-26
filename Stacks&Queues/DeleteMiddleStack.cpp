// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
// Approach: mid++ for every element popped until mid = sizeOfStack/2.
// Then pop and add whatever as popped earlier
// TC: O(n)
// SC: O(n)

int mid = 0;
// Function to delete middle element of a stack.
void deleteMid(stack<int> &s, int sizeOfStack)
{
    if (mid == sizeOfStack / 2)
    {
        s.pop();
    }
    else
    {
        int x = s.top();
        s.pop();
        mid++;
        deleteMid(s, sizeOfStack);
        s.push(x);
    }
}