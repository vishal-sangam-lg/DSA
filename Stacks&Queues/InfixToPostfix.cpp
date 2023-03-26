// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
// Approach:
// 1. Scan the string from left to right.
// 2. If scanned charecter(sc) is a alphabet then add it to the answer.
// 3. If sc is a opening parenthesis '(' then push it to the stack
// 4. If sc is a closing parenthesis ')' then till we find this '(' in the stack we need to pop the element from the stack and add it to the answer.(Associativity)
// 5.  If sc is a operator then while the operators present in the stack has higher precedence we need to pop from the stack and add it to the answer. Then add the scanned operator to the stack.
// 6. Add remaining elements from the stack to the answer.

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}
bool isChar(char c)
{
    if (c == '/' || c == '*' || c == '+' || c == '-' || c == ')' || c == '(' || c == '^')
        return false;

    return true;
}
// Function to convert an infix expression to a postfix expression.
string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (char c : infix)
    {
        if (isChar(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}