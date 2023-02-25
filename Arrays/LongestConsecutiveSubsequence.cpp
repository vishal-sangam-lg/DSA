// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
// Approach: Add all elements to set. For first element of subsequence. check count using set as reference
// TC: O(N)
// SC: O(N)

#include <iostream>
#include <unordered_set>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
    unordered_set<int> s;
    for (int i = 0; i < N; i++)
    {
        s.insert(arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        // Check if current element is first element of subsequence
        if (s.find(arr[i] - 1) == s.end())
        {
            int count = 0;
            int start = arr[i];
            // Increment count untill you find consecutive elements in set
            while (s.find(start) != s.end())
            {
                count++;
                start++;
            }
            // Update ans
            ans = max(ans, count);
        }
    }
    return ans;
}