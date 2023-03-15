// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1
// Approach: Multiply(prefix products) to auxillary vector(n,1) from LTR then RTL.
// TC: O(n)
// SC: O(n)

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> v(n, 1);
    long long int ptr = 1;
    for (int i = 0; i < n; i++)
    {
        v[i] *= ptr;
        ptr *= nums[i];
    }
    ptr = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        v[i] *= ptr;
        ptr *= nums[i];
    }
    return v;
}