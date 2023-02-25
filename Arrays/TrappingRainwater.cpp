// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// Approach: initilise leftMax, rightMax array
// calculate water that can be trapped in every column
// TC: O(n)
// SC: O(n)

#include <iostream>
using namespace std;

long long trappingWater(int arr[], int n)
{
    int leftMax[n];
    int rightMax[n];

    // Initialising leftMax and rightMax arrays
    int currLeftMax = INT_MIN;
    int currRightMax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currLeftMax = max(currLeftMax, arr[i]);
        currRightMax = max(currRightMax, arr[n - i - 1]);
        leftMax[i] = currLeftMax;
        rightMax[n - i - 1] = currRightMax;
    }

    // Calculate the water that can be trapped in every column
    long long trappedWater = 0;
    for (int i = 0; i < n; i++)
    {
        trappedWater += min(leftMax[i], rightMax[i]) - arr[i];
    }

    return trappedWater;
}