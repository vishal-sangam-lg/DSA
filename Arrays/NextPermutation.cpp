// https://leetcode.com/problems/next-permutation/
// https://practice.geeksforgeeks.org/problems/next-permutation5226/1
// Get the first element from RTL which is less than its next element -> i
// Get the first element from RTL which is greater than nums[i]
// swap nums[i] and nums[j]
// Reverse nums from i+1 to end

// Dry Run:
// 1 2 3 4 5
// 1 2 3 5 4
// 1 2 4 3 5
// 1 2 4 5 3
// 1 2 5 3 4
// 1 2 5 4 3
// 1 3 2 4 5
// 1 3 2 5 4
// 1 3 4 2 5
// 1 3 4 5 2
// 1 3 5 2 4
// 1 3 5 4 2
// 1 4 2 3 5
// .........

// Striver Explanation
// 1 3 5 4 2 -> Observe that there will always be an increasing sequence from RTL
// 3 is the breakpoint of this increasing sequence
// So you need to add next greater than 3 in its place from sequence
// Reverse the array after breakpoint to get minimum number out of breakpoint

#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &nums, int i, int j)
{
    while (i < j)
    {
        swap(nums[i++], nums[j--]);
    }
}
vector<int> nextPermutation(int N, vector<int> nums)
{
    if (nums.size() <= 1)
    {
        return nums;
    }
    int i = nums.size() - 2;
    // Point i at first element from RTL which is less than its next element
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;
    // If such an element doesn't exist. Only reverse the array (given arr was in desc order)
    if (i >= 0)
    {
        int j = nums.size() - 1;
        // Point j at first element from RTL which is greater than nums[i]
        while (nums[j] <= nums[i])
            j--;
        // Swap the numbers pointed by i and j
        swap(nums[i], nums[j]);
    }
    // Reverse the array from i + 1 to end to array
    reverse(nums, i + 1, nums.size() - 1);
    return nums;
}
