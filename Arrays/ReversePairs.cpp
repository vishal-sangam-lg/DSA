// https://leetcode.com/problems/reverse-pairs/
// Approach: merge() and count++
// TC: O(nlogn)
// SC: O(n)

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int left, int mid, int right, int &count)
{
    int *leftSubArr = new int[mid - left + 1];
    int *rightSubArr = new int[right - mid];
    for (int i = 0; i < mid - left + 1; i++)
        leftSubArr[i] = nums[left + i];
    for (int i = 0; i < right - mid; i++)
        rightSubArr[i] = nums[mid + 1 + i];
    int j = mid + 1;
    for (int i = left; i <= mid; i++)
    {
        while (j <= right && nums[i] > 2ll * nums[j])
        {
            j++;
        }
        count += j - (mid + 1);
    }
    j = 0;
    int k = left, i = 0;
    while (i < mid - left + 1 && j < right - mid)
    {
        if (leftSubArr[i] <= rightSubArr[j])
            nums[k++] = leftSubArr[i++];
        else
            nums[k++] = rightSubArr[j++];
    }
    while (i < mid - left + 1)
        nums[k++] = leftSubArr[i++];
    while (j < right - mid)
        nums[k++] = rightSubArr[j++];
    return;
}
void mergeSort(vector<int> &nums, int left, int right, int &count)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, count);
        mergeSort(nums, mid + 1, right, count);
        merge(nums, left, mid, right, count);
    }
}
int reversePairs(vector<int> &nums)
{
    int count = 0;
    int left = 0, right = nums.size() - 1;
    mergeSort(nums, left, right, count);
    return count;
}