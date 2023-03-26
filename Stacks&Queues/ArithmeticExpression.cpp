// https://practice.geeksforgeeks.org/problems/fun-with-expresions2523/1
// Approach:
// Initialise sign = '+' and append string + '+' dummy
// According to sign. Evaluate and push to stack.
// Add all element of stack and return ans

int calculate(string s)
{
    s += '+';        // Dummy sign after last number since we process a number after we get a sign
    char sign = '+'; // to store the previously encountered sign
    stack<int> stk;
    int ans = 0, currNum = 0;

    for (int i = 0; i < s.length(); i++)
    {
        // Construct the currNum if you see a digit
        if (isdigit(s[i]))
            currNum = currNum * 10 + (s[i] - '0');
        // Evaluate currNum according to previous sign
        // -> same reason we have intial sign as + and '+' is appended to last
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if (sign == '+')
                stk.push(currNum);

            else if (sign == '-')
                stk.push(currNum * (-1));

            else if (sign == '*')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top * currNum);
            }

            else if (sign == '/')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top / currNum);
            }

            sign = s[i];
            currNum = 0;
        }
    }
    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }

    return ans;
}