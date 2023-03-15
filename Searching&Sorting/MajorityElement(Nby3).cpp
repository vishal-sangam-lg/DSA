// https://leetcode.com/problems/majority-element-ii/
// Approach:
// Same as majority element(n/2)
// Except that we try to find 2 most frequent element
// coz, thats the max no. of elements you can have > n/3
// TC: O(n)
// SC: O(1)

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> ans;
    int count1 = 0, count2 = 0, major1 = INT_MIN, major2 = INT_MIN;
    // Getting first and second most frequent element in array
    // coz, thats the max no. of elements you can have > n/3
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == major1)
        {
            count1++;
        }
        else if (nums[i] == major2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            major1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            major2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    // Checking if their count > n/3
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == major1)
            count1++;
        if (nums[i] == major2)
            count2++;
    }
    if (count1 > nums.size() / 3)
        ans.push_back(major1);
    if (count2 > nums.size() / 3)
        ans.push_back(major2);

    return ans;
}