// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
// Approach: Get the maximum and minmum element in whole matrix
// Binary search in the range(mini, maxi) for a number which half number of numbers less that itself
// Binary search again for each row to get count of numbers less than mid
// TC: O(32*R*log(C))

#include <iostream>
#include <vector>
using namespace std;

// Solution I - Using upperbound STL function
int median(vector<vector<int>> &matrix, int R, int C)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    // Getting the smallest and largest number in whole matrix
    for (int i = 0; i < R; i++)
    {
        mini = min(mini, matrix[i][0]);
        maxi = max(maxi, matrix[i][C - 1]);
    }

    int half = (R * C + 1) / 2;
    // Median will be greater than half number of elements in matrix

    while (mini < maxi)
    {
        int mid = mini + (maxi - mini) / 2;
        int count = 0;
        // count number of elements less than mid in matrix
        for (int i = 0; i < R; i++)
        {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if (count < half)
        {
            mini = mid + 1;
        }
        else
        {
            maxi = mid;
        }
    }
    return mini;
}

// Solution II - Nested Binary search
int median(vector<vector<int>> &matrix, int R, int C)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    // Getting the smallest and largest number in whole matrix
    for (int i = 0; i < R; i++)
    {
        mini = min(mini, matrix[i][0]);
        maxi = max(maxi, matrix[i][C - 1]);
    }

    int half = (R * C + 1) / 2;
    // Median will be greater than half number of elements in matrix

    while (mini < maxi)
    {
        int mid = mini + (maxi - mini) / 2;
        int count = 0;
        // count number of elements less than mid in matrix
        for (int i = 0; i < R; i++)
        {
            int l = 0, h = C - 1;
            // Binary searching each row
            while (l <= h)
            {
                int m = l + (h - l) / 2;
                if (matrix[i][m] <= mid)
                {
                    l = m + 1;
                }
                else
                {
                    h = m - 1;
                }
            }
            count += l;
        }
        if (count < half)
        {
            mini = mid + 1;
        }
        else
        {
            maxi = mid;
        }
    }
    return mini;
}