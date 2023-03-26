// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
// Approach: if its operand, push to stack.
// if its operator, pop two element, stk.push(eval(num1, num2, op))
// TC: O(n)
// SC: O(n)

int eval(int a, int b, char oper)
{
    if (oper == '+')
        return a + b;
    else if (oper == '-')
        return a - b;
    else if (oper == '*')
        return a * b;
    else
        return a / b;
}
int evaluatePostfix(string s)
{
    stack<int> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            stk.push(s[i] - '0');
        }
        else
        {
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();

            stk.push(eval(num1, num2, s[i]));
        }
    }
    return stk.top();
}