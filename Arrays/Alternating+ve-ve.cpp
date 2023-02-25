// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

#include <iostream>
#include <vector>
using namespace std;

void rearrange(int arr[], int n)
{
    vector<int> pos, neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    int p = 0, q = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (p >= pos.size())
                arr[i] = neg[q++];
            else
                arr[i] = pos[p++];
        }
        else
        {
            if (q >= neg.size())
                arr[i] = pos[p++];
            else
                arr[i] = neg[q++];
        }
    }
}

// https://leetcode.com/problems/rearrange-array-elements-by-sign/

vector<int> rearrangeArray(vector<int> &nums)
{
    int posIdx = 0;
    int negIdx = 1;
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            ans[posIdx] = nums[i];
            posIdx += 2;
        }
        else
        {
            ans[negIdx] = nums[i];
            negIdx += 2;
        }
    }
    return ans;
}