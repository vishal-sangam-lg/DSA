// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
// Approach: prefixSum. Add to map.
// If prefixSum == 0, count++.
// If prefixSum already in map. count += freq - 1
// TC: O(n)
// SC: O(n)

long long int findSubarray(vector<long long int> &arr, int n)
{
    long long int count = 0, prefixSum = 0;
    unordered_map<long long int, int> mp;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == 0)
            count++;
        mp[prefixSum]++;

        count += mp[prefixSum] - 1;
    }
    return count;
}