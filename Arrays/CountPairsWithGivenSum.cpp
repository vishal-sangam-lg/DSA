// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
// Approach: Traverse LTR add to map
// if map already has k - arr[i]. Increase count
// TC: O(n)
// SC: O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int value = k - arr[i];
        if (mp[value])
        {
            count += mp[value];
        }
        mp[arr[i]]++;
    }
    return count;
}