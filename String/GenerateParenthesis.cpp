// https://leetcode.com/problems/generate-parentheses
// https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1
// Approach: Recursion with helper(open, close, n, current, &result)
// If current.length() == n*2. Add to result. Else helper(both cases)

void helper(int open, int close, int n, string current, vector<string> &result)
{
    if (current.length() == n * 2)
    {
        result.push_back(current);
        return;
    }
    if (open < n)
        helper(open + 1, close, n, current + "(", result);
    if (close < open)
        helper(open, close + 1, n, current + ")", result);
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    helper(0, 0, n, "", result);
    return result;
}