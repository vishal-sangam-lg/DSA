// https://leetcode.com/problems/basic-calculator-ii/
// https://practice.geeksforgeeks.org/problems/fun-with-expresions2523/1
// Same code for both

// Approach: Using stack to store numbers
// if isdigit(s[i]) construct currNum
// Else according to previous sign, evaluate currNum and push to stack
//      Upate sign to currSign and currNum = 0
// TC: O(n)
// SC: O(n)

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