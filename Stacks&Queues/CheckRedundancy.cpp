// https://practice.geeksforgeeks.org/problems/e015cb4d3f354b035d9665e7c8a54a7aefb1901b/1
// Approach: if ( or operator, push to stack.
// If ) while top != ( pop and if you find an operator in between, its not redundant
// pop (

// Check if redundant parentheses exist in expression

int checkRedundancy(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            stk.push(ch);
        }
        else if (ch == ')')
        {
            bool operatorWasFound = false;
            while (!stk.empty() && stk.top() != '(')
            {
                stk.pop();
                operatorWasFound = true;
            }
            stk.pop();
            if (operatorWasFound == false)
            {
                return 1;
            }
        }
    }
    return 0;
}