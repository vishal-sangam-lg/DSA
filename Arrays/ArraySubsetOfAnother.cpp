// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
// Approach: store frequency in map and decrease frequency
// TC: O(n)
// SC: O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (mp.find(a2[i]) != mp.end() && mp[a2[i]] != 0)
        {
            mp[a2[i]]--;
        }
        else
        {
            return "No";
        }
    }
    return "Yes";
}