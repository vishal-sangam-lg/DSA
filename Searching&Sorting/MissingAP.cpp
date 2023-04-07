// https://practice.geeksforgeeks.org/problems/missing-element-of-ap2228/1

// Brute force - Find all elements in sequence, return ans
// TC: O(n)
// SC: O(1)

int findMissing(int arr[], int n)
{
    int d = (arr[n - 1] - arr[0]) / n;
    int x = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != x)
        {
            return x;
        }
        x += d;
    }
}

// Optimal - Binary search
// TC: O(logn) SC: O(1)
// Find midEle value with formula -> nth element = a + nd
// If mid > midEle, it could be a possible ans. update and search

int findMissing(int arr[], int n)
{
    int d = (arr[n - 1] - arr[0]) / n;
    int low = 1, high = n - 1, ans;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midEle = arr[0] + mid * d; // AP -> nth element = a + nd
        if (arr[mid] > midEle)
        {
            ans = midEle;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}