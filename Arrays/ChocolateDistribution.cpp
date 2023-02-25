// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
// Approach: sort the array. slide a window of size students(m)
// TC: O(nlogn)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    long long minDiff = INT_MAX;
    // sliding window of size m
    int start = 0, end = m - 1;
    while (end < n)
    {
        minDiff = min(minDiff, a[end++] - a[start++]);
    }
    return minDiff;
}