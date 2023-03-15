// https://leetcode.com/problems/search-in-rotated-sorted-array/
// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
// Approach:
// Case 1: left rotated -> So left half will be sorted
// Case 2: right rotated -> So right half will be sorted
// Intuitive if else conditions

int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        // Case 1: left rotated -> So left half will be sorted
        if (nums[low] <= nums[mid])
        {
            if (target <= nums[mid] && target >= nums[low])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Case 2: right rotated -> So right half will be sorted
        else
        {
            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}