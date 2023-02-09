// https://leetcode.com/problems/find-the-duplicate-number/
// Approach: Traverse LTR mark the number at index defined by current a[i] as negative
// If you find it already marked as negative then i is the answer
// Since i has repeated, it has already been marked negative
// TC: O(n)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);
        if (nums[index] < 0)
        {
            return index;
        }
        nums[index] = -nums[index];
    }
    return 0;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    cout << findDuplicate(nums) << endl;
    return 0;
}