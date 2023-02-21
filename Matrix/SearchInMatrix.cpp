// https://leetcode.com/problems/search-a-2d-matrix/
// https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1
// Approach: Use the fact that its row-wise and column-wise sorted

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = 0, col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0)
    {
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}