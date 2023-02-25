// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Approach: Traverse LTR update min and ans at every step
// TC: O(n)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int ans = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        ans = max(ans, prices[i] - minPrice);
    }
    return ans;
}