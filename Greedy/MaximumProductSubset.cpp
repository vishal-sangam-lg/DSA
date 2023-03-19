// https://practice.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1
// Approach: Traverse, get count of zero, negative. maxNegative.
// Product * a[i]. If negative&1 product/maxNegative. return product

long long int findMaxProduct(vector<int> &a, int n)
{
    if (n == 1)
        return a[0];
    int negativeCount = 0, zeroCount = 0, maxNegative = INT_MIN;
    long long int product = 1, mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zeroCount++;
            // Don't include zero in product
            continue;
        }
        else if (a[i] < 0)
        {
            negativeCount++;
            maxNegative = max(maxNegative, a[i]);
        }
        product = (product * a[i]) % mod;
    }

    if (zeroCount == n || (negativeCount == 1 && zeroCount + negativeCount == n))
    {
        return 0;
    }

    // If there are odd no. of negative numbers
    // Remove largest -ve num from product
    if (negativeCount & 1)
    {
        product /= maxNegative;
    }

    return product;
}