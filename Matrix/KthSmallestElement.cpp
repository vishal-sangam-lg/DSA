// Kth smallest element in row and column sorted matrix
// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Brute force:
// TC: O(n^2)
const int MAX = INT_MAX;
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pq.push(mat[i][j]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
}

// Nested Binary Search
// Approach: Find mid in such a way that it is the kth element
// Inside nested binary search, count number of elements less than mid
// If count < k. low = mid + 1;
// Else high = mid - 1;
// TC: O(log(range)*n*log(n)) where range = high - low
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];

    while (low <= high)
    {
        int count = 0;
        int mid = low + (high - low) / 2;
        for (int i = 0; i < n; i++)
        {
            int left = 0, right = n - 1;
            while (left <= right)
            {
                int m = left + (right - left) / 2;
                if (mat[i][m] <= mid)
                {
                    left = m + 1;
                }
                else
                {
                    right = m - 1;
                }
            }
            count += left;
        }
        if (count < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}