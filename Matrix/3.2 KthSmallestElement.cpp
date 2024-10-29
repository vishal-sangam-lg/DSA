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
// If count < k. low = mid + 1; => mid is not our answer, answer is larger
// Else high = mid - 1; => mid could be our answer or some other smaller number
// TC: O(log(range)*n*log(n)) where range = high - low
// SC: O(1)

// Leetcode 378 - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size(), m = matrix[0].size();
    int low = matrix[0][0];
    int high = matrix[n - 1][m - 1];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;
        // Binary search each row and count the number of elements < mid
        for (int row = 0; row < n; ++row)
        {
            int l = 0, h = n - 1;
            while (l <= h)
            {
                int m = l + (h - l) / 2;
                if (matrix[row][m] <= mid)
                {
                    l = m + 1;
                }
                else
                {
                    h = m - 1;
                }
            }
            count += l; // l points at the number <= mid in that row
        }
        // count < k => kth smallest number > current mid
        if (count < k)
        {
            low = mid + 1;
        }
        // count >= k => kth smallest number <= current mid
        else
        {
            high = mid - 1;
        }
    }
    return low;
}