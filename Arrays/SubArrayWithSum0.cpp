// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
// Approach: insert prefixSum to set. If prefixSum was already present
// We had a subArray in between which contributed 0 to prefixSum
// TC: O(n)
// SC: O(n)

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    set<int> s;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == 0)
            return true;
        if (s.find(prefixSum) != s.end())
            return true;
        s.insert(prefixSum);
    }
    return false;
}
