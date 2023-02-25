// https://leetcode.com/problems/subarray-sums-divisible-by-k/
// https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1
// Approach: prefixSum and freq array of remainders previously found
// If current remainder was already found. update ans.
// TC: O(n)
// SC: O(k)

int subarraysDivByK(vector<int> &nums, int k)
{
    int freq[k];
    for (int i = 0; i < k; i++)
        freq[i] = 0;

    int prefixSum = 0;
    int count = 0;
    freq[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        int remainder = prefixSum % k;
        // Handling negative remainder
        if (remainder < 0)
            remainder += k;
        if (freq[remainder] != 0)
        {
            count += freq[remainder];
        }
        freq[remainder]++;
    }
    return count;
}