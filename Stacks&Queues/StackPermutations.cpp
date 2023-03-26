// https://practice.geeksforgeeks.org/problems/stack-permutations/1
// Approach: traverse a, push a[i] to stack, while(!stk.empty() && stk.top() == b[j]) pop and j++

// Dry run:
// a = [1, 2, 3]
// b = [2, 1, 3]
// Initially you will push 1 and 2 to stack
// Then stk.top == b[j]. So you pop 2 then 1 also
// Lastly stk.top = 3 = b[j]. pop 3
// Since stk.empty(), return 1

int isStackPermutation(int n, vector<int> &a, vector<int> &b)
{
    stack<int> stk;
    for (int i = 0, j = 0; i < n; i++)
    {
        stk.push(a[i]);
        while (!stk.empty() && stk.top() == b[j])
        {
            stk.pop();
            j++;
        }
    }
    return stk.empty();
}