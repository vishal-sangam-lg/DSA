// https://leetcode.com/problems/find-the-most-competitive-subsequence/
// Approach: Store smallest number possible till that point using monotonic array

vector<int> mostCompetitive(vector<int> &nums, int k)
{
    vector<int> ans;
    for (int i = 0, numFixed = 0; i < nums.size(); i++)
    {
        while (ans.size() > numFixed && ans.back() > nums[i])
        {
            ans.pop_back();
        }
        if (ans.size() < k)
        {
            ans.push_back(nums[i]);
        }
        if (i >= nums.size() - k)
        {
            numFixed++;
        }
    }
    return ans;
}