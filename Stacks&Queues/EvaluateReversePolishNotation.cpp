// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Approach: Iterate t:tokens, if its operand. stk.push(stoi(t)) else pop last two, evaluate and push

int evalRPN(vector<string> &tokens)
{
    stack<int> s;
    for (string t : tokens)
        if (t == "+" || t == "-" || t == "*" || t == "/")
        {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            if (t == "+")
                op1 = op2 + op1;
            if (t == "-")
                op1 = op2 - op1;
            if (t == "/")
                op1 = op2 / op1;
            if (t == "*")
                op1 = op2 * op1;
            s.push(op1);
        }
        else
            s.push(stoi(t)); // stoi - converts from string to int
    return s.top();
}