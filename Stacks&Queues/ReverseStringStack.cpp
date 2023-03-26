// https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1
// Approach: Store string in stack<char> Then pop and store back
// TC: O(n)
// SC: O(n)

char *reverse(char *S, int len)
{
    stack<char> stk;
    for (int i = 0; i < len; i++)
    {
        stk.push(S[i]);
    }
    for (int i = 0; i < len; i++)
    {
        S[i] = stk.top();
        stk.pop();
    }
    return S;
}