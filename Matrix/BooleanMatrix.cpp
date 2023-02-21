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