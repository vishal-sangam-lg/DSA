// https://practice.geeksforgeeks.org/problems/minimum-sum-of-absolute-differences-of-pairs/1
// Approach: Sort a and b. sum += abs(a[i] - b[i]);
// TC: O(nlogn)
// SC: O(1)

long long findMinSum(vector<int> &a, vector<int> &b, int N)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += abs(a[i] - b[i]);
    }
    return sum;
}