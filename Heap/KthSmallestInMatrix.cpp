// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// Approach: take mid of matrix. count number of elements <= mid using binary search
// update matrix low, high. If

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];

    while (low <= high)
    {
        int count = 0;
        // Get mid of matrix
        int mid = low + (high - low) / 2;
        // In every row, count number of elements less that mid
        for (int i = 0; i < n; i++)
        {
            int left = 0, right = n - 1;
            // Binary search current row
            while (left <= right)
            {
                int m = left + (right - left) / 2;
                if (mat[i][m] <= mid)
                {
                    left = m + 1;
                }
                else
                {
                    right = m - 1;
                }
            }
            count += left;
        }
        if (count < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}