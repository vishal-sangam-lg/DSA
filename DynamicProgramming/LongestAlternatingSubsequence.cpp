// https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1
// Approach:
// Count ups and downs in the array.
// If you imagine the array as a graph.
// Longest alternating subsequence would be 1 + max(ups, downs)

int AlternatingaMaxLength(vector<int> &nums)
{
    int ups = 0, downs = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            ups = downs + 1;
        }
        else if (nums[i] < nums[i - 1])
        {
            downs = ups + 1;
        }
    }
    return 1 + max(ups, downs);
}
