// Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.
// https://practice.geeksforgeeks.org/problems/count-element-occurences/1

// Approach: Map
// Add all elements to map with frequency
// Traverse the map and increase the count if frequency > n/k
// TC: O(n)
// SC: O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

int countOccurence(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    int count = 0;
    for (auto it : mp)
    {
        if (it.second > n / k)
        {
            count++;
        }
    }
    return count;
}