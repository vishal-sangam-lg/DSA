// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
// Approach: Binary search to get count of 0s in mid
// 0s depends on 2s and 5s, since we always have more number of 2s
// It depends only on 5s.
// Check if current number has >= n 5s

// TC: O(log2 N * log5 N)
// SC: O(1)

int findNum(int n)
{
    int ans = 0;
    int low = 1;
    int high = 5 * n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;

        for (int i = 5; mid / i >= 1; i *= 5)
        {
            count += mid / i;
        }

        if (count >= n)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}