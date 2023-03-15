// https://www.geeksforgeeks.org/square-root-of-an-integer/
// Approach: 1^2,2^2,3^2,4^2… is an increasing sequence.
// So apply binary search to get square root in logn time
// TC: O(logn)
// SC: O(1)

int squareRoot(int N)
{
    int low = 0, high = N / 2, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midSquare = mid * mid;
        if (midSquare == N)
        {
            return mid;
        }
        else if (midSquare < N)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}