// https://leetcode.com/problems/online-stock-span
// Approach: Store prices ascending order in stack<pair<int,int>> along with update span everytime
// while stk.top().first <= currPrice count+=stk.top().second.

class StockSpanner
{
public:
    StockSpanner()
    {
    }

    stack<pair<int, int>> s;
    int next(int price)
    {
        int res = 1;
        while (!s.empty() && s.top().first <= price)
        {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
vector<int> calculateSpan(int price[], int n)
{
    vector<int> ans;
    stack<pair<int, int>> stk;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        int currPrice = price[i];
        while (!stk.empty() && stk.top().first <= currPrice)
        {
            count += stk.top().second;
            stk.pop();
        }
        stk.push({currPrice, count});
        ans.push_back(count);
    }

    return ans;
}