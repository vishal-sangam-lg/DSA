// https://practice.geeksforgeeks.org/problems/maximum-sum-difference2545/1
// Approach:
// Let us take example of n = 5. We can easily see we can place numbers like 1 5 2 4 3.
// abs(1-5) = 4
// abs(5-2) = 3
// abs(2-4) = 2
// abs(4-3) = 1
// which sum is 4 + 3 + 2 + 1 = 10.
// In general sum of this permutation is n(n-1)/2.
// But the maximum sum is obtained if we move 3 at beginning of this permutation
// ie 3 1 5 2 4.
// Sum will become 2 + 4 + 3 + 2 = 11.
// Final relation = n (n – 1) / 2 – 1 + n / 2 for n > 1.
// The permutation of n having maximum sum will be of from n/2, n-1, 2, n-2, 3, n-3...
// So we have to find sum of this permutation which will be n(n-1)/2 – 1 + n/2.

int maxSum(int n)
{
    if (n == 1)
        return 1;
    return ((n * (n - 1)) / 2 + n / 2 - 1);
}