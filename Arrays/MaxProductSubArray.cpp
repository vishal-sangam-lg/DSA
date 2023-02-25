// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
// Approach: choice1 is maxProd * a[i] choice2 is minProd * a[i]
// update MaxProd, minProd with choice 1 or 2 then update ans for every step
// TC: O(n)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

long long min(long long a, long long b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
long long max(long long a, long long b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
// Function to find maximum product subarray
long long maxProduct(vector<int> arr, int n)
{
    long long ans = arr[0];
    long long minProd = arr[0], maxProd = arr[0];
    long long choice1, choice2;
    for (int i = 1; i < n; i++)
    {
        choice1 = minProd * arr[i];
        choice2 = maxProd * arr[i];
        minProd = min(arr[i], min(choice1, choice2));
        maxProd = max(arr[i], max(choice1, choice2));
        ans = max(ans, maxProd);
    }
    return ans;
}

// Approach - II : Prefix Suffix multiplication
// Kadane's Algorithm modification
long long maxProduct(vector<int> arr, int n)
{
    long long res = INT_MIN;
    long long prefix = 1, suffix = 1;
    for (int i = 0; i < n; i++)
    {
        prefix *= arr[i];
        suffix *= arr[n - i - 1];
        res = max(res, max(prefix, suffix));
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
    }
    return res;
}