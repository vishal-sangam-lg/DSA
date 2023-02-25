// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
// Approach: Sliding window of size number of elements <= k
// Increment good if you add <= k to window
// Decrement good if you remove <=k from window
// Update ans with min windowSize - good (which is also the number of swaps required)
// TC: O(n)
// SC: O(1)

#include <iostream>
using namespace std;

int minSwap(int arr[], int n, int k)
{
    // windowSize = number of elements <= k
    int windowSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            windowSize++;
        }
    }
    int good = 0;
    for (int i = 0; i < windowSize; i++)
    {
        if (arr[i] <= k)
            good++;
    }
    int minSwaps = windowSize - good;
    // Increment good if you add <= k to window
    // Decrement good if you remove <=k from window
    for (int i = 1; i + windowSize <= n; i++)
    {
        if (arr[i - 1] <= k)
            good--;
        if (arr[i + windowSize - 1] <= k)
            good++;
        minSwaps = min(minSwaps, windowSize - good);
    }
    return minSwaps;
}