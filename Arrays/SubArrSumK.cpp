// https://leetcode.com/problems/subarray-sum-equals-k/
// Approach: add prefix sum to map. If prefixSum - k is already present in map, update ans
// TC: O(n)
// SC: O(n)

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int prefixSum = 0, ans = 0;
    mp[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        if (mp.find(prefixSum - k) != mp.end())
        {
            ans += mp[prefixSum - k];
        }
        mp[prefixSum]++;
    }
    return ans;
}