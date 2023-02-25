// https://leetcode.com/problems/max-consecutive-ones/
// Approach: Maintain count and maxCount variable
// TC: O(n)
// SC: O(1)

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, maxCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}