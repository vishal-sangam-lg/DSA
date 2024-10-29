// Set zero matrix
// https://takeuforward.org/data-structure/set-matrix-zero/
// BooleanMatrix - gfg variant
// https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1

// Approach: 1st itr -> Maintain a row and col array which stores if current row/col must be 1
// 2nd itr -> if row[i] == 1 or col[j] == 1. Mark it as 1
// TC: O(n^2)
// SC: O(n+m)

#include <iostream>
#include <vector>
using namespace std;

void booleanMatrix(vector<vector<int>> &matrix)
{
    // // Brute Force
    // int n = matrix.size();
    // int m = matrix[0].size();
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         // If you find 1 mark its row and column with 0 as -1
    //         if(matrix[i][j] == 1) {
    //             for(int k = 0; k < m; k++) {
    //                 if(matrix[i][k] == 0)
    //                     matrix[i][k] = -1;
    //             }
    //             for(int k = 0; k < n; k++) {
    //                 if(matrix[k][j] == 0)
    //                     matrix[k][j] = -1;
    //             }
    //         }
    //     }
    // }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         if(matrix[i][j] == -1)
    //             matrix[i][j] = 1;
    //     }
    // }

    // Better Approach
    // This approach can we implemented using arrays or maps
    int n = matrix.size();
    int m = matrix[0].size();
    int row[n] = {0};
    int col[m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 1;
            }
        }
    }
}

// Optimal solution
// Use 1st row and 1st column to store the marking data
// TC - O(n^2) : SC - O(1)

void setZeroes(vector<vector<int>> &matrix)
{
    bool firstRowHasZero = false, firstColumnHasZero = false;
    int n = matrix.size(), m = matrix[0].size();

    // Check for firstRowHasZero and firstColumnHasZero
    for (int col = 0; col < m; ++col)
    {
        if (!matrix[0][col])
        {
            firstRowHasZero = true;
            break;
        }
    }
    for (int row = 0; row < n; ++row)
    {
        if (!matrix[row][0])
        {
            firstColumnHasZero = true;
            break;
        }
    }

    // Iterate through matrix and mark corresponding 1st row and 1st column if zero present
    for (int row = 1; row < n; ++row)
    {
        for (int col = 1; col < m; ++col)
        {
            if (!matrix[row][col])
            {
                matrix[0][col] = matrix[row][0] = 0;
            }
        }
    }

    // Iterate through matrix, if [0, col] or [row, 0] for [row, col] is 0, then mark [row, col] as 0
    for (int row = 1; row < n; ++row)
    {
        for (int col = 1; col < m; ++col)
        {
            if (!matrix[0][col] || !matrix[row][0])
            {
                matrix[row][col] = 0;
            }
        }
    }

    // Set 1st row and 1st column with 0s if required
    if (firstRowHasZero)
    {
        for (int col = 0; col < m; ++col)
        {
            matrix[0][col] = 0;
        }
    }
    if (firstColumnHasZero)
    {
        for (int row = 0; row < n; ++row)
        {
            matrix[row][0] = 0;
        }
    }
}