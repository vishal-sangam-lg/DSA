// https://practice.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1
// Approach: Maintain buy1, buy2, profit1, profit2 at every step
// TC: O(n)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &price)
{
    // buy1 -> First buying price
    // buy2 -> Second buying price
    // profit1 -> Profit made from first sell
    // profit2 -> Profit made including both first and second sell
    int buy1 = INT_MAX, buy2 = INT_MAX, profit1 = 0, profit2 = 0;
    for (int i = 0; i < price.size(); i++)
    {
        buy1 = min(buy1, price[i]);
        profit1 = max(profit1, price[i] - buy1);
        // Use previous profit to decrease buying price
        buy2 = min(buy2, price[i] - profit1);
        profit2 = max(profit2, price[i] - buy2);
    }
    return profit2;
}