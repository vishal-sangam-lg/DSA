// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
// Approach I : store in map. check it with all twoSum pairs to form triplet
// TC: O(n^2)
// SC: O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

bool find3Numbers(int a[], int n, int X)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mp[X - a[i] - a[j]] != 0)
            {
                return true;
            }
        }
        mp[a[i]]++;
    }

    return false;
}

// Approach II : sort the array. for i = 0 -> n. Two pointer
// TC: O(n^2)
// SC: O(1)

bool find3Numbers(int a[], int n, int X)
{
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            if (a[i] + a[left] + a[right] == X)
            {
                return true;
            }
            else if (a[i] + a[left] + a[right] > X)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return false;
}