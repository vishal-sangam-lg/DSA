// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Approach: find sum, min element in array.
// TC: O(n)
// SC: O(1)
// Dry run: 1 2 3 -> 2 3 3 -> 3 4 3 -> 4 4 4
// sum = 6, min = 1, ans = 6 - (3 * 1) = 3
// 1 - 1 = 0; 2 - 1 = 1; 3 - 1 = 2 => 0 + 1 + 2 = 3(ans)
// Intuition: Incrementing n-1 elements by 1 is same as decrementing 1 element by 1
// So if you delete length times minEle. You are indirectly deleting minEle from all element
// Which results in answer

int minMoves(vector<int> &nums)
{
    int sum = 0, minEle = nums[0], len = nums.size();
    for (int i = 0; i < len; i++)
    {
        sum += nums[i];
        minEle = min(minEle, nums[i]);
    }
    // The target sum when all elements are minEle would be len * minEle
    // sum - (len * minEle) gives number of decrements required
    // Incrementing (n-1) numbers by 1 is same as decrementing 1 number by 1
    return sum - (len * minEle);
}