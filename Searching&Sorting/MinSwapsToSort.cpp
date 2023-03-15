// https://practice.geeksforgeeks.org/problems/minimum-swaps/1
// Approach: Store vector<pair<int,int> {value, index}. sort it.
// traverse now swap whenever you see a change in index, swap++
// TC: O(nlogn)
// SC: O(n)

int minSwaps(vector<int> &nums)
{
    vector<pair<int, int>> originalIndex; // {num, index}
    for (int i = 0; i < nums.size(); i++)
    {
        originalIndex.push_back({nums[i], i});
    }

    sort(originalIndex.begin(), originalIndex.end());

    int swaps = 0;
    for (int i = 0; i < nums.size();)
    {
        if (i == originalIndex[i].second)
        {
            i++;
        }
        else
        {
            swap(originalIndex[i], originalIndex[originalIndex[i].second]);
            swaps++;
        }
    }
    return swaps;
}