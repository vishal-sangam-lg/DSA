// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
// Approach: Recursively reach bottom, insertAtBottom for every element
// TC: O(n)
// SC: O(n)

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(top);
}
void Reverse(stack<int> &st)
{
    if (st.size() == 1 || st.empty())
        return;

    int x = st.top();
    st.pop();
    Reverse(st);
    insertAtBottom(st, x);
    return;
}