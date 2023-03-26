// https://leetcode.com/problems/remove-invalid-parentheses
// Approach: Counting number of invalid parentheses, solve(s, minInv).
// If s already in mp, don't process. Else process. solve(left + right, minInv - 1);

// Try solving gfg variant -> https://practice.geeksforgeeks.org/problems/remove-invalid-parentheses/1
// Extra test cases with alphabets

vector<string> res;
unordered_map<string, int> mp;

// Counting number of invalid parentheses
int getMinInvalid(string s)
{
    stack<char> stk;
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == '(')
        {
            stk.push('(');
        }
        else
        {
            if (stk.size() > 0 && stk.top() == '(')
            {
                stk.pop();
            }
            else
            {
                stk.push(')');
            }
        }
        i++;
    }
    return stk.size();
}

void solve(string s, int minInv)
{
    // Don't process same string again
    if (mp[s] != 0)
    {
        return;
    }
    else
    {
        mp[s]++;
    }

    // Base case
    if (minInv < 0)
    {
        return;
    }
    if (minInv == 0)
    {
        if (getMinInvalid(s) == 0)
        {
            res.push_back(s);
        }
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        solve(left + right, minInv - 1);
    }
}

vector<string> removeInvalidParentheses(string s)
{
    solve(s, getMinInvalid(s));
    sort(res.begin(), res.end());
    return res;
}