// https://practice.geeksforgeeks.org/problems/non-overlapping-intervals/1
// https://leetcode.com/problems/non-overlapping-intervals/
// Approach: Sort according to ending of interval. Traverse and update prev, res
// TC: O(nlogn)
// SC: O(1)

static bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[1] < v2[1];
}
int minRemoval(int N, vector<vector<int>> &intervals)
{
    int res = 0;
    // Sort according to ending of interval
    sort(intervals.begin(), intervals.end(), cmp);

    int prev = intervals[0][1];
    for (int i = 1; i < N; i++)
    {
        if (intervals[i][0] < prev)
        {
            res++;
        }
        else
        {
            prev = intervals[i][1];
        }
    }
    return res;
}
