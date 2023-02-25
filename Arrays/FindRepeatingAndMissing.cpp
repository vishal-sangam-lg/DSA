// https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// Approach: mark a[a[i] - 1] as negative
// 1st itr -> If you already find it negative, its the repeated number
// 2nd itr -> a[i] remained +ve because i+1 was missing
// TC: O(n)
// SC: O(1)

#include <iostream>
using namespace std;

int *findTwoElement(int *arr, int n)
{
    int *ans = new int[2];
    // Repeating number
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] > 0)
        {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        else
        {
            ans[0] = abs(arr[i]);
        }
    }
    // Missing number
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans[1] = i + 1;
        }
    }
    return ans;
}