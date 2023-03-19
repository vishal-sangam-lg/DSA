// https://practice.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1
// Approach: vector<pair<int, int>> priceQty. Sort.
// Calculate max stocks starting from ascending order of prices
// TC: O(nlogn)
// SCL: O(n)

int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> priceQty;
    for (int i = 0; i < n; i++)
    {
        priceQty.push_back({price[i], i + 1});
    }
    sort(priceQty.begin(), priceQty.end());

    int stocks = 0;
    for (int i = 0; i < n; i++)
    {
        if (priceQty[i].first * priceQty[i].second < k)
        {
            stocks += priceQty[i].second;
            k -= priceQty[i].first * priceQty[i].second;
        }
        else
        {
            stocks += k / priceQty[i].first;
            break;
        }
    }
    return stocks;
}