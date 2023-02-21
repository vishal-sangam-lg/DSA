// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
// Approach: Start from arr[0][m-1]
// move left if you find 1, update answer
// move down if you find 0
// TC: O(N + M)

#include <iostream>
#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int row = 0, col = m - 1;
    int max1sRow = 0;
    int answerWasFound = false;
    while (row < n && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            answerWasFound = true;
            col--;
            max1sRow = row;
        }
        else
        {
            row++;
        }
    }
    if (!answerWasFound)
    {
        return -1;
    }
    return max1sRow;
}