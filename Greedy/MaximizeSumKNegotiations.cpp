// https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1
// Approach: Sort arr, replace the smallest -ve number as +ve. k--
// If k is odd in end. replace min(arr) with -ve
// TC: O(nlogn)
// SC: O(1)

long long int maximizeSum(long long int a[], int n, int k)
{
    long long int ans = 0, mini = INT_MAX;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0 && k)
        {
            a[i] *= -1;
            k--;
        }
        ans += a[i];
        mini = min(mini, a[i]);
    }
    if (k & 1)
    {
        ans -= 2 * mini;
    }
    return ans;
}