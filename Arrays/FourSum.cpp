// https://leetcode.com/problems/4sum/
// Approach: 3 nested loop. Brute force, t3, t2, 2sum, skip duplicate entries
// TC: O(n^3)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        long long target3 = target - nums[i];
        for (int j = i + 1; j < n; j++)
        {
            long long target2 = target3 - nums[j];

            int start = j + 1;
            int end = n - 1;
            while (start < end)
            {
                long long twoSum = nums[start] + nums[end];
                if (twoSum < target2)
                    start++;
                else if (twoSum > target2)
                    end--;
                else
                {
                    vector<int> quadruplet;
                    quadruplet.push_back(nums[i]);
                    quadruplet.push_back(nums[j]);
                    quadruplet.push_back(nums[start]);
                    quadruplet.push_back(nums[end]);
                    res.push_back(quadruplet);

                    // Processing the duplicates of 3rd level
                    while (start < end && nums[start] == quadruplet[2])
                        start++;
                    // Processing the duplicates of 2rd level
                    while (start < end && nums[end] == quadruplet[3])
                        end--;
                }
            }
            // Processing the duplicates of number 2nd level
            while (j + 1 < n && nums[j + 1] == nums[j])
                j++;
        }
        // Processing the duplicates of number 1st level
        while (i + 1 < n && nums[i + 1] == nums[i])
            i++;
    }
    return res;
}