// find Largest sum contiguous Subarray
// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// Approach: currMax stores max till that point
// finalMax stores the max found so far
// We update the finalMax if it is less than currMax
// We set the currMax to 0 if the resulting subarray sum is -ve
// Because a -ve sum subarray will always reduce the finalMax.
// TC: O(n)
// SC: O(1)

#include <iostream>
using namespace std;

long long maxSubarraySum(int a[], int n)
{

    long long currMax = 0;
    long long finalMax = a[0];
    for (int i = 0; i < n; i++)
    {
        currMax += a[i];
        finalMax = max(finalMax, currMax);
        if (currMax < 0)
        {
            currMax = 0;
        }
    }
    return finalMax;
}

int main()
{
    int arr[] = {1, -2, 3, -2, 5};
    cout << maxSubarraySum(arr, 5) << endl;
    return 0;
}