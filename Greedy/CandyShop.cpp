// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1
// Approach: Sort candies.
// For minimum, include candies from start and reduce size-k for every candy
// For maximum, include candies from last and reduce 0+k for every candy
// TC: O(nlogn)
// SC: O(1)

vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies + N);

    int minimum = 0, maximum = 0, n = N;

    for (int i = 0; i < n; i++)
    {
        minimum += candies[i];
        n -= K;
    }

    n = N;
    int j = 0;
    for (int i = n - 1; i >= j; i--)
    {
        maximum += candies[i];
        j += K;
    }

    return {minimum, maximum};
}