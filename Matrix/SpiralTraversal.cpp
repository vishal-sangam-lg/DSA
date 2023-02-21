// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> a, int r, int c)
{
    vector<int> ans;
    int top = 0;
    int bottom = r - 1;
    int right = c - 1;
    int left = 0;
    while (top <= bottom && left <= right)
    {
        if (top == bottom) // single row
        {
            for (int i = top; i <= right; i++)
            {
                ans.push_back(a[top][i]);
            }
            return ans;
        }
        if (left == right) // single col
        {
            for (int i = left; i <= bottom; i++)
            {
                ans.push_back(a[i][left]);
            }
            return ans;
        }
        for (int i = left; i <= right; i++) // processing top line
        {
            ans.push_back(a[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++) // processing right line
        {
            ans.push_back(a[i][right]);
        }
        right--;
        for (int i = right; i >= left; i--) // processing botton line
        {
            ans.push_back(a[bottom][i]);
        }
        bottom--;
        for (int i = bottom; i >= top; i--) // processing left line
        {
            ans.push_back(a[i][left]);
        }
        left++;
    }
    return ans;
}