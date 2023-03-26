// https://leetcode.com/problems/daily-temperatures/
// Approach: Next Greater Element using monotonic stack

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<pair<int, int>> stk; // {temperature, index}
    vector<int> ans(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        while (!stk.empty() && temperatures[i] >= stk.top().first)
        {
            stk.pop();
        }
        if (stk.empty())
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = stk.top().second - i;
        }
        stk.push({temperatures[i], i});
    }
    return ans;
}