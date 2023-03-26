// https://practice.geeksforgeeks.org/problems/valid-substring0624/1
// Approach: Traverse LTR & RTL. check validity and update len whenever open == close
// TC: O(n)
// SC: O(1)

int findMaxLen(string s)
{
    int open = 0, close = 0, len = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            open++;
        if (s[i] == ')')
            close++;

        if (close > open)
        {
            open = close = 0;
        }
        if (open == close)
        {
            len = max(len, open * 2);
        }
    }

    open = close = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            open++;
        if (s[i] == ')')
            close++;

        if (open > close)
        {
            open = close = 0;
        }
        if (open == close)
        {
            len = max(len, open * 2);
        }
    }

    return len;
}