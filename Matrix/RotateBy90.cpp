// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1
// https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1
// Same solution for both questions
// Approach: Transform the matrix then swap rows
// TC: O(n^2)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

void rotateby90(vector<vector<int>> &m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i == j)
            {
                continue;
            }
            swap(m[i][j], m[j][i]);
        }
    }
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(m[i][j], m[n - i - 1][j]);
        }
    }
}
